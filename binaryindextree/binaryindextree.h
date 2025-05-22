#ifndef BININDTREE
#define BININDTREE
#endif

struct BinaryIndexTree {
  int n;
  int *base;
  int *dp;
};

struct BinaryIndexTree *new_binaryindextree(int base[], int n);
void build_binaryindextree(struct BinaryIndexTree *bit,
                           int (*dp_func)(int, int));
void print_binaryindextree(struct BinaryIndexTree *bit);
int sum_func(int, int);
void update(struct BinaryIndexTree *st, int ind, int val);
int read(struct BinaryIndexTree *st, int ind);
