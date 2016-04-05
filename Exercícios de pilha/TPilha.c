/*
6)	Implemente uma função chamada TPilha, que receba um vetor de inteiros com 15 elementos. Para cada um deles, como segue:
- se o número for par, insira-o na pilha;
- se o número lido for ímpar, retire um número da pilha;
- Ao final, esvazie a pilha imprimindo os elementos.
*/

void TPilha(int array[15]){
	Pilha stack;
	int i;
	for(i = 0; i<15; i++){
		if(i%2==0){
			push(&stack, array[i]);
		}else{
			if(!isEmpty(&stack)){
				pop(&stack);
			}	
		}
	}
	while(!isEmpty(&stack)){
		printf("%d",&pop);
	}
}