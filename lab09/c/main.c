#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(){
    Lista *l = criar();
    for(int i = 256; i >= 1; i--)
        inserirInicio(l, i);
    
    printf("Ordem de insercao:\n");
    mostrar(l);
    printf("\n\nOrdem reversa:\n");
    mostrarReverso(l);
    fflush(stdin);
    getchar();
    return 0;
}