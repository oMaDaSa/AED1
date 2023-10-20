#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    struct no *prox;
    int valor;
} No;

typedef struct fila {
    struct no *inicio, *fim;
    int qtd;
}Fila;

Fila *criar() {
    Fila *f = (Fila*)malloc(sizeof(Fila));
    f->inicio = NULL;
    f->fim = NULL;
    f->qtd = 0;
    return f;
}

void limpar(Fila *f) {
    free(f);
    f = NULL;
}

int inserir(Fila *f, int it) {
    if (f == NULL) return 1;
    No *no = (No*)malloc(sizeof(No));
    no->valor = it;
    no->prox = NULL;
    if(filaVazia(f) == 0){
        f->inicio = no;
    }
    if(f->fim != NULL) f->fim->prox = no;
    f->fim = no;
    f->qtd++;
    return 0;
}

int remover(Fila *f, int *it) {
    if (f == NULL) return 2;
    if (filaVazia(f) == 0) return 1;
    
    *it = f->inicio->valor;
    f->qtd--;
    
    No *aux = f->inicio;
    f->inicio = aux->prox;
    free(aux);
    return 0;
}

int consultar(Fila *f, int *it) {
    if (f == NULL) return 2;
    if (filaVazia(f) == 0) return 1;
    *it = f->inicio->valor;
    return 0;
}

int tamanho(Fila *f) {
    if (f == NULL) return -1;
    return f->qtd;
}

int filaVazia(Fila *f) {
    if (f == NULL) return 2;
    if (f->qtd == 0) return 0;
    else return 1;
}

void mostrar(Fila *f) {
    if (f != NULL){
        printf("[");
        No *aux = f->inicio;
        while (aux != NULL) {
            printf("%d",aux->valor);
            if(aux->prox != NULL) printf(", ");
            aux = aux->prox;
        }
        printf("]\n\n");
    }
}