#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

int main(){
    const int max = 10;
    int op;
    Lista *l1 = criar(), *l2 = criar();
    Aluno aluno[max], teste;
    
    for(int i = 0; i < max; i++){
        aluno[i].mat = i;
        aluno[i].n1 = i + 1;
        strcpy(aluno[i].nome, "fulano");
    }

    teste.mat = 12221;
    strcpy(teste.nome,"Matheus");
    teste.n1 = 64;
    
    /*
    strcpy(aluno[1].nome,"Miguel");
    aluno[2].n1 = 78;
    strcpy(aluno[2].nome,"Henrique");
    aluno[3].n1 = 89;
    strcpy(aluno[3].nome,"Vanessa");
    aluno[4].n1 = 88;
    strcpy(aluno[4].nome,"Felipe");
    */
    
    for(int i = 0; i < max; i++){
        inserirFim(l1, aluno[i]);
    }
    for(int i = 9; i >= 0; i--){
        inserirFim(l2, aluno[i]);
    }

    printf("Inserir elemento para tornar listas diferentes?\n");
    printf("[1-sim][2-nao]\n");
    scanf("%d",&op);
    if(op == 1) inserirFim(l1, teste);

    printf("Lista 1:\n");
    mostrar(l1);
    printf("Lista 2:\n");
    mostrar(l2);

    if(listasEquivalentes(l1, l2) == 0){
        printf("Listas sao equivalentes\n");
    }else{
        printf("Listas nao sao equivalentes\n");
    }

    fflush(stdin);
    getchar();
    return 0;
}