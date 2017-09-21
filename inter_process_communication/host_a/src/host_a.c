#include <host_a.h>

void binary_semaphore_up(int semid){
    struct sembuf operations[1];

    operations[0].sem_num = 0;
    operations[0].sem_op = 1;
    operations[0].sem_flg = SEM_UNDO;

    if(semop(semid, operations, 1)){
       perror("Wasn't possible to up the semaphore");
    }
}
