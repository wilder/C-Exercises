/*
1)	Escrever uma função que receba como parâmetro uma pilha.
A função deve retornar o maior elemento da pilha. A passagem deve ser por valor ou referência?
R: A passagem deve ser por valor.
*/

int maiorElemento(Pilha stack){
	int maior, auxiliar;
	maior = pop(&stack);
	while(!isEmpty(&stack)){
		auxiliar = pop(&stack);
		if(auxiliar >= maior){
			maior = auxiliar;
		}
	}
	return maior;
}

