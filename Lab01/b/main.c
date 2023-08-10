#include <stdio.h>
#include <stdlib.h>

int main()
{
    int anoAtual, anoNasc, idadeAtual, idadeFutura;
    printf("Insira o ano de nascimento: ");
    scanf("%d", &anoNasc);
    printf("Insira o ano atual: ");
    scanf("%d", &anoAtual);

    idadeAtual = anoAtual - anoNasc;
    idadeFutura = idadeAtual + (2030 - anoAtual);

    printf("Idade Atual: %d\n", idadeAtual);
    printf("Idade em 2030: %d\n", idadeFutura);
    system("pause");
    return 0;
}
