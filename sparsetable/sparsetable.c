#include "sparsetable.h"
#include <math.h>
#include <stdio.h>

struct SparseTable *new_sparsetable(int nums[], int len) {
  struct SparseTable *st = malloc(sizeof(struct SparseTable));

  int P = floor(log2(len));

  st->n = len;
  st->p = P;

  st->table = malloc(sizeof(int *) * P);

  for (int i = 0; i <= P; i++) {
    st->table[i] = malloc(sizeof(int) * (len));
    // fill first row with origin datas
    if (i == 0) {
      for (int j = 0; j < len; j++) {
        st->table[i][j] = nums[j];
      }
    }
  }

  return st;
}

void build_sparsetable(struct SparseTable *st, int (*dp_func)(int, int)) {
  for (int i = 1; i <= st->p; i++) {
    for (int j = 0; j < st->n - (1 << (i - 1)); j++) {
      int left = st->table[i - 1][j];
      int right = st->table[i - 1][j + (1 << (i - 1))];
      st->table[i][j] = dp_func(left, right);
    }
  }
}

int min_func(int left, int right) { return left < right ? left : right; }

void print_table(struct SparseTable *st) {
  printf("n: %d, p: %d\n", st->n, st->p);
  int prev_len = st->n;
  for (int i = 0; i <= st->p; i++) {
    if (i == 0) {
      for (int j = 0; j < prev_len; j++) {
        printf("%2d, ", st->table[i][j]);
      }
      printf("\n");
      prev_len = st->n - (1 << i);
      continue;
    }
    for (int j = 0; j < prev_len; j++) {
      printf("%2d, ", st->table[i][j]);
    }
    printf("\n");
    prev_len -= (1 << i);
  }
}

int minQuery(struct SparseTable *st, int l, int r) {
  // NOTE: this is LEN so + 1 is essential
  int len = r - l + 1;
  int p = floor(log2(len));
  int k = 1 << p;
  return min_func(st->table[p][l], st->table[p][r - k + 1]);
}

int cascadingminQuery(struct SparseTable *st, int l, int r) {
  int min = -1000000000;
  for (int p = log2(r - l + 1); l <= r; p = log2(r - l + 1)) {
    min = min_func(min, st->table[p][l]);
    l += (1 << p);
  }
  return min;
}
