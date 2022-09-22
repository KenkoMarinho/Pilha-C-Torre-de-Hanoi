#ifndef __funcoes_hanoi_def_
#define __funcoes_hanoi_def_
#include "pilha.h"

int atoi_implementado(const char vet[]);

pilha* gerar_torre_inicial(int num_discos,pilha *variavel_pilha);

void solucionar_torre_hanoi_recursivo(pilha* A_source, pilha* C_target, pilha* B_auxiliary, int tamanho_inicial, int argc);



#endif