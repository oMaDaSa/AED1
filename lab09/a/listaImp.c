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
    No *no = (No*) malloc(sizeof(No));
    no->valor = x;
    no->prox = (*l);
    (*l) = no;
    return 0;
}

int removerInicio(Lista *l) {
    if (l == NULL) return 2;
    if (listaVazia(l)) return 1; //(*l) == NULL
    No *noLista = (*l);
    (*l) = (*l)->prox;
    free(noLista);
    return 0;
}

void mostrar(Lista *l){
    if(l != NULL){
        Lista no = *l;
        while(no != NULL){
            printf("%d ", no->valor);
            no = no->prox;
        }   
    }
}

int ultimoElemento(Lista *l, int *x){
    if(listaVazia(l) == 0) return 1;
    if(l == NULL) return 2;
    No* no = *l;
    if(no->prox == NULL){
        *x = no->valor;
        return 0;
    }    
    else return ultimoElemento(&(no->prox), x);
}
