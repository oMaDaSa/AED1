#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

int menu();
int cadastrarAluno(Aluno *it);

int main(){
    Lista *l = criar();
    Aluno alunoTemp;
    int op, matTemp;

    do{
        op = menu();
        switch(op){
            case 1:
                cadastrarAluno(&alunoTemp);
                inserirOrdenado(l, alunoTemp);
                break;
            case 2:
                printf("Insira a matricula do aluno a ser removido: ");
                scanf("%d",&matTemp);
                if(removerChave(l, matTemp) == 0)
                    printf("Aluno %d removido\n", matTemp);
                else
                    printf("Aluno nao encontrado\n");
                break;
            case 3:
                mostrar(l);
                break;
            case 4:
                maiorNota(l, &alunoTemp);
                printf("{%d,%s,%.2f}",alunoTemp.mat, alunoTemp.nome, alunoTemp.n1);
                break;
            case 5:
                limpar(l);
                break;
            case 6:
                break;
            default:
                printf("Opcao invalida\n");
        }
        fflush(stdin);
        getchar();
        system("cls");
    }while(op != 6);
    free(l);
    return 0;
}

int menu(){
    int op;
	printf("1-Cadastrar aluno\n");
	printf("2-Remover aluno\n");
	printf("3-Listar alunos cadastrados\n");
	printf("4-Mostrar dados do aluno com maior nota\n");
	printf("5-Remover todos os alunos\n");
	printf("6-Sair\n");
	printf("Insira uma opcao: ");
    scanf("%d",&op);
    return op;
}

int cadastrarAluno(Aluno *it){
    int mat;
    float n1;
    char nome[30];

    printf("Insira a matricula: ");
    scanf("%d",&mat);
    it->mat = mat;
    printf("Insira o nome: ");
    fflush(stdin);
    fgets(nome, 30, stdin);
    nome[strlen(nome)-1] = '\0';
    strcpy(it->nome, nome);
    printf("Insira a nota final: ");
    scanf("%f",&n1);
    it->n1 = n1;
    return 0;
}