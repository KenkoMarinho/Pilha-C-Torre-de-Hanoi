#ifndef __pilha_def_
#define __pilha_def_

typedef int info_t;

typedef struct pilha pilha;

pilha* create(char nomefornecido);

void push(pilha *variavel_pilha,info_t valor_inserido);

int size(pilha *variavel_pilha);

int pop(pilha *variavel_pilha);

char PRINTARONOMEDAPILHA(pilha* p);

int peek(pilha *variavel_pilha);

void printar_pilha(pilha *variavel_pilha,int argc);

void clear(pilha *variavel_pilha);

#endif