/*c) Escreva um programa que aloque dinamicamente uma matriz (de inteiros) de dimensões definidas pelo usuário,
e preencha a matriz com valores informados pelo usuário. 
O programa deve então construir umo utro vetor que contenha exatamente os números que aparecem na matriz. 
Por exemplo, caso a matriz seja [[1,3,5],[2,3,1],[1,1,6]], o vetor resultante será [1,3,5,2,6]. 
O vetor não precisa estar ordenado ao final da execução, 
e seu tamanho deve coincidir como necessário para o resultado*/


#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **mat, *v, l, c, i, j, count = 1, tamanho = 1, k;

    printf("Digite o numero de linhas e colunas da matriz:");
    scanf("%d %d", &l, &c);
    mat = (int **) malloc(l*sizeof(int *));
    v = (int *) malloc(tamanho*sizeof(int));

    for (i = 0; i < l; i++)
    {
        mat[i] = (int *) malloc(c*sizeof(int));
    }
    
    for (i = 0; i < l; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("Digite um valor para mat[%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }

    v[0] = mat[0][0];
    for (i = 0; i < l; i++)
    {
        for (j = 0; j < c; j++)
        {
            count = 1;
            for (k = 0; k < tamanho; k++)
            {
                if(mat[i][j] == v[k]){
                    count = 0;
                }
            }
            if (count == 1)
            {
                tamanho++;
                v = (int *) realloc(v,tamanho*sizeof(int));
                v[tamanho-1] = mat[i][j];
            }
        }
    }

    printf("\nVETOR:\n");
    for (i = 0; i < tamanho; i++)
    {
        printf("%d ", v[i]);
    }
    
    return 0;
}
