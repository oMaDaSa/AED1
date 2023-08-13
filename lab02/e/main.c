#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*Construa um programa que utilize um vetor de clientes, cujo tamanho é definido pelo usuário no início da execução do
programa, e ofereça as seguintes opções ao usuário: (i) inserir cliente no vetor; (ii) remover cliente do vetor (usar a
posição do vetor); (iii) mostrar os CPFs dos clientes já inseridos. Para cada cliente devem ser armazenados o seu CPF, 
seu estado civil e uma relação com os nomes dos filhos do mesmo, se houver (utilize um struct). A lista pode conter
uma quantidade qualquer de clientes (informado pelo usuário). Cada cliente pode possuir uma quantidade arbitrária de
filhos (informado pelo usuário*/

typedef struct cliente{
    char cpf[12], estadoCivil[20];
    int qtdFilhos;
    char **nomeFilho;

}cliente;

void printMenu();
void adicionarCliente(cliente *clientes);
void moverClientes(cliente *clientes, int posCliente, int nClientes);
void removerCliente(cliente *clientes, int posCliente);

int main(){
    int nClientes, opMenu, posCliente;
    cliente *clientes;

    printf("Insira a quantidade de clientes iniciais: ");
    scanf("%d",&nClientes);
    clientes = (cliente*)malloc(nClientes*sizeof(cliente));

    for(int i=0; i<nClientes; i++){
        printf("Inserindo o cliente %d: \n",i+1);
        adicionarCliente(&clientes[i]);
    }

    do{
        printMenu();
        printf("\nEscolha uma opcao: ");
        scanf("%d",&opMenu);
        switch(opMenu){
            case 4:
                break;
            case 1:
                clientes = (cliente*)realloc(clientes, (++nClientes)*sizeof(cliente));
                adicionarCliente(&clientes[nClientes-1]);
                break;
            case 2:
                printf("\n");
                if(nClientes == 0){
                    printf("Nao ha clientes cadastrados\n\n");
                }else{
                    for(int i = 0; i < nClientes; i++){
                        printf("%d - %s\n", i+1, clientes[i].cpf);
                    }
                    do{
                        printf("Insira o cliente a remover: ");
                        scanf("%d", &posCliente);
                        if(posCliente < 1 || posCliente > nClientes){
                            printf("Posicao invalida\n");
                        }
                    }while(posCliente < 1 || posCliente > nClientes);
                    posCliente--;
                    nClientes--;
                    if(posCliente != nClientes){
                        moverClientes(clientes, posCliente, nClientes);
                        removerCliente(clientes, nClientes);
                    }
                    clientes = (cliente*)realloc(clientes, (nClientes)*sizeof(cliente));
                }
                break;
            case 3:
                for(int i = 0; i < nClientes; i++){
                    printf("%d - %s\n", i+1, clientes[i].cpf);
                }
                printf("\n");
                fflush(stdin);
                getchar();
                break;
            default:
                printf("Opcao invalida\n");
                fflush(stdin);
                getchar();
                system("cls");
        }
    }while(opMenu != 4);
    free(clientes);
    return 0;
}

void printMenu(){
    printf("1 - Inserir cliente\n");
    printf("2 - Remover cliente\n");
    printf("3 - Mostrar os CPF's\n");
    printf("4 - Sair\n");
}

void adicionarCliente(cliente *clientes){
    printf("CPF: ");
    fflush(stdin);
    fgets(clientes->cpf, 12, stdin);
    clientes->cpf[strlen(clientes->cpf)-1]='\0';

    printf("Estado Civil: ");
    fflush(stdin);
    fgets(clientes->estadoCivil, 12, stdin);
    clientes->estadoCivil[strlen(clientes->estadoCivil)-1]='\0';

    printf("Quantidade de filhos: ");
    if(scanf("%d",&clientes->qtdFilhos) > 0){
        clientes->nomeFilho = (char**)malloc(clientes->qtdFilhos*sizeof(char*));
        for(int j = 0; j < clientes->qtdFilhos; j++){
            clientes->nomeFilho[j] = (char*)malloc(100*sizeof(char));
        }
    }

    for(int j = 0; j < clientes->qtdFilhos; j++){
        printf("Nome do filho %d: ",j+1);
        fflush(stdin);
        fgets(clientes->nomeFilho[j], 100, stdin);
        clientes->nomeFilho[j][strlen(clientes->nomeFilho[j])-1]='\0';
    }
}

void removerCliente(cliente *clientes, int posCliente){
    if(clientes[posCliente].qtdFilhos != 0){
        for(int j = 0; j < clientes[posCliente].qtdFilhos; j++){
            free(clientes[posCliente].nomeFilho[j]);
        }
        free(clientes[posCliente].nomeFilho);
    }
    free(&clientes[posCliente]);
}

void moverClientes(cliente *clientes, int posCliente, int nClientes){
    for(int i = posCliente; i < nClientes; i++){
        for(int j = 0; clientes[i+1].cpf[j] != '\0'; j++)
            clientes[i].cpf[j] = clientes[i+1].cpf[j];
        for(int j = 0; clientes[i+1].estadoCivil[j] != '\0'; j++)
            clientes[i].estadoCivil[j] = clientes[j+1].estadoCivil[j];
        clientes[i].qtdFilhos = clientes[i+1].qtdFilhos;
        for(int j=0; j<clientes[i].qtdFilhos; j++)
            for(int k=0; clientes[j+1].nomeFilho[k][j] != '\0'; k++){
                clientes[i].nomeFilho[k][j] = clientes[i+1].nomeFilho[k][j];
            }   
    }
}