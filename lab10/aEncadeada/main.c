#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main(){
    int recebe;
    Fila *f = criar();
    
    inserir(f, 10);
    mostrar(f);

    inserir(f, 20);
    mostrar(f);

    remover(f, &recebe);
    mostrar(f);

    inserir(f, 30);
    mostrar(f);

    inserir(f, 45);
    mostrar(f);

    inserir(f, 21);
    mostrar(f);

    remover(f, &recebe);
    mostrar(f);

    remover(f, &recebe);
    mostrar(f);

    fflush(stdin);
    getchar();
    return 0;
}