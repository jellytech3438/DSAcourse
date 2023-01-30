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

struct hnode{
    // if this heap represented in array, this node's index
    int index;
    int value;
    struct hnode* left;
    struct hnode* right;
};

struct heap{
    // max or min heap
    enum{ max, min} ordertype;
    struct hnode* root;
};

typedef struct cbintree cbinTree;
typedef struct cbintnode cbintNode;
typedef struct threadtree threadTree;
typedef struct threadnode threadNode;
typedef struct hnode hNode;
typedef struct heap Heap;

cbintNode* newCBinTNode(int val);
cbinTree* newCBinTree();
bool isCBinTEmpty(void*);
void printPreorder(void*);
void printInorder(void*);
void printPostorder(void*);
void cbtadd(cbinTree**,int);

threadNode* newThreadNode(int val);
threadTree* newThreadTree();
bool isThreadTEmpty(void*);
void tprintInorder(void*);
void threadtadd(threadTree**,int);

hNode* newHNode(int val);
Heap* newHeap(int order_type);
bool isHeapEmpty(void*);
void hadd(Heap**, int);
