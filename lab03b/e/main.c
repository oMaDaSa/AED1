#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Escreva um programa que leia 50 números sorteados pela Lotomania e em seguida leia os 50 números apostados pelo
usuário. O programa deve então comparar quantos números o jogador acertou, e alocar espaço para um vetor de
tamanho igual a quantidade de números corretos, guardando esses números corretos nesse vetor. Finalmente, o
programa deve exibir na tela os números sorteados, os números que o usuário acertou, e a porcentagem de acerto*/

void preencheVetor(int *v){
    for(int i = 0; i < 50;i++){
        v[i]  = -1;
    }
}

void printaVetor(int *v, int tamanho){
    for(int i = 0; i < tamanho;i++){
        printf("%d ",v[i]);
    }
    printf("\n");
}

int verificaAcertos(int *v1, int *v2, int *v3){
    int acertos = 0;
    for(int i = 0; i < 50; i++){
        for(int j = 0; j < 50; j++){
            if(v1[i] == v2[j]){
                acertos++;
                v3 = (int*)realloc(v3, acertos*sizeof(int));
                v3[acertos-1] = v2[j];
                break;
            }
        }
    }
    return acertos;
}

int main()
{
    int sorteados[50], apostados[50], i, j, *acertados, acertos, count, num;
    float taxaAcerto;
    srand(time(NULL));

    preencheVetor(sorteados);
    for(i = 0; i < 50; i++){
        num = rand()%100;
        count = 1;
        for(j=0; j < i; j++){
            if(num == sorteados[j]){
                count = 0;
                i--;
                break;
            }
        }
        if(count == 1) sorteados[i] = num;
    }

    preencheVetor(apostados);
    for(i = 0; i < 50; i++){
        do{
            count = 1;
            printf("Insira o numero %d: ",i);
            scanf("%d",&num);
            if(num < 0 || num > 100) count = 0;
            for(j=0; j < i; j++){
                if(num == apostados[j]){
                    count = 0;
                    break;
                }
            }
            if(count == 1) apostados[i] = num;
            else printf("Invalido\n");
        }while(count==0);
    }

    acertados = (int*)malloc(1*sizeof(int));
    acertos = verificaAcertos(apostados, sorteados, acertados);

    printf("\nSorteados: ");
    printaVetor(sorteados, 50);
    printf("Acertados: ");
    printaVetor(acertados, acertos);

    taxaAcerto = acertos*10/5;
    printf("%.2f%% de taxa de acerto\n", taxaAcerto);

    fflush(stdin);
    getchar();
    return 0;
}