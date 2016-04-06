#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{	char nome[50];
	int codigo;
	float preco;
	bool ativo;	
}Pizza;
  

/*
Objetivo: Cadastra pizza com os valores digitados pelo usuário no vetor de struct.
Parâmetros:
pizzas[] -> Parâmetro do tipo "Pizza". É onde os dados digitados pelo usuário serão armazenados. Passagem por referência (pois essa variável será alterada na função). 
quantidade -> Parâmetro inteiro. Possui o valor do tamanho do vetor, ou quantidade de "Pizzas" que serão cadastradas. Passagem por valor (pois essa variável não será alterada na função).
*/
void inserir(Pizza pizzas[], int quantidade)
{
	int i;
	for(i = 0; i < quantidade; ++i)
	{
		fflush(stdin);
		printf("Sabor da pizza: \n");
		fgets(pizzas[i].nome, sizeof pizzas[i].nome , stdin);
		fflush(stdin);
		printf("Valor da pizza: \n");
		scanf("%f",&pizzas[i].preco);
		fflush(stdin);
		pizzas[i].ativo = true;
		pizzas[i].codigo = i;
	}
}

/*
Objetivo: Procura pizza cadastrada por código e retorna um ponteiro da pizza encontrada.
Parâmetros:
pizzas[] -> Parâmetro do tipo "Pizza". É onde a "Pizza" será procurada. Passagem por referência (pois é um vetor). 
codigo ->  Parâmetro do tipo inteito. Código da "Pizza" a ser encontrada. Passagem por valor (pois essa variável não será alterada na função).
tamanho ->  Parâmetro do tipo inteito. Tamanho do vetor de "Pizzas". Passagem por valor (pois essa variável não será alterada na função).
*/
Pizza* procurar(Pizza pizzas[], int codigo, int tamanho)
{
	Pizza *pizzaProcurada;
	for (int i = 0; i < tamanho; ++i)
	{
		if(pizzas[i].ativo && pizzas[i].codigo==codigo){
			pizzaProcurada = &pizzas[i];
			printf("%s",pizzas[i].nome);
			return pizzaProcurada;
		}
	}
	printf("\nPizza não encontrada\n");
	return pizzaProcurada;
}

/*
Objetivo: Procura pizza por código e faz um delete lógico caso encontrado.
Parâmetros:
pizzas[] -> Parâmetro do tipo "Pizza". É onde a "Pizza" será procurada. Passagem por referência (pois a "Pizza" encontrada será alterada na função). 
codigo ->  Parâmetro do tipo inteito. Código da "Pizza" a ser encontrada. Passagem por valor (pois essa variável não será alterada na função).
tamanho ->  Parâmetro do tipo inteito. Tamanho do vetor de "Pizzas". Passagem por valor (pois essa variável não será alterada na função).
*/
void excluir(Pizza pizzas[], int codigo, int tamanho)
{
	Pizza *pizza_a_deletar = procurar(pizzas, codigo, tamanho);
	if(pizza_a_deletar){
		pizza_a_deletar->ativo = false;
		printf(" excluído!\n");
	}
}

/*
Objetivo: Procura pizza por código e faz um edita com novos valores digitados pelo usuário caso encontrado.
Parâmetros:
pizzas[] -> Parâmetro do tipo "Pizza". É onde a "Pizza" será procurada. Passagem por referência (pois a "Pizza" encontrada será alterada na função). 
codigo ->  Parâmetro do tipo inteito. Código da "Pizza" a ser encontrada. Passagem por valor (pois essa variável não será alterada na função).
tamanho ->  Parâmetro do tipo inteito. Tamanho do vetor de "Pizzas". Passagem por valor (pois essa variável não será alterada na função).
*/
void alterar(Pizza pizzas[], int codigo, int tamanho){
	Pizza *pizza_a_alterar = procurar(pizzas, codigo, tamanho);
	if(pizza_a_alterar != NULL && pizza_a_alterar->ativo){
		printf("\nSabor da pizza: \n");
		fflush(stdin);
		fgets(pizza_a_alterar->nome, sizeof pizza_a_alterar->nome , stdin);
		printf("Valor da pizza: \n");
		fflush(stdin);
		scanf("%f",&pizza_a_alterar->preco);
		fflush(stdin);
		printf("\nAlterado!\n");
	}
}

/*
Objetivo: Escrever em um arquivo os dados cadastados no vetor de "Pizzas"
Parâmetros:
pizzas[] -> Parâmetro do tipo "Pizza". É de onde os dados a serem salvos no arquivo serão "retirados". Passagem por referência (pois é um vetor). 
tamanho ->  Parâmetro do tipo inteito. Tamanho do vetor de "Pizzas". Passagem por valor (pois essa variável não será alterada na função).
*/
escreverArquivo(Pizza *pizzas, int tamanho){
	FILE *arq;
	int i;
	arq = fopen("/documents/programming/DataStructures/Structs/pizzas.bin" , "wa");
	
	if(!arq){
		printf("Erro ao abrir arquivo!");
		exit(0);
	}

	for(i = 0; i < tamanho ; ++i){
		fprintf(arq , "Codigo: %d" ,pizzas[i].codigo);
		fprintf(arq , "\nNome: %s" ,pizzas[i].nome);
		fprintf(arq , "\nPreco: %f" ,pizzas[i].preco);
	}

}

/*
Objetivo: Ler de um arquivo os dados escritos posteriormente, exibir e colocar em um vetor de "Pizzas"
Parâmetros:
pizzas[] -> Parâmetro do tipo "Pizza". É onde a os dados do arquivo serão guardados. Passagem por referência (pois será alterado na função). 
*/
lerArquivo(Pizza *pizzas){
	FILE *arq;
	arq = fopen("/documents/programming/DataStructures/Structs/pizzas.bin" , "r");

	int i=0; 
	
	while(fread(&pizzas[i],sizeof(pizzas[i]),i,arq)){
		printf("\nSabor: %s",pizzas[i].nome);
		printf("\nPreco: $%f",pizzas[i].preco);
		printf("\nCodigo: %i",pizzas[i].codigo);
	}

	fclose(arq);

}


int main(int argc, char const *argv[])
{
		int op = 1;		
						
		while(op>0 && op <=6)
		{
			//Valores fixos para teste
			Pizza pizzas[2];
			int tamanho = 2;
			int codigo = 0;
			printf("1) Inserir\t2) Procurar\t3) Excluir\n\n4) Alterar\t5) Gravar em arquivo\t6) Ler de arquivo\n\n\t\t0) Sair\n\n\nOpcao: ");
			scanf("%i",&op);
			switch (op)
			{
				case 1:				
					inserir(pizzas,tamanho);
					break;
				case 2:
					printf("\nCódigo da pizza que deseja procurar: ");
					scanf("%d",&codigo);				
					procurar(pizzas,codigo,tamanho);
					break;
				case 3:
					printf("\nCódigo da pizza que deseja excluir: ");
					scanf("%d",&codigo);	
					excluir(pizzas,codigo,tamanho);
					break;
				case 4:
					printf("\nCódigo da pizza que deseja alterar: ");
					scanf("%d",&codigo);	
					alterar(pizzas,codigo,tamanho);
					break;
				case 5:
					escreverArquivo(pizzas,tamanho);
					break;
				case 6:
					lerArquivo(pizzas);
					break;
				default:
					printf("Saindo...\n");
			}
		}
		return 0;
}
