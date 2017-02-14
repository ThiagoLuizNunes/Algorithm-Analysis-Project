#include "Algorithms.h"

/*<<<<<<<<<<<<<<<<<<<<COUNTING SORT>>>>>>>>>>>>>>>>>>>>*/

int countingSize(int *vet, int tam){
    int i, high = 0;

    for(i=0; i<tam; i++){
        if(vet[i] > high){
            high = vet[i];
        }
    }
    return high;
}

void countingSort(int* vet, int tam){

    int size = countingSize(vet, tam);
    //printf("HIGH: %d\n", size);
    int aux[size+1];
    int aux2[tam];
    int i, x, y, z, w;

    for(i=0; i<size; i++){
      aux[i] = 0;
    }

    for(x=0; x<size; x++){
      aux[vet[x]]++;
    }

    for (y=1; y<size; y++) {
      aux[y] = aux[y-1] + aux[y];
    }

    for(z=0; z<tam; z++){
      aux2[aux[vet[z]]-1] = vet[z];
      aux[vet[z]-1];
    }

    for(w=0; w<tam; w++){
      vet[w] = aux2[w];
    }
    printf("OI\n");
}
