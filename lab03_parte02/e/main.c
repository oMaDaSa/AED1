#include <stdio.h>
#include <stdlib.h>

/*Crie uma função que retorne um vetor alocado dinamicamente e preenchido com um valor passado como parâmetro*/

int *intPreenchido(int tamanho, int n);
float *floatPreenchido(int tamanho, float n);
char *charPreenchido(int tamanho, char n);
int menu();

int main(){
    int op, tamanho;
    int *vetorInt, valorInt;
    float *vetorFloat, valorFloat;
    char *vetorChar, valorChar;

    do{
        op = menu();
        if(op < 1 || op > 3){
            printf("Tipo invalido");
        }
    }while(op < 1 || op > 3);

    switch (op)
    {
        case 1:
            printf("Insira o tamanho do vetor: ");
            scanf("%d", &tamanho);
            printf("Insira o valor a preencher o valor: ");
            scanf("%d", &valorInt);
            vetorInt = (int*)intPreenchido(tamanho, valorInt);
            if(vetorInt != NULL) printf("Vetor de %d posicoes preenchido com %d's\n",tamanho, valorInt);
            break;
        case 2:
            printf("Insira o tamanho do vetor: ");
            scanf("%d", &tamanho);
            printf("Insira o valor a preencher o valor: ");
            scanf("%f", &valorFloat);
            vetorFloat = (float*)floatPreenchido(tamanho, valorFloat);
            if(vetorFloat != NULL) printf("Vetor de %d posicoes preenchido com %.2f's\n",tamanho, valorFloat);
            break;
        case 3:
            printf("Insira o tamanho do vetor: ");
            scanf("%d", &tamanho);
            printf("Insira o valor a preencher o valor: ");
            fflush(stdin);
            scanf("%c", &valorChar);
            vetorChar = (char*)charPreenchido(tamanho, valorChar);
            if(vetorChar != NULL) printf("Vetor de %d posicoes preenchido com %c's\n",tamanho, valorChar);
            break;
    }

    printf("\nAperte enter para sair ");
    
    free(vetorInt);
    free(vetorFloat);
    free(vetorChar);
    fflush(stdin);
    getchar();
    return 0;
}

int *intPreenchido(int tamanho, int n){
    int *vetor;
    vetor = (int*)malloc(tamanho*sizeof(int));
    for(int i=0; i<tamanho; i++){
        vetor[i] = n;
    }
    return vetor;
}

float *floatPreenchido(int tamanho, float n){
    float *vetor;
    vetor = (float*)malloc(tamanho*sizeof(int));
    for(int i=0; i<tamanho; i++){
        vetor[i] = n;
    }
    return vetor;
}
char *charPreenchido(int tamanho, char n){
    char *vetor;
    vetor = (char*)malloc(tamanho*sizeof(int));
    for(int i=0; i<tamanho; i++){
        vetor[i] = n;
    }
    return vetor;
}

int menu(){
    int op;

    printf("\n1 - int");
    printf("\n2 - float");
    printf("\n3 - char\n");
    printf("Insira o tipo do vetor: ");
    scanf("%d",&op);
    return op;
}