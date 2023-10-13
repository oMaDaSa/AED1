#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lista.h"

int main(){
    srand(time(NULL));
    Lista *l = criar();
    int x;
    for(int i = 1; i <= 10; i++){
        inserirFim(l, rand()%5+1);
    }
        
    
    printf("Antes da remocao:\n");
    mostrar(l);
    printf("\n\nInsira um valor de 1 a 5 para remover: ");
    scanf("%d", &x);
    printf("\n\nApos a remocao:\n");
    removerItem(l, x);
    mostrar(l);
    fflush(stdin);
    getchar();
    return 0;
}