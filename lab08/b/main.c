#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

int main(){
    Lista *l = criar();
    Aluno aluno[5];
    
    for(int i = 0; i < 5; i++){
        aluno[i].mat = i;
    }
    aluno[0].n1 = 98;
    strcpy(aluno[0].nome,"Matheus");
    aluno[1].n1 = 64;
    strcpy(aluno[1].nome,"Miguel");
    aluno[2].n1 = 78;
    strcpy(aluno[2].nome,"Henrique");
    aluno[3].n1 = 89;
    strcpy(aluno[3].nome,"Vanessa");
    aluno[4].n1 = 88;
    strcpy(aluno[4].nome,"Felipe");

    for(int i = 0; i < 5; i++){
        inserirFim(l, aluno[i]);
    }

    printf("Antes da troca:\n");
    mostrar(l);
    fflush(stdin);
    getchar();
    trocar(l, 2, 4);
    printf("Apos a troca:\n");
    mostrar(l);

    fflush(stdin);
    getchar();
    return 0;
}