#include <stdio.h>
#include <stdio.h>
#include <math.h>

/*a) Escreva uma fun��o que receba como par�metro um n�mero inteiro positivo N e retorne a soma de todos os n�meros
inteiros de 1 a N*/
int somaUmN(int n, int *resA);

/*b) Fa�a uma fun��o que calcule X elevado � Y (XY), sem utilizar a fun��o pow. No programa principal, leia 2 valores de X
e Y e exiba o resultado da chamada da sub-rotina na tela*/
int elevado(int x, int y, long long int *resB);

/*c) Fa�a uma fun��o para aproximar a fun��o exponencial pela s�rie de Taylor (DICA: utilize a fun��o de exponencia��o
criada no exerc�cio*/
long long int fatorial(int n);
double taylor(int x, int n, double *resC);

/*d) Construa uma fun��o que receba dois valores inteiros a e b, e retorne o quociente e o resto da divis�o de a por b. Utilize
passagem de par�metro por refer�ncia para retornar os resultados. A fun��o deve retornar -1 caso n�o seja poss�vel
realizar as opera��es e 0 caso seja poss�vel. Crie um programa que utilize a fun��o criada, tratando o retorno da fun��o.*/
int divisao(int a, int b, int *quociente, int *resto);

/*e) Crie um programa para calcular a �rea e o per�metro de um hex�gono. O seu programa deve implementar uma fun��o
chamada calculaHexagono que calcule e retorne a �rea e o per�metro de um hex�gono regular de lado L. A fun��o
deve obedecer o seguinte prot�tipo: void calculaHexagono(float l, float *area, float *perimetro);*/

int calculaHexagono(float l, float *area, float *perimetro); //mudan�a de void para int para informar erro em caso de lado <= 0

int main(){
    int n, resA;
    int x, y;
    long long resB;
    int n2, x2;
    double resC;
    int a, b, quociente, resto;
    float lado, area, perimetro;

    //a
    printf("a)\nInsira o valor de n: ");
    scanf("%d", &n);
    if(somaUmN(n,&resA) == -1) printf("Numero invalido\n");
    else (printf("%d\n\n", resA) == -1);

    //b
    printf("b)\nInsira o valor de x: ");
    scanf("%d", &x);
    printf("Insira o valor de y: ");
    scanf("%d", &y);
    if(elevado(x, y, &resB) == -1) printf("Numero invalido\n");
    else printf("Resultado = %lld\n\n", resB);

    //c
    printf("c)\nInsira o valor de x: ");
    scanf("%d", &x2);
    printf("Insira o valor de n: ");
    scanf("%d", &n2);
    taylor(x2,n2,&resC);
    printf("Resultado = %.3lf\n\n", resC);

    //d
    printf("d)\nInsira o valor de a: ");
    scanf("%d", &a);
    printf("Insira o valor de b: ");
    scanf("%d", &b);
    if(divisao(a,b,&quociente, &resto) == -1) printf("Divisao por 0 (indefinido)\n");
    else{
        printf("Quociente = %d\n", quociente);
        printf("Resto = %d\n\n", resto);
    }

    //e
    printf("e)\nInsira o valor do lado: ");
    scanf("%f", &lado);
    if(calculaHexagono(lado, &area, &perimetro) == -1) printf("Lado invalido\n");
    else{
        printf("Area = %.2f\n", area);
    printf("Perimetro = %.1f\n\n", perimetro);
    }

    fflush(stdin);
    getchar();
    return 0;
}

int somaUmN(int n, int *resA){
    int i, soma = 0;
    if(n <= 0){
        return -1;
    }
    for(i = 1; i <= n; i++){
        soma += i;
    }
    *resA = soma;
    return 0;
}

int elevado(int x, int y, long long int *resB){
    long long int expo = x;
    if(y == 0 && x != 0) expo = 1;
    else if(y > 0){
        for(int i = 2; i < y+1; i++){
            expo *= x;
        }
    }else{
        return -1;
    }
    *resB = expo;
    return 0;
}


long long int fatorial(int n){
    long long int fat;
    if(n <= 1){
        return 1;
    }else{
        fat = n * fatorial(n-1);
        return fat;
    }
}

double taylor(int x, int n, double *resC){
    double ex = 1+x;
    long long int el;
    for(int i = 1; i < n+1; i++){
        elevado(x, i+1, &el);
        ex += (el*(1.0)/(fatorial((i+1))));
    }
    *resC = ex;
    return 1;
}

int divisao(int a, int b, int *quociente, int *resto){
    if(b == 0) return -1;
    *quociente = a/b;
    *resto = a-(b*(*quociente));
    return 0;
}

int calculaHexagono(float l, float *area, float *perimetro){
    if(l <= 0) return -1;
    *area = 6*((l*l*sqrt(3))/4);
    *perimetro = 6*l;
    return 0;
}
