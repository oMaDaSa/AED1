#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

typedef struct pilha {
    int topo;
    int valores[MAX];
}Pilha;

Pilha *criar(){
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    p->topo = 0;
    return p;
}

void limpar(Pilha *p){
    free(p);
    p = NULL;
}

int push(Pilha *p, int it){
    if (p == NULL) return 2;
    if (pilhaCheia(p) == 0) return 1;
    p->valores[p->topo] = it;
    p->topo++;
    return 0;
}

int pop(Pilha *p, int *it){
    if (p == NULL) return 2;
    if (pilhaVazia(p) == 0) return 1;
    *it = p->valores[p->topo-1];
    p->topo--;
    return 0;
}

int pilhaConsultar(Pilha *p, int *it) {
    if (p == NULL) return 2;
    if (pilhaVazia(p) == 0) return 1;
    *it = p->valores[p->topo-1];
    return 0;
}

int tamanho(Pilha *p) {
    if (p == NULL) return -1;
    return p->topo;
}

int pilhaVazia(Pilha *p) {
    if (p == NULL) return 2;
    if (p->topo == 0) return 0;
    else return 1;
}

int pilhaCheia(Pilha *p) {
    if (p == NULL) return 2;
    if (p->topo == MAX) return 0;
    else return 1;
}

void mostrar(Pilha *p) {
    if (p != NULL) {
        printf("[");
        int i;
        for (i=0;i<p->topo;i++) {
            printf(" {%d} ",p->valores[i]);
        }
        printf("]\n");
    }
}