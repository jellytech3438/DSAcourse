#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "queue/queue.h"
#include "binarytree.h"

hNode* newHNode(int val){
    hNode* newNode = malloc(sizeof(hNode*));
    newNode->value = val;
    newNode->index = -1;
    return newNode;
}

Heap* newHeap(int order_type){
    Heap* newHeap = malloc(sizeof(Heap*));
    if(order_type == 0)
      newHeap->ordertype = max;
    else if(order_type == 1)
      newHeap->ordertype = min;
    else
      return NULL;
    return newHeap;
}

bool isHeapEmpty(void* h){
    return (((Heap*)h)->root == NULL);
}

void hadd(Heap** h, int val){
    hNode* newNode = newHNode(val);
    if(isHeapEmpty(*h)){
        newNode->index = 1;
        (*h)->root = newNode;
        return;
    }
    hNode* root = (*h)->root;
    hNode** temp;

    Queue* queue = newQueue();
    qpush(queue,&root);

    // add to the last position of heap
    while(!isQEmpty(queue)){
        temp = (hNode**)qpop(queue);
        if ((*temp)->left != NULL){
          qpush(queue,&(*temp)->left);
        }else{
          newNode->index = 2*(*temp)->index;
          (*temp)->left = newNode;
          temp = &(*temp)->left;
          break;
        }
        if ((*temp)->right != NULL){
          qpush(queue,&(*temp)->right);
        }else{
          newNode->index = 2*(*temp)->index+1;
          (*temp)->right = newNode;
          temp = &(*temp)->right;
          break;
        }
    }

    qclear(queue);

    // in the heap sort chapter, these parameters will be more clear to understand
    // get the depth of the added node by index and construct an array
    int curindex = (*temp)->index;
    int depth = log2((*temp)->index)+1;
    int parents[depth];
    int pind;
    for(pind = depth-1; pind >= 0; pind--){
        parents[pind] = curindex;
        if(curindex % 2 == 1){
          curindex--;
        }
        curindex /= 2;
    }
    // next we get all parent's index and kepp tracking them
    // swap with parent according to max or min

    hNode* backtrace = root;
    while(parents[pind] == backtrace->value){

    }

    //    for(int i = 0; i < depth; i++){
    //      printf("%d->",parents[i]);
    //    }
    //    printf("\n");



//    qclear(queue);
}