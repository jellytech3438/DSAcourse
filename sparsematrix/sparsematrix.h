#ifndef SPARSE
#define SPARSE
#endif

enum nodetype{
  head, entry
};

/*
 * there are two type of node: entry node and head node
 *
 * headnode: 
 * | down | head | right |
 * |---------------------|
 * |        next         |
 * NOTE:
 *   next mean the next headndoe and right means this node(ex: header1)
 *   as the column and it's right(see sparsematrix)
 * 
 * entry node:
 * | down | entry | row | col | right |
 * |----------------------------------|
 * |        value                     |
 * which have row(i in matrix) and col(j in matrix)
 * NOTE:
 *   if entrynode is the last one than it'll point back to head node
 *   is because it's convenient if we want add or remove
 */

struct entryNode{
  int row;
  int col;
  int value;
};

struct headNode{
  struct matrixNode *next;
};

struct matrixNode{
  struct matrixNode *down;
  struct matrixNode *right;
  enum nodetype ntype;
  union{
    struct headNode head;
    struct entryNode entry;  
  } u;
};

struct sparsematrix{
  /*
   * matrix
   *  '-> matrixNode ->(next) matrixNode(h1) ->(next) matrixNode(h2) -> ...
   *         
   *      headNode(h1) ->(right)  entryNode ->(right) -
   *         l     `-----------------------------------'(point back)
   *       (down)  
   *         v
   *      entryNode
   *         ...
   * NOTE:
   *   in the above example, h1 is the header node whose right is the first node
   *   in row 1 and whose down is the first node in col 1, thus if the matrix 
   *   is 4x5 then we only need 5 head node, but the fifth node will never use
   *   it's right because there is no fifth row.
   */
  struct matrixNode *head;
  int row;
  int col;
};

typedef struct sparsematrix SparseMatrix;
typedef struct matrixNode matrixNode;

SparseMatrix* newMatrix(int row, int col);
void addValue(SparseMatrix *sm, int row, int col, int val);
void clearValue(SparseMatrix *sm, int row, int col);
void printMatrix(SparseMatrix* sm);
void expendRow(SparseMatrix *sm,int addrowNum);
void expendCol(SparseMatrix *sm,int addcolNum);

 