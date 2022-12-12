# TR4_511226


------------------------------------------------------------------Jeito dificil----------------------------------------------------------------------------

#Baixe o arquivo .c

#Com o arquivo na sua maquina você terá que fazer um .h declarando as respectivas "typedef int COMP(void* x, void* y), typedef struct vet{
	int N;//tamanho do vetor
	int P;//numero de elementos no vetor
	void** elems;//o vetor de elementos
	COMP* comparador;//a funcao de comparacao
}VETORORD;, 
VETORORD* VETORD_create(int n, COMP* compara), void VETORD_add(VETORORD* vetor, void* newelem), void* VETORD_remove(VETORORD* vetor)". OBS1: Em "VETORORD* VETORD_create(int n, COMP* compara)"

#Para compilar este codigo .c vá na pasta em que ele esta localizado abra o terminal linux na pasta respectiva pasta e digite: gcc TR4_511226.c -o prog1

#Com as funcoes declaradas em um arquivo .h basta apenas chamar essa biblioteca na main do seu programa
-----------------------------------------------------------------------------------------------------------------------------------------------------------
