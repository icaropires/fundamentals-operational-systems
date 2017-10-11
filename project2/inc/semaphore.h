#ifndef PROJECT2_INC_SEMAPHORE_H_
#define PROJECT2_INC_SEMAPHORE_H_

#include "utils.h"
#include <sys/sem.h>

typedef union semun {
    int val;
    struct semid_ds *buf;
    unsigned short int *array;
    struct seminfo *__buf;
} Semun;

int create_semaphores(char *file_path, int sem_flags, int sem_num);

int initialize_semaphores(int semid, int sem_num);

int get_ready_semaphores(char *file_path, int sem_flags, int sem_num);

void check_sem_th_limit(int semid, int sem_th);

void semaphore_wait_for_zero(int semid, int sem_th);

void binary_semaphore_up(int semid, int sem_th);

void binary_semaphore_down(int semid, int sem_th);

#endif  // PROJECT2_INC_SEMAPHORE_H_