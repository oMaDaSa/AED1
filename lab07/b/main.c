#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lista.h"

int main() {
    const int qtdTeste = 10;
    Aluno alunoTeste[qtdTeste], matheus;
    Lista *lTeste = criar();

    for(int i = 1; i <= qtdTeste; i++){
        strcpy(alunoTeste[i-1].nome, "fulano");
        alunoTeste[i-1].n1 = (float)i;
        alunoTeste[i-1].mat = 12220+i;
    }

    for(int i = 1; i <= qtdTeste; i++){
        inserirFim(lTeste, alunoTeste[i-1]);
    }

    removerMeio(lTeste);
    mostrar(lTeste);

    fflush(stdin);
    getchar();
    return 0;
}
