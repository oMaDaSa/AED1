#include <stdio.h>
#include <stdlib.h>
#include "conjunto.h"

int main() {
    conjunto *a = criar(), *b = criar();
    conjunto *un = criar(), *in = criar(), *dif = criar();
    int el;

    for(int i = 1; i <= 10; i++){
        inserir(a, i); //a = elementos de 1 a 10
        inserir(b,i*2); // b = elementos pares de 2 a 20
    }

    remover(a, 2); // remove 2 do conjunto a
    printf("A = ");
    printConjunto(a);

    printf("B = ");
    printConjunto(b);

    interseccao(a,b,in);
    printf("A && B = ");
    printConjunto(in);

    uniao(a,b,un);
    printf("A || B = ");
    printConjunto(un);

    diferenca(a,b,dif);
    printf("A - B = ");
    printConjunto(dif);

    printf("Insira um elemento para buscar no Conjunto A: ");
    scanf("%d", &el);
    if(membro(a, el)) printf("%d nao esta em A\n", el);
    else printf("%d esta em A\n", el);
    fflush(stdin);
    getchar();
    return 0;
}
