#include <stdio.h>




void heapify(int v[], int pai, int ultimo){
    int filho = 2*pai + 1; // acha o indice do primeiro filho

     if (filho <= ultimo){ // se o indice do filho for maior q o ultimo, significa q ele nem existe, entao, nem tem oq fazer
        
        if(filho + 1 <= ultimo){ // verifica a existencia do segundo filho

            if (v[filho + 1] > v[filho]){ // verifica qual dos filhos é maior
                filho++; // troca o indice do filho maior para o segundo filho
            }

            if (v[pai] < v[filho]){ // o filho nao pode ser maior q o pai
                int temp = v[pai];
                v[pai] = v[filho];
                v[filho] = temp; // troca pai e filho

                heapify(v, filho,  ultimo); // tem chance de ao fazer essa troca, tirar o heap de outros elementos
            }

        }        

     }

}


void heap(int v[], int n){
    for (int  i = n/2; i >= 0; i--){
        heapify(v, i, n-1);  // faz a primeira heap, pra tornar um heap pela primeira vez
    }

    for (int i = n - 1; i > 0; i--){ 
        int temp = v[i];
        v[i] = v[0];
        v[0] = temp; // faz a troca do primeiro elemento com o ultimo ainda nao ordenado

        heapify(v, 0, i-1); // faz todo esse processo com os demais elementos
    }

}

void printaVetor(int v[], int n){
    for (int i = 0; i < n; i++){
        printf("%d ", v[i]);
    }

    printf("\n");
}

int main(){

    int n;
    scanf("%d", &n);

    int v[n];

    for (int i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }


    heap(v, n);

    printaVetor(v, n);


    return 0;
}
