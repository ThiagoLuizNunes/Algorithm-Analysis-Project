/*
SIZE = 50
100
9356
5028
9057
9511
4095
8951
467
2026
3426
5256
9989
3903
5023
7588
1416
3700
2492
6397
5252
7042
6074
2746
4321
8382
3621
2404
72
2346
9024
6723
9555
8731
6222
4892
9882
8729
2456
6828
4534
1218
7416
1616
1410
3728
6501
9729
1087
5598
3902
*/

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
	vet[i] = aux;
}

/*<<<<<<<<<<<<<<<<<<<<SELECTION SORT>>>>>>>>>>>>>>>>>>>>*/

void selectionSort(int *vet, int tam){
			 	
	int menor, aux;
	int i, j;
	
	for(i = 0; i < tam - 1; i++){
	menor = i;
		for (j = (i+1); j < tam; j++) {
			if(vet[j] < vet[menor]){
				menor = j;
			} 
		}
		if (i != menor) {
			aux = vet[i];
			vet[i] = vet[menor];
			vet[menor] = aux;
		}
	}
}

/*<<<<<<<<<<<<<<<<<<<<INSERTION SORT>>>>>>>>>>>>>>>>>>>>*/

void insertionSort(int *vet, int tam){
	
	int i, j;
	int aux;
	
	for(i = 1; i < tam; i++){
		aux = vet[i];
		for(j = i - 1; j >= 0 && vet[j] > aux; j--){
		    vet[j+1] = vet[j];
		}
		vet[j+1] = aux;
	}
}

void openInstances(int type, int size, char[] path, FILE open){
	
	if(type == 10){
		//Concatenar strings		
		char[] path = strcat(path, "10.100000.");
		int vet[size];
		
		
		
	}
	else if(type == 50){
		
	}
	else if(type == 90){
		
	}
}




