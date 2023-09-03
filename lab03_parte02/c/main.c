#include <stdio.h>
#include <stdlib.h>

/*Utilize a fun��o troca (swap) apresentada no slide te�rico da disciplina em uma outra fun��o que recebe como
par�metro um vetor e seu tamanho, e inverte os valores desse vetor. Assim, caso o vetor informado contenha os valores
1,3,6,5,8, o resultado ser� 8,5,6,3,1.*/

int inverte(int *vetor, int tamanho);
int swap(int *a, int *b);
void printaVetor(int *vetor, int tamanho);

int main(){
    int tamanho, *vetor;
    printf("Insira o tamanho do vetor: ");
    scanf("%d",&tamanho);
    vetor = (int*)malloc(tamanho*sizeof(int));
    for(int i = 0; i < tamanho; i++){
       printf("Insira o valor vetor[%d]: ",i);
       scanf("%d",&vetor[i]);
    }
    inverte(vetor, tamanho);
    printaVetor(vetor, tamanho);

    fflush(stdin);
    getchar();
    return 0;
}

int inverte(int *vetor, int tamanho){
    for(int i = 0; i < tamanho/2; i++){
        swap(&vetor[i],&vetor[tamanho-1-i]);
    }
}

void printaVetor(int *vetor, int tamanho){
    for(int i = 0; i < tamanho; i++){
        printf("%d ",vetor[i]);
    }
}

int swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
    return 0;
}
