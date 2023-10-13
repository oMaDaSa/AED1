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
    Lista no = (No*) malloc(sizeof(No));
    no->valor = x;
    no->prox = (*l);
    (*l) = no;
    return 0;
}

int removerInicio(Lista *l) {
    if (l == NULL) return 2;
    if (listaVazia(l)) return 1; //(*l) == NULL
    Lista noLista = (*l);
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

int somaElementos(Lista *l){
    if(listaVazia(l) == 0) return 0;
    Lista no = *l;
    return no->valor + somaElementos(&(no->prox));
}
