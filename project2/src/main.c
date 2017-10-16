#include "../inc/semaphore.h"
#include "../inc/message.h"
#include "../inc/kid.h"
#include "../inc/shared_memory.h"

int main(int argc, char** argv) {
    fprintf(stderr, "(start) Starting program...\n");

	generate_arb_file();

	// Interacting with user
	int n_kids = 0;
	fprintf(stdout, "Quantas crianças?\n");
	scanf("%d", &n_kids);

	// Prepare shared memory area with kids info
    int kids_segment_id = allocate_sh_memory(n_kids);
    Kid *kids = (Kid *) attach_sh_memory_segment(kids_segment_id);
    memset(kids, -1, n_kids * sizeof(Kid));

	// Prepare shared memory area which is the rope
	int rope_segment_id = allocate_sh_memory(ROPE_SIZE);
	int *rope = (pid_t *) attach_sh_memory_segment(rope_segment_id);
	memset(rope, -1, ROPE_SIZE * sizeof(pid_t));

	// Prepare shared memory area for managing kids crossing
	int manage_segment = allocate_sh_memory(META_SIZE);
	int *meta_sh = (int *) attach_sh_memory_segment(manage_segment);
	memset(meta_sh, -1, META_SIZE * sizeof(int));

	// Getting semaphores for managing kids and locking sides
	int sem_rope = get_ready_semaphores(ROPE_SIZE, 1, 1, ARB_CHAR_A);
	int locking_manage = get_ready_semaphores(LOCKING_MANAGE_SIZE, 1, 1, ARB_CHAR_B);

	// Initializing what is needed in shared memory area
    meta_sh[CROSSING_AMOUNT] = 0;
	meta_sh[CROSSES_TO_END] = 0;

	// Starts with one side locked
	down(locking_manage, LEFT_LOCK);

	// Generate the multiple kids
	for(int i = 0; i < n_kids; ++i){
		pid_t pid = fork();

		// Process parent
		if(pid && i == 0){
			fprintf(stderr, "Starting parent process: %d\n", getpid());

			// Process for watching
			pid_t watch_pid = fork();
			if(watch_pid == 0){
				watch_printing_rope(rope, n_kids, kids, meta_sh);
				exit(0);
			}

			// Process for swap sides
			pid_t swap_sides_pid = fork();
			if(swap_sides_pid == 0){
				int *meta_sh = attach_sh_memory_segment(manage_segment);
				
				
				// Finish when kids are tired
				while(meta_sh[CROSSES_TO_END] > 0){
					// Free left when has no one crossing
					usleep(SWITCH_SIDES_DELAY);
					down(locking_manage, RIGHT_LOCK);
					while(meta_sh[CROSSING_AMOUNT] > 0){
						usleep(STEP_DELAY);
					}
					up(locking_manage, LEFT_LOCK);

					// Free right when has no one crossing
					usleep(SWITCH_SIDES_DELAY);
					down(locking_manage, LEFT_LOCK);
					while(meta_sh[CROSSING_AMOUNT] > 0){
						usleep(STEP_DELAY);
					}
					up(locking_manage, RIGHT_LOCK);

					// Needs improvement
					if(meta_sh[CROSSES_TO_END] > 0){
						fprintf(stdout,
								"------------------------------------------------------------------\n"
								"Crosses to end: %d\n"
								"Finishing first turn\n"
								"------------------------------------------------------------------\n",
								meta_sh[CROSSES_TO_END]);
					}
				}
				exit(0);
			}

			fprintf(stderr, "Ending parent\n");
		} else if (!pid){  // Kid process
			pid_t my_pid = getpid();
			fprintf(stderr, "Starting kid (%d): %d\n", i + 1, my_pid);

			// Attaching to shared memory areas
			int *rope = attach_sh_memory_segment(rope_segment_id);
			int *meta_sh = attach_sh_memory_segment(manage_segment);
			Kid *kids = attach_sh_memory_segment(kids_segment_id);

			// Generate kid for each side
            if (!(i % 2)) {
                fill_kid_info(my_pid, kids, n_kids, RIGHT);
				meta_sh[RIGHT_AMOUNT]++;
            } else {
                fill_kid_info(my_pid, kids, n_kids, LEFT);
				meta_sh[LEFT_AMOUNT]++;
            }
			
			// Know what the index of this kid on kids vector
			int this_kid_id = find_kid(my_pid, kids, n_kids);

			meta_sh[CROSSES_TO_END] += kids[this_kid_id].maximum_crosses;

			while(meta_sh[CROSSES_TO_END] > 0 &&
					kids[this_kid_id].maximum_crosses >= kids[this_kid_id].crosses){
				kid_think(kids[this_kid_id]);
				kid_cross(kids[this_kid_id], rope, meta_sh);
				kids[this_kid_id].crosses++;
			}

			fprintf(stderr, "(success) Ending kid\n");
			exit(0);
		}
	}
	
	// Wait for kids finish
	for(int i = 0; i < n_kids + EXTRA_CHILD_PROCESS_AMOUNT; ++i){
		if(CROSSES_TO_END <= 0){
			for(int i = 0; i < n_kids; ++i){
				kill(kids[i].pid, SIGTERM);
				break;
			}
		}
		wait(0);
	}

	// Freeing resources
    fprintf(stderr, "\n(start) Final deallocations...\n");
	remove_semaphores(sem_rope);
	remove_semaphores(locking_manage);
	deallocate_sh_memory(rope_segment_id);
	deallocate_sh_memory(kids_segment_id);
	deallocate_sh_memory(manage_segment);
    fprintf(stderr, "(success) Final deallocations...\n");

    fprintf(stderr, "(success) Everything was like it meant to be\n");
	return 0;
}
