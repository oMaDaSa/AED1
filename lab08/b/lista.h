#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct aluno{
    int mat;
    char nome[30];
    float n1;
}Aluno;

typedef struct lista Lista;

Lista *criar();
void limpar(Lista *l);
int listaVazia(Lista *l);
int inserirInicio(Lista *l, Aluno it);
int inserirFim(Lista *l, Aluno it);
int inserirPos(Lista *l, Aluno it, int pos);
int inserirOrdenado(Lista *l, Aluno it);
void mostrar(Lista *l);
int removerInicio(Lista *l);
int removerFim(Lista *l);
int removerPosicao(Lista *l, int pos);
int removerChave(Lista *l, int chave);
int maiorNota(Lista *l, Aluno *maiorNota);
int trocar(Lista *l, int pos1, int pos2);

#endif // LISTA_H_INCLUDED
