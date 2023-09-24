#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#define MAX 10

typedef struct cidade
{
    char nome[100], sigla[3];
}Cidade;

typedef struct rota
{
    Cidade origem, destino;
    float preco;
}Rota;

typedef struct lista Lista;

Lista *criar();

void limpar(Lista *l);

int inserirInicio(Lista *l,void *it, int tipo);

int inserirFim(Lista *l,void *it, int tipo);

int inserirPosicao(Lista *l,void *it, int tipo, int pos);

int removerInicio(Lista *l);

int removerFim(Lista *l);

int removerPosicao(Lista *l,int pos);

int removerItem(Lista *l,void *it, int tipo);

int buscarItemChave(Lista *l,int chave,void *it, int tipo);

int buscarPosicao(Lista *l, int posicao,void *it, int tipo);

int listaVazia(Lista *l);

int listaCheia(Lista *l);

int tamanho(Lista *l);

void mostrarCidades(Lista *l);

void mostrarRotas(Lista *l);

int removerPosicao(Lista *l, int pos);

int removerItem(Lista *l, void *it, int tipo);

int buscarPosicao(Lista *l, int posicao, void *it, int tipo);

int contemItem(Lista *l, void *it, int tipo);

int removerNPrimeiros(Lista *l, int qtd);

int rotaBarata(Lista *l, Rota *retorno);

int rotaCara(Lista *l, Rota *retorno);

int consulta(Lista *l, const char *a, const char *b, float *valor);

#endif // LISTA_H_INCLUDED
