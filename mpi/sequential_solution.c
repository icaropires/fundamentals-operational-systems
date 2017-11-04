/*
 * Fundamentos de Sistemas Operacionais
 * Alunos: Arthur Temporim (14/0016759) e Ícaro Pires (15/0129815)
 * Construindo aplicações distribuídas usando MPI 
 * Versão sequencial
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

#define V_SIZE 1000000000

int main() {
	// Too big for static allocation.
	float *V = (float*) malloc(sizeof(float) * V_SIZE); 

	// Initialize V.
	for(int i = 0; i < V_SIZE; i++) {
		float aux = i - V_SIZE/2;
		V[i] = aux * aux;
	}

	float min = FLT_MAX;
	float max = FLT_MIN;

	// Calculate square root and get min/max.
	for(int i = 0; i<V_SIZE; i++) {
		V[i] = sqrt(V[i]);

		if(V[i] > max) {
			max = V[i];
		} else if(V[i] < min) {
			min = V[i];
		}
	}
	
	printf("Max: %f\n", max);
	printf("Min: %f\n", min);

	free(V);
	return 0;
}
