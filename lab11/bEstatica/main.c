#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int comparaPilha(Pilha *p1, Pilha *p2){
    if(p1 == NULL || p2 == NULL) return 2;
    if(tamanho(p1) != tamanho(p2)) return 1;
    Pilha *aux1 = criar(), *aux2 = criar();
    int tam = tamanho(p1), valor1, valor2;
    int igual = 1;
    for(int i = 0; i < tam; i++){
        pop(p1, &valor1);
        pop(p2, &valor2);
        push(aux1, valor1);
        push(aux2, valor2);
        if(valor1 != valor2){
            igual = 0;
            break; 
        }
    }

    tam = tamanho(aux1);
    for(int i = 0; i < tam; i++){
        pop(aux1, &valor1);
        pop(aux2, &valor2);
        push(p1, valor1);
        push(p2, valor2);
    }

    limpar(aux1);
    limpar(aux2);
    if(igual) return 0;
    else return 1;
}

int main(void){
    Pilha *p1 = criar(), *p2 = criar();
    int valor;
    for(int i = 0; i < 5; i++){
        printf("Insira o valor %d da pilha 1: ", i+1);
        scanf("%d", &valor);
        push(p1, valor);
    }

    for(int i = 0; i < 5; i++){
        printf("Insira o valor %d da pilha 2: ", i+1);
        scanf("%d", &valor);
        push(p2, valor);
    }

    printf("p1: ");
    mostrar(p1);
    printf("p2: ");
    mostrar(p2);
    
    if(comparaPilha(p1, p2) == 0) printf("As pilhas sao iguais\n");
    else printf("As pilhas nao sao iguais\n");

    fflush(stdin);
    getchar();
    return 0;
}