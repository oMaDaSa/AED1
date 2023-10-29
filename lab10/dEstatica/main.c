#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include <string.h>

void imprimeMenu();
int adicionarPaciente(Fila *f, int *qtd);
int chamarPaciente(Fila *f, Paciente *p);

int main(){
    Fila *filaDeAtendimento = criar();

    int opcao, posFila = 0;
    Paciente paciente;
    do{
        imprimeMenu();
        scanf("%d",&opcao);

        switch(opcao){
        case 1:
            adicionarPaciente(filaDeAtendimento, &posFila);
            break;
        case 2:
            if(chamarPaciente(filaDeAtendimento, &paciente) == 0){
                paciente.nome[strlen(paciente.nome)-1] = '\0';
                printf("%s!!!\n",strupr(paciente.nome));
            }else printf("Sem pacientes na fila de espera...\n");
            break;
        case 3:
            mostrar(filaDeAtendimento);
            break;
        case 4:
            printf("Expediente concluido...\n");
            limpar(filaDeAtendimento);
            break;
        default:
            printf("Invalido");
            break;
        }
        system("pause");
    }while(opcao!=4);
    return 0;
}

void imprimeMenu(){
    system("cls");
    printf("1 - Adicionar paciente\n");
    printf("2 - Chamar proximo\n");
    printf("3 - Mostrar fila\n");
    printf("4 - Encerrar o dia\n");
    printf("Inserir opcao: ");
}

int adicionarPaciente(Fila *f, int *qtd){
    Paciente p;
    char nome[60];

    printf("Insira o nome do paciente: ");
    fflush(stdin);
    fgets(nome, 60, stdin);
    strcpy(p.nome, nome);
    p.senha = ++(*qtd);
    inserir(f, p);
    return 0;
}

int chamarPaciente(Fila *f, Paciente *p){
    if(filaVazia(f) == 0) return 1;
    else remover(f, p);
    return 0;
}