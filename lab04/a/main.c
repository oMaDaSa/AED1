#include <stdio.h>
#include <stdlib.h>
#include "texto.h"

int main() {
    int tamanho, ocorre;
    char s[100], c;

    texto *txt = criarTexto();
    printf("Insira o texto: ");
    fgets(s,100,stdin);

    passarTexto(txt, s);

    printf("Insira o caracter a buscar: ");
    fflush(stdin);
    scanf("%c",&c);
    ocorre = ocorreTexto(txt, c);
    printf("'%c' ocorre %d vezes\n",c, ocorre);

    printf("Texto: ");
    printTexto(txt);

    tamanho = tamanhoTexto(txt);
    printf("Tamanho: %d\n",tamanho);

    fflush(stdin);
    getchar();

    return 0;
}
