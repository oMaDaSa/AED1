#define MAX 100
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Lista.h"

typedef struct aluno Aluno;

typedef struct lista
{
    int total;
    Aluno valores[MAX];
}Lista;

Lista *criar()
{
    Lista *l = (Lista *)malloc(sizeof(Lista));
    if (l != NULL) l->total = 0;
    return l;
}
void limpar(Lista *l)
{
    if (l != NULL) l->total = 0;
}

int inserirInicio(Lista *l, Aluno it)
{
    int i;
    if (l == NULL) return 2;
    if (listaCheia(l) == 0) return 1;
    for (i=l->total; i>0; i--)
    {
        l->valores[i] = l->valores[i-1];
    }
    l->valores[0] = it;
    l->total++;
    return 0;
}

int inserirFim(Lista *l, Aluno it)
{
    if (l == NULL) return 2;
    if (listaCheia(l) == 0) return 1;
    l->valores[l->total] = it;
    l->total++;
    return 0;
}

int buscarItemChave(Lista *l, int chave,Aluno *retorno)
{
    int i;
    if (l == NULL) return 2;
    if (listaVazia(l) == 0) return 1;
    for (i=0; i<l->total; i++)
        if (l->valores[i].mat == chave)
        {
            *retorno = l->valores[i];
            return 0;
        }
    return -1;
}
int listaVazia(Lista *l)
{
    if (l == NULL) return 2;
    if (l->total == 0) return 0;
    else return 1;
}

int listaCheia(Lista *l)
{
    if (l == NULL) return 2;
    if (l->total == MAX) return 0;
    else return 1;
}

void mostrar(Lista *l)
{
    int i;
    if (l != NULL)
    {
        printf("[\n");
        for (i=0; i<l->total; i++)
        {
            printf(" {%d, ",l->valores[i].mat);
            printf("%s, ",l->valores[i].nome);
            printf("%.2f}\n",l->valores[i].n1);
        }
        printf("]\n");
    }
}

int removerInicio(Lista *l)
{
    int i;
    if (l == NULL) return 2;
    if (listaVazia(l) == 0) return 1;
    for (i=0; i<l->total-1; i++)
        l->valores[i] = l->valores[i+1];
    l->total--;
    return 0;
}

int removerFim(Lista *l)
{
    if (l == NULL) return 2;
    if (listaVazia(l) == 0) return 1;
    l->total--;
    return 0;
}

int inserirPosicao(Lista *l, Aluno it, int pos)
{
    if(pos == 0) inserirInicio(l, it);
    else if(pos == l->total-1) inserirFim(l, it);
    else{
        l->total++;
        for(int i = l->total-1; i > pos; i--){
            l->valores[i] = l->valores[i-1];
        }
        l->valores[pos] = it;
    }
    return 0;
}

int removerPosicao(Lista *l, int pos){
    int i;
    if(l == NULL) return 2;
    if(listaVazia(l) == 0) return 1;
    if(pos < 0 || pos > MAX) return 3;
    if(pos == l->total-1) removerFim(l);
    for(i = pos-1; i < l->total; i++){
        l->valores[i] = l->valores[i+1];
    }
    l->total--;
    return 0;
}

int removerItem(Lista *l, Aluno it){
    int i, j;
    if(l == NULL) return 2;
    if(listaVazia(l) == 0) return 1;
    for(i = 0; i < l->total; i++){
        if(it.mat == l->valores[i].mat){
            for(j = i; j < l->total; j++){
                l->valores[j] = l->valores[j+1];
            }
            l->total--;
            i--;
        }
    }
    return 0;
}

int buscarPosicao(Lista *l, int posicao, Aluno *it){
    if(l == NULL) return 2;
    if(listaVazia(l) == 0) return 1;
    it->mat = l->valores[posicao].mat;
    it->n1 = l->valores[posicao].n1;
    strcpy(it->nome, l->valores[posicao].nome);
    return 0;
}

int contemItem(Lista *l, Aluno it){
    int i;
    if(l == NULL) return 2;
    if(listaVazia(l) == 0) return 3;
    for(i = 0; i < l->total; i++){
        if(l->valores[i].mat == it.mat && l->valores[i].n1 == it.n1 && strcmp(l->valores[i].nome, it.nome) == 0)
            return 0;
    }
    return 1;
}

int reversa(Lista *l, Lista *lr){
    int i, j;
    if(l == NULL) return 2;
    if(listaVazia(l) == 0) return 1;
    lr->total = l->total;
    for(i = 0, j = l->total-1; i < l->total; i++, j--){
        lr->valores[i].mat = l->valores[j].mat;
        lr->valores[i].n1 = l->valores[j].n1;
        strcpy(lr->valores[i].nome, l->valores[j].nome);
    }
    return 1;
}

int contaItem(Lista *l, Aluno it, int *occur){
    int i;
    *occur = 0;
    if(l == NULL) return 2;
    if(listaVazia(l) == 0) return 1;
    for(i = 0; i < l->total; i++){
        if(l->valores[i].mat == it.mat && l->valores[i].n1 == it.n1 && strcmp(l->valores[i].nome, it.nome) == 0)
            (*occur)++;
    }
    return 0;
}
