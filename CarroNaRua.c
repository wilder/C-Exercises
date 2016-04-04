/*
4)	Construa um programa utilizando uma pilha que resolva o seguinte problema:
Armazene as placas dos carros (apenas os números) que estão estacionados numa rua sem saída estreita.
Dado uma placa verifique se o carro está estacionado na rua.
Caso esteja, informe a sequência de carros que deverá ser retirada para que o carro em questão consiga sair.
*/
#include <stdio.h>

bool carroNaRua(int placa, Pilha rua){
	char seq[sizeof rua*2];
	int carro = pop(&rua);
	if(carro==placa){
		print("Nenhum carro precisará ser retirado para o carro de placa %i sair",placa);
		return true;
	}

	strcat(seq, "%d", carro);
	while(!isEmpty(&rua)){
		carro = pop(&rua);
		if(carro!=placa){
			strcat(seq, " ");
			strcat(seq, "%d", carro);
		}else{
			printf("Sequência de carros a serem retirados:\n");
			printf("%s",seq);
			return true;
		}
	}
	return false;
}