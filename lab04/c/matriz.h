#ifndef C_MATRIZ_H
#define C_MATRIZ_H

typedef struct Matriz{
    float **elemento;
    int m, n;
}matriz;
matriz *criar(const int m, const int n);
matriz *destruir(matriz *mat);
int atribuir(matriz *m, const float valor, const int i, const int j);
int acessar(matriz *m, float *recebe, const int i, const int j);
void preencherAleatorio(matriz *m, const int min, const int max);
int somar(matriz *m1, matriz *m2, matriz *soma);
void printMatriz(matriz *mat);


#endif //C_MATRIZ_H
