#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

typedef struct no {
    int valor;
    struct no *prox;
}No;

typedef struct pilha {
    No *topo;
}Pilha;

Pilha *criar(){
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}

void limpar(Pilha *p){
    if(p == NULL) return;
    int temp;
    while (pilhaVazia(p) != 0) pop(p, &temp);
    free(p);
    p = NULL;
}

int push(Pilha *p, int it){
    if (p == NULL) return 2;
    No *no = (No *)malloc(sizeof(No));
    no->valor = it;
    no->prox = p->topo;
    p->topo = no;
    return 0;
}

int pop(Pilha *p, int *it){
    if (p == NULL) return 2;
    if (pilhaVazia(p) == 0) return 1;
    No *temp = p->topo;
    *it = temp->valor;
    p->topo = temp->prox;
    free(temp);
    return 0;
}

int consultar(Pilha *p, int *it) {
    if (p == NULL) return 2;
    if (pilhaVazia(p) == 0) return 1;
    No *temp = p->topo;
    *it = temp->valor;
    return 0;
}

int tamanho(Pilha *p) {
    if (p == NULL) return -1;
    int ct = 0;
    No *no = p->topo;
    while (no != NULL) {
        ct++;
        no = no->prox;
    }
    return ct;
}

int pilhaVazia(Pilha *p) {
    if (p == NULL) return 2;
    if (p->topo == NULL) return 0;
    else return 1;
}

void mostrar(Pilha *p) {
    if (p != NULL) {
        printf("[");
        No *no = p->topo;
        while (no != NULL) {
            printf(" {%d} ",no->valor);
            no = no->prox;
    }
        printf("]\n");
    }   
}