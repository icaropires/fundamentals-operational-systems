#include "../inc/semaphore.h"
#include "../inc/message.h"
#include "../inc/kid.h"
#include "../inc/shared_memory.h"

int main(int argc, char** argv) {
    fprintf(stderr, "(start) Starting program...\n");

	generate_arb_file();

	int n_kids = 0;
	fprintf(stdout, "Quantas crianças?\n");
	scanf("%d", &n_kids);

    int kids_segment_id = allocate_sh_memory(n_kids);
    Kid *kids = (Kid *) attach_sh_memory_segment(kids_segment_id);
    memset(kids, -1, n_kids * sizeof(Kid));

	int rope_segment_id = allocate_sh_memory(ROPE_SIZE);
	pid_t *rope = (pid_t *) attach_sh_memory_segment(rope_segment_id);
	memset(rope, -1, ROPE_SIZE * sizeof(pid_t));

	int sem_rope = get_ready_semaphores(ROPE_SIZE, 1, 1);

	rope[AMOUNT_CROSSED] = 0;

	for(int i = 0; i < n_kids; ++i){
		pid_t pid = fork();

		if(pid && i == 0){
			fprintf(stderr, "Starting parent process: %d\n", getpid());

			pid_t watch_pid = fork();
			if(watch_pid == 0){
				watch_printing_rope(rope, n_kids);
				exit(0);
			}

			fprintf(stderr, "Ending parent\n");
		} else if (!pid){
			pid_t my_pid = getpid();
			fprintf(stderr, "Starting kid (%d): %d\n", i + 1, my_pid);

			pid_t *rope = attach_sh_memory_segment(rope_segment_id);
			Kid *kids = attach_sh_memory_segment(kids_segment_id);

            fill_kid_info(my_pid, kids, n_kids, 'L');
            Kid this_kid = kids[find_kid(my_pid, kids, n_kids)];

			kid_think(this_kid);
			kid_cross(this_kid, rope);

			fprintf(stderr, "Ending kid\n");
			exit(0);
		}
	}

	// Plus 1 because of watching process
	for(int i = 0; i < n_kids + 1; ++i){
		wait(0);
	}

    fprintf(stderr, "\n(start) Final deallocations...\n");
	remove_semaphores(sem_rope);
	deallocate_sh_memory(rope_segment_id);
	deallocate_sh_memory(kids_segment_id);
    fprintf(stderr, "\n(success) Final deallocations...\n");

    fprintf(stderr, "(success) Everything was like it meant to be\n");
	return 0;
}
