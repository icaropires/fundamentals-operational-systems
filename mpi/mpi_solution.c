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

#define MIN_INDEX 0 
#define MAX_INDEX 1
#define TOTAL_SIZE 1000000000

// Update min and/or max if candidates are bigger/smaller
void set_min_max(float min_candidate, float *min, float max_candidate, float *max){
	if(max_candidate > *max) {
		*max = max_candidate;
	} else if(min_candidate < *min) {
		*min = min_candidate;
	}
}

int main(int argc, char** argv) {
	MPI_Init(&argc, &argv);

	int rank;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	int world_size;
	MPI_Comm_size(MPI_COMM_WORLD, &world_size);

	float min = FLT_MAX;
	float max = FLT_MIN;

	if(rank == 0){  // Manager
		float min_max[2];
		for(int i = 0; i < world_size - 1; ++i){  // Wait for all slices to be calculated
			MPI_Recv(&min_max, 2, MPI_FLOAT, MPI_ANY_SOURCE,
					 MPI_ANY_TAG, MPI_COMM_WORLD, MPI_STATUS_IGNORE);  // Receive mins and maxs

			set_min_max(min_max[MIN_INDEX], &min, min_max[MAX_INDEX], &max);
		}

		printf("Max: %f\n"
			   "Min: %f\n", max, min);
	} else if (rank > 0){  // Processes that will calculate slices of bigger array
		int V_size = TOTAL_SIZE/world_size;  // Size of each slice
		float *V = (float*) malloc(sizeof(float) * V_size); // Slice vector

		// Initialize array using formula
		for(int i = 0; i < V_size; ++i){
			float aux = (rank * i) - TOTAL_SIZE/2;
			V[i] = aux * aux;
		}

		float min_local = min;
		float max_local = max;
		
		// Find mins and maxs of square
		for(int i = 0; i < V_size; ++i){
			V[i] = sqrt(V[i]);
			set_min_max(V[i], &min_local, V[i], &max_local);
		}

		// Send this slice min and max to the manager
		float min_max[2] = {min_local, max_local};
		MPI_Send(&min_max, 2, MPI_FLOAT, 0, 0, MPI_COMM_WORLD);

		free(V);
	}

	MPI_Finalize();
	return 0;
}
