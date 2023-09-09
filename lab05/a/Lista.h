#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#define MAX 100
typedef struct aluno{
    int mat;
    char nome[30];
    float n1;
}Aluno;

typedef struct lista Lista;

Lista *criar();

int inserirInicio(Lista *l,Aluno it);
int inserirFim(Lista *l,Aluno it);
int inserirPosicao(Lista *l,Aluno it,int pos);
int removerInicio(Lista *l);
int removerFim(Lista *l);
int removerPosicao(Lista *l,int pos);
int removerItem(Lista *l,Aluno it);


void limpar(Lista *l);
int buscarItemChave(Lista *l,int chave,Aluno *retorno);
int buscarPosicao(Lista *l,int posicao,Aluno *it);
int listaVazia(Lista *l);
int listaCheia(Lista *l);
int tamanho(Lista *l);
void mostrar(Lista *l);

#endif // LISTA_H_INCLUDED
