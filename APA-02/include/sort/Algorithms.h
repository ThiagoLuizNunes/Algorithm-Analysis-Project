#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <stdio.h>
#include <stdlib.h>

//MergeSort
void mergeSort(int* vetor, int posicaoInicio, int posicaoFim);

//QuickSort
int partition(int* ar, int ini, int fim);

void quickSort(int* ar, int ini, int fim);

//HeapSort
void createHeap(int *vet, int i, int f);

void heapSort(int *vet, int tam);

//SelectionSort
void selectionSort(int *vet, int tam);

//InsertionSort
void insertionSort(int *vet, int tam);

#endif
