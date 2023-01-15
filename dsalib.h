#ifndef DSALIB
#define DSALIB

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
  qpop(q);
  printQueue(q);
}
#endif

#ifdef SPARSE
void __dsa__sparse__(){
  SparseMatrix *sm = newMatrix(4,3);
  printMatrix(sm);
  addValue(sm,0,0,1);
  addValue(sm,2,1,3);
  addValue(sm,3,0,4);
  printMatrix(sm);
}
#endif

#ifdef BINTREE
void __dsa__completebinarytree__(){
  Tree* tree = newTree();
  btadd(&tree, 1);
  btadd(&tree, 2);
  btadd(&tree, 3);
  btadd(&tree, 4);
  btadd(&tree, 5);
  printInorder(tree);
}
#endif

#endif