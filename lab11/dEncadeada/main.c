#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

void decimalParaBinario(Pilha *p, int decimal){
    if(pilhaVazia(p) != 0) limpar(p);
    int resto;
    while(decimal != 0){
        resto = decimal%2;
        decimal /= 2;
        push(p, resto);
    }
}

void mostrarBinario(Pilha *p){
    if (p != NULL) {
        Pilha *aux = criar(p);
        int tam = tamanho(p), valor;
        for (int i=0;i<tam;i++){
            pop(p, &valor);
            push(aux,valor);
            printf("%d",valor);
        }
        for (int i=0;i<tam;i++){
            pop(aux, &valor);
            push(p,valor);
        }
        printf("\n");
        limpar(aux);
    }
}

int main(void){
    Pilha *binario = criar();
    unsigned long long int decimal;
    
    printf("Insira um decimal: ");
    scanf("%lld", &decimal);
    decimalParaBinario(binario, decimal);
    mostrarBinario(binario);
    
    fflush(stdin);
    getchar();
    return 0;
}