#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int matriz[5][10], vetorLinhas[5], matrizResultante[5][10], tempSoma;
    srand(time(NULL));

    for(int i = 0; i < 5; i++){
        tempSoma = 0;
        for(int j = 0; j < 10; j++){
            matriz[i][j] = rand()%100;
            tempSoma += matriz[i][j];
        }
        vetorLinhas[i] = tempSoma;
    }

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 10; j++){
            matrizResultante[i][j] = matriz[i][j] * vetorLinhas[i];
        }
    }

    printf("Matriz Inicial:\n");
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 10; j++){
            printf("%d ", matriz[i][j]);
            printf(" ");
        }
        printf("\n");
    }

    printf("Matriz Resultante:\n");
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 10; j++){
            printf("%d ", matrizResultante[i][j]);
        }
        printf("\n");
    }

    system("pause");
    return 0;
}
