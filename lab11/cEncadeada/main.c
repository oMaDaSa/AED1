#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int avaliaDelimitadores(Pilha *p){
    if(p == NULL) return 3;
    if(pilhaVazia(p) == 0) return 2;

    int parenteses = 0, colchetes = 0, chaves = 0;
    int tam = tamanho(p), valor;
    
    for(int i = 0; i < tam; i++){
        pop(p, &valor);
        switch(valor){
            case '(':
                if(parenteses <= 0) return 1;
                parenteses--;
                break;
            case ')':
                parenteses++;
                break;
            case '[':
                if(colchetes <= 0) return 1;
                if(parenteses > 0) return 1;
                colchetes--;
                break;
            case ']':
                if(parenteses > 0) return 1;
                colchetes++;
                break;
            case '{':
                if(chaves <= 0) return 1;
                if(parenteses > 0 || colchetes > 0) return 1;
                chaves--;
                break;
            case '}':
                if(parenteses > 0 || colchetes > 0) return 1;
                chaves++;
                break;
        }
    }
    if(parenteses != 0 || colchetes != 0 || chaves != 0) return 1;
    else return 0;
}

int main(void){
    Pilha *delimitadores = criar();
    char string[100];
    int code;
    printf("Insira uma sequencia de delimitadores matematicos: ");
    fflush(stdin);
    fgets(string, 100, stdin);

    for(int i = 0; string[i] != '\0' && string[i] != '\n'; i++){
        push(delimitadores, (int)string[i]);
    }

    code = avaliaDelimitadores(delimitadores);
    if(code == 0) printf("Correto\n");
    else if(code == 1) printf("incorreto\n");
    else printf("Erro\n");

    fflush(stdin);
    getchar();
    return 0;
}