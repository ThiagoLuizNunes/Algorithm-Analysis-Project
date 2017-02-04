#include <stdio.h>
#include <stdlib.h> 
#include "Algorithms.h"

void printArray(int *array, int size){
	int y;
	printf("\n\n");
	for(y=0; y<size; y++){
		printf("%d\n", array[y]);
	}
}
void sortInstances(char path[], int sort, int size, int type){
	
	//Initializing Vector with size coming parameter
	int *vet = (int*) malloc(size*sizeof(int));
	
	if(vet!= NULL){
		
		int i;
		char *mySort;
		//Comparing size of vector
		if(size == 1000000){
			mySort = (char*) malloc(10*sizeof(char));
			char *arr = (char*) malloc(7*sizeof(char));
			
			if((mySort != NULL) && (arr!= NULL)){
				//Transforming Interger at String and Concatening
				itoa(sort, mySort, 10);
				strcat(mySort, ".");
				//Transforming Interger at String and Concatening
				itoa(size, arr, 10);
				strcat(arr, ".");
				
				//Concatening Strings to form PATH
				strcat(mySort, arr);
				
				free(arr);
			}
		}
		else{
			mySort = (char*) malloc(9*sizeof(char));
			char *arr = (char*) malloc(6*sizeof(char));
			
			if((mySort != NULL) && (arr!= NULL)){
				itoa(sort, mySort, 10);
				strcat(mySort, ".");
				
				itoa(size, arr, 10);
				strcat(arr, ".");
				
				strcat(mySort, arr);
				
				free(arr);
			}
		}
		
		//Dynamic Initialization of arrays
		char *myPath = (char*) malloc(strlen(path) + strlen(mySort));
		//Coping PATH(parameter) to a new variable myPath
		strcpy(myPath, path);
		//Concatening Strings to form myPATH
		strcat(myPath, mySort);
		//Memory deallocation 
		free(mySort);
		
		char *number;
		char *tempPath;
		
		for(i=1; i<=1; i++){
			
			if(size == 1000000){
				number = (char*) malloc(5*sizeof(char));
			}
			else{
				number = (char*) malloc(4*sizeof(char));
			}
			
			//Provisional PATH
			char tempPath[strlen(myPath)];
			strcpy(tempPath, myPath);
			
			if(number != NULL){
				//Transforming Interger at String
				itoa(i, number, 10);
				//Concatening Strings to form tempPATH(PROVISIONAL)
				strcat(number, ".in");
				strcat(tempPath, number);
				
				int position = 0;
				int  j = 0;
				//Opening data from FILE 
				FILE *file;
				file = fopen(tempPath, "r");
				
				if(file != NULL){
					/*do{
						fscanf(file, "%d", &j);
						printf("NUMBER: %d\n", j);
						//vet[position] = j;
						//position++;
						
					}while(!feof(file));*/
					while((fscanf(file, "%d", &j)) != EOF){
						printf("NUMBER: %d\n", j);
					}
				}
				else{
					printf("Error to open FILE!");
				}
				
				int *ptr;
				switch(type){
					case 1:
						//ptr = &vet;
						//mergeSort(ptr, 0, size-1);
						//printArray(ptr, size);
						break;
				}
				//Close FILE
				fclose(file);
				//Memory deallocation 
				free(number);
				free(tempPath);
			}
		}
	}
}


int main(void){
	
	char PATH[] = "instancias/";
	
	int size1 = 100000;
	int size2 = 500000;
	int size3 = 1000000;
	
	int sort1 = 10;
	int sort2 = 50;
	int sort3 = 90;
	
	printf("passei\n\n");
	sortInstances(PATH, sort1, size2, 1);
	system("pause");
	
	return 0;
}
