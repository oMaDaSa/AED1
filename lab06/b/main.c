#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

int main()
{
    Lista *l1 = criar(), *l2 = criar(), *l3;
    Aluno teste1[MAX], teste2[MAX], matheus;

    matheus.mat = 709;
    matheus.n1 = 94;
    strcpy(matheus.nome,"Matheus");

    for(int i = 0; i < MAX; i++){
        teste1[i].mat = i;
        strcpy(teste1[i].nome,"aaa");
        teste1[i].n1 = 10;
    }
    for(int i = 0; i < MAX; i++){
        teste2[i].mat = i+30;
        strcpy(teste2[i].nome,"bbb");
        teste2[i].n1 = 2;
    }

    for(int i = 0; i < MAX; i++){
        inserirFim(l1, teste1[i]);
    }
    inserirFim(l1, matheus);
    for(int i = 0; i < MAX; i++){
        inserirFim(l2, teste2[i]);
    }

    l3 = concatena(l1, l2);
    printf("Listas concatenadas:\n");
    mostrar(l3);
    if(contemItem(l3, matheus)) printf("O item {%d, %s, %.2f},  esta na lista\n", matheus.mat, matheus.nome, matheus.n1);
    fflush(stdin);
    getchar();
    free(l1); free(l2);
    return 0;
}
