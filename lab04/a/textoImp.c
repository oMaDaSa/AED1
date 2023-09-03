#include "texto.h"

texto* criarTexto(){
    texto *t = (texto*)malloc(sizeof(texto));
    t->conteudo = (char*)malloc(sizeof(char));
    return t;
}
void passarTexto(texto *t, const char *s){
    int i;
    for(i = 0; s[i] != '\0'; i++);
    t->tamanho = i-1;

    t->conteudo =  realloc(t->conteudo,(t->tamanho)*sizeof(char));
    for(i = 0; i < (t->tamanho); i++)
        t->conteudo[i] = s[i];
    t->conteudo[i] = '\0';
}
int tamanhoTexto(texto *t){
    return t->tamanho;
}
int ocorreTexto(texto *t, char c){
    int ocorre = 0, i;
    for(i = 0; i < (t->tamanho); i++){
        if(t->conteudo[i] == c) ocorre++;
    }
    return ocorre;
}
void printTexto(texto *t){
    printf("%s\n",t->conteudo);
}