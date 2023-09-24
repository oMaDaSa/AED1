#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

typedef struct no
{
    void *valor;
    struct no *prox;
}No;

typedef struct lista
{
    No *inicio;
} Lista;

Lista *criar()
{
    Lista *l = (Lista*)malloc(sizeof(Lista));
    l->inicio = NULL;
    return l;
}
int listaVazia(Lista *l)
{
    if (l == NULL)
        return 2;
    if (l->inicio == NULL)
        return 0;
    return 1;
}

int inserirInicio(Lista *l, void *it, int tipo)
{
    if (l == NULL)
        return 2;
    No *no = (No*)malloc(sizeof(No));
    if(tipo == 1){
        no->valor = (Cidade*)it;
    }
    if(tipo == 2){
        no->valor = (Rota*)it;
    }
    no->prox = l->inicio;
    l->inicio = no;
    return 0;
}

int inserirFim(Lista *l, void *it, int tipo)
{
    if (l == NULL)
        return 2;
    if (listaVazia(l) == 0)
        return inserirInicio(l,it, tipo);
    No *noLista = l->inicio;
    while (noLista->prox != NULL)noLista = noLista->prox;
    No *no = (No*)malloc(sizeof(No));
    if(tipo == 1){
        no->valor = (Cidade*)it;
    }
    if(tipo == 2){
        no->valor = (Rota*)it;
    }
    no->prox = noLista->prox;
    noLista->prox = no;
    return 0;
}

int inserirPosicao(Lista *l, void *it, int tipo,int pos)
{
    if (l == NULL) return 2;
    if (pos < 0) return 3;
    if ((listaVazia(l) == 0)||(pos ==0))return inserirInicio(l,it, tipo);
    No *noLista = l->inicio;
    int p = 1;
    while ((noLista->prox != NULL)&&(p!=pos))
    {
        p++;
        noLista = noLista->prox;
    }
    No *no = (No*)malloc(sizeof(No));
    if(tipo == 1){
        no->valor = (Cidade*)it;
    }
    if(tipo == 2){
        no->valor = (Rota*)it;
    }
    no->prox = noLista->prox;
    noLista->prox = no;
    return 0;
}

int removerInicio(Lista *l)
{
    if (l == NULL)
        return 2;
    if (listaVazia(l) == 0)
        return 1;
    No *noLista = l->inicio;
    l->inicio = noLista->prox;
    free(noLista);
    return 0;
}

void limpar(Lista *l)
{
    while (listaVazia(l) != 0)
        removerInicio(l);
}

void mostrarCidades(Lista *l)
{
    if (l != NULL)
    {
        printf("[\n");
        No *noLista = l->inicio;
        while (noLista != NULL)
        {
            Cidade *a = (Cidade*)noLista->valor;
            printf(" {%s, ",a->sigla);
            printf("%s}\n",a->nome);
            noLista = noLista->prox;
        }
        printf("]\n");
    }
}

void mostrarRotas(Lista *l)
{
    if (l != NULL)
    {
        printf("[\n");
        No *noLista = l->inicio;
        while (noLista != NULL)
        {
            Rota *a = (Rota*)noLista->valor;
            printf(" {%s[%s], ",a->origem.nome,a->origem.sigla);
            printf("%s[%s], ",a->destino.nome,a->destino.sigla);
            printf("R$%.2f}\n",a->preco);
            noLista = noLista->prox;
        }
        printf("]\n");
    }
}

int removerFim(Lista *l)
{
    if (l == NULL)
        return 2;
    if (listaVazia(l) == 0)
        return 1;
    No *noAuxiliar = NULL;
    No *noLista = l->inicio;
    while (noLista->prox != NULL)
    {
        noAuxiliar = noLista;
        noLista = noLista->prox;
    }
    if (noAuxiliar == NULL) l->inicio=NULL;
    else noAuxiliar->prox = NULL;
    free(noLista);
    return 0;
}

int removerPosicao(Lista *l, int pos){
    if(l == NULL) return 2;
    if(listaVazia(l) == 0) return 1;
    if(pos < 0) return 3;
    int p = 0;
    No *noLista = l->inicio, *noAux = NULL;
    while ((noLista->prox != NULL)&&(p!=pos))
    {
        noAux = noLista;
        noLista = noLista->prox;
        p++;
    }
    if(noAux == NULL) return removerInicio(l);
    else noAux->prox = noLista->prox;
    free(noLista);
    return 0;
}

int buscarPosicao(Lista *l, int posicao, void *retorno, int tipo){
    if(l == NULL) return 2;
    if(listaVazia(l) == 0) return 1;
    No *noLista = l->inicio;
    int p = 0;
    while(noLista->prox != NULL && p!=posicao){
        noLista = noLista->prox;
        p++;
    }
    if(tipo == 1) *(Cidade*)retorno = *(Cidade*)noLista->valor;
    else if(tipo == 2) *(Rota*)retorno = *(Rota*)noLista->valor;

    return 1;
}

int contemItem(Lista *l, void *it, int tipo){
    if(listaVazia(l) == 0) return 0;
    if(l == NULL) return 2;
    No *noLista = l->inicio;
    if(tipo == 1){
        Cidade *a = (Cidade*)noLista->valor;
        Cidade *b = (Cidade*)it;
        while(noLista != NULL){
            if(strcmp(a->nome, b->nome) == 0)
                return 1;
            noLista = noLista->prox;
            a = (Cidade*)noLista->valor;
        }
    }else if(tipo == 2){
        Rota *a = (Rota*)noLista->valor;
        Rota *b = (Rota*)it;
        while(noLista != NULL){
            if(strcmp(a->destino.sigla, b->destino.sigla) == 0 && strcmp(a->origem.sigla, b->origem.sigla) == 0)
                return 1;
            noLista = noLista->prox;
            a = (Rota*)noLista->valor;
        }
    }
    return 0;
}

int rotaBarata(Lista *l, Rota *retorno){
    if(listaVazia(l) == 0) return 0;
    if(l == NULL) return 2;

    No *noLista = l->inicio;
    Rota *rotaAtual = (Rota*)noLista->valor;
    float precoBarato, precoAtual;
    precoBarato = rotaAtual->preco;
    *retorno = *rotaAtual;

    while(noLista != NULL){
        *rotaAtual = *(Rota*)noLista->valor;
        precoAtual = rotaAtual->preco;
        if(precoAtual<precoBarato)
            *retorno = *rotaAtual;
        noLista = noLista->prox;
    }
    return 1;
}

int rotaCara(Lista *l, Rota *retorno){
    if(listaVazia(l) == 0) return 0;
    if(l == NULL) return 2;

    No *noLista = l->inicio;
    Rota *rotaAtual = (Rota*)noLista->valor;
    float precoBarato, precoAtual;
    precoBarato = rotaAtual->preco;
    *retorno = *rotaAtual;

    while(noLista != NULL){
        *rotaAtual = *(Rota*)noLista->valor;
        precoAtual = rotaAtual->preco;
        if(precoAtual>precoBarato)
            *retorno = *rotaAtual;
        noLista = noLista->prox;
    }
    return 1;
}

int consulta(Lista *l, const char *a, const char *b, float *valor){
    if(listaVazia(l) == 0) return 0;
    if(l == NULL) return 2;
    No *noLista = l->inicio;
    Rota *rota;
    while(noLista != NULL){
        rota = (Rota*)noLista->valor;
        if(strcmp(a, rota->origem.sigla) == 0 && strcmp(b, rota->destino.sigla) == 0){
            *valor = rota->preco;
            break;
        }
        noLista = noLista->prox;
    }
    return 1;
}

/*
if(tipo == 1){
Cidade *a = (Cidade*)noLista->valor;
Cidade *b = (Cidade*)it;

}else if(tipo == 2){
Rota *a = (Rota*)noLista->valor;
Rota *b = (Rota*)it;



}*/