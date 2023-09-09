#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista.h"

int main()
{
    Lista *l = criar();
    Aluno aluno[128], matheus;
    int conta;

    for(int i = 0; i < 128; i++){
        aluno[i].mat = i;
        aluno[i].n1 = (float)i;
        strcpy(aluno[i].nome, "aaaa\0");
        inserirFim(l, aluno[i]);
    }

    matheus.mat=1000;
    strcpy(matheus.nome, "Matheus\0");
    matheus.n1 = 10;


    inserirPosicao(l, matheus, 3);
    inserirPosicao(l, matheus, 7);
    inserirPosicao(l, matheus, 9);
    inserirInicio(l,matheus);
    inserirFim(l,matheus);
    contaItem(l,matheus, &conta);
    printf("Lista Original: ");
    mostrar(l);
    printf("Matheus aparece %d vezes\n",conta);
    fflush(stdin);
    getchar();
    free(l);
    return 0;
}
