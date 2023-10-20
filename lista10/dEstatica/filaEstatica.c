#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct fila {
    int inicio,fim,qtd;
    Paciente valor[MAX];
}Fila;

Fila *criar() {
    Fila *f = (Fila*)malloc(sizeof(Fila));
    f->inicio = 0;
    f->fim = 0;
    f->qtd = 0;
    return f;
}

void limpar(Fila *f) {
    free(f);
    f = NULL;
}

int inserir(Fila *f, Paciente it) {
    if (f == NULL) return 2;
    if (filaCheia(f) == 0) return 1;
    f->valor[f->fim] = it;
    f->fim = (f->fim+1)%MAX;
    f->qtd++;
    return 0;
}

int remover(Fila *f, Paciente *it) {
    if (f == NULL) return 2;
    if (filaVazia(f) == 0) return 1;
    *it = f->valor[f->inicio];
    f->qtd--;
    f->inicio = (f->inicio+1)%MAX;
    return 0;
}

int consultar(Fila *f, Paciente *it) {
    if (f == NULL) return 2;
    if (filaVazia(f) == 0) return 1;
    *it = f->valor[f->inicio];
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

int filaCheia(Fila *f) {
    if (f == NULL) return 2;
    if (f->qtd == MAX) return 0;
    else return 1;
}

void mostrar(Fila *f) {
    if (f != NULL){
        printf("[\n");
        int i = f->inicio;
        int q = f->qtd;
        while (q > 0) {
            printf(" %d - %s",f->valor[i].senha, f->valor[i].nome);
            i = (i+1)%MAX;
            q--;
        }
        printf("]\n\n");
    }
}