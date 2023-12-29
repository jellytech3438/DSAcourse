#ifndef DSALIB
#define DSALIB

#include <stdio.h>
#ifdef STACK
void __dsa__stack__() {
  Stack *s = newStack();
  spush(s, 3);
  spush(s, 2);
  spush(s, 1);
  //  printf("%d poped out\n",spop(s));
  printStack(s);
}

#ifdef BINTREE
void __dsa__stack2__() {
  Stack *s = newStack();
  cbintNode *first = newCBinTNode(3);
  cbintNode *second = newCBinTNode(2);
  cbintNode *third = newCBinTNode(1);
  spush(s, &first);
  spush(s, &second);
  spush(s, &third);
  cbintNode **temp = (cbintNode **)spop(s);
  printf("%d poped out\n", (*temp)->value);
  PRINTSTACK(s, cbintNode, value);
}
#endif
#endif

#ifdef QUEUE
void __dsa__queue__() {
  Queue *q = newQueue();
  qpush(q, 3);
  qpush(q, 2);
  qpush(q, 1);
  qpush(q, 0);
  //  printf("%d poped out\n",(qpop(q)));
  printQueue(q);
}

#ifdef BINTREE
void __dsa__queue2__() {
  Queue *q = newQueue();
  cbintNode *first = newCBinTNode(3);
  cbintNode *second = newCBinTNode(2);
  qpush(q, &first);
  qpush(q, &second);
  cbintNode **temp = (cbintNode **)qpop(q);
  printf("%d poped out\n", (*temp)->value);
  PRINTQUEUE(q, cbintNode, value);
}
#endif
#endif

#ifdef SPARSEMAT
void __dsa__sparsematrix__() {
  SparseMatrix *a = newMatrix(4, 3);
  //  printMatrix(a);
  addValue(a, 0, 0, 1);
  addValue(a, 2, 1, 3);
  addValue(a, 3, 0, 4);
  addValue(a, 3, 2, 1);
  printMatrix(a);
  SparseMatrix *b = newMatrix(3, 4);
  addValue(b, 0, 3, 2);
  addValue(b, 1, 0, 3);
  addValue(b, 2, 2, 5);
  addValue(b, 2, 3, 6);
  printMatrix(b);
  SparseMatrix *c = multiply(a, b);
  printMatrix(c);
}
#endif

#ifdef SPARSETABLE
void __dsa__sparsetable__() {
  int nums[40] = {32, 15, 28, 14, 17, 25, 24, 46, 24, 52, 39, 35, 26, 35,
                  37, 15, 37, 55, 23, 30, 27, 45, 33, 25, 26, 19, 47, 54,
                  41, 22, 25, 37, 14, 58, 67, 33, 24, 15, 42, 54};
  struct SparseTable *st = new_sparsetable(nums, 40);
  build_sparsetable(st, min_func);
  print_table(st);

  printf("in range: [%d, %d]: the min is: %d\n", 0, 39, minQuery(st, 0, 39));
  printf("in range: [%d, %d]: the min is: %d\n", 3, 22, minQuery(st, 3, 22));
  printf("in range: [%d, %d]: the min is: %d\n", 13, 16, minQuery(st, 13, 16));
  printf("in range: [%d, %d]: the min is: %d\n", 28, 37, minQuery(st, 28, 37));
  printf("in range: [%d, %d]: the min is: %d\n", 28, 30, minQuery(st, 28, 30));
}
#endif

#ifdef BININDTREE
void __dsa__binaryindextree__() {
  int nums[40] = {32, 15, 28, 14, 17, 25, 24, 46, 24, 52, 39, 35, 26, 35,
                  37, 15, 37, 55, 23, 30, 27, 45, 33, 25, 26, 19, 47, 54,
                  41, 22, 25, 37, 14, 58, 67, 33, 24, 15, 42, 54};
  struct BinaryIndexTree *bit = new_binaryindextree(nums, 40);
  build_binaryindextree(bit, sum_func);
  print_binaryindextree(bit);
}
#endif

#ifdef BINTREE
void __dsa__completebinarytree__() {
  cbinTree *tree = newCBinTree();
  cbtadd(&tree, 1);
  cbtadd(&tree, 2);
  cbtadd(&tree, 3);
  cbtadd(&tree, 4);
  cbtadd(&tree, 5);
  cbtadd(&tree, 6);
  cbtadd(&tree, 7);
  cbtadd(&tree, 8);
  //  printPreorder(tree->root);
  //  printf("\n");
  printInorder(tree->root);
  printf("\n");
  //  printPostorder(tree->root);
  //  printf("\n");
}

void __dsa__threadbinarytree__() {
  threadTree *tree = newThreadTree();
  threadtadd(&tree, 1);
  threadtadd(&tree, 2);
  threadtadd(&tree, 3);
  threadtadd(&tree, 4);
  threadtadd(&tree, 5);
  threadtadd(&tree, 6);
  threadtadd(&tree, 7);
  threadtadd(&tree, 8);
  tprintInorder(tree->root);
  printf("\n");
}

void __dsa__heap__() {
  // 0 represent max heap
  // 1 represent min heap
  Heap *heap = newHeap(0);
  hadd(&heap, 1);
  hadd(&heap, 2);
  hadd(&heap, 3);
  hadd(&heap, 4);
  hadd(&heap, 5);
  hadd(&heap, 6);
  hadd(&heap, 7);
  hadd(&heap, 8);
  //  printInorder(heap);
}

#endif

#ifdef UBBINTREE
void __dsa__binarysearchtree__() {
  binsearTree *tree = newBinSTree();
  binseartadd(&tree, 10);
  binseartadd(&tree, 20);
  binseartadd(&tree, 15);
  binseartadd(&tree, 17);
  binseartadd(&tree, 31);
  binseartadd(&tree, 30);
  printInorder(tree->root);
  printf("\n");
  printf("contains %d: %d\n", 17, containsBinST(tree, 17));
  printf("contains %d: %d\n", 18, containsBinST(tree, 18));
}

#endif

#endif
