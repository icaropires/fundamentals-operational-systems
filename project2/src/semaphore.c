#include "semaphore.h"

int create_semaphores(char *file_path, int sem_flags, int sem_num) {
	fprintf(stderr, "\n(start) Creating semaphores...\n");

	int semid = -1;
	key_t key = ftok(file_path, ARB_CHAR_A);

	if(key != -1){
		fprintf(stderr, "Key generated, key: %d\n", (int)key);
		semid = semget(key, sem_num, sem_flags);

		if(semid != -1){
			fprintf(stderr, "(success) Semaphore created, semid: %d\n", semid);
		} else {
			perror("(error) Was not possible to create semaphores");
			exit(1);
		}
	} else {
		perror("(error) Couldn't generate key with ftok");
	}

	return semid;
}

void remove_semaphores(int semid){
    fprintf(stderr, "\n(start) Removing semaphore %d...\n", semid);

	if(!semctl(semid, IGNORED_VALUE, IPC_RMID)){
        fprintf(stderr, "(success) Semaphore %d removed\n", semid);
	} else {
		perror("(error) Wasn't possible to remove semaphore");
    }
}

size_t get_sem_size(int semid){
	fprintf(stderr, "\n(start) Getting size of %d semaphore...\n", semid);

	struct semid_ds info;
	size_t size = -1;

	if(semctl(semid, IGNORED_VALUE, IPC_STAT, &info) != -1){
		size = info.sem_nsems;
		fprintf(stderr, "(success) Size gotten: %d\n", (int) size);
	} else {
		perror("(error) Couldn't get semaphore size");
		exit(1);
	}

	return size;
}

int initialize_semaphores(int semid, int value) {
	fprintf(stderr, "\n(start) Initializing sem %d semaphores with value %d...\n", semid, value);

	size_t sem_size = get_sem_size(semid);

	union semun argument;
	argument.array =
		(unsigned short int *) malloc(sizeof(unsigned short int) * sem_size);

	for(int i = 0; i < sem_size; ++i){
		argument.array[i] = value;
	}

	int code = semctl(semid, sem_size, SETALL, argument);
	free(argument.array);

	if(code != -1){
		fprintf(stderr, "(success) Semaphore initialized\n");
	} else {
		perror("(error) Wasn't possible intialize semaphores");
		exit(1);
	}

	return code;
}

int get_ready_semaphores(int sem_num, int exclusive, int initialize) {
	fprintf(stderr, "\n(start) Getting semaphores ready...\n");

	int semid = -1;

	if(exclusive){
		semid = create_semaphores(ARB_FILE,
				IPC_CREAT | IPC_PRIVATE | S_IRUSR | S_IWUSR,
				sem_num);
	} else {
		semid = create_semaphores(ARB_FILE,
				IPC_CREAT | S_IRUSR | S_IWUSR,
				sem_num);
	}

	initialize_semaphores(semid, initialize);

	fprintf(stderr, "(success) Got semaphores ready\n");

	return semid;
}

void get_sem_th_val(int semid, int sem_th){
	fprintf(stderr, "\n(start) Getting sem %d, sem-th:%d value...\n", semid, sem_th);

	assert(sem_th < get_sem_size(semid));

	struct semid_ds info;
	int sem_val = semctl(semid, sem_th, GETVAL, &info);

	if(sem_val != -1){
		fprintf(stderr,
				"------------------------------------------------------------\n"
				"(success) current status: semid: %d, sem_th: %d, sem_val: %d\n" 
				"-------------------------------------------------------------\n",
				semid,
				sem_th,
				sem_val);
	} else {
		perror("(error) Couldn't get information about semaphore");
		exit(1);
	}
}

void up(int semid, int sem_th) {
    fprintf(stderr, "\n(start) Upping semaphore %d, sem-th: %d...\n", semid, sem_th);
	assert(sem_th < get_sem_size(semid));

	struct sembuf operations[1];

	operations[0].sem_num = sem_th;
	operations[0].sem_op = 1;
	operations[0].sem_flg = 0;

	fprintf(stderr, "(success) Semaphore was incremented\n");
	if(semop(semid, operations, 1) != -1){
		get_sem_th_val(semid, sem_th);
	} else {
		perror("(error) Wasn't possible to up the semaphore");
		exit(1);
	}
}

void down(int semid, int sem_th) {
    fprintf(stderr, "\n(start) Downing semaphore %d, sem-th: %d...\n", semid, sem_th);
	assert(sem_th < get_sem_size(semid));

	struct sembuf operations[1];

	operations[0].sem_num = sem_th;
	operations[0].sem_op = -1;
	operations[0].sem_flg = 0;

	fprintf(stderr, "(success) Semaphore will be decremented\n");
	get_sem_th_val(semid, sem_th);

	if(semop(semid, operations, 1) != -1){
		// Nothing
	} else {
		perror("(error) Wasn't possible to down the semaphore");
	}
}

void semaphore_wait_for_zero(int semid, int sem_th) {
    fprintf(stderr, "\n(start) Making semaphore %d, sem-th:%d wait for zero...\n", semid, sem_th);
	assert(sem_th < get_sem_size(semid));

	struct sembuf operations[1];

	operations[0].sem_num = sem_th;
	operations[0].sem_op = 0;
	operations[0].sem_flg = 0;

	if(semop(semid, operations, 1) != -1){
		fprintf(stderr, "(success) Semaphore is waiting for zero\n");
		get_sem_th_val(semid, sem_th);
	} else {
		perror("(error) Wasn't possible to make semaphore wait for zero");
		exit(1);
	}
}
