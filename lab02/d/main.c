#include<stdio.h>
#include<stdlib.h>

/*
Escreva um programa em C que crie um vetor de n números inteiros (n informado pelo usuário). Faça a leitura dos
elementos desse vetor. Depois, exclua os elementos ímpares desse vetor, e redimensione-o, utilizando alocação
dinâmica de memória, para que não haja buracos no resultado final.
*/

int main(){
    int n, *vetor, qtdImpar = 0, aux;
    printf("Insira o tamanho do vetor: ");
    scanf("%d",&n);
    vetor = (int*)malloc(n*sizeof(int));
    if(vetor == NULL) exit(1);

    for(int i = 0; i < n; i++){
        printf("Insira o valor [%d]: ",i);
        scanf("%d", &vetor[i]);
        if(vetor[i]%2 == 1) qtdImpar++;
    }

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
           if(vetor[i] % 2 == 1 && vetor[j] % 2 == 0){
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
           }
        }
    }   

    vetor = realloc(vetor, sizeof(int)*(n-qtdImpar));
    for(int i = 0; i < n-qtdImpar; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
    free(vetor);
    fflush(stdin);
    getchar();
    return 0;
}