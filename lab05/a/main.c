#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista.h"

#define MAX 100

int main()
{
    Lista *l = criar();
    Aluno aluno[MAX], matheus, busca;
    for(int i = 0; i < MAX; i++){
        aluno[i].mat = i;
        aluno[i].n1 = (float)i;
        strcpy(aluno[i].nome, "aaaa\0");
        inserirFim(l, aluno[i]);
    }

    matheus.mat=1000;
    strcpy(matheus.nome, "Matheus\0");
    matheus.n1 = 10;
    inserirFim(l, matheus);
    removerItem(l, aluno[4]);
    inserirPosicao(l,matheus,10);

    mostrar(l);
    buscarPosicao(l, 10, &busca);
    printf("Nome da pos 10: %s\n", busca.nome);

    fflush(stdin);
    getchar();
    return 0;
}
