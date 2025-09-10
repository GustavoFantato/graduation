#include <stdio.h>
#include <stdlib.h>

void printVetor(int *vetor, int n){
    for(int i = 0; i < n; i++){
        printf("%d", vetor[i]);
    }
}


int main(){

    int n;
    scanf("%d", &n);
    int *vetor = malloc(n*sizeof(int));

    for (int i = 0; i < n; i++){
        scanf("%d", &vetor[i]);
    }

    int u = -1;
    int i = n - 1;
    int temp = 0;

    while (i > 0){
        for (int j = 0; j < i; j++){
            if(vetor[j] > vetor[j+1]){
                temp = vetor[j];
                vetor[j] = vetor [j+1];
                vetor[j+1] = temp;
                u = j+1;
            }
        }

        i = u;
    }

    printVetor(vetor, n);

    return 0;
}
