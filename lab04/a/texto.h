#ifndef A_TEXTO_H
#define A_TEXTO_H

typedef struct Texto{
    char *conteudo;
    int tamanho;
}texto;

texto* criarTexto();
void passarTexto(texto *t, const char *s);
int tamanhoTexto(texto *t);
int ocorreTexto(texto *t, char c);
void printTexto(texto *t);

#endif //A_TEXTO_H
