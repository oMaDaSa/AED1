#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include <time.h>

int removerNegativos(Fila *f){
    if(f == NULL) return 2;
    if(filaVazia(f) == 0) return 1;

    int valor, qtd = tamanho(f);
    for(int i = 0; i < qtd; i++){
        remover(f, &valor);
        if(valor >= 0)  inserir(f, valor);
    }
    return 0;
}

int main(){
    Fila *f1 = criar();
    srand(time(NULL));

    int tamanhoLista1 = rand()%10;
    for(int i = 0; i < tamanhoLista1; i++)
        inserir(f1, rand()%100-50);
    mostrar(f1);

    removerNegativos(f1);
    mostrar(f1);

    fflush(stdin);
    getchar();
    return 0;
}