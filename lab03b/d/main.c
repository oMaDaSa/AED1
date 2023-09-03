/*d) Faça uma função que receba um texto de até 400 caracteres, e retorne dois vetores,
 um contendo cada um dos caracteres digitados (sem repetição), 
 e outro contendo quantas vezes cada caractere presente no primeiro vetor aparece. 
 O vetor não precisa estar em ordem alfabética. 
Faça um programa que utilize a função e mostre essas informações na tela*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int preenche_Vetor(char *s, char *v){
    int i, j, count, tamanho = 1;
    v[0] = s[0];
    for (i = 0; s[i]!='\0'; i++)
    {
        count = 1;
        for (j = 0; j < tamanho; j++)
        {
            if(s[i] == v[j]) count = 0;
        }
        if (count == 1)
        {
            tamanho++;
            v = (char *) realloc(v,tamanho*sizeof(char));
            v[tamanho-1] = s[i];
        }
    }
    return tamanho;
}

void conta_Caracteres(char *st, char *str_usuario, int tamanho, int *conta_char){
    int i, j = 0, count;
    for (i = 0; i < tamanho; i++)
    {
        count = 0;
        for (j = 0; str_usuario[j] != '\0'; j++)
        {
            if (st[i] == str_usuario[j])
            {
                count++;
            }
        }
        conta_char[i] = count;
    }
}

int main()
{
    char str[400], *v1;
    int *v2, tam, i;
    printf("Digite o texto: ");
    fgets(str, 400, stdin);
    str[strlen(str)-1] = '\0'; // tirar o \n do final 
    fflush(stdin);
    v1 = (char *) malloc(1*sizeof(char));
    tam = preenche_Vetor(str, v1);
    v2 = (int *) malloc(tam*sizeof(int));
    conta_Caracteres(v1, str, tam, v2);

    for (i = 0; i < tam; i++)
    {
        printf("\nCaractere '%c'\n", v1[i]);
        printf("Repete %d vezes\n", v2[i]);
    }
    
    free(v1);
    free(v2);
    fflush(stdin);
    getchar();
    return 0;
}
