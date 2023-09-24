#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

int main()
{
    Lista *l = criar();
    Aluno teste[MAX], matheus, retorno;

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
    inserirFim(l, matheus);
    printf("Antes da remocao: \n");
    mostrar(l);

    removerPosicao(l, 3);
    removerItem(l, matheus);
    printf("Apos as remocoes: \n");
    mostrar(l);
    buscarPosicao(l, 11, &retorno);
    printf("retorno = %s, %d, %.2f\n",retorno.nome, retorno.mat, retorno.n1);

    fflush(stdin);
    getchar();
    free(l);
    return 0;
}
