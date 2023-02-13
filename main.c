#include <stdio.h>
#include <stdbool.h>
#include "stack/stack.h"
#include "queue/queue.h"
#include "sparsematrix/sparsematrix.h"
#include "binarytree/binarytree.h"
#include "unbalancedbinarytree/unbalancedbinarytree.h"

#include "dsalib.h"

#define execute(s) fflush(stdout); \
__dsa__##s##__()

int main(int argc, char const *argv[]) {
//    execute(completebinarytree);
//    execute(threadbinarytree);
    execute(binarysearchtree);
    return 0;
}
