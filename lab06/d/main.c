#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

int main(){
    Lista *l = criar();
    Aluno teste[MAX], matheus;
    int remover;

    matheus.mat = 709;
    matheus.n1 = 94;
    strcpy(matheus.nome,"Matheus");

    for(int i = 0; i < MAX; i++){
        teste[i].mat = i;
        strcpy(teste[i].nome,"aaa");
        teste[i].n1 = 10;
    }

    for(int i = 0; i < MAX; i++){
        inserirFim(l, teste[i]);
    }

    inserirPosicao(l, matheus, 6);
    printf("Pre remocao:\n");
    mostrar(l);
    printf("Insira quantos elementos deseja remover da listal: ");
    scanf("%d", &remover);
    removerNPrimeiros(l,remover);
    printf("Pos remocao:\n");
    mostrar(l);

    fflush(stdin);
    getchar();
    free(l);
    return 0;
}
