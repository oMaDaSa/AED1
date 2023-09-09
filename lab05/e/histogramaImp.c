#include "histograma.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct histograma{
    int tamanho, *qtd;
    char *conteudo;
}histograma;

histograma *criar(){
    histograma *h = (histograma*)malloc(sizeof(histograma));
    h->conteudo = (char*)malloc(sizeof(char));
    h->qtd = (int*)malloc(sizeof(int));
    h->tamanho = 0;
    return h;
}

int verifica(histograma *h, char c){
    int i;
    if(c < 32 || c > 126) return -2;
    for(i = 0; i < h->tamanho; i++){
        if(h->conteudo[i] == c) return i;
    }return -1;
}

void  redimensiona(histograma *h){
    if(h->tamanho == 0 ){
        h->qtd[h->tamanho] = 1;
        h->tamanho++;
    }else{
        h->conteudo = realloc(h->conteudo,(h->tamanho+1)*sizeof(char));
        h->qtd = realloc(h->qtd,(h->tamanho+1)*sizeof(int));
        h->qtd[h->tamanho] = 1;
        h->conteudo[h->tamanho] = 0;
        h->tamanho++;
    }
}

void adicionaFim(histograma *h, char c){
    h->conteudo[h->tamanho-1] = c;
}

void gera(histograma *h, const char *texto){
    int i, pos, tamanho;
    tamanho = (int)strlen(texto);
    for(i = 0; i < tamanho; i++){
        pos = verifica(h, texto[i]);
        if(pos > 0){
            h->qtd[pos]++;
        }else if(pos == -1){
            redimensiona(h);
            adicionaFim(h, texto[i]);
        }
    }
}

void mostra(histograma *h){
    int i;
    printf("{\n");
    for(i = 0; i <h->tamanho; i++){
        printf(" '%c' = %d\n",h->conteudo[i], h->qtd[i]);
    }
    printf("}\n");
}