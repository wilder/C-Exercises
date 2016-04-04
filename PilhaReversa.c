/*
5)	Utilizando uma pilha resolver o exercício a seguir:
Dada uma sequência contendo N (N >0) números reais, imprimi-la na ordem inversa.
*/

void reverse(Pilha stack){
	tamanho = length(&stack);
	int reversa[tamanho];
	int i;
	//Armazenando elementos da pilha no vetor
	for(i = 0; i < tamanho; i++){
		reversa[i]=pop(&stack);
	}
	//Imprimindo elementos do vetor começando do último elemento
	for(i=tamanho-1; i >=0; i--){
		printf("%i", reversa[i]);
	}
}