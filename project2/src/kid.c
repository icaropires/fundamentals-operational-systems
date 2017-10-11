#include "kid.h"

void thinking_kid(int pid) {
    fprintf(stdout, "%d %s\n", pid, THINKING_MSG);
    unsigned int seed = clock();
    int delay = rand_r(&seed)%MAX_THINKING_DELAY;
    usleep(delay);
}

void acrossing_kid(int pid) {
    fprintf(stdout, "%d %s\n", pid, ACROSSING_MSG);
    unsigned int seed = clock();
    int delay = rand_r(&seed)%MAX_CROSSING_DELAY;
    usleep(delay);
}
