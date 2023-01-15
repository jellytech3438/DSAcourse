#include <stdio.h>
#include <stdlib.h>
#include "sparsematrix.h"

SparseMatrix* newMatrix(int row, int col){
  SparseMatrix* sm = malloc(sizeof(SparseMatrix));
  sm->row = row;
  sm->col = col;
  sm->head = malloc(sizeof(matrixNode));
  matrixNode* head = sm->head;
  int maxnode = row <= col ? col : row;
  for(int _mx = 0; _mx < maxnode; _mx++){
    head->ntype = 0;
    // make pointer point to self
    head->down = head;
    head->right = head;
    head->u.head.next = malloc(sizeof(matrixNode));
    head = head->u.head.next;
  }
  head = NULL;
  return sm;
};

void addValue(SparseMatrix *sm, int row, int col, int val){
  if(sm->col < col || sm->row < row)
    return;

  // create a new entry node
  matrixNode *newNode = malloc(sizeof(matrixNode));
  newNode->ntype = entry;
  newNode->u.entry.col = col;
  newNode->u.entry.row = row;
  newNode->u.entry.value = val;

  // get the row and col matrixnode
  matrixNode* nthRow = sm->head;
  matrixNode* nthCol = sm->head;
  for(int _r = 0,_c = 0; _r < row || _c < col;_r++,_c++){
    if(_r < row) (nthRow) = (*nthRow).u.head.next;
    if(_c < col) (nthCol) = (*nthCol).u.head.next;
  }

  // find row to add until the nthRow is on position or end
  if(&((*nthRow).right) == &(*nthRow) || nthRow == NULL ){
    (*nthRow).right = newNode;
    newNode->right = nthRow;
  }else{
    matrixNode* en = nthRow;
    while(en->right != nthRow)
      en = en->right;
    en->right = newNode;
    newNode->right = nthRow;
  }

  // find col to add until the nthCol is on position or end
  if(&((*nthCol).down) == &(*nthCol) || nthCol == NULL){
    (*nthCol).down = newNode;
    newNode->down = (nthCol);
  }else{
    matrixNode* en = nthCol;
    while((en)->down != (nthCol))
      (en) = (en)->down;
    (en)->down = newNode;
    newNode->down = (nthCol);
  }
}

void printMatrix(SparseMatrix *sm){
  matrixNode* temphead = sm->head;
  int row = sm->row;
  int col = sm->col;
  printf("%dx%d\n",row, col);
  for (int i = 0; i < row; i++, temphead = temphead->u.head.next){
    matrixNode* rowNode = temphead->right;
    if(rowNode->ntype == head){
        for(int j = 0; j < col; j++){
            printf("0->");
        }
        printf("END\n");
    }else{
        for(int j = 0; j < col; j++){
            if(rowNode->u.entry.col == j){
                printf("%d->",rowNode->u.entry.value);
                rowNode = rowNode->right;
            }else{
                printf("0->");
            }
        }
        printf("END\n");
    }
  }
}