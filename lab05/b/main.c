#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista.h"

#define MAX 100

int main()
{
    Lista *l = criar(), *lReversa = criar();
    Aluno aluno[MAX], matheus;
    int conta;

    for(int i = 0; i < MAX; i++){
        aluno[i].mat = i;
        aluno[i].n1 = (float)i;
        strcpy(aluno[i].nome, "aaaa\0");
        inserirFim(l, aluno[i]);
    }

    matheus.mat=1000;
    strcpy(matheus.nome, "Matheus\0");
    matheus.n1 = 10;

    removerPosicao(l, 99);
    inserirFim(l, matheus);
    removerPosicao(l, 12);
    inserirPosicao(l, matheus, 12);
    //mostrar(l);

    if(contemItem(l, matheus) == 0) printf("Matheus esta na lista\n");
    reversa(l, lReversa);
    printf("Lista reversa:\n");
    mostrar(lReversa);

    contaItem(l, matheus, &conta);
    printf("Matheus aparece %d vezes\n", conta);
    fflush(stdin);
    getchar();
    return 0;
}
