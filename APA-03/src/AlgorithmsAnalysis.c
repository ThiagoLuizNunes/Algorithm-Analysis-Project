#include <stdio.h>
#include <stdlib.h>
#include "Algorithms.h"

int main(void){

  printf("1 - Counting Sort\n");
	printf("2 - Bucket Sort\n");
	printf("3 - Radix Sort\n");

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
	    ptr = ar;
	    countingSort(ptr, tam);
			break;

		case 2:
			ptr = ar;
			//bucketSort();
			break;

		case 3:
			ptr = ar;
			//radixSort();
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
