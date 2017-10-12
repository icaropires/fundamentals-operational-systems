#include "../inc/semaphore.h"
#include "../inc/message.h"
#include "../inc/kid.h"
#include "../inc/shared_memory.h"

int main(int argc, char** argv) {
	generate_arb_file();

	int n_kids = 0;
	fprintf(stdout, "Quantas crianças?\n");
	scanf("%d", &n_kids);

	int semid = get_ready_semaphores(STEPS_TO_CROSS, 1);

	int segment_id = allocate_sh_memory(STEPS_TO_CROSS);
	pid_t *rope = attach_sh_memory_segment(segment_id);
	memset(rope, -1, sizeof(*rope) * STEPS_TO_CROSS);

	for(int i = 0; i < n_kids; ++i){
		pid_t pid = fork();

		if(pid && i == 0){
			fprintf(stderr, "Starting parent process: %d\n", getpid());

			const int each_step_time = MAX_CROSSING_DELAY/STEPS_TO_CROSS;
			
			printf("Meu pid: %d\n", getpid());

			for(int i = 0; i <= STEPS_TO_CROSS; ++i){
				usleep(2000);
				fflush(stdout);
				print_rope(rope, STEPS_TO_CROSS);
			}

			// Waiting for children to die
			for(int j = n_kids; j > 0; --j){
				int status = 3;
				wait(&status);

				if(status == 0){
					fprintf(stderr, "Some kid returned succesfully\n");
				} else {
					fprintf(stderr, "Some kid returned an error\n");
				}
			}

			remove_semaphores(semid);
			deallocate_sh_memory(segment_id);

			fprintf(stderr, "Ending parent\n");
		} else if (!pid){
			printf("criança %d\n", getpid());

			pid_t my_pid = getpid();
			fprintf(stderr, "Starting kid (%d): %d\n", i, my_pid);

			pid_t *rope = attach_sh_memory_segment(segment_id);

			kid_think(my_pid);
			// if can cross
			kid_cross(my_pid, rope);

			fprintf(stderr, "Ending kid\n");
			exit(0);
		}
	}
			
	return 0;
}
