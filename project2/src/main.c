#include "semaphore.h"
#include "message.h"
#include "kid.h"
#include <signal.h>

int semid;

void handle_sigint(int signal){
	printf("%d\n", semid);
	remove_semaphores(semid);
	exit(0);
}

int main(int argc, char** argv) {
	generate_arb_file();

	semid = create_semaphores(ARB_FILE, IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR, 1);

    pid_t pid = fork();

	if(pid){
		signal(2, handle_sigint);
		int count = 0;

		while(1){
			printf("pai\n");
			sleep(1);

			if(count == 5){
				fprintf(stderr, "pai: %d\n", count);
				binary_semaphore_up(semid, 0);
			}
			count++;
		}
		kill(pid, SIGINT);
	} else{
		int count = 0;
		while(1){
			printf("filho\n");
			sleep(1);

			if(count == 2){
				fprintf(stderr, "filho: %d\n", count);
				binary_semaphore_down(semid, 0);
			}

			count++;
		}
	}
    // thinking_kid(pid);
    // waiting_kid(pid);
    // acrossing_kid(pid);

	fprintf(stdout, "I'm working\n");

    return 0;
}
