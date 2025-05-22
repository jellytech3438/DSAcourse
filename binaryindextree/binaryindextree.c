#include "binaryindextree.h"

/*
 * codes are from:
 * https://www.topcoder.com/thrive/articles/Binary%20Indexed%20Trees
 * this site explain bit nicely and recommand checking
 */

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
    int j = i & -i;
    int cnt = 0;
    for (; j > 0; j--) {
      cnt = dp_func(cnt, bit->base[i - j]);
    }
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

void update(struct BinaryIndexTree *bit, int ind, int val) {
  while (ind <= bit->n) {
    bit->dp[ind] += val;
    ind = (ind & -ind);
  }
}

int read(struct BinaryIndexTree *bit, int ind) {
  int sum = bit->dp[ind];
  if (ind > 0) {
    int z = ind - (ind & -ind);
    ind--;
    while (ind != z) {
      sum -= bit->dp[ind];
      ind -= (ind & -ind);
    }
  }
  return sum;
}
