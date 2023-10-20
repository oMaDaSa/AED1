#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include <time.h>

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