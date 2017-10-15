#ifndef PROJECT2_INC_KID_H_
#define PROJECT2_INC_KID_H_

#define _GNU_SOURCE
#define _BSD_SOURCE

#include <time.h>

#include "../inc/utils.h"
#include "../inc/semaphore.h"

// Messages
#define CROSSING_MSG "Kid is crossing"
#define CROSSED_MSG "Kid has crossed"
#define THINKING_MSG "Kid is thinking"

// About crossing
#define STEPS_TO_CROSS 7
#define ROPE_SIZE (STEPS_TO_CROSS + 2)
#define LAST_STEP (FIRST_STEP + STEPS_TO_CROSS - 1)
#define FIRST_STEP 1

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
#define RIGHT_AMOUNT 0  // Index
#define LEFT_AMOUNT 1  // Index
#define CROSSED_AMOUNT 2  // Index
#define CROSSING_AMOUNT 3  // Index

// About locking
#define LOCKING_MANAGE_SIZE 2
#define RIGHT_LOCK 0  // Index
#define LEFT_LOCK 1  // Index

#define EXTRA_CHILD_PROCESS_AMOUNT 2 // Watch and switch

typedef struct kid {
	pid_t pid;
	unsigned int short_id;
	char side;
} Kid;

int find_kid(pid_t kid_pid, Kid *kids, int n_kids);

void apply_random_delay(time_t time);

void kid_think(Kid kid);

void kid_wait(Kid kid);

void kid_cross(Kid kid, pid_t *rope, int *meta_sh);

void print_rope(pid_t *rope, Kid *kids);

void watch_printing_rope(pid_t *rope, int n_crosses, Kid *kids, int *meta_sh);

void fall_kid();

void print_kid_status(Kid kid, char *status);

void fill_kid_info(pid_t kid_pid, Kid *kids, int n_kids, char side);

#endif // PROJECT2_INC_KID_H_
