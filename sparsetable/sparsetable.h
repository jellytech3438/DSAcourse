#ifndef SPARSETABLE
#define SPARSETABLE
#endif

struct SparseTable {
  int n;
  int p;
  int **table;
};

struct SparseTable *new_sparsetable(int nums[], int len);
void build_sparsetable(struct SparseTable *st, int (*dp_func)(int, int));
int min_func(int, int);
void print_table(struct SparseTable *st);

// TODO:
// given range: l to r, find the dp_func num in the range
// int minQuery(struct SparseTable* st, int l, int r);
// int cascadingQuery(struct SparseTable*, int l, int r);
