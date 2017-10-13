#include "../inc/kid.h"

int find_kid(pid_t kid_pid, Kid *kids, int n_kids){
	// Could sort and binary search
	int i; for(i = 0; kids[i].pid != kid_pid && i < n_kids; ++i);

	return i;
}

// time is the maximum value
void apply_random_delay(time_t time) {
    fprintf(stderr, "\n(start) Applying delay of %d miliseconds..\n", (int)time);

    unsigned int seed = clock();
    assert(seed != -1);

    int delay = rand_r(&seed) % time;
    usleep(delay);

    fprintf(stderr, "(success) Delay of %d miliseconds ended\n", (int)time);
}

void print_kid_status(Kid kid, char *status) {
    fprintf(stderr, "%d %s\n", kid.short_id, status);
}

void kid_think(Kid kid) {
    fprintf(stderr, "\n(start) Kid %d starting to think...\n", kid.short_id);

    print_kid_status(kid, THINKING_MSG);
    apply_random_delay(MAX_THINKING_DELAY);

    fprintf(stderr, "(success) Kid %d ended thinking\n", kid.short_id);
}

void kid_wait(Kid kid) {
    fprintf(stderr, "\n(start) Kid %d will be waiting...\n", kid.short_id);

    print_kid_status(kid, WAITING_MSG);

    fprintf(stderr, "(success) Kid %d stopped waiting\n", kid.short_id);
}

void kid_cross(Kid kid, pid_t *rope) {
    fprintf(stderr, "\n(start) Kid %d starting crossing...\n", kid.short_id);

    int semid = get_ready_semaphores(ROPE_SIZE, 0, 1);
	assert(get_sem_size(semid) == ROPE_SIZE);

	// Crosses depending on which side the kid is
	if (kid.side == RIGHT) {
		for(int i = FIRST_STEP - 1; i <= LAST_STEP; ++i){
			if (i != LAST_STEP){
				down(semid, i + 1);
				rope[i + 1] = kid.short_id;
				rope[i] = -1;
				up(semid, i);
				usleep(STEP_DELAY);	
			} else {
				rope[i] = -1;
				up(semid, i);
			}
		}
	} else {
		for(int i = LAST_STEP + 1; i >= FIRST_STEP; --i){
			if (i != FIRST_STEP){
				down(semid, i - 1);
				rope[i - 1] = kid.short_id;
				rope[i] = -1;
				up(semid, i);
				usleep(STEP_DELAY);	
			} else {
				rope[i] = -1;
				up(semid, i);
			}
		}
	}

	// swap side
	if(kid.side == RIGHT){
		kid.side = LEFT;
	} else {
		kid.side = RIGHT;
	}

	rope[AMOUNT_CROSSED]++;

    fprintf(stderr, "(success) Kid %d crossed\n", kid.short_id);
}

void print_rope(pid_t *rope, Kid *kids){
	fprintf(stderr, "\n(start) Printing rope...\n");

	for(int i = FIRST_STEP; i <= LAST_STEP; ++i){

		// I has some kid on this rope position
		if(rope[i] != -1){
			const char KID_SIDE = kids[rope[i] - 1].side;

			// Which side are the kid?
			if(KID_SIDE == LEFT){
				fprintf(stdout, "|<-%3d|%s",
						(int) rope[i],
						i != LAST_STEP? "" : "\n");
			} else {
				fprintf(stdout, "|%3d->|%s",
						(int) rope[i],
						i != LAST_STEP? "" : "\n");
			}
		} else {
			fprintf(stdout, "%s%s",
					"~~~~~~~",
					i != LAST_STEP? "" : "\n");
		}
	}

    fprintf(stderr, "(success) Rope was printed\n");
}

void watch_printing_rope(pid_t *rope, int n_crosses, Kid *kids){
	fprintf(stdout, "\n================================================================\n");

	time_t time_counter = 0;
	time_t time_step = MAX_CROSSING_DELAY/STEPS_TO_CROSS;

	while(rope[AMOUNT_CROSSED] < n_crosses){
		fprintf(stdout, "%10d ms: ", (int)time_counter);
		print_rope(rope, kids);

		usleep(time_step);
		time_counter += time_step;
	}
	fprintf(stdout, "%10d ms: ", (int)time_counter);
	print_rope(rope, kids);
	fprintf(stdout, "================================================================\n");
}

void fill_kid_info(pid_t kid_pid, Kid *kids, int n_kids, char side) {
   fprintf(stderr, "\nStarting filling information about kid with pid: %d\n", kid_pid);

   int i; for(i = 0; kids[i].pid != -1 && i < n_kids; ++i);

   kids[i].pid = kid_pid;
   kids[i].short_id = i + 1;
   kids[i].side = side;

   fprintf(stderr, "(success) Filled information about kid with pid: %d\n", kid_pid);
}
