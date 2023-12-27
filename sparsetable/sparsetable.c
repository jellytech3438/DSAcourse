#include "sparsetable.h"
#include <math.h>
#include <stdio.h>

struct SparseTable *new_sparsetable(int nums[], int len) {
  struct SparseTable *st = malloc(sizeof(struct SparseTable));

  int P = floor(log(len) / log(2));

  st->n = len;
  st->p = P;

  st->table = malloc(sizeof(int *) * P);

  for (int i = 0; i < P; i++) {
    st->table[i] = malloc(sizeof(int) * (len));
    // fill first row with origin datas
    if (i == 0) {
      for (int j = 0; j < len - 1; j++) {
        st->table[i][j] = nums[j];
      }
    }
  }

  return st;
}

void build_sparsetable(struct SparseTable *st, int (*dp_func)(int, int)) {
  for (int i = 1; i < st->p; i++) {
    for (int j = 0; j <= st->n - (1 << i); j++) {
      int left = st->table[i - 1][j];
      int right = st->table[i - 1][j + (1 << i) - 1];
      st->table[i][j] = dp_func(left, right);
    }
  }
}

int min_func(int left, int right) { return left < right ? left : right; }

void print_table(struct SparseTable *st) {
  printf("n: %d, p: %d\n", st->n, st->p);
  for (int i = 0; i < st->p; i++) {
    if (i == 0) {
      for (int j = 0; j < st->n; j++) {
        printf("%d, ", st->table[i][j]);
      }
      printf("\n");
      continue;
    }
    for (int j = 0; j <= st->n - (1 << i); j++) {
      printf("%d, ", st->table[i][j]);
    }
    printf("\n");
  }
}
