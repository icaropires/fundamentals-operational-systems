#include "semaphore.h"

int create_semaphores(char *file_path, int sem_flags){

    key_t key = ftok(file_path, ARB_CHAR_A);

    int semid = semget(key, SEMAPHORES_NUMBER, sem_flags);
    if(semid != -1){
        return semid;
    } else {
        perror("Was not possible to allocate semaphores");
    }
}

// Ready for binary semaphore
int initialize_semaphores(int semid){
    unsigned short SEMNUM_TH = 0;

    union semun argument;
    unsigned short values[1];
    values[0] = 1;
    argument.array = values;

    int code = semctl(semid, SEMNUM_TH, SETALL, argument);
    if(code != -1){
        return code;
    } else {
        perror("Wasn't possible intializing semaphores");
    }
}

void binary_semaphore_up(int semid){
    struct sembuf operations[1];

    operations[0].sem_num = 0;
    operations[0].sem_op = 1;

    if(semop(semid, operations, 1)){
       perror("Wasn't possible to up the semaphore");
    }
}

void semaphore_wait_for_zero(int semid) {
		struct sembuf operations[1];

    operations[0].sem_num = 0;
    operations[0].sem_op = 0;

    if(semop(semid, operations, 1)){
       perror("Wasn't possible to down the semaphore");
    }
}

void binary_semaphore_down(int semid) {
    struct sembuf operations[1];

    operations[0].sem_num = 0;
    operations[0].sem_op = -1;

    if(semop(semid, operations, 1)){
       perror("Wasn't possible to down the semaphore");
    }
}
