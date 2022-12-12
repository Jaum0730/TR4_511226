#include <stdio.h>
#include <stdlib.h>

#ifndef ORDVETOR_H
#define ORDVETOR_H


//gcc -c [arq1.c arq2.c ...] || gcc -o nome do executavel [arq1.o arq2.o ...]

/*Definicao do tipo de funcao a ser utilizado para comparacao
Esta funÃ§Ã£o recebe dois valores x e y e retorna

1 : se x Ã© menor que y.
0 : se x Ã© equivalente a y.
-1: se x Ã© maior que y na ordem.

*/
typedef int COMP(void* x, void* y);



//Vetor ordenado estatico. Os elementos do vetor estao colocado no vetor
//de acordo com a ordem indicada por comparador.
typedef struct vet{
	int N;//tamanho do vetor
	int P;//numero de elementos no vetor
	void** elems;//o vetor de elementos
	COMP* comparador;//a funcao de comparacao
}VETORORD;

/**
Cria um vetor ordernado vazio de tamanho n e com funcao de comparacao compara

@param n: o tamanho do vetor
@param compara: a funcao de comparacao

@return um ponteiro para uma estrutura VETORORD, observe que este ponteiro ja
deve apontar para a estrutura, ou seja, a alocacao de memoria deve ser feita nele.
*/
VETORORD* VETORD_create(int n, COMP* compara)
{
//Criei um ponteiro que aponta para uma estrutura de dados do Tipo VETORORD e aloquei memoria correspondente
	VETORORD * vtr = malloc(sizeof(VETORORD));

	vtr->N = n;
	vtr->P = 0; 
	vtr->comparador = compara;
	vtr->elems = malloc(sizeof(void*) * n);

	return vtr;


}

/**
Adiciona o elemento newelem ao vetor ordenado, na posicao correta se for possÃ­vel
ainda incluir o elemento (se existe espaco no vetor). O vetor deve estar ordenado em
ordem crescente, ou seja: x[i] Ã© menor que ou equivalente a x[j] para todo i < j.

@param vetor: o vetor ordenado a ter o elemento incluÃ­do
@param newelem: o elemento a ser adicionado
*/
void VETORD_add(VETORORD* vetor, void* newelem){
	//essa vriavel fiac responsavel por guardar em que posicao estamos no vetor
	int index;
	
	//essa condicao serve apenas entrarmos na condicionL
	if(vetor->P < vetor->P+1)
	{
	
		index = vetor->P;
		
		//AQUI trilhamos a estrutura comparando newelem a quem ja esta no vet
		for(int passo = 0; passo < vetor->N; passo++)
			{
				//guardando a posicao maior que newelem
				if(vetor->comparador(vetor->elems[passo], newelem) == -1)
				{
					index = passo;
					break;
				}
				//reorganizando o vetor
				for(int passo = vetor->P; passo > index; passo--)
					{
						vetor->elems[passo] = vetor->elems[passo -1];
					}
			}
		vetor->elems[index] = newelem;
		vetor->P++;
	}

}

/**
Remove o menor elemento do vetor, de acordo com a funcao compara.

@param vetor: o vetor a ter seu elemento removido

@return um ponteiro para o elemento que foi removido do vetor.
*/
void* VETORD_remove(VETORORD* vetor){
	void* removed  =  vetor->elems[0];
	
	for(int passo = 0; passo > vetor->P-1; passo++)
	{
		vetor->elems[passo] = vetor->elems[passo+1];
	} 
		
	vetor->P--;		
	
	return removed;







}
#endif
