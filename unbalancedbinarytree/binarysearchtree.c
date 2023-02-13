#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack/stack.h"
#include "unbalancedbinarytree/unbalancedbinarytree.h"

binseartNode* newBinSTNode(int val){
    binseartNode* bsn = malloc(sizeof(binseartNode));
    bsn->value = val;
    return bsn;
}

binsearTree* newBinSTree(){
    binsearTree* bst = malloc(sizeof(binsearTree));
    return bst;
}

bool isBinSTEmpty(void* t){
    binsearTree* tree = (binsearTree*)t;
    return (tree->root == NULL);
}

bool containsBinST(binsearTree* t, int val){
    binseartNode* temp = t->root;
    while(temp != NULL){
      if(val > (temp)->value && (temp)->right == NULL){
        return false;
      }else if(val > (temp)->value && (temp)->right != NULL){
        temp = temp->right;
      }else if(val < (temp)->value && (temp)->left == NULL){
        return false;
      }else if(val < (temp)->value && (temp)->left != NULL){
        temp = temp->left;
      }else if(val == temp->value){
        return true;
      }
    }
    return false;
}


/*
* add function using stack and it can actually replaced by the containsBinST function way
* the reason it uses stack is to keep tracing the parent and back modifying if needed.
*/
void binseartadd(binsearTree** t, int val){
    binseartNode* newNode = newBinSTNode(val);
    if(isBinSTEmpty(*t)){
        (*t)->root = newNode;
        return;
    }
    binseartNode* root = (*t)->root;
    binseartNode** temp;
    Stack* stack = newStack();

    spush(stack,&root);

    while(!isSEmpty(stack)){
        temp = (binseartNode**)spop(stack);
        // put right if beq
        if(val >= (*temp)->value && (*temp)->right == NULL){
            (*temp)->right = newNode;
            break;
        }else if(val >= (*temp)->value && (*temp)->right != NULL){
          spush(stack,&(*temp)->right);
        }
        // put left is less
        else if(val < (*temp)->value && (*temp)->left == NULL){
          (*temp)->left = newNode;
            break;
        }else if(val < (*temp)->value && (*temp)->left != NULL){
          spush(stack,&(*temp)->left);
        }
    }

    sclear(stack);
}