/*
Escreva um programa que lê um vetor de inteiros (a leitura pára quando o usuário digita -1), 
remove valores consecutivos repetidos e mostra o vetor atualizado. 
O programa deve alocar memória dinamicamente para utilizar o vetor, 
e o vetor deve ter ao final da operação sempre o tamanho exato dos elementos presentes nele.
Permitaa o usuário informar mais conjuntos de números,
e defina uma condição para o usuário parar a criação de novos vetores.
Oprograma deve, ao final de cada operação, mostrar o seu tamanho final.
*/
#include <stdio.h>
#include <stdlib.h>

void printa_Vetor(int *vet, int tam){
    int i;
    for (i = 0; i < tam; i++)
    {
        printf("%4d", vet[i]);
    }
}

int main()
{
    int *v, tamanho, num, i, j, escolha;
    v = (int *) malloc(1*sizeof(int));

    do
    {
        tamanho = 0;
        printf("1) Criar novo vetor.\n");
        printf("2) Sair.\n");
        scanf("%d", &escolha);

        if (escolha == 2)
        {
            break;
        }
        
        for (i = 0;; i++)
        {
            printf("Digite um numero para adicionar no vetor, digite -1 para sair. ");
            scanf("%d", &num);
            if (num == -1) break;
            tamanho++;
            v = (int *) realloc(v,tamanho*sizeof(int));
            v[i] = num;
        }
        printf("\nVetor criado: \n");
        printa_Vetor(v, tamanho);
        printf("\nTamanho do vetor: %d\n", tamanho);

        // remover valores consecutivos repetidos
        for (i = 0; i < tamanho-1; i++)
        {
            if (v[i] == v[i+1])
            {
                for (j= i+1; j < tamanho-1; j++)
                {
                    v[j] = v[j+1];
                }
                i--;
                tamanho--;   
            }

        }
        v = (int *) realloc(v,tamanho*sizeof(int));

        printa_Vetor(v, tamanho);
        printf("\nTamanho do vetor: %d\n", tamanho);
    }while(escolha != 2);
    
    fflush(stdin);
    getchar();
    free(v);
    return 0;
}
