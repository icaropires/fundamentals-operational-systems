#include "semaphore.h"
#include "message.h"
#include "kid.h"

int main(int argc, char** argv) {
	generate_arb_file();

    pid_t pid = fork();
    thinking_kid(pid);
    waiting_kid(pid);
    acrossing_kid(pid);

	fprintf(stdout, "I'm working\n");

    return 0;
}
