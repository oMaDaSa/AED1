#include <stdio.h>
#include <stdlib.h>

/*Faça uma função para multiplicar um vetor por um escalar (um número). Mostre, no programa principal, o vetor antes e
depois da multiplicação*/

int multiplica(float *vetorIncial, float *vetorFinal, int tamanho, float escalar);
void printaVetor(float *vetor, int tamanho);

int main(){
    float *vetorInicial, *vetorFinal, escalar;
    int tamanho;

    printf("Insira o tamanho do vetor: ");
    scanf("%d",&tamanho);

    vetorInicial = (float*)malloc(tamanho*sizeof(float));
    vetorFinal = (float*)malloc(tamanho*sizeof(float));

    for(int i = 0; i < tamanho; i++){
        printf("Insira o valor de vetor[%d]: ",i);
        scanf("%f",&vetorInicial[i]);
    }

    printf("insira o escalar da multiplicacao: ");
    scanf("%f", &escalar);

    multiplica(vetorInicial, vetorFinal, tamanho, escalar);
    printf("Vetor Inicial: ");
    printaVetor(vetorInicial, tamanho);
    printf("Vetor Final: ");
    printaVetor(vetorFinal, tamanho);

    fflush(stdin);
    getchar();
    return 0;
}

int multiplica(float *vetorInicial, float *vetorFinal, int tamanho, float escalar){
    for(int i = 0; i < tamanho; i++){
        vetorFinal[i] = vetorInicial[i]*escalar;
    }
    return 1;
}

void printaVetor(float *vetor, int tamanho){
    for(int i = 0; i < tamanho; i++){
        printf("%.2f ",vetor[i]);
    }
    printf("\n");
}
