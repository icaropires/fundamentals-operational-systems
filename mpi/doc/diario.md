# Diário de Bordo MPI

## Dados

* Disciplina: Fundamentos de Sistemas Operacionais
* Professor: Fernando W Cruz
* Alunos:

	* Nome: Arthur Temporim
	* Matrícula: 14/0016759

	* Nome: Ícaro Pires
	* Matrícula: 15/0129815

## Introdução

Este trabalho consiste na criação de um software capaz de manipular um vetor de 1.000.000.000 de posições de valores de tipo float. Esta solução deve ser implementada utilizando o framework MPI.
	
## Descrição da Solução

### Solução Sequencial

A construção da solução sequencial foi simples na primeira versão, pois o problema sugerido é simples com execeção de um fator, o tamanho do vetor.

Para que fosse possível a solução do projeto, foi necessário alocar o vetor dinamicamente, pois ele utiliza 4GB, sendo (1 bilhão de elementos * 4 bytes) que é o tamanho do tipo float.

Só foi possível rodar o projeto em computadores ou VMs com memória acima de 4Gb, todos os testes com configurações inferiores a esta não tiveram sucesso.

Os dados coletados das execuções podem ser verificados nos [Arquivo](https://github.com/icaropires/Fundamentos_Sistemas_Operacionais/blob/devel/mpi/doc/anexo_sequencial.md).

### Solução com MPI

A lógica para a solução utilizando MPI não se difere muito da lógica sequencial, tendo em vista que o problema é o mesmo.

Após importar a biblioteca de MPI foi criado a função de comparação de menor e maior, a configuração do `rank` e grupos também foi feita.

Dentro do escopo do MPI (`MPI_Init()`, `MPI_Finalize()`) foi dividido 2 comportamentos principais, sendo eles:

* Manager:

	1. Divide todos os pedaços do vetor de acordo com a quantidade de processos.
	2. Recebe os `mins` e `maxs` valores.
	3. Imprime o resultado.

* Workers:

	1. Inicializa o vetor com a formula dada.
	2. Encontra os `mins` e `maxs` do quadrado que o worker está responsável.
	3. Envia os resultados do quadrado para o manager.


Com essa implementação a solução usou cerca de 2.7GB de RAM e teve desempenho 2x mais rápido que a solução sequencial.

Os dados coletados das execuções podem ser verificados nos [Arquivo](https://github.com/icaropires/Fundamentos_Sistemas_Operacionais/blob/devel/mpi/doc/anexo_mpi.md)
Todos os testes nos anexos foram feitos com **5** processos.

### Solução com MPI distribuída

Para aplicar a solução de MPI em vários computadores, foi configurado máquinas virtuais.

A instalação e execução do projeto de forma distribuída foi feita utilizando o seguinte tutorial:

[Running an MPI Cluster within a LAN](http://mpitutorial.com/tutorials/running-an-mpi-cluster-within-a-lan/)

Após a instação e configuração feitas nas máquinas virtuais foram executados testes:

1. Executando o binário do cliente a partir do master
2. Executando o binário do master a partir do master
3. Executando o binário nas 2 máquinas.

O resultado foi positivo para os 2 primeiros casos, porém mesmo após esperar 5 minutos de execução o resultado não foi alcançado.

Os dados coletados das execuções podem ser verificados nos [Arquivo](https://github.com/icaropires/Fundamentos_Sistemas_Operacionais/blob/devel/mpi/doc/anexo_distribuido.md).

## Códigos

* [Sequencial](https://github.com/icaropires/Fundamentos_Sistemas_Operacionais/blob/devel/mpi/sequential_solution.c)

```
/*
 * Fundamentos de Sistemas Operacionais
 * Alunos: Arthur Temporim (14/0016759) e Ícaro Pires (15/0129815)
 * Construindo aplicações distribuídas usando MPI 
 * Solução sequencial
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
```

* [MPI](https://github.com/icaropires/Fundamentos_Sistemas_Operacionais/blob/devel/mpi/mpi_solution.c)


```
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
```

## Conclusão

Com a implementação de MPI várias barreiras podem ser quebradas, como a solução de problemas que são insolucionáveis com os recursos de apenas uma máquina, mas quando mais uma máquina é adicionada a solução pode se tornar alcançável.

Outro ponto obeservável com MPI, é a melhoria no desempenho das soluções. Quando é possível paralelizar uma atividade e dividir entre mais `workers`.

# Instruções para execução

## Sequencial

* Compilar

`gcc -o prog sequential_solution.c -lm -std=c99`

* Executar

`./prog`

## MPI em apenas uma máquina

* Compilar

`mpicc -o mpi mpi_solution.c -lm -std=c99`

* Executar

`mpirun -np [numero de processos] mpi`

## MPI Distribuído

* Compilar

`mpicc -o mpi mpi_solution.c -lm -std=c99`

* Executar

`mpirun -np [numero de processos] --host [host1,hostn] ./mpi`
