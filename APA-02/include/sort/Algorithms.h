#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <stdio.h>
#include <stdlib.h>

void mergeSort(int* vetor, int posicaoInicio, int posicaoFim);

/*<<<<<<<<<<<<<<<<<<<<QUICK SORT>>>>>>>>>>>>>>>>>>>>*/

int partition(int* ar, int ini, int fim);

void quickSort(int* ar, int ini, int fim);

/*<<<<<<<<<<<<<<<<<<<<HEAP SORT>>>>>>>>>>>>>>>>>>>>*/

void createHeap(int *vet, int i, int f);

void heapSort(int *vet, int tam);

/*<<<<<<<<<<<<<<<<<<<<SELECTION SORT>>>>>>>>>>>>>>>>>>>>*/

void selectionSort(int *vet, int tam);
/*<<<<<<<<<<<<<<<<<<<<INSERTION SORT>>>>>>>>>>>>>>>>>>>>*/

void insertionSort(int *vet, int tam);

#endif
