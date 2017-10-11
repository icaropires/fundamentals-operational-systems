#include "semaphore.h"
#include "message.h"
#include "kid.h"

int main(int argc, char** argv) {
	generate_arb_file();
	int semid = get_ready_semaphores(10);

    pid_t pid = fork();

	if(pid){
		remove_semaphores(semid);
		fprintf(stderr, "Ending parent\n");
	} else{
		fprintf(stderr, "Ending kid\n");
	}
	return 0;
    // thinking_kid(pid);
    // waiting_kid(pid);
    // acrossing_kid(pid);
	
}
