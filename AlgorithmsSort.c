#include <stdio.h>
#include <stdlib.h> 

int main(void){
	
	printf("1 - Insertion Sort\n");
	printf("2 - Selection Sort\n");
	printf("3 - Merge Sort\n");
	printf("4 - Quick Sort\n");
	printf("5 - Heap Sort\n \n");
	
	int choice, size;
	
	printf("Algorithim:");
	scanf("%d", &choice);
	
	printf("\nSize of vector:");
	scanf("%d", &size);
	
	int vector[size];
	int i,x, variable;
	
	for(i=0; i<size; i++){
		scanf("%d", &variable);
		vector[i] = variable;
	}
	
	for(x=0; x<size; x++){
		printf("\n Position: %d \n", vector[x]);
	}
	
	switch(choice){
		case 1:
			//insertion();
			printf("\nInsertion\n");
			break;
		case 2:
			//selection();
			printf("Selection\n");
			break;
		case 3: 
			//merge();
			printf("Merge\n");
			break;
		case 4: 
			//quick();
			printf("Quick\n");
			break;
		case 5: 
			//heap();
			printf("Heap\n");
			break;
	}
	
	system("pause");
	
	return 0;
}
