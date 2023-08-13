#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
Utilizando aritmética de ponteiros, mostre na tela o conteúdo da string char nome[] = “Carla Faria”. Utilize o
printf com %c e não %s. Exiba também o conteúdo de um vetor de double de 10 posições usando o nome do vetor
como ponteiro para acessar as posições.
*/

int main(){
    char nome[] = "Carla Faria", *p1 = nome;
    double vetor[10], *p2 = vetor;
    int tamanho = strlen(nome);
    srand(time(NULL));

    for(int i = 0; i < tamanho; i++){
        printf("%c\n", *(p1+i));
    }

    for(int i = 0; i < 10; i++){
        *(p2+i) = (rand()%100) + ((rand()%1000)/1000.0);
        printf("%.2lf ", *(p2+i));
    }

    printf("\n");
    fflush(stdin);
    getchar();
    return 0;
}