#ifndef E_HISTOGRAMA_H
#define E_HISTOGRAMA_H

typedef struct histograma histograma;
histograma *criar();
int verifica(histograma *h, char c);
void redimensiona(histograma *h);
void gera(histograma *h, const char *texto);
void mostra(histograma *h);
void ordena(histograma *h);

#endif //E_HISTOGRAMA_H
