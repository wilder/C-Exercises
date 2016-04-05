#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{	char nome[50];
	int codigo;
	float preco;
	bool ativo;	
}Pizza;
  

void inserir(Pizza pizzas[], int quantidade)
{
	int i;
	for(i = 0; i < quantidade; ++i)
	{
		printf("Sabor da pizza: \n");
		fgets(pizzas[i].nome, sizeof pizzas[i].nome , stdin);
		printf("Valor da pizza: \n");
		scanf("%f",&pizzas[i].preco);
		getchar();
		pizzas[i].ativo = true;
		pizzas[i].codigo = i;
	}
}

Pizza* procurar(Pizza pizzas[], int codigo)
{
	int tamanho = 2;
	printf("%i",tamanho);
	Pizza *pizzaProcurada;
	for (int i = 0; i < tamanho; ++i)
	{
		if(pizzas[i].ativo && pizzas[i].codigo==codigo){
			pizzaProcurada = &pizzas[i];
			printf("%s",pizzas[i].nome);
			return pizzaProcurada;
		}
	}
	printf("Pizza não encontrada");
	return pizzaProcurada;
}

void excluir(Pizza pizzas[], int codigo)
{
	Pizza *pizza_a_deletar = procurar(pizzas, codigo);
	if(pizza_a_deletar){
		pizza_a_deletar->ativo = false;
	}
}

void alterar(Pizza pizzas[], int codigo){
	Pizza *pizza_a_alterar = procurar(pizzas, codigo);
	if(pizza_a_alterar != NULL && pizza_a_alterar->ativo){
		printf("Sabor da pizza: \n");
		fgets(pizza_a_alterar->nome, sizeof pizza_a_alterar->nome , stdin);
		printf("Valor da pizza: \n");
		scanf("%f",&pizza_a_alterar->preco);
		getchar();
	}
}


int main(int argc, char const *argv[])
{
	Pizza pizzas[2];
	inserir(pizzas,2);
	char nome[] = "wilder";
	alterar(pizzas, 0);
	printf("%s", pizzas[0].nome);
	
	system("PAUSE");
	return 0;
}