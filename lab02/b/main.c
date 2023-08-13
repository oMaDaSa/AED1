#include <stdio.h>
#include <stdlib.h>

/*
Crie um programa que:
o Aloque dinamicamente um vetor de 5 números inteiros,
o Peça para o usuário digitar os 5 números no espaço alocado,
o Mostre na tela os 5 números,
o Libere a memoria alocada
*/

int main(){
    int *vetor = (int*)malloc(5*sizeof(int));
    if(vetor == NULL) exit(1);

    for(int i = 0; i < 5; i++){
        printf("Insira o valor [%d]: ", i);
        scanf("%d", vetor+i);
    }
    for(int i = 0; i < 5; i++){
        printf("%d ", *(vetor+i));
    }
    free(vetor);
    fflush(stdin);
    getchar();
    return 0;
}