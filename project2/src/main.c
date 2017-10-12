#include "../inc/semaphore.h"
#include "../inc/message.h"
#include "../inc/kid.h"

int main(int argc, char** argv) {
	generate_arb_file();

	int n_kids = 0;
	fprintf(stdout, "Quantas crianças, meu chapa?\n");
	scanf("%d", &n_kids);

	pid_t rope[STEPS_TO_CROSS];
	memset(rope, -1, sizeof(rope));

	int semid = get_ready_semaphores(STEPS_TO_CROSS, 1);
	fprintf(stderr, "Initialized semaphore with semid: %d\n", semid);

	for(int i = 0; i < n_kids; ++i){
		pid_t pid = fork();

		if(pid){
			fprintf(stderr, "Starting parent process: %d\n", getpid());

			fprintf(stderr, "Ending parent\n");
		} else{
			pid_t my_pid = getpid();

			fprintf(stderr, "Starting kid (%d): %d\n", i, my_pid);

			kid_think(my_pid);
			// if can cross
			kid_cross(my_pid, rope);

			fprintf(stderr, "Ending kid\n");
		}
	}
			
	return 0;
}
