#include "../inc/kid.h"

// time is the maximum value
void apply_random_delay(time_t time) {
    fprintf(stderr, "\n(start) Applying delay of %d miliseconds..\n", (int)time);

    unsigned int seed = clock();
    assert(seed != -1);

    int delay = rand_r(&seed) % time;
    usleep(delay);

    fprintf(stderr, "(success) Delay of %d miliseconds ended\n", (int)time);
}

void print_kid_status(pid_t pid, char *status) {
    fprintf(stderr, "%d %s\n", pid, status);
}

void kid_think(pid_t pid) {
    fprintf(stderr, "\n(start) Kid %d starting to think...\n", pid);

    print_kid_status(pid, THINKING_MSG);
    apply_random_delay(MAX_THINKING_DELAY);

    fprintf(stderr, "(success) Kid %d ended thinking\n", pid);
}

void kid_wait(pid_t pid) {
    fprintf(stderr, "\n(start) Kid %d will be waiting...\n", pid);

    print_kid_status(pid, WAITING_MSG);

    fprintf(stderr, "(success) Kid %d stopped waiting\n", pid);
}

void kid_cross(pid_t pid, pid_t *rope) {
    fprintf(stderr, "\n(start) Kid %d starting thinking...\n", pid);

    int semid = get_ready_semaphores(ROPE_SIZE, 0, 1);
	assert(get_sem_size(semid) == ROPE_SIZE);

    for(int i = 1; i < ROPE_SIZE; ++i){
        // Erase footprint of previus step
        if(i > 1){
			if(rope[i - 1] == pid){
				rope[i-1] = -1;
			}
        }

        down(semid, i);
        rope[i] = pid;
        usleep(MAX_CROSSING_DELAY/STEPS_TO_CROSS);
		if(i == ROPE_SIZE - 1){
			rope[i] = -1;
		}
        up(semid, i);
    }

	rope[AMOUNT_CROSSED]++;

    fprintf(stderr, "(success) Kid %d crossed\n", pid);
}

void print_rope(pid_t *rope){
    fprintf(stderr, "\n(start) Printing rope...\n");

	for(int i = 1; i < ROPE_SIZE; ++i){
		fprintf(stdout, "[%4d]%s",
				(int) rope[i], i != ROPE_SIZE - 1? "" : "\n");
	}

    fprintf(stderr, "(success) Rope was printed\n");
}


void watch_printing_rope(pid_t *rope, int n_crosses){
	fprintf(stdout, "\n=========================================================\n");

	time_t time_counter = 0;
	time_t time_step = MAX_CROSSING_DELAY/STEPS_TO_CROSS;

	while(rope[AMOUNT_CROSSED] < n_crosses){
		fprintf(stdout, "%10d ms: ", (int)time_counter);
		print_rope(rope);

		usleep(time_step);
		time_counter += time_step;
	}
	fprintf(stdout, "%10d ms: ", (int)time_counter);
	print_rope(rope);
	fprintf(stdout, "=========================================================\n");
}
