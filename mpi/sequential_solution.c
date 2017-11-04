#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define VECTOR_SIZE 1000000000

int main() {
	long double *vector;
	// Simple computer cant alloc this size of vector.
	vector = (long double*) malloc(sizeof(long double) * VECTOR_SIZE); 
	long double aux;
	for(long int i=0;i<VECTOR_SIZE;i++) {
		printf("%d ", i);
		aux = i-VECTOR_SIZE/2;
		vector[i] = pow(aux,2);
	}
	return 0;
}
