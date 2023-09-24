#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

int main(){
    Lista *cidades = criar(), *rotas = criar();
    Cidade uber, arag, prata;
    Rota r1, r2, r3, rBarata, rCara;
    float valor;

    strcpy(uber.nome, "Uberlandia");
    strcpy(uber.sigla, "Ub");

    strcpy(arag.nome, "Araguari");
    strcpy(arag.sigla, "Ar");

    strcpy(prata.nome, "Prata");
    strcpy(prata.sigla, "Pr");

    r1.destino = uber;
    r1.origem = arag;
    r1.preco = 20;

    r2.destino = arag;
    r2.origem = uber;
    r2.preco = 30;

    r3.destino = prata;
    r3.origem = uber;
    r3.preco = 80;

    inserirFim(cidades, &uber, 1);
    inserirFim(cidades, &arag, 1);
    inserirFim(cidades, &prata, 1);
    inserirFim(cidades, &uber, 1);
    inserirFim(rotas, &r1, 2);
    inserirFim(rotas, &r2, 2);
    inserirFim(rotas, &r3, 2);

    printf("Cidades:\n");
    mostrarCidades(cidades);
    printf("Rotas:\n");
    mostrarRotas(rotas);

    rotaBarata(rotas, &rBarata);
    rotaCara(rotas, &rCara);
    printf("Rota mais barata: ");
    printf("{%s[%s], %s[%s], R$%.2f}\n",rBarata.origem.nome,rBarata.origem.sigla, rBarata.destino.nome, rBarata.destino.sigla, rBarata.preco);
    printf("Rota mais cara: ");
    printf("{%s[%s], %s[%s], R$%.2f}\n",rCara.origem.nome,rCara.origem.sigla, rCara.destino.nome, rCara.destino.sigla, rCara.preco);

    consulta(rotas, "Ub", "Ar", &valor);
    printf("Valor da rota Uberlandia[Ub]-Araguari[Ar] = R$%.2f\n",valor);

    fflush(stdin);
    getchar();
    free(cidades);
    free(rotas);
    return 0;
}
