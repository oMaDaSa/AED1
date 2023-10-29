#define MAX 100

typedef struct fila Fila;

typedef struct paciente{
    char nome[60];
    int senha;
} Paciente;

Fila *criar();
void limpar(Fila *f);
int inserir(Fila *f, Paciente it);
int remover(Fila *f, Paciente *it);
int consultar( Fila *f, Paciente *it);
int tamanho(Fila *f);
int filaVazia(Fila *f);
void mostrar(Fila *f);