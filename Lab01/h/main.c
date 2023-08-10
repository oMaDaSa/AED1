#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char linha[100];
    int letras[26], size;

    printf("Insira uma string: ");
    fgets(linha, 100, stdin);
    size = strlen(linha);

    for(int i = 0; i < 26; i++){
        letras[i] = 0;
    }

    for(int i = 0; i < size; i++){
        if(linha[i] >= 'A' && linha[i] < 'Z') linha[i] += 32;
        if(linha[i] >= 'a' && linha[i] < 'z') letras[linha[i] - 'a']++;
    }

    for(int i = 0; i < 26; i++){
        if(letras[i] > 1) printf("letra %c se repete %d vezes\n", 'a'+i, letras[i]-1);
    }
    system("pause");
    return 0;
}
