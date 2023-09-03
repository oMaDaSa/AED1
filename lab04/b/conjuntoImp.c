#include <stdio.h>
#include <stdlib.h>
#include "conjunto.h"

conjunto* criar(){
    conjunto *c = (conjunto*)malloc(sizeof(conjunto));
    c->elemento = (int*)malloc(sizeof(int));
    c->tamanho = 0;
    return c;
}

int membro(conjunto *c, int x){
    for(int i = 0; i < c->tamanho; i++){
        if(c->elemento[i] == x){
            return 0;
        }
    }
    return 1;
}

int inserir(conjunto *c, int x){
    if(c->tamanho == 0){
        c->elemento[0] = x;
        c->tamanho++;
    }

    else{
        for(int i = 0; i < c->tamanho; i++){
            if(c->elemento[i] == x) return 1;
        }
        c->elemento = realloc(c->elemento,(c->tamanho+1)*sizeof(int));
        c->elemento[c->tamanho] = x;
        c->tamanho++;
    }
    return 0;
}

int remover(conjunto *c,  int x){
    for(int i = 0; i < c->tamanho; i++){
        if(c->elemento[i] == x){
            for(int j = i; j < c->tamanho-1; j++){
                c->elemento[j] = c->elemento[j+1];
            }
            c->elemento = realloc(c->elemento,(c->tamanho-1)*sizeof(int));
            c->tamanho--;
            return 0;
        }
    }
    return 1;
}

void interseccao(conjunto *c1, conjunto *c2, conjunto *inter){
    for(int i = 0; i < c1->tamanho; i++){
        for(int j = 0; j < c2->tamanho; j++){
            if(c1->elemento[i] == c2->elemento[j]){
                inserir(inter, c1->elemento[i]);
                break;
            }
        }
    }
}

void uniao(conjunto *c1, conjunto *c2, conjunto *un){
    int valid, pos = 0;

    for(int i = 0; i < c1->tamanho; i++){
        inserir(un, c1->elemento[i]);
    }
    for(int i = 0; i < c2->tamanho; i++){
        valid = 1;
        for(int j = 0; j < un->tamanho; j++){
            if(c2->elemento[i] == un->elemento[j]){
                valid = 0;
                break;
            }
        }
        if(valid){
            inserir(un, c2->elemento[i]);
        }
    }
}

void diferenca(conjunto*c1, conjunto *c2, conjunto *dif){
    int valid;
    for(int i = 0; i < c1->tamanho; i++){
        valid = 1;
        for(int j = 0; j < c2->tamanho; j++){
            if(c1->elemento[i] == c2->elemento[j]){
                valid = 0;
                break;
            }
        }
        if(valid){
            inserir(dif, c1->elemento[i]);
        }
    }
}

void printConjunto(conjunto *c){
    for(int i = 0; i < c->tamanho; i++){
        if(i == 0) printf("{");
        printf("%d", c->elemento[i]);
        if(i < (c->tamanho)-1) printf(", ");
    }
    printf("}\n");
}