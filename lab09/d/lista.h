#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct No{
    int valor;
    struct No *prox;
}No;

typedef No* Lista;

Lista* criar();
int listaVazia(Lista *l);
int inserirInicio(Lista *l, int x);
int inserirFim(Lista *l, int x);
int removerInicio(Lista *l);
void mostrar(Lista *l);
int listaVazia(Lista *l);
int removerItem(Lista *l, int x);

#endif //LISTA_H_INCLUDED