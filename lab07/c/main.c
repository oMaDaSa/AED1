#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lista.h"

int main() {
    const int qtdTeste = 10;
    Aluno alunoTeste[qtdTeste], matheus;
    Lista *lTeste = criar();

    strcpy(matheus.nome, "Matheus");
    matheus.n1 = (float)99.9;
    matheus.mat = 919191;

    for(int i = 1; i <= qtdTeste; i++){
        strcpy(alunoTeste[i-1].nome, "fulano");
        alunoTeste[i-1].n1 = (float)i;
        alunoTeste[i-1].mat = 12220+i;
    }

    for(int i = 1; i <= qtdTeste; i++){
        inserirFim(lTeste, matheus); //insere lixo na lista para remover depois
        inserirFim(lTeste, alunoTeste[i-1]);
    }

    removerItemChave(lTeste, matheus.mat);
    mostrar(lTeste);
    removerItem(lTeste, matheus.mat);
    mostrar(lTeste);

    fflush(stdin);
    getchar();
    free(lTeste);
    return 0;
}
