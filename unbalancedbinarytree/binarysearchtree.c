#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "unbalancedbinarytree/unbalancedbinarytree.h"

binseartNode* newBinSTNode(){
    return malloc(sizeof(binseartNode));
}

binsearTree* newBinSTree(){
    return malloc(sizeof(binsearTree));
}

void binseartadd(binsearTree** t, int val){
    binseartNode* r = (*t)->root;
    while(r != NULL){
      if (val > r->value){
        
      }
    }
}