#ifndef PROJECT2_INC_KID_H_
#define PROJECT2_INC_KID_H_

#define _GNU_SOURCE
#define _BSD_SOURCE

#include "../inc/utils.h"
#include "../inc/semaphore.h"

#include <time.h>

// Messages
#define CROSSING_MSG "Kid is crossing"
#define CROSSED_MSG "Kid has crossed"
#define THINKING_MSG "Kid is thinking"

// About crossing
#define STEPS_TO_CROSS 7
#define ROPE_SIZE (STEPS_TO_CROSS + 2)
#define LAST_STEP (ROPE_SIZE -2)
#define FIRST_STEP 1
#define MAXIMUM_KIDS_CROSSES 1 // is this + 2

// Delays
#define MAX_THINKING_DELAY 1000  // micro-seconds
#define MAX_CROSSED_DELAY 70 * (int)2e4 // micro-seconds
#define STEP_DELAY (MAX_CROSSED_DELAY/STEPS_TO_CROSS) // micro-seconds
#define SWITCH_SIDES_DELAY (int)5e3 // mico-seconds

// Sides
#define RIGHT 'R'
#define LEFT 'L'

// About meta shared
#define META_SIZE 4
#define RIGHT_AMOUNT 0  // Value is a index
#define LEFT_AMOUNT 1  // Value is a index
#define CROSSES_TO_END 2  // Value is a index; Crosses to stop execution
#define CROSSING_AMOUNT 3  // Value is a index;

// About locking
#define LOCKING_MANAGE_SIZE 2
#define RIGHT_LOCK 0  // Value is a index
#define LEFT_LOCK 1  // Value is a index

#define EXTRA_CHILD_PROCESS_AMOUNT 2 // Processes watch and switch

typedef struct kid {
	pid_t pid;
	unsigned int short_id;
	char side;
    unsigned int crosses;
    unsigned int maximum_crosses; // Crosses to get tired
} Kid;

int find_kid(pid_t kid_pid, Kid *kids, int n_kids);

void apply_random_delay(time_t time);

void kid_think(Kid kid);

void kid_wait(Kid kid);

void kid_cross(Kid kid, pid_t *rope, int *meta_sh);

void print_rope(pid_t *rope, Kid *kids, int *meta_sh);

void watch_printing_rope(pid_t *rope, int n_crosses, Kid *kids, int *meta_sh);

void print_kid_status(Kid kid, char *status);

void fill_kid_info(pid_t kid_pid, Kid *kids, int n_kids, char side);

void swap_side(Kid *kid, int *meta_sh);

#endif // PROJECT2_INC_KID_H_
