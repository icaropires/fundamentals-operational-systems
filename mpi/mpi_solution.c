/*
 * Fundamentos de Sistemas Operacionais
 * Alunos: Arthur Temporim (14/0016759) e Ícaro Pires (15/0129815)
 * Construindo aplicações distribuídas usando MPI 
 * Solução MPI
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <mpi.h>

#define V_SIZE 1000000000

int main(int argc, char** argv) {
	MPI_Init(&argc, &argv);

	int rank;
	int world_size;

	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &world_size);

	int step = V_SIZE/world_size;

	if(rank == 0){
		printf("world size: %d\n", world_size);
	} else if (rank > 0){
	
	}

	free(V);
	MPI_Finalize();
	return 0;
}
