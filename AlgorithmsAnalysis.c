#include <stdio.h>
#include <stdlib.h> 

void sortInstances(char path[], int sort, int size, int type){
	
	int vet[size];
	int i;
	char mySort[3];
	
	itoa(sort, mySort, 10);
	strcat(mySort, ".");
	
	if(size == 1000000){
		char arr[7];
		itoa(size, arr, 10);
		strcat(arr, ".");
		strcat(mySort, arr);
	}
	else{
		char arr[6];
		itoa(size, arr, 10);
		strcat(arr, ".");
		strcat(mySort, arr);
	}

	char myPath[20];
	strcat(myPath, path);
	strcat(myPath, mySort);
	printf("myPATH: %s \n", myPath);
	
	
	FILE *fp;
	
	for(i=0; i<=10; i++){
		//myPath = strcat(myPath, entropia);
		//fp = fopen();
	}
	
}


int main(void){
	
	const char PATH[] = "instancias/";
	
	int size1 = 100000;
	int size2 = 500000;
	int size3 = 1000000;
	
	int sort1 = 10;
	int sort2 = 50;
	int sort3 = 90;
		
		printf("passei");
	sortInstances(PATH, sort3, size3, 1);
	system("pause");
	
	return 0;
}
