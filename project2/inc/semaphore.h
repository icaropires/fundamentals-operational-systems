#ifndef PROJECT2_INC_SEMAPHORE_H_
#define PROJECT2_INC_SEMAPHORE_H_

#define _GNU_SOURCE

#include <sys/sem.h>

#include "../inc/utils.h"
#include "../inc/semaphore.h"

#define IGNORED_VALUE 0

union semun {
    int val;
    struct semid_ds *buf;
    unsigned short int *array;
    struct seminfo *__buf;
};

int create_semaphores(char *file_path, int sem_flags, int sem_num, char arb_file);

void remove_semaphores(int semid);

size_t get_sem_size(int semid);

int initialize_semaphores(int semid, int value);

int get_ready_semaphores(int sem_num, int exclusive, int initialize, char arb_file);

void semaphore_wait_for_zero(int semid, int sem_th);

void up(int semid, int sem_th);

void down(int semid, int sem_th);

#endif  // PROJECT2_INC_SEMAPHORE_H_
