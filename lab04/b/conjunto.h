#ifndef B_CONJUNTO_H
#define B_CONJUNTO_H

typedef struct Conjunto{
    int *elemento, tamanho;
}conjunto;
conjunto* criar();
int membro(conjunto *c, int x);
int inserir(conjunto *c, int x);
int remover(conjunto *c, int x);
void uniao(conjunto *c1, conjunto *c2, conjunto *un);
void interseccao(conjunto *c1, conjunto *c2, conjunto *inter);
void diferenca(conjunto *c1, conjunto *c2, conjunto *dif);
void printConjunto(conjunto *c);

#endif //B_CONJUNTO_H
