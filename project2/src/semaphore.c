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
    if(semctl(semid, IGNORED_VALUE, IPC_RMID)){
        perror("Wasn't possible to remove semaphore");
    }
}

// Ready for binary semaphore
int initialize_semaphores(int semid, int sem_num, int value) {
    Semun argument;

    for(int i = 0; i < sem_num; ++i){
        argument.array[i] = value;
    }

    int code = semctl(semid, sem_num, SETALL, argument);
    if(code != -1){
        return code;
    } else {
        perror("Wasn't possible intializing semaphores");
    }
}

int get_ready_semaphores(int sem_num) {
    int semid = create_semaphores(ARB_FILE, IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR, sem_num);
    initialize_semaphores(semid, sem_num, 0);

    return semid;
}

void check_sem_th_limit(int semid, int sem_th){
	struct semid_ds info;

	if(semctl(semid, IGNORED_VALUE, IPC_STAT, &info) != -1){
        assert(sem_th < info.sem_nsems);
	} else {
		perror("Couldn't get information about semaphore");
	
	}
}

void get_sem_th_val(int semid, int sem_th){
	struct semid_ds info;
    int sem_val = semctl(semid, sem_th, GETVAL, &info);

	if(sem_val != -1){
        fprintf(stderr,
                "---------------------------------------------------------\n"
                "current status: semid: %d, sem_th: %d, sem_val: %d\n" 
                "---------------------------------------------------------\n",
                semid,
                sem_th,
                sem_val);
	} else {
		perror("Couldn't get information about semaphore");
	
	}
}

void up(int semid, int sem_th) {
	check_sem_th_limit(semid, sem_th);

    struct sembuf operations[1];

    operations[0].sem_num = sem_th;
    operations[0].sem_op = 1;
    operations[0].sem_flg = 0;

   fprintf(stderr, "Semaphore was incremented\n");
    if(semop(semid, operations, 1) != -1){
        get_sem_th_val(semid, sem_th);
    } else {
       perror("Wasn't possible to up the semaphore");
	}
}

void down(int semid, int sem_th) {
	check_sem_th_limit(semid, sem_th);

    struct sembuf operations[1];

    operations[0].sem_num = sem_th;
    operations[0].sem_op = -1;
    operations[0].sem_flg = 0;

    fprintf(stderr, "Semaphore will be decremented\n");
    get_sem_th_val(semid, sem_th);

    if(semop(semid, operations, 1) != -1){
        // Nothing
    } else {
       perror("Wasn't possible to down the semaphore");
	}
}

void semaphore_wait_for_zero(int semid, int sem_th) {
	check_sem_th_limit(semid, sem_th);

    struct sembuf operations[1];

    operations[0].sem_num = sem_th;
    operations[0].sem_op = 0;
    operations[0].sem_flg = 0;

    if(semop(semid, operations, 1) != -1){
       fprintf(stderr, "Semaphore is waiting for zero\n");
        get_sem_th_val(semid, sem_th);
    } else {
       perror("Wasn't possible to make semaphore wait for zero");
	}
}
