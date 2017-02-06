#include <stdio.h>
#include <stdlib.h>
#include "Algorithms.h"

int main(void){

	printf("1 - Insertion Sort\n");
	printf("2 - Selection Sort\n");
	printf("3 - Merge Sort\n");
	printf("4 - Quick Sort\n");
	printf("5 - Heap Sort\n \n");

	int choice, tam;

	printf("Algorithim:");
	scanf("%d", &choice);

	printf("\nSize of vector:");
	scanf("%d", &tam);

	int ar[tam];
	int w, variable;
	int *ptr;

	for(w=0; w<tam; w++){
		scanf("%d", &variable);
		ar[w] = variable;
	}

	switch(choice){
		case 1:
			//printf("\nInsertion\n");
		    ptr = ar;
		    insertionSort(ptr, tam);
			break;

		case 2:
			//printf("\nSelection\n");
			ptr = ar;
			selectionSort(ptr, tam);
			break;

		case 3:
			//printf("\nMerge\n");
			ptr = ar;
			mergeSort(ptr, 0, tam-1);
			break;

		case 4:
			//printf("\nQuick\n");
			ptr = ar;
			quickSort(ptr, 0, tam-1);
			break;

		case 5:
			//printf("Heap\n");
			ptr = ar;
			heapSort(ptr, tam);
			break;
	}

	int y;
	printf("\n\n");
	for(y=0; y<tam; y++){
		printf("%d\n", ar[y]);
	}
	system("pause");

	return 0;
}
