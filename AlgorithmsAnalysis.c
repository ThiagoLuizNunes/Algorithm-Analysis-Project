#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <time.h>
#include "Algorithms.h"

void print_vector(int v[], int size){
	int i;
	for(i = 0; i < size; i++){
		printf("%d \n", v[i]);
	}
}
void sortInstances(char path[], int sort, int size, int type){
	
	//Initializing Vector with size coming parameter
	//int *vet = (int*) malloc(size*sizeof(int));
	int *vet = malloc(size*sizeof(int));
	
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
				int x = 0;
				//Opening data from FILE 
				FILE *file;
				file = fopen(tempPath, "r");
				
				if(file != NULL){
					while((fscanf(file, "%d", &j)) != EOF){
						if(x==0){
							x++;
							//Faz nada
						}else{
							vet[position] = j;
							position++;
						}
					}
				}
				else{
					printf("Error to open FILE!");
				}
				
				switch(type){
					
					case 1:
						printf("BEGIN SELECTION");
					    insertionSort(vet, size);
					    printf("END SELECTION");
					    print_vector(vet, size);
						break;
						
					case 2:
						selectionSort(vet, size);
						print_vector(vet, size);
						break;
					case 3:
						mergeSort(vet, 0, size-1);
						print_vector(vet, size);
						break;
					case 4: 
						quickSort(vet, 0, size-1);
						print_vector(vet, size);
						break;
						
					case 5: 
						heapSort(vet, size);
						print_vector(vet, size);
						break;	
				}
				printf("OI THIAGO\n");
				//Close FILE
				fclose(file);
				//Memory deallocation 
				free(number);
				
			}
		}
		free(tempPath);
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
	
	sortInstances(PATH, sort3, size3, 1);
	system("pause");
	
	return 0;
}
