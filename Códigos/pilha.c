#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "funcoes_hanoi.h"

typedef struct pilha pilha;
struct pilha
{
	char nomepilha;
	info_t *vetor;
	int tam_pilha;
};

pilha* create(char nomefornecido) /*Create: Criac¸˜ao (alocac¸˜ao) de pilhas vazias.*/
{
	pilha *variavel_pilha=malloc(sizeof(pilha));
	variavel_pilha->nomepilha=nomefornecido;
	variavel_pilha->tam_pilha=0;
	variavel_pilha->vetor = (info_t*) malloc(sizeof(info_t)* 100);
	return variavel_pilha;
}

int size(pilha *variavel_pilha) /*retorna o tamanho da pilha*/
{
	return variavel_pilha->tam_pilha;
}
void push(pilha *variavel_pilha,info_t valor_inserido)  /*Push: Inserir um elemento no topo da pilha*/
{
	variavel_pilha->vetor[size(variavel_pilha)]=valor_inserido;
	variavel_pilha->tam_pilha+=1;
}

char PRINTARONOMEDAPILHA(pilha* p) {
	return p->nomepilha;
}

info_t pop(pilha *variavel_pilha) /*Remover o elemento do topo da pilha.*/
{
	info_t variavel;
	variavel=variavel_pilha->vetor[size(variavel_pilha)-1];
	variavel_pilha->tam_pilha=variavel_pilha->tam_pilha-1;
	/*acho que isso aqui libera o espaço de memória que topo está apontando. do contrário, use a variavel tam_pilha para encontrar o topo da pilha.*/
	return variavel;
}

info_t peek(pilha *variavel_pilha) /*Peek: Inspecionar o elemento do topo da pilha mas sem remover.*/
{
	return variavel_pilha->vetor[size(variavel_pilha)-1];
}

void printar_pilha(pilha *variavel_pilha,int argc)/*printa a pilha toda no Terminal.*/
{
	if (argc>=3)
	{
		int i;
		printf("\n");
		printf("%c: ", variavel_pilha->nomepilha);		/*WARN: LEMBRAR DE AJUSTAR A SAÍDA PARA CORREÇÃO AUTOMATIZADA*/
		for(i=0;i<variavel_pilha->tam_pilha;i++)
		{
			printf("%d ",variavel_pilha->vetor[i]);
		}
		printf("\n");
	}
}

void clear(pilha *variavel_pilha)
{
	int i=0;
	for(i=0;i<variavel_pilha->tam_pilha;i++)
	{
		pop(variavel_pilha);
	}
}

/*
1. Create: Criacao (alocacao) de pilhas vazias.
2. Size: Tamanho da pilha.
3. Push: Inserir um elemento no topo da pilha.
4. Pop: Remover o elemento do topo da pilha.
5. Peek: Inspecionar o elemento do topo da pilha mas sem remover.
6. Print: Imprimir o conte´udo da pilha no terminal.
*/