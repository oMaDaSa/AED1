#include <stdlib.h>
#include <stdio.h>
#include "matriz.h"

matriz *criar(const int m, const int n){
    matriz *mat = (matriz*)malloc(sizeof(matriz));
    mat->elemento = (float**)calloc(m,sizeof(float*));
    for(int i = 0; i < m; i++)
        mat->elemento[i] = (float*)calloc(n,sizeof(float));
    mat->m = m;
    mat->n = n;
    return mat;
}

matriz *destruir(matriz *mat){
    for(int i = 0; i < mat->m; i++){
        for(int j = 0; j < mat->n; j++){
            mat->elemento[i][j] = 0;
        }
    }
    for(int i = 0; i < mat->m; i++){
        free(mat->elemento[i]);
    }free(mat->elemento);
    free(mat);
    return NULL;
}

int atribuir(matriz *m, const float valor, const int i, const int j){
    if(i > m->m || j > m->n) return 1;
    m->elemento[i][j] = valor;
    return 0;
}

int acessar(matriz *m, float *recebe, const int i, const int j){
    if(i > m->m || j > m->n) return 1;
    *recebe = m->elemento[i][j];
    return 0;
}

void preencherAleatorio(matriz *m, const int min, const int max){
    for(int i = 0; i < m->m; i++){
        for(int j = 0; j < m->n; j++){
            m->elemento[i][j] = (rand()%(max*100) + min)/100.0;
        }
    }
}

int somar(matriz *m1, matriz *m2, matriz *soma){
    int m = m1->m, n = m1->n;;
    if(m2->m != m || m2->m != n) return 1;
    soma->elemento = realloc(soma->elemento, m1->m * sizeof(float*));

    for(int i = 0; i < m; i++){
        soma->elemento[i] = realloc(soma->elemento[i], n * sizeof(float));
    }
    soma->m = m;
    soma->n = m;

    for(int i = 0; i < m1->m; i++){
        for(int j = 0; j < m1->n; j++){
            atribuir(soma, (m1->elemento[i][j] + m2->elemento[i][j]),i, j);
        }
    }
    return 0;
}

void printMatriz(matriz *mat){
    for(int i = 0; i < mat->m; i++){
        for(int j = 0; j < mat->n; j++){
            printf("%.2f ", mat->elemento[i][j]);
        }
        printf("\n");
    }
}