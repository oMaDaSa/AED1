#include <stdio.h>

#include "histograma.h"

int main() {
    char texto[2000];
    histograma *h = criar();

    printf("Insira um texto: \n");
    fflush(stdin);
    fgets(texto,2000,stdin);

    gera(h, texto);
    mostra(h);

    fflush(stdin);
    getchar();
    return 0;
}
