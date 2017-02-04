#include <stdio.h>
#include <stdlib.h> 

void sortInstances(char path[], int sort, int size, int type){
	
	int *vet = (int*) malloc(size*sizeof(int));
	
	if(vet!= NULL){
		
		int i;
		char *mySort;
		
		//itoa(sort, mySort, 10);
		//strcat(mySort, ".");
		
		if(size == 1000000){
			mySort = (char*) malloc(10*sizeof(char));
			char *arr = (char*) malloc(7*sizeof(char));
			
			if((mySort != NULL) && (arr!= NULL)){
				itoa(sort, mySort, 10);
				strcat(mySort, ".");
				
				itoa(size, arr, 10);
				strcat(arr, ".");
				
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
	
		char *myPath = (char*) malloc(strlen(path) + strlen(mySort));
		strcpy(myPath, path);
		strcat(myPath, mySort);
		
		free(mySort);
		
		printf("myPATH: %s \n", myPath);
		
		FILE *fp;
		
		char *number;
		char *tempPath;
		
		for(i=1; i<=10; i++){
			
			number = (char*) malloc(5*sizeof(char));
			tempPath = (char*) malloc(strlen(number) + strlen(myPath));
			
			char arr[strlen(myPath)];
			strcpy(arr, myPath);
			
			if(number != NULL){
				itoa(i, number, 10);
				strcat(number, ".in");
				strcpy(tempPath, arr);
				strcat(tempPath, number);
				printf("TEMPATH: %s \n", tempPath);
				
				//fp = fopen();
				
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
		
	sortInstances(PATH, sort1, size3, 1);
	system("pause");
	
	return 0;
}
