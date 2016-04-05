Criação de um programa em linguagem C (ANSI) que efetua o cadastro de algo (a sua escolha). 

O programa deverá ter 6 opções:

1)	Inserir (guarda os dados em um vetor do tipo struct)
2)	Procurar (efetua procura e mostra o dado encontrado ou exibe a informação que não encontrou)
3)	Excluir (elimina um cadastro)
4)	Alterar (altera os dados de um cadastro e altera o vetor de struct que possui as informações do cadastro)
5)	Gravar em arquivo (guarda as informações do vetor de struct em um arquivo – como visto em aula)
6)	Ler de arquivo (Lê as informações de um arquivo e guarda em um vetor do tipo struct)

a) Os dados do cadastro deverão obrigatoriamente ser armazenados em variáveis do tipo “struct”

b) Para cada opção deverá ser criada um função com os parâmetros adequados.

c) Criar um cabeçalho antes da função (comentário) contendo as seguintes informações:

Objetivo da Função:
Parâmetros: (Para cada parâmetro indicar seu conteúdo e porque ele esta sendo usado)
Indicar e justificar o tipo de passagem do parâmetro
Exemplo:

float divide(int N1, int N2)

Objetivo: divide dois números e retorna um número real, resultado da divisão do primeiro número (N1) pelo segundo (N2).     N1/N2
Parâmetros:
N1 -> parâmetro inteiro Possui o valor do numerador da divisão. Passagem por valor (pois essa variável não será alterada na função). 
N2 -> parâmetro inteiro Possui o valor do denominador da divisão. Passagem por valor (pois essa variável não será alterada na função).




d) Utilizar gravação e leitura de arquivo binário como visto em aula


e) NÃO USAR VARIÁVEIS GLOBAIS
