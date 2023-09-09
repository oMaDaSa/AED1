#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista.h"

int main()
{
    int tamanho = 26, conta;
    Lista *l = criar(tamanho), *lReversa = criar(tamanho);
    Aluno aluno[26], matheus;


    for(int i = 0; i < tamanho; i++){
        aluno[i].mat = i;
        aluno[i].n1 = (float)i;
        strcpy(aluno[i].nome, "aaaa\0");
        inserirFim(l, aluno[i]);
    }

    matheus.mat=1000;
    strcpy(matheus.nome, "Matheus\0");
    matheus.n1 = 10;

    removerPosicao(l, tamanho-1);
    inserirFim(l, matheus);
    removerPosicao(l, 12);
    inserirPosicao(l, matheus, 12);
    printf("Lista Original: ");
    mostrar(l);
    
    fflush(stdin);
    getchar();
    return 0;
}
