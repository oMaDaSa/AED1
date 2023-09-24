#ifndef A_LISTA_H
#define A_LISTA_H

typedef struct aluno{
    int mat;
    char nome[30];
    float n1;
}Aluno;
typedef struct lista Lista;
Lista *criar();
void limpar(Lista *l);
int inserirInicio(Lista *l,Aluno it);
int inserirFim(Lista *l,Aluno it);
int inserirPosicao(Lista *l, Aluno it,int pos);
int removerInicio(Lista *l);
int removerFim(Lista *l);
int removerPosicao(Lista *l,int pos);
int removerItem(Lista *l,int it);
int buscarItemChave(Lista *l, int chave, Aluno *retorno);
int buscarPosicao(Lista *l,int posicao,int *retorno);
int listaVazia(Lista *l);
int listaCheia(Lista *l);
int tamanho(Lista *l);
void mostrar(Lista *l);

int removerMeio(Lista *l);

int removerItemChave(Lista *l, int chave);

int removerItem(Lista *l, int it);

Lista* interseccao(Lista *l1, Lista *l2);

int contaOcorrencia(Lista *l, Aluno it);

int inserirFimSemRepeticao(Lista *l, Aluno it);

#endif //A_LISTA_H
