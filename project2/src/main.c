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
	pid_t *rope = (pid_t *) attach_sh_memory_segment(rope_segment_id);
	memset(rope, -1, ROPE_SIZE * sizeof(pid_t));

	// Prepare shared memory area for managing kids crossing
	int manage_segment = allocate_sh_memory(META_SIZE);
	int *meta_sh = (int *) attach_sh_memory_segment(manage_segment);
	memset(meta_sh, -1, META_SIZE * sizeof(int));

	// Getting semaphores for managing kids and locking sides
	int sem_rope = get_ready_semaphores(ROPE_SIZE, 1, 1, ARB_CHAR_A);
	int locking_manage = get_ready_semaphores(LOCKING_MANAGE_SIZE, 1, 1, ARB_CHAR_B);

	// Initializing what is needed in shared memory area
    meta_sh[CROSSED_AMOUNT] = 100;
    meta_sh[CROSSING_AMOUNT] = 0;

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

				while(meta_sh[CROSSED_AMOUNT]){
					usleep(SWITCH_SIDES_DELAY);
					down(locking_manage, RIGHT_LOCK);
					while(meta_sh[CROSSING_AMOUNT]){
						usleep(STEP_DELAY);
					}
					up(locking_manage, LEFT_LOCK);

					usleep(SWITCH_SIDES_DELAY);
					down(locking_manage, LEFT_LOCK);
					while(meta_sh[CROSSING_AMOUNT]){
						usleep(STEP_DELAY);
					}
					up(locking_manage, RIGHT_LOCK);
				}
				exit(0);
			}

			fprintf(stderr, "Ending parent\n");
		} else if (!pid){  // Kid process
			pid_t my_pid = getpid();
			fprintf(stderr, "Starting kid (%d): %d\n", i + 1, my_pid);

			// Attaching to shared memory areas
			pid_t *rope = attach_sh_memory_segment(rope_segment_id);
			int *meta_sh = attach_sh_memory_segment(manage_segment);
			Kid *kids = attach_sh_memory_segment(kids_segment_id);

			// Generate kid for each side
            if (i % 2) {
                fill_kid_info(my_pid, kids, n_kids, RIGHT);
            } else {
                fill_kid_info(my_pid, kids, n_kids, LEFT);
            }

			// Know what the index of this kid on kids vector
			int this_kid_index = find_kid(my_pid, kids, n_kids);
            Kid this_kid = kids[this_kid_index];

			// Crossing
			kid_think(this_kid);
			kid_cross(this_kid, rope, meta_sh);

			fprintf(stderr, "Ending kid\n");
			exit(0);
		}
	}
	
	// Wait for kids finish
	for(int i = 0; i < n_kids + EXTRA_CHILD_PROCESS_AMOUNT; ++i){
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
