#include "binaryindextree.h"

struct BinaryIndexTree *new_binaryindextree(int base[], int n) {
  struct BinaryIndexTree *bit = malloc(sizeof(struct BinaryIndexTree));

  bit->n = n;
  bit->base = base;

  return bit;
}

void build_binaryindextree(struct BinaryIndexTree *bit,
                           int (*dp_func)(int, int)) {
  int n = bit->n;
  int *dp = malloc(sizeof(int) * (n + 1));
  dp[0] = 0;
  for (int i = 1; i <= n; i++) {
    int j = i;
    int cnt = 0;
    while (j > 0) {
      printf("%d, ", j);
      cnt = dp_func(cnt, bit->base[j - 1]);
      j -= (j & -j);
    }
    printf("\n");
    dp[i] = cnt;
  }
  bit->dp = dp;
}

void print_binaryindextree(struct BinaryIndexTree *bit) {
  for (int i = 0; i <= bit->n; i++) {
    printf("%d, ", bit->dp[i]);
  }
  printf("\n");
}

int sum_func(int a, int b) { return a + b; }
