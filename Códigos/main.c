#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "funcoes_hanoi.h"

#include <unistd.h>
#include <time.h>    
#define BILLION  1000000000.0

int main(int argc,char*argv[])
{

	double time_spent;
	struct timespec startTime, endTime;
	clock_gettime(CLOCK_REALTIME,&startTime);
	
	
	pilha *pilhaA=create('A');
	pilha *pilhaB=create('B');
	pilha *pilhaC=create('C');
	gerar_torre_inicial(atoi_implementado(argv[1]),pilhaA); /*isso lê o que o lamas inputar quando chamar o código, converte pra inteiro e joga pra ser o número de discord da torre A*/
	if (argc >= 3){
		printar_pilha(pilhaA,argc);
		printar_pilha(pilhaB,argc);
		printar_pilha(pilhaC,argc);
	}
	solucionar_torre_hanoi_recursivo(pilhaA, pilhaC,pilhaB, atoi_implementado(argv[1]), argc);
	if (argc >= 3){
	printar_pilha(pilhaA,argc);
	printar_pilha(pilhaB,argc);
	printar_pilha(pilhaC,argc);
	}
	
	
	clock_gettime(CLOCK_REALTIME,&endTime);	
	time_spent = (endTime.tv_sec - startTime.tv_sec) +
	(endTime.tv_nsec - startTime.tv_nsec) / BILLION;
	
	if (argc == 2){
		printf("tempo de execucao: %f\n" , time_spent);
	}
	
	clear(pilhaA);
	clear(pilhaB);
	clear(pilhaC);
	return 0;
} 

/*
LEMBRAR DE AJUSTAR O CÓDIGO PARA CORREÇÃO AUTOMÁTICA
LEMBRAR DE AJUSTAR PARA SÓ MOSTRAR O TEMPO DE EXECUÇÃO QUANDO NÃO PRINTAR NADA. 
*/