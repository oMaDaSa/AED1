#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#define MAX 10

typedef struct aluno
{
    int mat;
    char nome[100];
    float n1;
} Aluno;

typedef struct lista Lista;

Lista *criar();

void limpar(Lista *l);

int inserirInicio(Lista *l,Aluno it);

int inserirFim(Lista *l,Aluno it);

int inserirPosicao(Lista *l,Aluno it,int pos);

int removerInicio(Lista *l);

int removerFim(Lista *l);

int removerPosicao(Lista *l,int pos);

int removerItem(Lista *l,Aluno it);

int buscarItemChave(Lista *l,int chave,Aluno*retorno);

int buscarPosicao(Lista *l, int posicao,Aluno *retorno);

int listaVazia(Lista *l);

int listaCheia(Lista *l);

int tamanho(Lista *l);

void mostrar(Lista *l);

int removerPosicao(Lista *l, int pos);

int removerItem(Lista *l, Aluno it);

int buscarPosicao(Lista *l, int posicao, Aluno *retorno);

int contemItem(Lista *l, Aluno it);

Lista *concatena(Lista *l1, Lista *l2);

void mostrarAluno(Aluno *a);

int maiorNotas(Lista *l);

int removerNPrimeiros(Lista *l, int qtd);

#endif // LISTA_H_INCLUDED
