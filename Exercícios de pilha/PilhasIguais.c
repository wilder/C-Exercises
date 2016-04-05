/*
2)Escreva uma função que receba como parâmetro duas pilhas e verifique de elas são iguais.
 Duas pilhas são iguais se possuem os mesmos elementos, na mesma ordem. 
*/

 bool equals(Pilha stack, Pilha stack2){
 	//Se o tamanho for diferente, não são iguais
 	if(length(&stack)!=length(&stack2)){
 		return false;
 	}

 	while(!isEmpty(&stack)){
 		if(pop(&stack)!=pop(&stack2)){
 			return false
 		}
 	}
 	//Nenhum dos elementos são diferentes, portanto as pilhas são iguais
 	return true;
 }