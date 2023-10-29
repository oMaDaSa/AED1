#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include <time.h>

Fila *intercalar(Fila *f1, Fila *f2){
    if(f1 == NULL) return f2;
    if(f2 == NULL) return f1;
    Fila *f3 = criar();
    int valor;
    while(filaVazia(f1) != 0){
        if(remover(f1, &valor) == 0) inserir(f3, valor);
        if(remover(f2, &valor) == 0) inserir(f3, valor);
    }
    while(filaVazia(f2) != 0){
        if(remover(f2, &valor) == 0) inserir(f3, valor);
    }
    return f3;
}

int main(){
    Fila *f1 = criar(), *f2 = criar();
    srand(time(NULL));

    int tamanhoLista1 = rand()%10;
    for(int i = 0; i < tamanhoLista1; i++)
        inserir(f1, rand()%100);
    mostrar(f1);

    int tamanhoLista2 = rand()%10;
    for(int i = 0; i < tamanhoLista2; i++)
        inserir(f2, rand()%100);
    mostrar(f2);
    
    Fila *f3 = intercalar(f1, f2);

    mostrar(f3);

    fflush(stdin);
    getchar();
    return 0;
}