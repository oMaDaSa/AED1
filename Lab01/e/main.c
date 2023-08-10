#include <stdio.h>
#include <stdlib.h>

int main()
{
    float num, sum;
    int count = 0;
    do{
        printf("Insira o numero: ");
        scanf("%f", &num);
        if(num < 10) sum += num;
        else if(num > 10) count++;
        else break;
    }while(num != 10);

    printf("soma dos menores que 10 = %f\n", sum);
    printf("quantidade de maiores que 10 = %d\n", count);
    system("pause");
    return 0;
}
