#include <stdio.h>
#include <stdbool.h>
#include "stack/stack.h"
#include "queue/queue.h"
#include "sparsematrix/sparsematrix.h"
#include "binarytree/binarytree.h"

#include "dsalib.h"

#define execute(s) fflush(stdout); \
__dsa__##s##__()

int main(int argc, char const *argv[]) {
//    execute(completebinarytree);
//    execute(threadbinarytree);
//    execute(queue2);
    execute(stack);
    execute(stack2);
    return 0;
}
