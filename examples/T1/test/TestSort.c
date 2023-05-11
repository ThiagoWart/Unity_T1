#include "sort.h"
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP(Sort);

TEST_SETUP(Sort){}

TEST_TEAR_DOWN(Sort){}

/*
  sort(int* a, int length, char*type , int algorithm);
  a         -> ponteiro para o vetor de inteiros a ser ordenado
  length    -> comprimento do vetor passado
  type      -> complexidade do algoritmo a ser utilizado ("On", "On2", "Onlogn")
  algorithm -> indica qual o algoritmo de ordenação se pretende utilizar ("COUNTING", "RADIX", "BUBBLE", "INSERTION", "SELECTION", "HEAP", "MERGE", "QUICK")
*/

// teste de ordenação simples
TEST(Sort, TestSort1)
{
  int vet1[10] = {9, 5, 7, 2, 1, 0, 4, 6, 8, 3};
  int vet2[10] = {9, 5, 7, 2, 1, 0, 4, 6, 8, 3};
  int vet3[10] = {9, 5, 7, 2, 1, 0, 4, 6, 8, 3};
  int vet4[10] = {9, 5, 7, 2, 1, 0, 4, 6, 8, 3};
  int vet5[10] = {9, 5, 7, 2, 1, 0, 4, 6, 8, 3};
  int vet6[10] = {9, 5, 7, 2, 1, 0, 4, 6, 8, 3};
  int vet7[10] = {9, 5, 7, 2, 1, 0, 4, 6, 8, 3};
  int vet8[10] = {9, 5, 7, 2, 1, 0, 4, 6, 8, 3};
  int expected[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int tam = 10;
  int i = 0;

  sort(vet1, tam, "On", COUNTING);
  sort(vet2, tam, "On", RADIX);
  sort(vet3, tam, "On2", BUBBLE);
  sort(vet4, tam, "On2", INSERTION);
  sort(vet5, tam, "On2", SELECTION);
  sort(vet6, tam, "Onlogn", HEAP);
  sort(vet7, tam, "Onlogn", MERGE);
  sort(vet8, tam, "Onlogn", QUICK);

  TEST_ASSERT_EQUAL_INT32_ARRAY(vet1, expected, tam);
  TEST_ASSERT_EQUAL_INT32_ARRAY(vet2, expected, tam);
  TEST_ASSERT_EQUAL_INT32_ARRAY(vet3, expected, tam);
  TEST_ASSERT_EQUAL_INT32_ARRAY(vet4, expected, tam);
  TEST_ASSERT_EQUAL_INT32_ARRAY(vet5, expected, tam);
  TEST_ASSERT_EQUAL_INT32_ARRAY(vet6, expected, tam);
  TEST_ASSERT_EQUAL_INT32_ARRAY(vet7, expected, tam);
  TEST_ASSERT_EQUAL_INT32_ARRAY(vet8, expected, tam);
}

// teste de ordenação com um vetor com menos de 2 elementos
TEST(Sort, TestSort2)
{
  int vet[1] = {10};
  int tam = 1;

  TEST_ASSERT_EQUAL(1, sort(vet, tam, "On", COUNTING));
  TEST_ASSERT_EQUAL(1, sort(vet, tam, "On", RADIX));
  TEST_ASSERT_EQUAL(1, sort(vet, tam, "On2", BUBBLE));
  TEST_ASSERT_EQUAL(1, sort(vet, tam, "On2", INSERTION));
  TEST_ASSERT_EQUAL(1, sort(vet, tam, "On2", SELECTION));
  TEST_ASSERT_EQUAL(1, sort(vet, tam, "Onlogn", HEAP));
  TEST_ASSERT_EQUAL(1, sort(vet, tam, "Onlogn", MERGE));
  TEST_ASSERT_EQUAL(1, sort(vet, tam, "Onlogn", QUICK));
}

// teste de ordenação com um vetor de tamanho maior que 20
TEST(Sort, TestSort3)
{
  int vet[21] = {20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
  int tam = 21;

  TEST_ASSERT_EQUAL(1, sort(vet, tam, "On", COUNTING));
  TEST_ASSERT_EQUAL(1, sort(vet, tam, "On", RADIX));
  TEST_ASSERT_EQUAL(1, sort(vet, tam, "On2", BUBBLE));
  TEST_ASSERT_EQUAL(1, sort(vet, tam, "On2", INSERTION));
  TEST_ASSERT_EQUAL(1, sort(vet, tam, "On2", SELECTION));
  TEST_ASSERT_EQUAL(1, sort(vet, tam, "Onlogn", HEAP));
  TEST_ASSERT_EQUAL(1, sort(vet, tam, "Onlogn", MERGE));
  TEST_ASSERT_EQUAL(1, sort(vet, tam, "Onlogn", QUICK));
}

// teste de ordenação com um vetor ja ordenado
TEST(Sort, TestSort4)
{
  int vet1[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int vet2[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int vet3[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int vet4[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int vet5[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int vet6[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int vet7[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int vet8[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int expected[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int tam = 10;
  int i = 0;

  sort(vet1, tam, "On", COUNTING);
  sort(vet2, tam, "On", RADIX);
  sort(vet3, tam, "On2", BUBBLE);
  sort(vet4, tam, "On2", INSERTION);
  sort(vet5, tam, "On2", SELECTION);
  sort(vet6, tam, "Onlogn", HEAP);
  sort(vet7, tam, "Onlogn", MERGE);
  sort(vet8, tam, "Onlogn", QUICK);

  TEST_ASSERT_EQUAL_INT32_ARRAY(vet1, expected, tam);
  TEST_ASSERT_EQUAL_INT32_ARRAY(vet2, expected, tam);
  TEST_ASSERT_EQUAL_INT32_ARRAY(vet3, expected, tam);
  TEST_ASSERT_EQUAL_INT32_ARRAY(vet4, expected, tam);
  TEST_ASSERT_EQUAL_INT32_ARRAY(vet5, expected, tam);
  TEST_ASSERT_EQUAL_INT32_ARRAY(vet6, expected, tam);
  TEST_ASSERT_EQUAL_INT32_ARRAY(vet7, expected, tam);
  TEST_ASSERT_EQUAL_INT32_ARRAY(vet8, expected, tam);
}

// teste de ordenação com um vetor vazio
TEST(Sort, TestSort5)
{
  int vet[] = {};
  int tam = 0;

  TEST_ASSERT_EQUAL(1, sort(vet, tam, "On", COUNTING));
  TEST_ASSERT_EQUAL(1, sort(vet, tam, "On", RADIX));
  TEST_ASSERT_EQUAL(1, sort(vet, tam, "On2", BUBBLE));
  TEST_ASSERT_EQUAL(1, sort(vet, tam, "On2", INSERTION));
  TEST_ASSERT_EQUAL(1, sort(vet, tam, "On2", SELECTION));
  TEST_ASSERT_EQUAL(1, sort(vet, tam, "Onlogn", HEAP));
  TEST_ASSERT_EQUAL(1, sort(vet, tam, "Onlogn", MERGE));
  TEST_ASSERT_EQUAL(1, sort(vet, tam, "Onlogn", QUICK));
}

// teste de ordenação com um vetor com todos numeros iguais
TEST(Sort, TestSort6)
{
  int vet1[5] = {5, 5, 5, 5, 5};
  int vet2[5] = {5, 5, 5, 5, 5};
  int vet3[5] = {5, 5, 5, 5, 5};
  int vet4[5] = {5, 5, 5, 5, 5};
  int vet5[5] = {5, 5, 5, 5, 5};
  int vet6[5] = {5, 5, 5, 5, 5};
  int vet7[5] = {5, 5, 5, 5, 5};
  int vet8[5] = {5, 5, 5, 5, 5};
  int expected[5] = {5, 5, 5, 5, 5};
  int tam = 5;
  int i = 0;

  sort(vet1, tam, "On", COUNTING);
  sort(vet2, tam, "On", RADIX);
  sort(vet3, tam, "On2", BUBBLE);
  sort(vet4, tam, "On2", INSERTION);
  sort(vet5, tam, "On2", SELECTION);
  sort(vet6, tam, "Onlogn", HEAP);
  sort(vet7, tam, "Onlogn", MERGE);
  sort(vet8, tam, "Onlogn", QUICK);

  TEST_ASSERT_EQUAL_INT32_ARRAY(vet1, expected, tam);
  TEST_ASSERT_EQUAL_INT32_ARRAY(vet2, expected, tam);
  TEST_ASSERT_EQUAL_INT32_ARRAY(vet3, expected, tam);
  TEST_ASSERT_EQUAL_INT32_ARRAY(vet4, expected, tam);
  TEST_ASSERT_EQUAL_INT32_ARRAY(vet5, expected, tam);
  TEST_ASSERT_EQUAL_INT32_ARRAY(vet6, expected, tam);
  TEST_ASSERT_EQUAL_INT32_ARRAY(vet7, expected, tam);
  TEST_ASSERT_EQUAL_INT32_ARRAY(vet8, expected, tam);
}
// teste de ordenação com um vetor com todos numeros iguais com exceção de um
TEST(Sort, TestSort7)
{
  int vet1[5] = {5, 5, 5, 5, 1};
  int vet2[5] = {5, 5, 5, 5, 1};
  int vet3[5] = {5, 5, 5, 5, 1};
  int vet4[5] = {5, 5, 5, 5, 1};
  int vet5[5] = {5, 5, 5, 5, 1};
  int vet6[5] = {5, 5, 5, 5, 1};
  int vet7[5] = {5, 5, 5, 5, 1};
  int vet8[5] = {5, 5, 5, 5, 1};
  int expected[5] = {1, 5, 5, 5, 5};
  int tam = 5;
  int i = 0;

  sort(vet1, tam, "On", COUNTING);
  sort(vet2, tam, "On", RADIX);
  sort(vet3, tam, "On2", BUBBLE);
  sort(vet4, tam, "On2", INSERTION);
  sort(vet5, tam, "On2", SELECTION);
  sort(vet6, tam, "Onlogn", HEAP);
  sort(vet7, tam, "Onlogn", MERGE);
  sort(vet8, tam, "Onlogn", QUICK);

  TEST_ASSERT_EQUAL_INT32_ARRAY(vet1, expected, tam);
  TEST_ASSERT_EQUAL_INT32_ARRAY(vet2, expected, tam);
  TEST_ASSERT_EQUAL_INT32_ARRAY(vet3, expected, tam);
  TEST_ASSERT_EQUAL_INT32_ARRAY(vet4, expected, tam);
  TEST_ASSERT_EQUAL_INT32_ARRAY(vet5, expected, tam);
  TEST_ASSERT_EQUAL_INT32_ARRAY(vet6, expected, tam);
  TEST_ASSERT_EQUAL_INT32_ARRAY(vet7, expected, tam);
  TEST_ASSERT_EQUAL_INT32_ARRAY(vet8, expected, tam);
}