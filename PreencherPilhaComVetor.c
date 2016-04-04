/*
3) Escreva uma função que preencha uma pilha passada como
 parâmetro com os elementos de um vetor passado como parâmetro
*/

 void pushArray(Pilha* stack, int array[30]){
 	int i;
 	int tamanho = sizeof array / sizeof array[0]
 	for(i = 0; i < tamanho; i++){
 		push(&stack,array[i]);
 	}
 }