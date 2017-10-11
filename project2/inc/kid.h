#ifndef KID_H
#define KID_H

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

// Messages.
#define ACROSSING_MSG "Kid acrossing"
#define CROSSED_MSG "Kid crossed"
#define THINKING_MSG "Kid thinking"
#define WAITING_MSG "Kid waiting"

// Consts.
#define MAX_THINKING_DELAY 1000
#define MAX_CROSSING_DELAY 70

void thinking_kid(int pid);

void waiting_kid(int pid);

void acrossing_kid(int pid);

void fall_kid();

void apply_delay();

void print_kid_status(int id, char *status);

#endif // PROJECT2_INC_UTILS_H_
