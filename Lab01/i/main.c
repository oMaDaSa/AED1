#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct livro{
    char titulo[100];
    int ano, paginas;
    float preco;
}livro;
int main()
{
    livro livro[5];
    float mediaPag;
    int soma;

    for(int i = 0; i < 5; i++){
        printf("Insira os dados do livro %d\n", i+1);
        printf("Insira o nome do livro: ");
        setbuf(stdin, NULL);
        fgets(livro[i].titulo, 100, stdin);

        printf("Insira o ano do livro: ");
        scanf("%d", &livro[i].ano);

        printf("Insira a quantidade de paginas do livro: ");
        scanf("%d", &livro[i].paginas);
        soma += livro[i].paginas;

        printf("Insira o preco do livro: ");
        scanf("%f", &livro[i].preco);
        printf("\n");
    }

    mediaPag = soma/5;
    printf("A media de paginas dos livros eh de %.1f paginas\n", mediaPag);
    system("pause");
    return 0;
}
