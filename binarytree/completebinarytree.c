#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue/queue.h"
#include "binarytree.h"

cbintNode* newCBinTNode(int val){
    cbintNode* t = malloc(sizeof(cbintNode));
    t->value = val;
    return t;
}

cbinTree* newCBinTree(){
    cbinTree* t = malloc(sizeof(cbinTree));
    return t;
}

bool isCBinTEmpty(void* t){
    cbinTree* tree = (cbinTree*)t;
    return (tree->root == NULL);
}

void printPreorder(void* r){
    if(r == NULL) return;
    cbintNode* root = (cbintNode*)r;
    printf("%d->",root->value);
    if (root->left != NULL){
        printPreorder(root->left);
    }
    if (root->right != NULL){
        printPreorder(root->right);
    }
}

void printInorder(void* r){
    if(r == NULL) return;
    cbintNode* root = (cbintNode*)r;
    if (root->left != NULL){
        printInorder(root->left);
    }
    printf("%d->",(root)->value);
    if (root->right != NULL){
        printInorder(root->right);
    }
}

void printPostorder(void* r){
    if(r == NULL) return;
    cbintNode* root = (cbintNode*)r;
    if (root->left != NULL){
        printPostorder(root->left);
    }
    if (root->right != NULL){
        printPostorder(root->right);
    }
    printf("%d->",root->value);
}

void cbtadd(cbinTree** t, int val){
    cbintNode* newNode = newCBinTNode(val);
    if(isCBinTEmpty(*t)){
        newNode->level = 1;
        (*t)->root = newNode;
        return;
    }
    cbintNode* root = (*t)->root;
    cbintNode** temp;

    Queue* queue = newQueue();
    qpush(queue,&root);

    while(!isQEmpty(queue)){
        temp = (cbintNode**)qpop(queue);
        // printf("value %d level %d\n",(*temp)->value, (*temp)->level);
        // PRINTQUEUE(queue,tnode,value);
        if ((*temp)->left != NULL){
            qpush(queue,&(*temp)->left);
        }else{
            // find first external
            newNode->level = (*temp)->level+1;
            (*temp)->left = newNode;
            break;
        }
        if ((*temp)->right != NULL){
            qpush(queue,&(*temp)->right);
        }else{
            // find first external
            newNode->level = (*temp)->level+1;
            (*temp)->right = newNode;
            break;
        }
    }
    qclear(queue);
}