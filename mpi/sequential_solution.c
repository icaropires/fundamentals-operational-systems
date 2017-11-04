#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define VECTOR_SIZE 1000000000

int main() {
	double *vector;
	int i=0;

	// Simple computer cant alloc this size of vector.
	vector = (double*) malloc(sizeof(double) * VECTOR_SIZE); 
	double aux;

	// Initialize vector.
	for(i=0;i<VECTOR_SIZE;i++) {
		aux = i-VECTOR_SIZE/2;
		vector[i] = pow(aux,2);
	}

	for(i=0;i<VECTOR_SIZE;i++) {
		vector[i] = sqrt(vector[i]);
	}

	for(i=0;i<VECTOR_SIZE;i++) {
		printf("I: %d, result: %d\n", i, vector[i]);
	}
	
	return 0;
}
