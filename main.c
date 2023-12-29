#include "binaryindextree/binaryindextree.h"
#include "binarytree/binarytree.h"
#include "queue/queue.h"
#include "sparsematrix/sparsematrix.h"
#include "sparsetable/sparsetable.h"
#include "stack/stack.h"
#include "unbalancedbinarytree/unbalancedbinarytree.h"
#include <stdbool.h>
#include <stdio.h>

#include "dsalib.h"

#define execute(s)                                                             \
  fflush(stdout);                                                              \
  __dsa__##s##__()

int main(int argc, char const *argv[]) {
  // execute(completebinarytree);
  // execute(threadbinarytree);
  // execute(binarysearchtree);
  // execute(sparsetable);
  execute(binaryindextree);
  return 0;
}
