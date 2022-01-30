/**
 * @mainpage
 * # 💻 Projeto - Laboratórios de Programação
 * 
 * ## Descrição
 * - Programa que calcula várias estatísticas e operações baseadas num vetor introduzido pelo utilizador.
 * 
 * ## Constituição do grupo
 * | Nome              | Número |
 * |:-----------------:|:------:|
 * | Pedro Batista     | 48389  |
 * | Afonso Ferreira   | 48277  |
 * | Diogo Silva       | 47564  |
 * 
 * ## Características
 * | Número do grupo   | Código do trabalho |
 * |:-----------------:|:------------------:|
 * | 15                | FB85BD             |
 * 
 * @file main-team-15.c
 * @authors Pedro Batista, Afonso Ferreira, Diogo Silva
 * @brief Programa que realiza operações matemáticas.
 * @details Programa que calcula várias estatísticas ou operações baseadas num vetor introduzido pelo utilizador.
 * @version 0.1
 * @date 2022-01-29
 * 
 * @copyright Copyright (c) 2022
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions-team-15.h"

/**
 * @brief Função principal
 * 
 * @param argc é o número de argumentos formais recebidos na função main.
 * @param argv é o vetor de argumentos formais recebidos na função main.
 * 
 * @return 0, caso o programa termine sem input do utilizador.
 * @return 1, caso o utilizador decida sair do programa pelo menu ou o preenchimento do vetor falhe.
 */
int main(int argc, char *argv[])
{
	// Procura pelo argumento "--help" nos parâmetros passados via terminal.
	for (int i = 0; i < argc; i++)
	{
		// Compara a string argv[i] (i-ésimo elemento vetor de argumentos) com a string "--help". Caso verdadeiro, retorna 0 (zero).
		if (!strcmp(argv[i], "--help"))
		{
			printf("HELP PAGE!\n");
		}
	}

	// Vetor que armazenará os valores introduzidos pelo utilizador.
	int array[N];

	// Tenta preencher o vetor armazenando na variável "isFilled", retornando -1 ou 0, dependendo do sucesso no preenchimento do vetor.
	const int isFilled = fillArray(array);

	// Verifica se o vetor foi preenchido na sua totalidade (-1 caso não seja preenchido).
	if (isFilled == -1)
	{
		printf("Vetor não preenchido. A sair...\n");
		return 1;
	}

	// Imprime o vetor com quebra de linha no final.
	printf("Vetor = ");
	printArray(array, 0, N, 1);

	// Reserva de memória para a matriz das opções 9 e 10.
	int **matrix = malloc(sizeof(int *) * N);
	for (int i = 0; i < N; i++)
	{
		matrix[i] = malloc(sizeof(int *) * N);
	}

	while (1)
	{
		// Imprime o menu principal e guarda na variável "option" a opção nele selecionada.
		int option = printMenu();

		printf("------------------------------------------------------------\n");

		switch (option)
		{
		case 1:
			// Imprime uma matriz do tipo 4*N, onde cada linha é constituída pelo vetor original.
			printMatrix(array);
			break;

		case 2:
			// Calcula o logaritmo natural de cada elemento do vetor original.
			calculateNaturalLog(array);
			break;

		case 3:
			// Calcula a mediana dos elementos do vetor original.
			calculateMedian(array);
			break;

		case 4:
			// Calcula o vetor simétrico ao original e ordena-o.
			sortSimetricArray(array);
			break;

		case 5:
			// Imprime os valores pertencentes ao vetor original, maiores do que dois e divisíveis por cinco.
			gt2AndDivisibleBy5(array);
			break;

		case 6:
			// Calcula o vetor que resulta da soma das duas metades do vetor original.
			sumTwoHalvesArray(array);
			break;

		case 7:
			// Mistura o vetor original com um novo vetor.
			mixArrays(array);
			break;

		case 8:
			// Decompõe os números ímpares do vetor original em números primos.
			decomposeInPrimeNumbers(array);
			break;

		case 9:; // O ponto e vírgula tem como função terminar a "label" do "case", dado que está a ser declarada uma variável logo a seguir à declaração do "case".
			// Cálcula a matriz 18x18 resultante do produto do vetor inicial com o mesmo vetor ordenado por ordem crescente.
			matrix = multiplyTwoArrays(array);
			break;

		case 10:
			// Cálcula a matriz transposta obtida a partir da matriz calculada na opção anterior (nove)
			// Impressão da matriz inicial obtida na opção anterior (nove).
			printf("Matriz inicial:\n");
			printArray2D(matrix);
			// Função que calcula e imprime a matriz transposta.
			transposeMatrix(matrix);
			break;

		default:
			// Caso a opção selecionada seja -1, a execução do programa é terminada.
			return 1;
		}

		printf("------------------------------------------------------------\n");
	}

	return 0;
}
