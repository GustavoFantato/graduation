#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

/*

push(e) --> insercao do elemento e no topo

pop() --> remove e retorna o elemento do topo da pilha

top() ou peek() --> retorna (sem remover) o elemento do topo da pilha

is_empty() --> verifica se a pilha esta vazia

is_full() --> (qnd a pilha é um tamanho fixo) verifica se a pilha está cheia

free_stack() --> libera a memoria alocada na pilha 

*/

typedef struct {

    int dados[MAX];
    int qtd;

} Stack;

Stack *create_stack(){
    Stack *s = malloc (sizeof(Stack));

    // se der errado, retorna NULL
    if (s == NULL){
        return NULL; // nao alocou
    }

    // se der certo, atribuimos em qtd
    s -> qtd = 0;

    // retornamos o ponteiro da alocacao

    return s;
}


    int is_empty(Stack *s){

        if (s == NULL) {
            return -1; // pilha nao inicializada
        }

        // pilha vazia. qtd == 0
        if (s-> qtd == 0){
            return 1; // verdadeiro
        } else {
            return 0; // falso. nao esta vazio
        }
    }

    int is_full(Stack *s){

        if (s == NULL) {
            return -1; // pilha nao inicializada
        }

        if (s-> qtd == MAX){
            return 1; // verdadeiro. pilha cheia
        } else {
            return 0; // falso. nao cheia 
        }
    }

    int push(Stack *s, int value){
        if (s == NULL) {
            return -1; // pilha nao inicializada
        }

        if (is_full(s) == 0){
            return -1; // pilha 
            
            // insere o valor desejado no topo da pilha
            s -> dados[s -> qtd] = value;
            // incrementa qtd (topo avanca)
            s -> qtd++;

            return 1; // inserido com sucesso  
        } else {
            // pilha inicializada, mas sem espaco
            return 0;
        }

    }


    int pop(Stack *s, int *value){
        if (s == NULL) {
            return -1; // pilha nao inicializada
        }

        if (is_empty(s) == 1){
            return 0; // pilha vazia. nao eh possivel retirar 
        } else {
            *value = s -> dados[s -> qtd - 1]; // salvo o valor a ser retirado do topo
            s -> qtd--; // decrementa qtd
            return 1; // retirado com sucesso
        }
    }

    int peek(Stack *s, int *value){
        if (s == NULL) {
            return -1; // pilha nao inicializada
        }

        if (is_empty(s) == 1){
            return 0; // pilha vazia 
        } else {
            *value = s -> dados[s -> qtd - 1]; // salvo o valor a ser retirado do topo
            return 1; // retirado com sucesso
        }
    }


    int free_stack(Stack *s){
        free(s); // memoria liberada
        s = NULL; // aponta pra NULL
    }

