#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*
Faça um programa que crie duas matrizes 3x3, utilizando dois ponteiros. Preencha as matrizes com valores inteiros.
Crie uma terceira matriz, também utilizando ponteiros, e preencha com o resultado da soma dos elementos respectivos
das outras matrizes. Mostre na tela as três matrizes.
*/

void imprime(int **matriz);

int main(){
    int **matriz1, **matriz2, **matriz3;
    srand(time(NULL));
    matriz1 = (int**)malloc(3*sizeof(int*));
    if(matriz1 == NULL) exit(1);
    for(int i = 0; i < 3; i++){
        matriz1[i] = (int*)malloc(3*sizeof(int));
        if(matriz1[i] == NULL) exit(1);
        for(int j = 0; j < 3; j++){
            matriz1[i][j] = rand()%100;
        }
    }

    matriz2 = (int**)malloc(3*sizeof(int*));
    if(matriz2 == NULL) exit(1);
    for(int i = 0; i < 3; i++){
        matriz2[i] = (int*)malloc(3*sizeof(int));
        if(matriz2[i] == NULL) exit(1);
        for(int j = 0; j < 3; j++){
            matriz2[i][j] = rand()%100;
        }
    }

    matriz3 = (int**)malloc(3*sizeof(int*));
    if(matriz3 == NULL) exit(1);
    for(int i = 0; i < 3; i++){
        matriz3[i] = (int*)malloc(3*sizeof(int));
        if(matriz3[i] == NULL) exit(1);
        for(int j = 0; j < 3; j++){
            matriz3[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }
    printf("Matriz A:\n");
    imprime(matriz1);
    printf("Matriz B:\n");
    imprime(matriz2);
    printf("Matriz A+B:\n");
    imprime(matriz3);
    fflush(stdin);
    getchar();
    return 0;
}

void imprime(int **matriz){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}