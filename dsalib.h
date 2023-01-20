#ifndef DSALIB
#define DSALIB

#include <stdio.h>
#ifdef STACK
void __dsa__stack__(){
  Stack *s = newStack();
  spush(s,3);
  spush(s,2);
  spush(s,1);
  spush(s,0);
  spop(s);
  printStack(s);
}
#endif

#ifdef QUEUE
void __dsa__queue__(){
  Queue *q = newQueue();
  qpush(q,3);
  qpush(q,2);
  qpush(q,1);
  qpush(q,0);
//  printf("%d poped out\n",(qpop(q)));
  printQueue(q);
}
#endif

#ifdef SPARSE
void __dsa__sparse__(){
  SparseMatrix* a = newMatrix(4,3);
//  printMatrix(a);
  addValue(a,0,0,1);
  addValue(a,2,1,3);
  addValue(a,3,0,4);
  addValue(a,3,2,1);
  printMatrix(a);
  SparseMatrix* b = newMatrix(3,4);
  addValue(b,0,3,2);
  addValue(b,1,0,3);
  addValue(b,2,2,5);
  addValue(b,2,3,6);
  printMatrix(b);
  SparseMatrix* c = multiply(a,b);
  printMatrix(c);
}
#endif

#ifdef BINTREE
void __dsa__completebinarytree__(){
  cbinTree* tree = newCBinTree();
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

void __dsa__threadbinarytree__(){
  threadTree* tree = newThreadTree();
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
#endif

#endif