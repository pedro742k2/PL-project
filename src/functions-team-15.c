/**
 * @file functions-team-15.c
 * @authors Pedro Batista, Afonso Ferreira, Diogo Silva
 * @brief Ficheiro com as funções auxiliares.
 * @version 0.1
 * @date 2022-01-29
 * 
 * @copyright Copyright (c) 2022 
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "functions-team-15.h"

int fillArray(int array[N])
{
  // Mensagem introdutória
  printf("Insira %d valores inteiros compreendidos entre %d e %d (inclusive). Insira \"-1\" sem as aspas para sair.\n", N, MIN, MAX);

  // Variável que irá armazenar temporariamente cada entrada introduzida.
  int entry;

  for (int i = 0; i < N; i++)
  {
    // Pede ao utilizador para inserir um valor.
    printf("Insira o valor n.%d: ", i);
    scanf("%d", &entry);

    // Verifica se a entrada está entre 1 e 11, inclusive.
    while (entry < MIN || entry > MAX)
    {
      // Verica se a entreda é "-1". Caso afirmativo, termina a função retornando 1.
      if (entry == -1)
      {
        return -1;
      }

      // Pede para reintroduzir um valor válido.
      printf("O valor introduzido (%d) deve ser inteiro e estar compreendido entre %d e %d.\n", entry, MIN, MAX);
      printf("Insira novamente o valor n.%d: ", i);
      scanf("%d", &entry);
    }

    // Quando a entrada for válida, armazena-a na respetiva posição do vetor.
    array[i] = entry;
  }

  // Finalmente, quando e se totalmente finalizado, retorna 0.
  return 0;
}

void printArray(int array[N], int startAt, int length, int breakLine)
{
  // Imprime o vetor com uma formatação específica: {x1, x2, ..., xn}.
  printf("{");
  for (int i = startAt; i < length; i++)
  {
    printf("%d", array[i]);
    // Caso esteja na última iteração, não imprime a vírgula que separa os elementos.
    if (i != length - 1)
    {
      printf(", ");
    }
  }
  printf("}");

  // Se breakLine for verdadeiro (!=0), imprime uma quebra de linha no terminal
  if (breakLine)
  {
    printf("\n");
  }
}

void printArray2D(int **matrix)
{
  for (int i = 0; i < N; i++)
  {
    printf("|");
    for (int j = 0; j < N; j++)
    {
      printf("%d", matrix[i][j]);
      if (j < N - 1)
      {
        printf("\t");
      }
      else
      {
        printf("|\n");
      }
    }
  }
}

int printMenu(void)
{
  // Lista de opções numa matrix de caracteres, com a finalidade de facilitar a manutenção do menu principal, caso sejam adicionadas funcionalidades.
  // "OPTIONS_NUMBER" é uma macro definida no ficheiro "functions-team-5.h".
  char optionsList[OPTIONS_NUMBER][255] = {
      "Construir uma matriz do tipo 4xN cujas linhas são constituidas pelos elementos do vetor",
      "Calcular o logaritmo natural dos elementos do vetor",
      "Calcular a mediana dos elementos do vetor",
      "Exibir o vetor simétrico e ordenado relativamente ao vetor original",
      "Exibir os valores do vetor maiores do que 2 e divisíveis por 5",
      "Exibir um vetor que resulta da soma da primeira com a segunda metade do vetor original",
      "Misturar o vetor original com um novo vetor",
      "Decompor números ímpares do vetor original em números primos",
      "Cálculo da matriz NxN resultante do produto do vetor inicial com o mesmo vetor ordenado por ordem crescente",
      "Cálculo da matriz transposta obtida a partir da matriz calculada na opção anterior (nove)"};
  // Variável que armazenará a opção selecionada pelo utilizador.
  int option;

  // Impressão das opções disponíveis.
  printf("Escolha uma das seguintes opções:\n");
  printf("Nota: N = %d.\n", N);
  for (int i = 0; i < OPTIONS_NUMBER; i++)
  {
    // Formatação: Caso seja a última iteração, a mesma acaba com ponto e vírgula, por exemplo:
    // x.) Penúltima opção;
    // y.) Última opção.
    printf("%d.) %s", i + 1, optionsList[i]);
    if (i != OPTIONS_NUMBER - 1)
    {
      printf(";\n");
    }
    else
    {
      printf(".\n");
    }
  }

  // Leitura da opção desejada (-1 para sair do menu).
  printf("Opção (-1 para sair): ");
  scanf("%d", &option);
  // Validação da opção selecionada. Este ciclo é repetido enquanto não for introduzida uma opção válida.
  while (option < 1 || option > OPTIONS_NUMBER)
  {
    if (option == -1)
    {
      return -1;
    }

    // Mensagem de erro e nova leitura da opção desejada.
    printf("O valor introduzido (%d) deve ser inteiro e estar compreendido entre %d e %d.\n", option, 1, 6);
    printf("Insira novamente uma opção: ");
    scanf("%d", &option);
  }

  // Finalmente, retorna uma opção válida.
  return option;
}

void printMatrix(int array[N])
{
  int matrix[4][N];

  printf("A imprimir matrix do tipo 4*18, cujas linhas são constituídas pelo vetor armazenado.\n");

  // Impressão da matriz com uma formatação específica:
  /* Formatação específica:
  | a1 a2 ... an |
  | b1 b2 ... bn |
  | c1 c2 ... cn |
  */
  for (int i = 0; i < 4; i++)
  {
    printf("|");
    for (int j = 0; j < N; j++)
    {
      matrix[i][j] = array[j];
      printf("%d", matrix[i][j]);
      if (j < N - 1)
      {
        printf("\t");
      }
    }
    printf("|\n");
  }
}

void calculateNaturalLog(int array[N])
{
  printf("ln(x) significa: Logaritmo natural de x.\n");
  for (int i = 0; i < N; i++)
  {
    printf("ln(%d)\t=\t%lf\n", array[i], log(array[i]));
  }
}

void calculateMedian(int array[N])
{
  double mediana;

  mediana = !(N % 2) ? ((double)(array[(N / 2) - 1] + array[N / 2]) / 2) : array[N / 2];

  printf("A mediana do vetor:\n");
  printArray(array, 0, N, 1);
  printf("arredondada a duas casas decimais é: %.2lf.\n", mediana);
}

/**
 @brief A função "swap" troca entre si os valores armazenados em endereços diferentes.

 @note Esta função não é prototipada no ficheiro "header"" dado que é uma função auxiliar a outras funções neste mesmo ficheiro.
*/
void swap(int *ptrX, int *ptrY)
{
  int temp = *ptrX;
  *ptrX = *ptrY;
  *ptrY = temp;
}

void sortSimetricArray(int array[N])
{
  // Vetor que irá armazenar as entradas simétricoas às do vetor original.
  int simetricArray[N];
  // Cálculo do simétrico das entradas do vetor original, resultando no vetor simétrico ao original.
  for (int i = 0; i < N; i++)
  {
    simetricArray[i] = (-1) * array[i];
  }

  // Exibição do vetor original.
  printf("Vetor original: ");
  printArray(array, 0, N, 1);
  // Exibição do vetor simétrico.
  printf("Vetor simétrico: ");
  printArray(simetricArray, 0, N, 1);
  // Ciclo que irá ordenar o vetor simétrico, utilizando ponteiros para esse finalidade.
  for (int i = 0; i < N - 1; i++)
  {
    for (int j = 0; j < N - i - 1; j++)
    {
      if (simetricArray[j + 1] < simetricArray[j])
      {
        swap(&simetricArray[j], &simetricArray[j + 1]);
      }
    }
  }
  // Exibição do vetor simétrico ordenado.
  printf("Vetor simétrico ordenado por ordem crescente: ");
  printArray(simetricArray, 0, N, 1);
}

/**
 * @brief verifica se o valor passado como segundo argumento já se encontra no vetor passado como primeiro argumento, com a finalidade de não exibir valores repetidos no terminal.
 * 
 * @param addedValues Vetor a analisar.
 * @param value Elemento a procurar no vetor "addedValues".
 * 
 * @note Esta função não é prototipada no ficheiro "header" (functions-team-5.h) dado que é uma função auxiliar à função "gt2AndDivisibleBy5", localizada logo abaixo desta.
 * 
 * @returns 0 (zero), caso o valor já se encontre no vetor passado como primeiro parâmetro formal.
 * @returns 1, caso o valor ainda não se encontre no vetor passado como primeiro parâmetro formal.
 */
int notAdded(int addedValues[N], int value)
{
  for (int i = 0; i < N; i++)
  {
    if (addedValues[i] == value)
    {
      return 0;
    }
  }

  return 1;
}

void gt2AndDivisibleBy5(int array[N])
{
  // Vetor (addedValues) que irá armazenar os valores já adicionados, com a finalidade de não repetir números na impressão final. A variável "index" vai incrementando conforme valores vão sendo adicionados ao vetor "addedValues".
  int addedValues[N], index = 0;

  // Preenche o vetor "addedValues" com zeros, para evitar ficar com valores aleatórios.
  for (int i = 0; i < N; i++)
  {
    addedValues[i] = 0;
  }

  printf("Números maiores do que dois e divisíveis por cinco: ");
  for (int i = 0; i < N; i++)
  {
    if (array[i] > 2 && !(array[i] % 5) && notAdded(addedValues, array[i]))
    {
      /* Imprime o valor caso:
      1.) Seja maior do que 2 [array[i] > 2],
      2.) Seja divisível por 5 [!(array[i] % 5)] ou [array[i] % 5 == 0] e
      3.) Ainda não tenha sido exibido.
      */
      printf("%d ", array[i]);
      // Adiciona o valor ao vetor "addedValues" para que não seja exibido novamente, incrementando "index" para rastrear a quantidade de valores adicionados.
      addedValues[index] = array[i];
      index++;
    }
  }
  printf("\n");
}

void sumTwoHalvesArray(int array[N])
{
  // Verifica se o número de elementos é par.
  // A condição [ !(N % 2) ] é equivalente a [ N % 2 == 0 ].
  if (!(N % 2))
  {
    // Vetor resultante da soma das duas metades.
    int sumArray[N / 2];

    // Ciclo que armazena a soma dos elementos no vetor "sumArray".
    for (int i = 0; i < N / 2; i++)
    {
      sumArray[i] = array[i] + array[N / 2 + i];
    }

    // Exibição com a finalidade de demonstrar o processo.
    printf("A soma das duas metades do vetor original resultou no seguinte vetor:\n");
    printArray(array, 0, (N / 2), 0);
    printf(" + ");
    printArray(array, (N / 2), N, 0);
    printf(" = ");
    // Exibição do resultado
    printArray(sumArray, 0, (N / 2), 1);
  }
  else
  {
    // Apresenta uma breve mensagem caso o número de elementos do vetor original seja ímpar.
    printf("Para somar as duas metades do vetor original, o número de elementos do mesmo deve ser par.\n");
  }
}

void mixArrays(int array[N])
{
  // "newArray" é o vetor que armazenará os novos valores introduzidos pelo utilizador.
  // "mixedArray" é o vetor cujos elementos serão a mistura da primeira metade do vetor original com a do novo vetor (newArray).
  int newArray[N], mixedArray[N];

  // Preenche o novo vetor.
  fillArray(newArray);

  // Verifica se o número de elementos dos vetores é par.
  if (!(N % 2))
  {
    // Ciclo que irá misturar o vetor original (array) e o novo vetor (newArray) no vetor (mixedArray).
    for (int i = 0; i < N; i++)
    {
      mixedArray[i] = (i < N / 2) ? array[i] : newArray[i];
    }

    printf("Vetores misturados: ");
    printArray(mixedArray, 0, N, 1);
  }
  else
  {
    // Caso não seja par, a função apresenta apenas a seguinte mensagem.
    printf("O número de elementos dos vetores deve ser par.\n");
  }
}

/**
 * @brief Anula um array de "length" posições.
 * 
 * @param length Tamanho do vetor.
 * @param array Vetor cujos valores serão anulados.
 * 
 * @note Esta função não é prototipada no ficheiro "header" (functions-team-5.h) dado que é uma função auxiliar a outras funções neste mesmo ficheiro.
 */
void resetArray(int length, int array[length])
{
  for (int i = 0; i < N; i++)
  {
    array[i] = 0;
  }
}

void decomposeInPrimeNumbers(int array[N])
{
  // Vetor que irá armazenar os fatores de cada número ímpar do vetor.
  // "index" é a variável que incrementa cada vez que um valor é adicionado ao vetor "multiples".
  int multiples[255], index = 0;
  resetArray(255, multiples);

  // Ciclo que percorre o vetor original para procurar por números ímpares.
  for (int i = 0; i < N; i++)
  {
    // Caso seja ímpar...
    if (array[i] % 2)
    {
      // Guarda uma cópia do valor que será manipulado, com o fim de não afetar o vetor principal.
      int num = array[i];

      // Se "num" (valor clonado) for igual a um, então apenas tem um múltiplo que é o próprio valor.
      if (num == 1)
      {
        multiples[0] = 1;
        index++;
      }
      else
      {
        // "divider" é a variável candidata a múltiplo
        int divider = 2; // >= 2
        // Enquanto "num" não estiver fatorado...
        while (num != 1)
        {
          // Se a divisão entre "num" e o divisor (divider) for zero, ou seja, se forem divisíveis, "divider" é um fator de "num".
          if (!(num % divider))
          {
            // "num" é dividido por "divider", "divider" é acrescentado aos múltiplos (vetor "multiples"), o index é incrementado em uma unidade e a variável "divider" é reiniciada para dois.
            num = num / divider;
            multiples[index] = divider;
            index++;
            divider = 2;
          }
          else
          {
            // Caso "divider" não seja divisível por "num", este é incrementado e a validação é repetida.
            divider++;
          }
        }
      }

      // Após decomposto, o número ímpar do vetor original é exibido decomposto nos respetivos fatores.
      printf("%d decomposto em fatores primos: ", array[i]);
      for (int j = 0; j < index; j++)
      {
        printf("%d", multiples[j]);
        if (j != index - 1)
        {
          printf(" * ");
        }
        else
        {
          printf("\n");
        }
      }

      // O índice (index) e vetor dos fatores (multiples) são reiniciados.
      index = 0;
      resetArray(255, multiples);
    }
  }
}

int **multiplyTwoArrays(int array[N])
{
  int sortedArray[N];
  int **matrix;

  // Alocação de memória para as linhas e colunas da matriz.
  matrix = malloc(sizeof(int *) * N);
  for (int i = 0; i < N; i++)
  {
    matrix[i] = malloc(sizeof(int *) * N);
  }

  // Ciclo para clonar o vetor original (array) para o vetor "sortedArray".
  for (int i = 0; i < N; i++)
  {
    sortedArray[i] = array[i];
  }

  // Ciclo que irá ordenar o vetor simétrico, utilizando ponteiros para esse finalidade.
  for (int i = 0; i < N - 1; i++)
  {
    for (int j = 0; j < N - i - 1; j++)
    {
      if (sortedArray[j + 1] < sortedArray[j])
      {
        swap(&sortedArray[j], &sortedArray[j + 1]);
      }
    }
  }

  // Cria a matrix resultante da multiplicação dos dois vetores
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      matrix[i][j] = array[i] * sortedArray[j];
    }
  }

  // Impressão das operações realizadas
  printArray(array, 0, N, 0);
  printf(" * ");
  printArray(sortedArray, 0, N, 0);
  printf(" =\n");
  // Impressão da matriz resultante
  printArray2D(matrix);

  return matrix;
}

void transposeMatrix(int **matrix)
{
  // Declaração da matriz transposta.
  int **transpose;

  // Alocação de memória das linhas e colunas da matriz
  transpose = malloc(sizeof(int *) * N);
  for (int i = 0; i < N; i++)
  {
    transpose[i] = malloc(sizeof(int *) * N);
  }

  // Ciclo que calcula a matriz transposta a partir da matriz inicial.
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      transpose[i][j] = matrix[j][i];
    }
  }

  // Impressão da matriz transposta.
  printf("Matriz transposta:\n");
  printArray2D(transpose);
}
