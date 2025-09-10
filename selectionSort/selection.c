#include <stdio.h>
#include <stdlib.h>


void leVetor(int *vetor, int n){
    for(int i = 0; i < n; i++){
        scanf("%d", &vetor[i]);
    } // Loop para ler cada elemento do vetor

    // printf("Lido com sucesso");
}

void printaVetor(int *vetor, int n){
    for(int i = 0; i < n; i++){
        printf("%d ", vetor[i]);
    } // Loop para printar cada elemento do vetor
}

void selectionSort(int *vetor, int n){
    int menor; // Variavel auxiliar pra guardar o índice do menor elemento durante as comparações
    int aux; // Auxiliar para realizar a troca dos elementos

    for (int i = 0; i < n-1; i++){
        menor = i;

        for (int j = i+1; j < n; j++){
            printf("C %d %d\n", menor, j);
            if(vetor[menor] > vetor[j]){
                menor = j;
            }
        }

        printf("T %d %d\n", i, menor);
        aux = vetor[menor];
        vetor[menor] = vetor[i];
        vetor[i] = aux; // Realiza a troca dos elementos
    }
}


int main(){

  int n;
  scanf("%d", &n); // Le quantidade de elementos do vetor

  int *v = malloc(n*sizeof(int)); // Declara vetor com memoria dinamica
  leVetor(v, n); // Chama funcao para ler vetor

  selectionSort(v, n); // Chama ordenacao selection
  printaVetor(v, n); // Printa vetor pos ordenacao

return 0; 
}
