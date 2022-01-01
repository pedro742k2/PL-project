#include <stdio.h>
#include "functions-team-5.h"

int main(void)
{
	int array[N];

	// Tenta preencher o vetor, armazenando na variável "isFilled" -1 ou 0, dependendo do sucesso no preenchimento do vetor.
	const int isFilled = fillArray(array);

	// Verifica se o vetor foi preenchido na sua totalidade (-1 caso o seu preenchimento seja interrompido).
	if (isFilled == -1)
	{
		printf("Vetor não preenchido. A sair...\n");
		return 1;
	}

	// Imprime o vetor com quebra de linha no final.
	printf("Vetor = ");
	printArray(array, 0, N, 1);

	while (1)
	{
		// Imprime o menu principal e guarda na variável "option" a opção nele selecionada
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
			int matrix[N][N];
			multiplyTwoArrays(array, matrix);
			break;

		case 10:
			// Cálcula a matriz transposta obtida a partir da matriz calculada na opção anterior (nove)
			// Impressão da matriz inicial obtida na opção anterior (nove).
			printf("Matriz inicial:\n");
			printArray2D(matrix);
			// Declaração da matriz transposta.
			int transpose[N][N];
			// Função que calcula e imprime a matriz transposta.
			transposeMatrix(matrix, transpose);
			break;

		default:
			// Caso a opção selecionada seja -1, a execução do programa é terminada.
			return 1;
		}

		printf("------------------------------------------------------------\n");
	}

	return 0;
}
