/**
 * @file functions.h
 * @authors Pedro Batista, Afonso Ferreira, Diogo Silva
 * @brief Ficheiro com a assinatura das funções programadas.
 * @version 0.1
 * @date 2022-01-29
 *
 * @copyright Copyright (c) 2022
 */

#define N 18
#define MIN 1
#define MAX 11
#define OPTIONS_NUMBER 11

/**
 @brief A função "helpPageRequest" exibe uma breve página de ajuda.

 @details Mostra uma breve página de ajuda caso o utilizador selecione a respetiva opção no menu principal ou insira o argumento "--help" na linha de comandos ao executar o programa.
*/
void helpPageRequest(void);

/**
 * @brief Preenche o vetor passado como argumento, com N posições.
 * @details Preenche um vetor de N posições, cujas mesmas devem ser inteiras e compreendidas entre 1 e 11, inclusive.
 *
 * @param array Vetor a ser preenchido.
 *
 * @returns 0, caso o vetor seja preenchido com sucesso na sua totalidade.
 * @returns -1, caso o utilizador insira -1 ao invés de uma entrada válida.
 */
int fillArray(int array[N]);

/**
 * @brief Imprime um vetor de N posições, com uma formatação específica.
 *
 * @param array Vetor a ser preenchido.
 * @param startAt Iteração pela qual o ciclo deve começar.
 * @param length Número de iterações.
 * @param breakLine Imprime uma quebra de linha no final, caso verdadeira.
 */
void printArray(int array[N], int startAt, int length, int breakLine);

/**
 * @brief Imprime uma matriz do tipo N por N, com uma formatação especial.
 *
 * @param matrix Matriz a ser impressa.
 */
void printArray2D(int **matrix);

/**
 * @brief Exibe o menu principal do programa.
 * @details Exibe um menu com "OPTIONS_NUMBER" (macro) posições.
 *
 * @return -1, caso o utilizador insira -1 ao invés de uma opção válida;
 * @return n (opção inserida entre 1 e "OPTIONS_NUMBER").
 */
int printMenu(void);

/**
 * @brief Cria e imprime uma matriz do tipo 4*N.
 * @details Cria e imprime uma matriz do tipo 4*N, com uma formatação especial, onde cada linha é constituída pelo vetor armazenado de N elementos.
 *
 * @param array Vetor que constituirá as quatro linhas da matriz.
 */
void printMatrix(int array[N]);

/**
 * @brief Imprime o logaritmo natural de todos os elementos do vetor passado.
 * @details Calcula e imprime o logaritmo de base "e" (logaritmo natural) de todos os elementos do vetor (argumento formal) passado como argumento.
 *
 * @param array Vetor cujo logaritmo natural de cada elemento será calculado.
 */
void calculateNaturalLog(int array[N]);

/**
 * @brief Calcula e exibe a mediana dos elementos do vetor passado como argumento formal.
 * @note Caso o número de elementos seja par, a mediana é calculada realizando a média dos dois valores centrais [(N/2)-1] e (N/2). Caso contrário, a mediana é o valor central dos elementos (N/2).
 *
 * @param array Vetor cuja mediana dos elementos será calculada.
 */
void calculateMedian(int array[N]);

/**
 * @brief Cria um vetor cujas entradas são as simétricas do vetor original e, de seguida, ordena-as com o auxílio da função "swap", onde são recebidos dois parâmetros formais no formato de apontadores e são trocados entre si os valores respetivos aos endereços recebidos, permitindo assim ordenar o vetor simétrico.
 *
 * @note As operações realizadas são efetuadas num vetor localmente criado, não alterando o vetor original.
 *
 * @param array Vetor original que originará o novo vetor.
 */
void sortSimetricArray(int array[N]);

/**
 * @brief Exibe os valores maiores do que dois e divisíveis por cinco, relativamente ao vetor original.
 *
 * @note "gt2AndDivisibleBy5" significa "Greater than two and divisible by five".
 *
 * @param array Vetor cujos valores serão analisados.
 */
void gt2AndDivisibleBy5(int array[N]);

/**
 * @brief Calcula a soma dos elementos da primeira metade com os da segunda metade do vetor, resultando num vetor com metade do tamanho do original.
 *
 * @note O número de elementos do vetor deve ser par, caso contrário as operações sobre o mesmo não são realizadas.
 *
 * @param array Vetor cujas duas metades serão somadas.
 */
void sumTwoHalvesArray(int array[N]);

/**
 * @brief Mistura a primeira metade do vetor original com a segunda metade de um novo vetor pedido, resultando num novo vetor.
 *
 * @param array Vetor cuja primeira metade será misturada com a segunda de um novo vetor.
 */
void mixArrays(int array[N]);

/**
 * @brief Decompõe, em fatores primos, todos os elementos do vetor passado como argumento formal que sejam ímpares.
 *
 * @param array Vetor cujos elementos serão decompostos em fatores primos.
 */
void decomposeInPrimeNumbers(int array[N]);

/**
 * @brief Multiplica dois vetores, sendo eles o vetor original passado como argumento formal e o vetor resultante da ordenação crescente do vetor original, resultando numa matriz do tipo N por N.
 *
 * @param array Vetor original.
 *
 * @return Matriz do tipo N por N (N*N).
 */
int **multiplyTwoArrays(int array[N]);

/**
 * @brief Calcula a matriz transposta da matriz calculada na função "multiplyTwoArrays".
 *
 * @param matrix Matriz original.
 */
void transposeMatrix(int **matrix);
