#include <stdio.h>
#include <stdlib.h>

void leVetor(int *vetor, int n){
    for(int i = 0; i < n; i++){
        scanf("%d", &vetor[i]);
    } // le elementos dos vetores
}

void printaVetor(int *vetor, int n){
    for(int i = 0; i < n; i++){
        printf("%d ", vetor[i]);
    } // printa elementos do vetor
    printf("\n");
}

void insertionSort(int *vetor, int n){

    for(int i = 1; i < n; i++){
            int x = vetor[i]; // vetor auxiliar para salvar o elemento a ser ordenado
            int j = i-1; // indice auxiliar
            while(vetor[j] > x && j>= 0){
                vetor[j + 1] = vetor[j]; // troca os elementos anteriores até encontrar o local certo a se colocar x
                j--; // decrementa até encontrar o local correto e j>= 0
            }
            vetor[j + 1] = x; // coloca o x no local certo
    }

}



int main(){
    int n; // Tamanho vetor
    scanf("%d", &n); // le tamanho vetor

    int *vetor = malloc(n * sizeof(int)); // aloca espaço pro vetor
    
    leVetor(vetor, n); // chama funcao para ler elementos do vetor

    insertionSort(vetor, n); // chama funcao para ordenar pelo metodo insertion

    printaVetor(vetor, n); // funcao para printar vetor

    return 0;
}
