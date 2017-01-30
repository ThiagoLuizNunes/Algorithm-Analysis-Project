#include <stdio.h>
#include <stdlib.h> 


/*<<<<<<<<<<<<<<<<<<<<MERGE SORT>>>>>>>>>>>>>>>>>>>>*/
void mergeSort(int* vetor, int posicaoInicio, int posicaoFim){
	int i, j, k, metadeTam, *vetorTemp;
	
	if(posicaoInicio == posicaoFim){
		return;
	}

	metadeTam = (posicaoInicio + posicaoFim)/2;
	
	mergeSort(vetor, posicaoInicio, metadeTam);
	mergeSort(vetor, metadeTam +1, posicaoFim);
	
	i = posicaoInicio;
	j = metadeTam +1;
	k = 0;
	vetorTemp = (int *) malloc(sizeof(int) * (posicaoFim - posicaoInicio + 1));


	while(i < metadeTam + 1 || j  < posicaoFim + 1) {
        if (i == metadeTam + 1 ) { 
            vetorTemp[k] = vetor[j];
            j++;
            k++;
        } 
        else {
            if (j == posicaoFim + 1) { 
                vetorTemp[k] = vetor[i];
                i++;
                k++;
            } 
            else {
                if (vetor[i] < vetor[j]) { 
                    vetorTemp[k] = vetor[i];
                    i++;
                    k++;
                } 
                else { 
                    vetorTemp[k] = vetor[j];
                    j++;
                    k++;
                }
            }
        }
	}
	for(i = posicaoInicio; i <= posicaoFim; i++) {
    	vetor[i] = vetorTemp[i - posicaoInicio];
	}
	free(vetorTemp);
}

/*<<<<<<<<<<<<<<<<<<<<QUICK SORT>>>>>>>>>>>>>>>>>>>>*/

int partition(int* ar, int ini, int fim){
    int pivo = 0;
    int topo = 0;
    int i = 0;
 
    pivo = ar[ini];
    topo = ini;
 
    for(i = ini + 1; i <= fim; i++){
        if(pivo > ar[i]){
            ar[topo] = ar[i];
            ar[i] = ar[topo + 1];
            topo++;
        }
    }
    ar[topo] = pivo;
    return topo;
}

void quickSort(int* ar, int ini, int fim){
    int mid = 0;
 
    if(ini < fim){
        mid = partition(ar, ini, fim);
        quickSort(ar, ini, mid);
        quickSort(ar, mid+1, fim);
    }
}

/*<<<<<<<<<<<<<<<<<<<<HEAP SORT>>>>>>>>>>>>>>>>>>>>*/

void heapSort(int *vet, int tam){
	int i, aux;

	for(i=(tam - 1)/2; i>=0; i--){
		createHeap(vet, i, tam-1);
	}
	for(i = tam-1; i>=1; i--){
		aux = vet[0];
		vet[0] = vet[i];
		vet[i] = aux;
		createHeap(vet, 0, i-1);
	}
}
void createHeap(int *vet, int i, int f){
	int aux = vet[i];
	int j = i * 2 + 1;

	while(j<=f){
		if(j<f){
			if(vet[j] < vet[j+1]){
				j = j + 1;
			}
		}
		if(aux < vet[j]){
			vet[i] = vet[j];
			i = j;
			j = 2*i+1;
		}
		else{
			j = f+1;
		}
	}
	printf("Passei aqui");
	vet[i] = aux;
}

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
	int j = 0;
    int i = 0;
	int aux = 0;
	int menor;
	int *ptr;
	
	for(w=0; w<tam; w++){
		scanf("%d", &variable);
		ar[w] = variable;
	}
	
	switch(choice){
		case 1:
			
			printf("\nInsertion\n");
			for(i = 1; i < tam; i++){
		        aux = ar[i];
		        for(j = i - 1; j >= 0 && ar[j] > aux; j--){
		            ar[j+1] = ar[j];
		        }
		        ar[j+1] = aux;
		    }
			break;
			
		case 2:
			 
			printf("\nSelection\n");
			for(i = 0; i < tam - 1; i++){
			    menor = i;
				for (j = (i+1); j < tam; j++) {
					if(ar[j] < ar[menor]){
						menor = j;
					} 
				}
				if (i != menor) {
					aux = ar[i];
					ar[i] = ar[menor];
					ar[menor] = aux;
				}
			}
			break;
			
		case 3: 
			
			printf("\nMerge\n");
			ptr = &ar;
			mergeSort(ptr, 0, tam-1);
			break;
			
		case 4: 
			
			printf("\nQuick\n");
			ptr = &ar;
			quickSort(ptr, 0, tam-1);
			break;
			
		case 5: 
			
			printf("Heap\n");
			ptr = &ar;
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
