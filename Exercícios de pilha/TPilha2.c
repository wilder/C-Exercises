/*
7)	Escreva uma função chamada TPilha2 que recebe como parâmetro 2 pilhas (N e P) e um vetor de inteiros. Para cada um:
- se positivo, inserir na pilha P;
- se negativo, inserir na pilha N;
- se zero, retirar um elemento de cada pilha.
*/

void TPilha2(Pilha N, Pilha P, int array[]){	
	int tamanho = sizeof array / sizeof array[0];
	for(i = 0; i<tamanho; i++){
		if(i>0){
			push(&P, array[i]);
		}else if(i<0){
			push(&N, array[i]);
		}else{
			pop(&P);
			pop(&N);
		}
	}
}