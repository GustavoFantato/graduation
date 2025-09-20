#include <stdio.h>
#include <stdlib.h>

void quick(int *vetor, int c, int f){
    if (c >= f){
        return ; // se o ponteiro do comeco for maior que o do fim, retorna
    }
    
    int m = (c + f) / 2; // calcula o meio
    int p = vetor[m]; // atribui pro pivo o meio do vetor
    int i = c; // "ponteiro" auxiliar para o comeco
    int j = f; // "ponteiro" auxiliar para o fim

    while(1){
    while(vetor[i] < p){
        i++;
    } // percorre o vetor ate achar um elemento q seja menor q o pivo

    while(vetor[i] > p){
        j--; 
    } // percorre o vetor ate achar um elemento q seja maior q o pivo

    if (i >= j){
        break;
    } // quando i para pelo j, significa que eu terminei de particionar

    int temp = vetor[i];
    vetor[i] = vetor[j];
    vetor[j] = temp; // realiza a troca dos elementos

    i++;
    j--; // acrescenta e incrementa os indices 
    }

    quick(vetor, c, j); // ordenacao para o vetor da esquerda
    quick(vetor, j+1, f); // ordenacao para o vetor da direita


}

void leVetor(int *vetor, int n){
    for(int i = 0; i < n; i++){
        scanf("%d", &vetor[i]);
    }
}

void printaVetor(int *vetor, int n){
    for(int i = 0; i < n; i++){
        printf("%d ", vetor[i]);
    }

    printf("\n");
}
#include <stdio.h>
#include <stdlib.h>

void quick(int *vetor, int c, int f){
    if (c >= f){
        return ; // se o ponteiro do comeco for maior que o do fim, retorna
    }
    
    int m = (c + f) / 2; // calcula o meio
    int p = vetor[m]; // atribui pro pivo o meio do vetor
    int i = c; // "ponteiro" auxiliar para o comeco
    int j = f; // "ponteiro" auxiliar para o fim

    while(1){
    while(vetor[i] < p){
        i++;
    } // percorre o vetor ate achar um elemento q seja menor q o pivo

    while(vetor[i] > p){
        j--; 
    } // percorre o vetor ate achar um elemento q seja maior q o pivo

    if (i >= j){
        break;
    } // quando i para pelo j, significa que eu terminei de particionar

    int temp = vetor[i];
    vetor[i] = vetor[j];
    vetor[j] = temp; // realiza a troca dos elementos

    i++;
    j--; // acrescenta e incrementa os indices 
    }

    quick(vetor, c, j); // ordenacao para o vetor da esquerda
    quick(vetor, j+1, f); // ordenacao para o vetor da direita


}

void leVetor(int *vetor, int n){
    for(int i = 0; i < n; i++){
        scanf("%d", &vetor[i]);
    }
}

void printaVetor(int *vetor, int n){
    for(int i = 0; i < n; i++){
        printf("%d ", vetor[i]);
    }

    printf("\n");
}


int main(){
    
    int n;
    scanf("%d", &n); // leitura do tamanho do vetor

    int *vetor = malloc(n*sizeof(int));
    leVetor(vetor, n); // atribuicao dos elementos do vetor

    quick(vetor, 0, n-1); // chama funcao para ordenar 

    printaVetor(vetor, n);



    return 0;
}

int main(){
    
    int n;
    scanf("%d", &n); // leitura do tamanho do vetor

    int *vetor = malloc(n*sizeof(int));
    leVetor(vetor, n); // atribuicao dos elementos do vetor

    quick(vetor, 0, n-1); // chama funcao para ordenar 

    printaVetor(vetor, n);



    return 0;
}
