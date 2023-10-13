#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

typedef No* Lista;

Lista* criar(){
    Lista *l = (Lista*)malloc(sizeof(Lista));
    *l=NULL;
    return l;
}

int listaVazia(Lista *l){
    if(l == NULL) return 2;
    if(*l == NULL) return 0;
    return 1;
}

int inserirInicio(Lista *l, int x) {
    if (l == NULL) return 2;
    Lista no = (No*)malloc(sizeof(No));
    no->binario = x;
    no->prox = (*l);
    (*l) = no;
    return 0;
}

int inserirFim(Lista *l, int x){
    if (l == NULL) return 2;
    if(listaVazia(l) == 0) return inserirInicio(l, x);
    Lista no = (No*)malloc(sizeof(No));
    no->binario = x;
    no->prox = NULL;
    Lista noLista = (*l);
    while(noLista->prox != NULL) noLista = noLista->prox;
    noLista->prox = no;
    return 0;
}

int removerInicio(Lista *l) {
    if (l == NULL) return 2;
    if (listaVazia(l) == 0) return 1; //(*l) == NULL
    Lista noLista = (*l);
    (*l) = (*l)->prox;
    free(noLista);
    return 0;
}

void mostrar(Lista *l){
    if(l != NULL){
        Lista no = *l;
        while(no != NULL){
            printf("%d ", no->binario);
            no = no->prox;
        }   
    }
}

void mostrarReverso(Lista *l){
    if(l != NULL){
        if(listaVazia(l) != 0){
            Lista no = *l;
            mostrarReverso(&no->prox);
            printf("%d ", no->binario);
        }
    }
}

int incrementar(Lista *l){
    Lista no = *l;
    no->binario++;
    if(no->binario == 2){
        no->binario = 0;
        if(no->prox == NULL) return inserirFim(l, 1);
        else return incrementar(&(no->prox));
    }
    return 0;
}