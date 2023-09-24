#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lista.h"

int main() {
    const int qtdTeste = 10;
    Aluno alunoTeste[qtdTeste], matheus, ciclaninho, busca;
    Lista *lTeste = criar();

    for(int i = 0; i < qtdTeste; i++){
        strcpy(alunoTeste[i].nome, "fulano");
        alunoTeste[i].n1 = (float)i;
        alunoTeste[i].mat = 12220+i;
    }

    for(int i = 0; i < qtdTeste; i++){
        inserirFim(lTeste, alunoTeste[i]); //teste insercao no fim
    }

    strcpy(matheus.nome, "Matheus");
    matheus.n1 = (float)99.9;
    matheus.mat = 919191;

    strcpy(ciclaninho.nome, "Ciclaninho");
    ciclaninho.n1 = (float)25.2;
    ciclaninho.mat = 14144;

    inserirInicio(lTeste, matheus);
    inserirInicio(lTeste, ciclaninho); //testa insercao no inicio

    removerInicio(lTeste); // testa remocao no inicio
    removerFim(lTeste); //testa remocao no fim
    removerPosicao(lTeste, 3); // testa remocao em posicao especifica

    if(buscarItemChave(lTeste, 919191, &busca) == 0)
        printf("Estudante encontrado: %s\n", busca.nome);

    mostrar(lTeste); // imprime a lista

    limpar(lTeste); // testa limpar lista
    mostrar(lTeste); // imprime a lista pós limpar()

    fflush(stdin);
    getchar();
    return 0;
}
