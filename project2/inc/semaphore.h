#ifndef PROJECT2_INC_SEMAPHORE_H_
#define PROJECT2_INC_SEMAPHORE_H_

#include "utils.h"
#include <sys/sem.h>

#define SEMAPHORES_NUMBER 1

union semun {
    int val;
    struct semid_ds *buf;
    unsigned short int *array;
    struct seminfo *__buf;
};

void semaphore_wait_for_zero(int semid);

int create_semaphores(char *file_path, int sem_flags);

int initialize_semaphores(int semid);

void binary_semaphore_up(int semid);

void binary_semaphore_down(int semid);

#endif  // PROJECT2_INC_SEMAPHORE_H_
