#include <stdio.h>
#include <stdlib.h>

void leVetor(int *vetor, int n){
    for(int i = 0; i < n; i++){
        scanf("%d", &vetor[i]);
    }
} // Funcao que le cada elemento do vetor

void printaVetor(int *vetor, int n){
    for(int i = 0; i < n; i++){
        printf("%d ", vetor[i]);
    }

    printf("\n");
} // Funcao que printa cada elemento do vetor


void merge(int *vetor, int inicio, int meio, int fim){

    int n1 = meio - inicio + 1; // Tamanho do vetor de suporte a ser criado
    int aux1[n1]; // vetor de suporte 1 (a ser usado do lado esquerdo)

    int n2 = fim - meio; // Tamanho do vetor de suporte
    int aux2[n2]; // vetor de suporte 2 (lado direito)

    // Copiando os valores do lado esquerdo para o vetor aux1
    for (int i = 0; i < n1; i++){
        aux1[i] = vetor[inicio + i]; // O vetor pode nao comecar no 0, por isso soma-se inicio (onde de fato inicia) com o índice atual do loop
    }

    // Copiando os valores do lado direito para o vetor aux2
    for (int i = 0; i < n2; i++){
        aux2[i] = vetor[meio + 1 + i]; // O meio em si está contido na parte esquerda, por isso conta-se do meio + 1
    }


    // Ordenando os valores de volta no vetor original

    int i = 0; // indice do aux1 (esquerda)
    int j = 0; // indice do aux2 (direita)
    int u = inicio; //u = índice que percorre o vetor original do [inicio, fim]

    for (; i < n1 && j < n2; u++){ // 

        if(aux1[i] <= aux2[j]){ // Se o elemento do vetor aux1 for menor q o elemento do vetor 2, coloca-se o elemento do aux1 no vetor original[u]
            vetor[u] = aux1[i];
            i++; // soma-se +1 no indice do aux1
        } else {
            vetor[u] = aux2[j];
            j++; // soma-se +1 no indice do aux2
        }
    }

    // Caso tenha sobrado valores nao copiados do aux1, precisamos passar eles pro original, se nao, perde-se elementos

    while (i < n1){
        vetor[u] = aux1[i];
        i++;
        u++;
    }

    // Mesma coisa para o vetor aux2

    while (j < n2){
        vetor[u] = aux2[j];
        j++;
        u++;
    }

    printf("INTERCALACAO [%d,%d]: ", inicio, fim);
    for (int t = inicio; t <= fim; t++){
        printf("%d ", vetor[t]);
    }
    printf("\n");

}

void mergeSort(int *vetor, int inicio, int fim){

    if (inicio >= fim){return;} // Caso base atingido

    int meio = inicio + (fim - inicio) / 2;

    if (inicio < fim) printf("DIVISAO [%d,%d]\n", inicio, fim);

    // Lado esquerdo
    mergeSort(vetor, inicio, meio);

    // Lado direito
    mergeSort(vetor, meio + 1, fim);


    merge(vetor, inicio, meio, fim);
}




int main(){

    int n;
    scanf("%d", &n); // Le tamanho vetor
    int *vetor =  malloc(n*sizeof(int)); // Aloca espaco pro vetor de n * tamanho de int 

    leVetor(vetor, n);

    mergeSort(vetor, 0, n-1);
    
    // printaVetor(vetor, n);


    return 0;
}
