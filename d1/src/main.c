#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMSTR_SIZE 8

#define LIST1 0
#define LIST2 1

#define LIST_SIZE 2048

int comp(const void *a, const void *b) {
  return (*(const int *)a) - (*(const int *)b);
}

void Puzzle1() {

  int list[2][LIST_SIZE];
  memset(list[0], -1, LIST_SIZE * sizeof(int));
  memset(list[1], -1, LIST_SIZE * sizeof(int));

  FILE *f = fopen("input", "r");
  assert(f);

  char c;

  char numStr[NUMSTR_SIZE];
  memset(numStr, 0, NUMSTR_SIZE);
  int numIdx = 0;

  int listIdx = 0;
  int listEle = 0;
  while ((c = fgetc(f)) != EOF) {
    if (isdigit(c)) {
      assert(numIdx < NUMSTR_SIZE);
      numStr[numIdx] = c;
      numIdx++;
    } else if (numIdx > 0) {
      assert(listEle < LIST_SIZE);
      int num = atoi(numStr);
      list[listIdx][listEle] = num;

      if (listIdx == 1)
        listEle++;
      listIdx = listIdx == 0 ? 1 : 0;

      numIdx = 0;
      memset(numStr, 0, NUMSTR_SIZE);
    }
  }
  fclose(f);

  qsort(list[0], listEle, sizeof(int), comp);
  qsort(list[1], listEle, sizeof(int), comp);

  int sum = 0;
  for (int i = 0; i < listEle; i++) {
    sum += abs(list[0][i] - list[1][i]);
  }
  printf("Sum: %d\n", sum);
}

void Puzzle2() {

  int list[2][LIST_SIZE];
  memset(list[0], -1, LIST_SIZE * sizeof(int));
  memset(list[1], -1, LIST_SIZE * sizeof(int));

  FILE *f = fopen("input", "r");
  assert(f);

  char c;

  char numStr[NUMSTR_SIZE];
  memset(numStr, 0, NUMSTR_SIZE);
  int numIdx = 0;

  int listIdx = 0;
  int listEle = 0;
  while ((c = fgetc(f)) != EOF) {
    if (isdigit(c)) {
      assert(numIdx < NUMSTR_SIZE);
      numStr[numIdx] = c;
      numIdx++;
    } else if (numIdx > 0) {
      assert(listEle < LIST_SIZE);
      int num = atoi(numStr);
      list[listIdx][listEle] = num;

      if (listIdx == 1)
        listEle++;
      listIdx = listIdx == 0 ? 1 : 0;

      numIdx = 0;
      memset(numStr, 0, NUMSTR_SIZE);
    }
  }
  fclose(f);

  qsort(list[0], listEle, sizeof(int), comp);
  qsort(list[1], listEle, sizeof(int), comp);

  int sum = 0;
  // I know it's O(n^2) but I don't care it's not real time anyway
  for (int i = 0; i < listEle; i++) {
    int sim = 0;
    for (int j = 0; j < listEle; j++) {
      if (list[0][i] == list[1][j]) {
        sim++;
      }
      if (list[0][i] < list[1][j])
        break;
    }
    sum += list[0][i] * sim;
  }
  printf("Sim sum: %d\n", sum);
}

int main() {
  printf("Puzzle 1:\n");
  Puzzle1();
  printf("Puzzle 2:\n");
  Puzzle2();
  return 0;
}
