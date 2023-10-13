#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(){
    Lista *l = criar();
    int elemento;
    for(int i = 256; i >= 1; i--)
        inserirInicio(l, i);
        
    mostrar(l);
    ultimoElemento(l, &elemento);
    printf("\nUltimo elemento = %d",elemento);
    fflush(stdin);
    getchar();
    return 0;
}