#include "../inc/semaphore.h"
#include "../inc/message.h"
#include "../inc/kid.h"
#include "../inc/shared_memory.h"

int main(int argc, char** argv) {
	generate_arb_file();

	int n_kids = 0;
	fprintf(stdout, "Quantas crianças?\n");
	scanf("%d", &n_kids);

	int sem_rope = get_ready_semaphores(ROPE_SIZE, 1, 1);

	int segment_id = allocate_sh_memory(ROPE_SIZE);
	pid_t *rope = attach_sh_memory_segment(segment_id);
	memset(rope, -1, sizeof(*rope) * ROPE_SIZE);
	rope[AMOUNT_CROSSED] = 0;

	for(int i = 0; i < n_kids; ++i){
		pid_t pid = fork();

		if(pid && i == 0){
			fprintf(stderr, "Starting parent process: %d\n", getpid());

			fprintf(stderr, "Ending parent\n");

			pid_t watch_pid = fork();
			if(watch_pid == 0){
				watch_printing_rope(rope, n_kids);
				exit(0);
			}
		} else if (!pid){
			pid_t my_pid = getpid();
			fprintf(stderr, "Starting kid (%d): %d\n", i, my_pid);

			pid_t *rope = attach_sh_memory_segment(segment_id);

			kid_think(my_pid);
			kid_cross(my_pid, rope);

			fprintf(stderr, "Ending kid\n");
			exit(0);
		}
	}

	// Plus 1 because of watching process
	for(int i = 0; i < n_kids + 1; ++i){
		wait(0);
	}

	remove_semaphores(sem_rope);
	deallocate_sh_memory(segment_id);

	return 0;
}
