#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"



int atoi_implementado(const char vet[])
{
    int retorno = 0;
 
    int i = 0;
    while ((vet[i] >= '0' && vet[i] <= '9')&&vet[i])
    {
		retorno=retorno*10;
		retorno=retorno+(vet[i] - '0');
        i++;
    }
	/*printf("%d",retorno);*/
    return retorno;
}

pilha* gerar_torre_inicial(int num_discos,pilha *variavel_pilha)
{
	int i;
	for(i=0;i<num_discos;i++)
	{
		push(variavel_pilha, num_discos-i);
	}
	return 0;
}


void solucionar_torre_hanoi_recursivo(pilha* A_source, pilha* C_target, pilha* B_auxiliary,int tamanho_inicial, int argc)
{
 
    if (tamanho_inicial == 1)
    {
        if (argc >= 3) {
            printf("Move disk %d", peek(A_source));
            printf(" from %c", PRINTARONOMEDAPILHA(A_source));
            printf(" to %c\n", PRINTARONOMEDAPILHA(C_target));
        }
        push(C_target, pop(A_source));
    }
    else
    {
        solucionar_torre_hanoi_recursivo(A_source, B_auxiliary, C_target, tamanho_inicial - 1, argc);
        solucionar_torre_hanoi_recursivo(A_source, C_target, B_auxiliary, 1, argc);
        solucionar_torre_hanoi_recursivo(B_auxiliary, C_target, A_source, tamanho_inicial - 1, argc);
    }
}



/*

Para um número par de discos:
fazer o movimento legal entre os pinos A e B (em qualquer direção),
fazer o movimento legal entre os pinos A e C (em qualquer direção),
fazer o movimento legal entre os pinos B e C (em qualquer direção),
repita até completar.

Para um número ímpar de discos:
fazer o movimento legal entre os pinos A e C (em qualquer direção),
fazer o movimento legal entre os pinos A e B (em qualquer direção),
fazer o movimento legal entre os pinos B e C (em qualquer direção),
repita até completar.

*/