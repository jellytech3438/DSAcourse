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
  // detect the address of the value that the pointer(right) point to are same or not
  if(&(*(nthRow->right)) == &(*nthRow) || nthRow == NULL ){
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
  if(&(*(nthCol->down)) == &(*nthCol) || nthCol == NULL){
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

SparseMatrix* multiply(SparseMatrix* a, SparseMatrix* b){
    if(a->col != b-> row) return NULL;
    SparseMatrix* c = newMatrix(a->row,b->col);
    for(int i = 0; i < c->row; i++){
        for(int j = 0; j < c->col; j++){
            // get a's j row and multiply b's i col and give to c's [i][j]
            // if any of both are zero then continue;

            // a's part
            matrixNode* arow = a->head;
            for(int cnt = 0; cnt < i;cnt++) arow = arow->u.head.next;
            // construct a array
            int a_row_arr[a->col];
            for(int _ = 0; _ < a->col; _++) a_row_arr[_] = 0;
            // keep right
            // if is itself then it means there are no entry node
            if(&(*(arow->right)) == &(*arow) || arow == NULL ){
              continue;
            }else{
              // extract values to a_row
              matrixNode* a = arow;
              while(a->right != arow){
                int etycol = a->right->u.entry.col;
                a_row_arr[etycol] = a->right->u.entry.value;
                a = a->right;
              }
            }

            // b's part
            matrixNode* bcol = b->head;
            for(int cnt = 0; cnt < j;cnt++) bcol = bcol->u.head.next;
            // construct a array
            int b_col_arr[b->row];
            for(int _ = 0; _ < b->row; _++) b_col_arr[_] = 0;
            // keep down
            // if is itself then it means there are no entry node
            if(&(*(*bcol).down) == &(*bcol) || bcol == NULL ){
              continue;
            }else{
              // extract values to a_row
              matrixNode* b = bcol;
              while(b->down != bcol){
                int etyrow = b->down->u.entry.row;
                b_col_arr[etyrow] = b->down->u.entry.value;
                b = b->down;
              }
            }

            // multiply a with b and write to c
            int cntval = 0;
            for(int k = 0; k< a->col; k++){
              cntval += (a_row_arr[k] * b_col_arr[k]);
            }
            addValue(c, i, j, cntval);

        }
    }

    return c;
}