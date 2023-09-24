#include <stdio.h>
#include "Lista.h"
#include "stdlib.h"

typedef struct no {
    Aluno valor;
    struct no *prox;
}No;
typedef struct lista {
    No *inicio;
}ListaCircular;
Lista *criar() {
    Lista *l =(Lista*)malloc(sizeof(Lista));
    l->inicio = NULL;
    return l;
}
void limpar(Lista *l) {
    while (listaVazia(l) != 0)
        removerInicio(l);
    free(l);
    l = NULL;
}
int tamanho(Lista *l) {
    if (l == NULL) return -1;
    if (listaVazia(l) == 0) return 0;
    No *noLista = l->inicio;
    int cont = 0;
    do {
        cont++;
        noLista = noLista->prox;
    } while (noLista != l->inicio);
    return cont;
}
void mostrar(Lista *l) {
    if (l != NULL) {
        printf("[\n");
        if (listaVazia(l) != 0) {
            No *noLista = l->inicio;
            No *noInicio = noLista;
            do {
                printf("  {%d, %s, %.2f}\n",noLista->valor.mat,noLista->valor.nome,noLista->valor.n1);
                noLista = noLista->prox;
            } while (noLista != noInicio);
        }
        printf("]\n");
    }
}
int listaVazia(Lista *l) {
    if (l == NULL) return 2;
    if (l->inicio == NULL)
        return 0;
    else
        return 1;
}
int listaCheia(Lista *l) {
    return 1;
}
int inserirInicio(Lista *l, Aluno it) {
    if (l == NULL) return 2;
    No *no = (No *)malloc(sizeof(No));
    no->valor = it;
    if (listaVazia(l) == 0) {
        l->inicio = no;
        no->prox = no;
    }else {
        No *temp = l->inicio;
        while (temp->prox != l->inicio)
            temp = temp->prox;
        temp->prox = no;
        no->prox = l->inicio;
        l->inicio = no;
    }
    return 0;
}
int inserirFim(Lista *l, Aluno it) {
    if (l == NULL) return 2;
    No *no = (No *)malloc(sizeof(No));
    no->valor = it;
    if (listaVazia(l) == 0) {
        l->inicio = no;
        no->prox = no;
    }else {
        No *temp = l->inicio;
        while (temp->prox != l->inicio)
            temp = temp->prox;
        temp->prox = no;
        no->prox = l->inicio;
    }
    return 0;
}
int removerInicio(Lista *l) {
    if (l == NULL) return 2;
    if (listaVazia(l) == 0) return 1;
    if (l->inicio->prox == l->inicio) {
        free(l->inicio);
        l->inicio = NULL;
        return 0;
    }
    No *no = l->inicio;
    while (no->prox != l->inicio)
        no = no->prox;
    No *temp = l->inicio;
    no->prox = temp->prox;
    l->inicio = temp->prox;
    free(temp);
    return 0;
}
int removerFim(Lista *l) {
    if (l == NULL) return 2;
    if (listaVazia(l) == 0) return 1;
    if (l->inicio->prox == l->inicio) {
        free(l->inicio);
        l->inicio = NULL;
        return 0;
    }
    No *anterior = NULL, *no = l->inicio;
    while (no->prox != l->inicio) {
        anterior = no;
        no = no->prox;
    }
    anterior->prox = no->prox;
    free(no);
    return 0;
}
int removerPosicao(Lista *l,int pos) {
    if (l == NULL) return 2;
    if (listaVazia(l) == 0) return 1;
    if (l->inicio->prox == l->inicio) {
        free(l->inicio);
        l->inicio = NULL;
        return 0;
    }

    if(pos == 0){
        removerInicio(l);
        return 0;
    }
    No *anterior = NULL, *no = l->inicio;
    while ((no->prox != l->inicio)&&(pos > 0)) {
        anterior = no;
        no = no->prox;
        pos--;
    }
    anterior->prox = no->prox;
    free(no);
    return 0;
}
int buscarItem(Lista *l, int chave, Aluno *it) {
    if (l == NULL) return 2;
    if (listaVazia(l) == 0) return 1;
    No *no = l->inicio;
    while ((no->prox != l->inicio)&&
           ((no->valor).mat != chave))
        no = no->prox;
    if ((no->valor).mat != chave )
        return 1;
    else {
        *it = no->valor;
        return 0;
    }
}

int removerMeio(Lista *l){
    if (l == NULL) return 2;
    if (listaVazia(l) == 0) return 1;
    No *no = l->inicio;
    if (no == no->prox)
        removerInicio(l);
    else{
        int p = 0;
        while(no->prox != l->inicio){
            p++;
            no = no->prox;
        }
        p /= 2;
        removerPosicao(l, p);
    }
    return 0;
}

int removerItemChave(Lista *l, int chave){
    if (l == NULL) return 2;
    if (listaVazia(l) == 0) return 1;
    No *no = l->inicio;
    int p = 0, achou = 0;
    while(no->prox != l->inicio){
        if(no->valor.mat == chave){
            achou = 1;
            break;
        }
        p++;
        no = no->prox;
    }
    removerPosicao(l, p);
    if(achou == 0) return 3;
    return 0;
}

int removerItem(Lista *l, int it){
    if (l == NULL) return 2;
    if (listaVazia(l) == 0) return 1;
    No *no = l->inicio;
    int p = 0;
    while(1){
        if(removerItemChave(l, it) > 0){
            break;
        }
    }
    return 0;
}