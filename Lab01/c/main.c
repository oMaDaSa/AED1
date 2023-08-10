#include <stdio.h>
#include <stdlib.h>

int main()
{
    char op;
    float a, b, res;
    printf("Digite o valor a: ");
    scanf("%f", &a);
    setbuf(stdin, NULL);
    printf("Digite a operacao: ");
    scanf("%c", &op);
    printf("Digite o valor b: ");
    scanf("%f", &b);

    switch(op){
        case '+':
            res = a + b;
            break;
        case '-':
            res = a - b;
            break;
        case '*':
            res = a * b;
            break;
        case '/':
            res = a / b;
            break;
        default:
            printf("Operacao invalida\n");
            system("pause");
            return 0;
    }
    printf("%.2f %c %.2f = %.2f\n", a, op, b, res);
    system("pause");
    return 0;
}
