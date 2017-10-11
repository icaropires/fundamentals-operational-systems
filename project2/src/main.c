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

    // Generate 10 kids.
    //for(int i=0;i<10;i++) {
        pid_t pid = fork();
    	if(pid){
            signal(2, handle_sigint);
            fprintf(stdout, "PAI\n");
    	} else {
            //while(1) {
    	        printf("filho %d\n", pid);
                sleep(1);
                fprintf(stdout,"%d: Quero atravessar", pid);
    			binary_semaphore_down(semid, 0);
                acrossing_kid(pid);
    			binary_semaphore_up(semid, 0);
            //}
        }
    //}

    fprintf(stdout, "I'm working\n");

    return 0;
}
