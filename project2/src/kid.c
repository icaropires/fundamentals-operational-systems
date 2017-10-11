#include "kid.h"

void thinking_kid(int pid) {
    print_kid_status(pid, THINKING_MSG);
    apply_delay(MAX_THINKING_DELAY);
}

void waiting_kid(int pid) {
    print_kid_status(pid, WAITING_MSG);
    
}

void acrossing_kid(int pid) {
    print_kid_status(pid, ACROSSING_MSG);
    apply_delay(MAX_CROSSING_DELAY);
}

void apply_delay(int time) {
    unsigned int seed = clock();
    int delay = rand_r(&seed)%time;
    usleep(delay);
}

void print_kid_status(int id, char *status) {
    fprintf(stdout, "%d %s\n", id, status);
}
