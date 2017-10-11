#include "semaphore.h"
#include "message.h"
#include "kid.h"

int main(int argc, char** argv) {
    pid_t pid = fork();
    thinking_kid(pid);
    return 0;
}
