
#include <stdio.h>
#include <stdlib.h>

/*Fa�a uma fun��o que receba um vetor de n�meros inteiros como par�metro, e devolve:
o a m�dia dos valores do vetor;
o o maior valor do vetor.
Esses valores devem ser retornados utilizando passagem de par�metros por refer�ncia*/

int mediaMaior(int *vetor, int size, float *media, int *maior);

int main(){
    int *vetor, size, maior;
    float media;

    printf("Insira o tamanho do vetor: ");
    scanf("%d",&size);
    vetor = (int*)malloc(size*sizeof(int));
    for(int i = 0; i < size; i++){
        printf("Insira o valor de vetor[%d]: ",i);
        scanf("%d",&vetor[i]);
    }
    mediaMaior(vetor, size, &media, &maior);
    printf("A media eh %.2f e o maior valor eh %d", media, maior);

    fflush(stdin);
    getchar();
    return 0;
}

int mediaMaior(int *vetor, int size, float *media, int *maior){
    int soma = vetor[0];
    *maior = vetor[0];
    for(int i = 1; i < size; i++){
        if (vetor[i] > *maior) *maior = vetor[i];
        soma+=vetor[i];
    }
    *media = (soma/((1.0)*size));
    return 0;
}
