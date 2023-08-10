#include <stdio.h>
#include <stdlib.h>

int main()
{
    float base, altura, area;
    do{
        printf("Insira o comprimento da base: ");
        scanf("%f", &base);
        printf("Insira o comprimento da base: ");
        scanf("%f", &altura);
        if(base <= 0 || altura <= 0) 
            printf("Dados invalidos\n");
    }while(base <= 0 || altura <= 0);
    
    area = (base * altura) / 2;
    printf("Triangulo de area %.2f u.a\n", area);
    system("pause");
    return 0;
}
