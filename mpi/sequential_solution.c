#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

//#define VECTOR_SIZE 1000000000
#define VECTOR_SIZE 100

int main() {
	double *vector;
	int i=0;
	double min = DBL_MAX;
	double max = DBL_MIN;

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
		if(vector[i] > max) {
			max = vector[i];
		}
		if(vector[i] < min) {
			min = vector[i];
		}
	}
	
	printf("Max: %lf\n", max);
	printf("Min: %lf\n", min);

	return 0;
}
