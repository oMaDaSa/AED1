#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

int main()
{
    Lista *l = criar();
    Aluno teste[MAX], matheus;

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

    inserirPosicao(l, matheus, 2);
    mostrar(l);
    printf("Aluno com a maior nota:");
    maiorNotas(l);
    fflush(stdin);
    getchar();
    free(l);
    return 0;
}
