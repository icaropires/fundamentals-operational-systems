#include "../inc/kid.h"

void kid_think(pid_t pid) {
    print_kid_status(pid, THINKING_MSG);
    apply_delay(MAX_THINKING_DELAY);
}

void kid_wait(pid_t pid) {
    print_kid_status(pid, WAITING_MSG);
}

void kid_cross(pid_t pid, pid_t *rope) {
    print_kid_status(pid, CROSSING_MSG);

    int semid = get_ready_semaphores(STEPS_TO_CROSS, 0);
	assert(get_sem_size(semid) == STEPS_TO_CROSS);

    for(int i = 0; i < STEPS_TO_CROSS; ++i){
        // Erase foot print of previus step
        if(rope[i - (i != 0)] && rope[i] == pid){
            rope[i-1] = -1;
        }

        down(semid, i);
        rope[i] = pid;
        apply_delay((float)MAX_CROSSING_DELAY/STEPS_TO_CROSS);
        up(semid, i);
    }

    apply_delay(MAX_CROSSING_DELAY);
}

void apply_delay(time_t time) {
    unsigned int seed = clock();
    assert(seed != -1);

    int delay = rand_r(&seed) % time;
    usleep(delay);
}

void print_kid_status(pid_t pid, char *status) {
    fprintf(stdout, "%d %s\n", pid, status);
}
