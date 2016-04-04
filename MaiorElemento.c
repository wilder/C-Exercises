/*
1)	Escrever uma função que receba como parâmetro uma pilha.
A função deve retornar o maior elemento da pilha. A passagem deve ser por valor ou referência?
R: A passagem deve ser por referência.
*/

int maiorElemento(Pilha stack){
	int maior, auxiliar;
	maior = stack.pop();
	while(!stack.isEmpty()){
		auxiliar = stack.pop();
		if(auxiliar >= maior){
			maior = auxiliar;
		}
	}
	return maior;
}

