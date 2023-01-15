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
    execute(completebinarytree);
    return 0;
}
