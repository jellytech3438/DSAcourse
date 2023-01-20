#ifndef BINTREE
#define BINTREE
#endif

struct cbintnode{
  int value;
  int level;
  struct cbintnode *left;
  struct cbintnode *right;
};

struct cbintree{
  struct cbintnode* root;
  int depth;
};

typedef enum{
  link,
  thread
} pointerType;

struct threadnode{
  int value;
  pointerType lpt;
  pointerType rpt;
  struct threadnode *left;
  struct threadnode *right;
};

// this threadtree is based on cbintree
struct threadtree{
  // this root is not a regular root, it is used for recording
  // the most left node and the most right node's threaded pointer
  // should point back to this root, and this root's right pointer point
  // to itself, left pointer points to the REAL root
  // and we set this root node's value to -1
  struct threadnode* root;
};

typedef struct cbintree cbinTree;
typedef struct cbintnode cbintNode;
typedef struct threadtree threadTree;
typedef struct threadnode threadNode;

cbintNode* newCBinTNode(int val);
cbinTree* newCBinTree();
bool isCBinTEmpty(void*);
void printPreorder(void*);
void printInorder(void*);
void printPostorder(void*);
void cbtadd(cbinTree**,int);
void cbtremove(cbinTree**,int);

threadNode* newThreadNode(int val);
threadTree* newThreadTree();
bool isThreadTEmpty(void*);
void tprintPreorder(void*);
void tprintInorder(void*);
void tprintPostorder(void*);
void threadtadd(threadTree**,int);
void threadtremove(threadTree**,int);