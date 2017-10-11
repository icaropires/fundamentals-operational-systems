#include "semaphore.h"

int create_semaphores(char *file_path, int sem_flags, int sem_num) {

    key_t key = ftok(file_path, ARB_CHAR_A);

    if(key != -1){
        int semid = semget(key, sem_num, sem_flags);

        if(semid != -1){
            return semid;
        } else {
            perror("Was not possible to allocate semaphores");
        }
    } else {
        perror("Couldn't generate key with ftok");
    }
}

void remove_semaphores(int semid){
    const int IGNORED_VALUE = 0;

    if(semctl(semid, IGNORED_VALUE, IPC_RMID)){
        perror("Wasn't possible to remove semaphore");
    }
}

// Ready for binary semaphore
int initialize_semaphores(int semid, int sem_num) {
    Semun argument;

    for(int i = 0; i < sem_num; ++i){
        argument.array[i] = 1;
    }

    int code = semctl(semid, sem_num, SETALL, argument);
    if(code != -1){
        return code;
    } else {
        perror("Wasn't possible intializing semaphores");
    }
}

int get_ready_semaphores(char *file_path, int sem_flags, int sem_num) {
    int semid = create_semaphores(file_path, sem_flags, sem_num);
    initialize_semaphores(semid, sem_num);

    return semid;
}

void check_sem_th_limit(int semid, int sem_th){
	const int IGNORED_VALUE = 0;

	struct semid_ds info;
	if(semctl(semid, IGNORED_VALUE, IPC_STAT, &info) != -1){
		if(sem_th >= info.sem_nsems){
			fprintf(stderr, "Was specified a sem_th bigger than the array");
		}
	} else {
		perror("Couldn't get information about semaphore");
	
	}
}

void binary_semaphore_up(int semid, int sem_th) {
	check_sem_th_limit(semid, sem_th);

    struct sembuf operations[1];

    operations[0].sem_num = sem_th;
    operations[0].sem_op = 1;

    if(semop(semid, operations, 1) != -1){
       fprintf(stderr, "Semaphore was incremented\n");
    } else {
       perror("Wasn't possible to up the semaphore");
	}
}

void semaphore_wait_for_zero(int semid, int sem_th) {
	check_sem_th_limit(semid, sem_th);

    struct sembuf operations[1];

    operations[0].sem_num = sem_th;
    operations[0].sem_op = 0;

    if(semop(semid, operations, 1) != -1){
       fprintf(stderr, "Semaphore is waiting for zero\n");
    } else {
       perror("Wasn't possible to make semaphore wait for zero");
	}
}

void binary_semaphore_down(int semid, int sem_th) {
	check_sem_th_limit(semid, sem_th);

    struct sembuf operations[1];

    operations[0].sem_num = sem_th;
    operations[0].sem_op = -1;

    if(semop(semid, operations, 1) != -1){
       fprintf(stderr, "Semaphore was decremented\n");
    } else {
       perror("Wasn't possible to down the semaphore");
	}
}
