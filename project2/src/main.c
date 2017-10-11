#include "semaphore.h"
#include "message.h"
#include "kid.h"

int main(int argc, char** argv) {
    pid_t pid = fork();
    thinking_kid(pid);
    waiting_kid(pid);
    acrossing_kid(pid);
    return 0;
}
