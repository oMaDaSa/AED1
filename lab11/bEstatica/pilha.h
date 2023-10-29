#define MAX 100

typedef struct pilha Pilha;

Pilha *criar();

void limpar(Pilha *p);

int push(Pilha *p, int it);

int pop(Pilha *p, int *it);

int consultar(Pilha *p, int *it);

int tamanho(Pilha *p);

int pilhaVazia(Pilha *p);

int pilhaCheia(Pilha *p);

void mostrar(Pilha *p);
