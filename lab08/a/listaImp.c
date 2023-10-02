#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

typedef struct no{
    struct no *prox;
    struct no *ant;
    Aluno valor;
}No;

typedef struct lista{
    No *inicio;
}Lista;

Lista *criar(){
    Lista *l = (Lista*)malloc(sizeof(Lista));
    l->inicio = NULL;
    return l;
}

void limpar(Lista *l) {
    while (listaVazia(l) != 0)
        removerInicio(l);
}

int tamanho(Lista *l) {
    if (l == NULL) return -1;
        No *no = l->inicio;
    int cont = 0;
    while (no != NULL) {
        cont++;
        no = no->prox;
    }
    return cont;
}

int listaVazia(Lista *l){
    if(l == NULL) return 2;
    if(l->inicio == NULL) return 0;
    else return 1;
}

int inserirInicio(Lista *l, Aluno it){
    if(l == NULL)return 2;
    No *n = (No*)malloc(sizeof(No));
    n->valor = it;
    n->prox = l->inicio;
    n->ant = NULL;
    if(l->inicio!=NULL)
        l->inicio->ant = n;
    l->inicio = n;
    return 0;
}

int inserirFim(Lista *l, Aluno it) {
    if (l == NULL) return 2;
    if (listaVazia(l) == 0)
        return inserirInicio(l,it);
    No *noLista = l->inicio;
    while (noLista->prox != NULL)
        noLista = noLista->prox;
    No *no = (No*)malloc(sizeof(No));
    no->valor = it;
    no->prox = NULL;
    no->ant = noLista;
    noLista->prox = no;
    return 0;
}

int inserirOrdenado(Lista *l, Aluno it){
    if(l == NULL) return 2;
    
    if(listaVazia(l) == 0 || l->inicio->valor.mat > it.mat) return inserirInicio(l, it);
    No *nl = l->inicio;
    while(nl->prox != NULL){
        if(nl->prox->valor.mat < it.mat)
            nl = nl->prox;
        else{
            break;
        }
    }
    if(nl->prox == NULL) return inserirFim(l,it);

    No *n = (No*)malloc(sizeof(No));
    n->valor = it;
    n->ant = nl;
    n->prox = nl->prox;
    nl->prox = n;
    if(nl->prox != NULL) n->prox->ant = n;
    return 0;
}

int inserirPos(Lista *l, Aluno it, int pos){
    if(l == NULL) return 1;
    if(listaVazia(l) == 0 || pos == 0) return inserirInicio(l, it);
    No *nl = l->inicio;
    while(nl->prox != NULL && pos > 1){
        nl=nl->prox;
        pos--;
    }

    No *n = (No*)malloc(sizeof(No));
    n->valor = it;
    n->ant = nl;
    n->prox = nl->prox;
    nl->prox = n;
    if(nl->prox != NULL) n->prox->ant = n;
    return 0;
}

void mostrar(Lista *l){
    if(l!=NULL){
        if(listaVazia(l) != 0){
            No *n = l->inicio;
            printf("[\n");
            do{
                printf("{%d, %s, %.2f}\n",n->valor.mat, n->valor.nome, n->valor.n1);
                n = n->prox;
            }while(n != NULL);
            printf("]\n");
        }else
        printf("Lista vazia\n");
    }
}

int removerInicio(Lista *l){
    if (l == NULL) return 2;
    if (listaVazia(l) == 0)
    return 1;
    No *noLista = l->inicio;
    l->inicio = noLista->prox;
    if (l->inicio != NULL)
        l->inicio->ant = NULL;
    free(noLista);
    return 0;
}

int removerFim(Lista *l) {
    if (l == NULL) return 2;
    if (listaVazia(l) == 0)
        return 1;
    No *noLista = l->inicio;
    while (noLista->prox != NULL)
        noLista = noLista->prox;
    if (noLista->ant == NULL)
        l->inicio = NULL;
    else
        noLista->ant->prox = NULL;
        free(noLista);
    return 0;
}

int removerPosicao(Lista *l, int pos) {
    if (l == NULL) return 1;
    if (listaVazia(l) == 0) return 2;
    No *n = l->inicio;
    while ((n->prox != NULL)&&(pos > 0)) {
        n = n->prox;
        pos--;
    }
    if (n->ant == NULL) return removerInicio(l);
    if (n->prox == NULL) return removerFim(l);
    n->ant->prox = n->prox;
    n->prox->ant = n->ant;
    free(n);
    return 0;
}

int removerChave(Lista *l, int chave){
    if (l == NULL) return 1;
    if (listaVazia(l) == 0) return 2;
    No *n = l->inicio;
    if(n->valor.mat == chave) return removerPosicao(l, 0);
    int pos = 1;
    while(n->prox != NULL){
        if(n->prox->valor.mat == chave) return removerPosicao(l, pos+1);
        pos++;
        n = n->prox;
    }
    return 3;
}

int maiorNota(Lista *l, Aluno *maiorNota){
    if (l == NULL) return 1;
    if (listaVazia(l) == 0) return 2;
    No *n = l->inicio;
    int nota = n->valor.n1;
    *maiorNota = n->valor;
    while(n->prox != NULL){
        if(n->prox->valor.n1 > nota){
            nota = n->prox->valor.n1;
            *maiorNota = n->prox->valor;
        }
        n = n->prox;
    }
    
    return 0;
}

