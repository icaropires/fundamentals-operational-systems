#ifndef PROJECT2_INC_KID_H_
#define PROJECT2_INC_KID_H_

#define _GNU_SOURCE
#define _BSD_SOURCE

#include <time.h>

#include "../inc/utils.h"
#include "../inc/semaphore.h"

// Messages.
#define CROSSING_MSG "Kid is crossing"
#define CROSSED_MSG "Kid is crossed"
#define THINKING_MSG "Kid is thinking"
#define WAITING_MSG "Kid is waiting"

#define MAX_THINKING_DELAY 1000
#define MAX_CROSSING_DELAY 70
#define STEPS_TO_CROSS 7

void kid_think(pid_t pid);

void kid_wait(pid_t pid);

void kid_cross(pid_t pid, pid_t *rope);

void print_rope(pid_t *rope, size_t size);

void fall_kid();

void apply_delay(time_t time);

void print_kid_status(pid_t pid, char *status);

#endif // PROJECT2_INC_KID_H_
