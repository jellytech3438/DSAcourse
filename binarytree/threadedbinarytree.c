#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue/queue.h"
#include "binarytree.h"

threadNode* newThreadNode(int val){
    threadNode* t = malloc(sizeof(threadNode));
    t->value = val;
    t->rpt = thread;
    t->lpt = thread;
    return t;
}

threadTree* newThreadTree(){
    threadTree* t = malloc(sizeof(threadTree));
    threadNode* n = newThreadNode(-1);
    n->right = n;
    n->rpt = link;
    n->lpt = link;
    t->root = n;
    return t;
}

bool isThreadTEmpty(void* t){
    threadTree* tree = (threadTree*)t;
    // if wondering why this is left plz see binarytree.h
    return (tree->root->left == NULL);
}

void tprintInorder(void* r){
    threadNode* temp = (threadNode*)r;
    while (temp->lpt == link)
        temp = temp->left;
    while(temp->rpt == thread){
        printf("%d->",temp->value);
        temp = temp->right;
    }
    if(temp->value == -1) return;
    printf("%d->",temp->value);
    // if is link then go right and keep go left
    temp = temp->right;
    tprintInorder(temp);
}

void threadtadd(threadTree** t,int val){
    threadNode* newNode = newThreadNode(val);
    if(isThreadTEmpty(*t)){
        (*t)->root->left = newNode;
        newNode->right = (*t)->root;
        newNode->left = (*t)->root;
        return;
    }
    threadNode* root = (*t)->root->left;
    threadNode** temp;

    Queue* queue = newQueue();
    qpush(queue,&root);

    while(!isQEmpty(queue)){
        temp = (threadNode**)qpop(queue);
        // PRINTQUEUE(queue,tnode,value);
        if ((*temp)->lpt != thread){
          qpush(queue,&(*temp)->left);
        }else{
          // unlink parent's left and link new's left
          threadNode* origin_point_to = (*temp)->left;
          (*temp)->lpt = link;
          (*temp)->left = newNode;
          newNode->left = origin_point_to;
          // deal with right
          newNode->right = (*temp);
          break;
        }
        if ((*temp)->rpt != thread){
          qpush(queue,&(*temp)->right);
        }else{
          threadNode* origin_point_to = (*temp)->right;
          (*temp)->rpt = link;
          (*temp)->right = newNode;
          newNode->right = origin_point_to;
          newNode->left = (*temp);
          break;
        }
    }
    qclear(queue);
}