#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matriz.h"

int main() {
    srand(time(NULL));
    matriz *m1 = criar(5,5), *m2 = criar(5,5), *soma = criar(5,5);
    float valor;
    int i, j;

    printf("Insira um valor para inserir na posicao [0][0] da matriz A: ");
    scanf("%f",&valor);
    atribuir(m1, valor, 0, 0);

    preencherAleatorio(m2, 1, 10);
    printf("Insira um indice [i<5][j<5] para acessar na Matriz aleatoria B: ");
    scanf("%d%d",&i, &j);
    if(i < 5 && j < 5){
        acessar(m2, &valor, i,j);
        printf("B[%d][%d] = %.2f\n",i, j, valor);
    }else printf("Posicao invalida\n");

    printf("\n\nA:\n");
    printMatriz(m1);

    printf("\n\nB:\n");
    printMatriz(m2);

    if(somar(m1, m2, soma)) printf("\nMatrizes incompativeis para soma\n");
    else{
        printf("\n\nA+B:\n");
        printMatriz(soma);
    }
    fflush(stdin);
    getchar();
    return 0;
}
