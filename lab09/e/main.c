#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

int main(){
    Lista *l = criar();
    char numeroBinario[100];
    int x;

    printf("Insira um numero binario: ");
    fgets(numeroBinario, 100, stdin);
    numeroBinario[strlen(numeroBinario)-1] = '\0';
    
    for(int i = 0; numeroBinario[i] != '\0'; i++){
        if(numeroBinario[i] == '1') inserirInicio(l, 1);
        else if(numeroBinario[i] == '0') inserirInicio(l, 0);
    }

    printf("Insira um decimal para somar: ");
    scanf("%d", &x);
    for(int i = 0; i < x; i++)
        incrementar(l);
    mostrarReverso(l);
    fflush(stdin);
    getchar();
    return 0;
}