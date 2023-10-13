#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(){
    Lista *l = criar();
    for(int i = 256; i >= 1; i--)
        inserirInicio(l, i);
    
    mostrar(l);
    printf("\nSoma = %d\n", somaElementos(l));
    fflush(stdin);
    getchar();
    return 0;
}