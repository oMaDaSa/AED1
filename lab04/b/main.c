#include <stdio.h>
#include <stdlib.h>

/*Crie uma função que receba um vetor de caracteres (String), seu tamanho e um caractere como parâmetros, e substitua
todas as ocorrências desse caractere por ‘*’. A função deve retornar a quantidade de substituições realizadas.*/

int substitui(char *string, char caractere, int tamanho);

int main(){
    char string[1000], caractere;
    int tamanho = 0, qtdSubstituicoes;

    printf("Insira a string: ");
    fflush(stdin);
    fgets(string, 1000, stdin);

    for(int i = 0; string[i] != '\0'; i++)
        tamanho++;
    printf("Insira o caracter a ser substituido: ");
    fflush(stdin);
    scanf("%c",&caractere);
    qtdSubstituicoes = substitui(string, caractere, tamanho);
    printf("Foram feitas %d substituicoes\n'%s'",qtdSubstituicoes, string);

    fflush(stdin);
    getchar();
    return 0;
}

int substitui(char *string, char caractere, int tamanho){
    int qtdSubst = 0;
    char caractere2;
    if(caractere > 'A' && caractere < 'Z') caractere2 = caractere+32;
    else if(caractere > 'a' && caractere < 'z') caractere2 = caractere-32;
    else caractere2 = caractere;

    for(int i = 0; i < tamanho; i++){
        if(string[i] == caractere || string[i] == caractere2){
            string[i] = '*';
            qtdSubst++;
        }
    }
    string[tamanho-1]='\0';
    return qtdSubst;
}
