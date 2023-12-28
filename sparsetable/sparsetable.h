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

int minQuery(struct SparseTable *st, int l, int r);
int cascadingminQuery(struct SparseTable *st, int l, int r);
