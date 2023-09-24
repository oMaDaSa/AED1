#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lista.h"

int main() {
    const int qtdTeste = 10;
    Aluno aluno[qtdTeste];//, matheus;
    Lista *lista1 = criar(), *lista2 = criar(), *listaInterseccao;

    //strcpy(matheus.nome, "Matheus");
    //matheus.n1 = (float)99.9;
    //matheus.mat = 919191;

    for(int i = 1; i <= qtdTeste; i++){
        strcpy(aluno[i-1].nome, "fulano");
        aluno[i-1].n1 = (float)i;
        aluno[i-1].mat = 12220+i;
    }

    for(int i = 1; i <= qtdTeste; i++){
        inserirFim(lista1, aluno[i-1]);
        if(i%2==0) inserirFim(lista2, aluno[i-1]);
    }

    printf("Lista 1:\n");
    mostrar(lista1);
    printf("Lista 2:\n");
    mostrar(lista2);
    printf("Lista Interseccao:\n");
    listaInterseccao = interseccao(lista1, lista2);
    mostrar(listaInterseccao);


    fflush(stdin);
    getchar();
    free(lista1);free(lista2);free(listaInterseccao);
    return 0;
}
