/*a) Escreva uma fun��o que receba como par�metro uma data
(crie um struct com informa��es referentes a dia, m�s e ano), e mostre na tela a data no formato dd/mm/aaaa.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct data{
    int dia, mes, ano;
}data;

int main()
{
    data data;
    printf("Insira o dia: ");
    scanf("%d",&data.dia);
    printf("Insira o mes: ");
    scanf("%d",&data.mes);
    printf("Insira o ano: ");
    scanf("%d",&data.ano);

    if(data.dia < 10) printf("0%d/",data.dia);
    else printf("%d/",data.dia);
    if(data.mes < 10) printf("0%d/",data.mes);
    else printf("%d/",data.mes);
    printf("%d",data.ano);

    fflush(stdin);
    getchar();
    return 0;
}
