#include "../inc/kid.h"

void kid_think(pid_t pid) {
    fprintf(stderr, "\nKid %d starting to think...\n", pid);

    print_kid_status(pid, THINKING_MSG);
    apply_delay(MAX_THINKING_DELAY);

    fprintf(stderr, "Kid %d ended thinking\n", pid);
}

void kid_wait(pid_t pid) {
    fprintf(stderr, "\nKid %d will be waiting...\n", pid);

    print_kid_status(pid, WAITING_MSG);

    fprintf(stderr, "Kid %d stopped waiting\n", pid);
}

void kid_cross(pid_t pid, pid_t *rope) {
    fprintf(stderr, "\nKid %d starting thinking...\n", pid);

    int semid = get_ready_semaphores(STEPS_TO_CROSS, 0);
	assert(get_sem_size(semid) == STEPS_TO_CROSS);

    for(int i = 0; i < STEPS_TO_CROSS; ++i){
        // Erase footprint of previus step
        if(rope[i - (i != 0)] && rope[i] == pid){
            rope[i-1] = -1;
        }

        down(semid, i);
        rope[i] = pid;
        apply_delay((float)MAX_CROSSING_DELAY/STEPS_TO_CROSS);
        up(semid, i);
    }

    fprintf(stderr, "Kid %d crossed\n", pid);
}

void print_rope(pid_t *rope, size_t size){
    fprintf(stderr, "\nPrinting rope...\n");

	for(int i = 0; i < size; ++i){
		fprintf(stdout, "[%d]%s",
				(int) rope[i], i != size - 1? "" : "\n");
	}

    fprintf(stderr, "Rope was printed\n");
}

void apply_delay(time_t time) {
    fprintf(stderr, "\nApplying delay of %d miliseconds..\n", (int)time);

    unsigned int seed = clock();
    assert(seed != -1);

    int delay = rand_r(&seed) % time;
    usleep(delay);

    fprintf(stderr, "Delay of %d miliseconds ended\n", (int)time);
}

void print_kid_status(pid_t pid, char *status) {
    fprintf(stderr, "%d %s\n", pid, status);
}
