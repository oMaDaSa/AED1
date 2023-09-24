#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lista.h"

int main() {
    const int qtdTeste = 10;
    Aluno aluno[qtdTeste], matheus;
    Lista *lista = criar();

    strcpy(matheus.nome, "Matheus");
    matheus.n1 = (float)99.9;
    matheus.mat = 919191;

    for(int i = 1; i <= qtdTeste; i++){
        strcpy(aluno[i-1].nome, "fulano");
        aluno[i-1].n1 = (float)i;
        aluno[i-1].mat = 12220+i;
    }

    for(int i = 1; i <= qtdTeste; i++){
        inserirFimSemRepeticao(lista, matheus);
        inserirFimSemRepeticao(lista, aluno[i-1]);
    }

    inserirFimSemRepeticao(lista, aluno[0]);
    mostrar(lista);

    fflush(stdin);
    getchar();
    free(lista);
    return 0;
}
