#include <stdio.h>
#include "Lista.h"
#include "stdlib.h"

typedef struct no {
    Aluno valor;
    struct no *prox;
}No;
typedef struct lista {
    No *final;
}ListaCircular;

Lista *criar() {
    Lista *l =(Lista*)malloc(sizeof(Lista));
    l->final = NULL;
    return l;
}

void limpar(Lista *l) {
    while (listaVazia(l) != 0)
        removerInicio(l);
    l = NULL;
    free(l);
}

int tamanho(Lista *l) {
    if (l == NULL) return -1;
    if (listaVazia(l) == 0) return 0;
    No *noLista = l->final;
    int cont = 0;
    do {
        cont++;
        noLista = noLista->prox;
    } while (noLista != l->final);
    return cont;
}

void mostrar(Lista *l) {
    if (l != NULL) {
        printf("[\n");
        if (listaVazia(l) != 0) {
            No *noLista = l->final;
            noLista = noLista->prox;
            No *noInicio = noLista;
            do {
                printf("{%d, %s, %.2f}\n",noLista->valor.mat,noLista->valor.nome,noLista->valor.n1);
                noLista = noLista->prox;
            } while (noLista != noInicio);
        }
        printf("]\n");
    }
}
int listaVazia(Lista *l) {
    if (l == NULL) return 2;
    if (l->final == NULL)
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
        l->final = no;
        no->prox = no;
    }else {
        no->prox = l->final->prox;
        l->final->prox = no;
    }
    return 0;
}

int inserirFim(Lista *l, Aluno it) {
    if (l == NULL) return 2;
    No *noFinal = (No *)malloc(sizeof(No));
    noFinal->valor = it;

    if (listaVazia(l) == 0) {
        l->final = noFinal;
        noFinal->prox = noFinal;

    }else {
        No *noPrimeiro = l->final->prox;
        l->final->prox = noFinal;
        noFinal->valor = it;
        noFinal->prox = noPrimeiro;
        l->final = noFinal;
    }
    return 0;
}

int removerInicio(Lista *l) {
    if (l == NULL) return 2;
    if (listaVazia(l) == 0) return 1;

    if (l->final->prox == l->final) {
        free(l->final);
        l->final = NULL;
        return 0;
    }
    No *inicio = l->final->prox;
    No *segundo = inicio->prox;

    l->final->prox = segundo;
    free(inicio);
    return 0;
}


int removerFim(Lista *l) {
    if (l == NULL) return 2;
    if (listaVazia(l) == 0) return 1;
    if (l->final->prox == l->final) {
        free(l->final);
        l->final = NULL;
        return 0;
    }
    No *anterior = NULL, *no = l->final, *inicio = no->prox;
    while (no->prox != l->final) {
        anterior = no;
        no = no->prox;
    }
    l->final = no;
    free(no->prox);
    l->final->prox = inicio;

    return 0;
}

int removerPosicao(Lista *l,int pos) {
    if (l == NULL) return 2;
    if (listaVazia(l) == 0) return 1;
    if (l->final->prox == l->final) {
        free(l->final);
        l->final = NULL;
        return 0;
    }

    No *anterior = NULL, *no = l->final;
    while ((no->prox != l->final)&&(pos >= 0)) {
        anterior = no;
        no = no->prox;
        pos--;
    }
    anterior->prox = no->prox;
    free(no);
    return 0;
}

int buscarItemChave(Lista *l, int chave, Aluno *it) {
    if (l == NULL) return 2;
    if (listaVazia(l) == 0) return 1;
    No *no = l->final;
    while ((no->prox != l->final)&&((no->valor).mat != chave))
        no = no->prox;
    if((no->valor).mat != chave )
        return 1;
    else {
        *it = no->valor;
        return 0;
    }
}

