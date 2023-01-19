#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue/queue.h"
#include "binarytree.h"

tnode* newTNode(int val){
    tnode* t = malloc(sizeof(tnode));
    t->value = val;
    return t;
}

Tree* newTree(){
    Tree* t = malloc(sizeof(Tree));
    return t;
}

bool isTEmpty(void* t){
    Tree* tree = (Tree*)t;
    return (tree->root == NULL);
}

void printPreorder(void* r){
    if(r == NULL) return;
    tnode* root = (tnode*)r;
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
    tnode* root = (tnode*)r;
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
    tnode* root = (tnode*)r;
    if (root->left != NULL){
        printPostorder(root->left);
    }
    if (root->right != NULL){
        printPostorder(root->right);
    }
    printf("%d->",root->value);
}

void btadd(Tree** t, int val){
    tnode* newNode = newTNode(val);
    if(isTEmpty(*t)){
        newNode->level = 1;
        (*t)->root = newNode;
        return;
    }
    tnode* root = (*t)->root;
    tnode** temp;

    Queue* queue = newQueue();
    qpush(queue,&root);

    while(!isQEmpty(queue)){
        temp = (tnode**)qpop(queue);
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