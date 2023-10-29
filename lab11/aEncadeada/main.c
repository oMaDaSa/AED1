#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main(void){
    Pilha *pilha = criar();
    int x;

    push(pilha, 11);
    push(pilha, 34); 
    pop(pilha, &x);
    printf("Removeu %d\n", x);
    pop(pilha, &x); 
    printf("Removeu %d\n", x);
    push(pilha, 23);
    push(pilha, 45); 
    pop(pilha, &x); 
    printf("Removeu %d\n", x);
    push(pilha, 121); 
    push(pilha, 22); 
    pop(pilha, &x); 
    printf("Removeu %d\n", x);
    pop(pilha, &x);
    printf("Removeu %d\n", x);
    mostrar(pilha);

    fflush(stdin);
    getchar();
    return 0;
}