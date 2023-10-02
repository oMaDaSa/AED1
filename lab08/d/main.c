#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

int main(){
    Lista *l = criar();
    Aluno aluno[15];
    
    for(int i = 0; i < 10; i++){
        aluno[i].n1 = (float)i+90;
    }

    //Inserindo testes para remocao
    aluno[0].mat = 74;
    strcpy(aluno[0].nome,"Matheus");

    aluno[1].mat = 64;
    strcpy(aluno[1].nome,"Miguel");

    aluno[2].mat = 78;
    strcpy(aluno[2].nome,"Henrique");

    aluno[3].mat = 89;
    strcpy(aluno[3].nome,"Vanessa");

    aluno[4].mat = 88;
    strcpy(aluno[4].nome,"Felipe");

    aluno[5].mat = 88;
    strcpy(aluno[5].nome,"Felipe");

    aluno[6].mat = 78;
    strcpy(aluno[6].nome,"Henrique");

    aluno[7].mat = 74;
    strcpy(aluno[7].nome,"Matheus");

    aluno[8].mat = 88;
    strcpy(aluno[8].nome,"Felipe");

    aluno[9].mat = 89;
    strcpy(aluno[9].nome,"Vanessa");

    aluno[10].mat = 88;
    strcpy(aluno[8].nome,"Felipe");

    aluno[11].mat = 64;
    strcpy(aluno[1].nome,"Miguel");

    aluno[12].mat = 64;
    strcpy(aluno[1].nome,"Miguel");

    aluno[13].mat = 64;
    strcpy(aluno[1].nome,"Miguel");

    aluno[14].mat = 74;
    strcpy(aluno[0].nome,"Matheus");
    
    
    for(int i = 0; i < 10; i++){
        inserirFim(l, aluno[i]);
    }

    printf("Antes das remocoes:\n");
    mostrar(l);
    removerRepeticoes(l);
    printf("Apos as remocoes:\n");
    mostrar(l);


    fflush(stdin);
    getchar();
    return 0;
}