#ifndef BINTREE
#define BINTREE
#endif

struct tnode{
  int value;
  int level;
  struct tnode *left;
  struct tnode *right;
};

struct tree{
  struct tnode* root;
  int depth;
};

typedef struct tree Tree;
typedef struct tnode tnode;

tnode* newTNode(int val);
Tree* newTree();
bool isTEmpty(void*);
void printPreorder(void*);
void printInorder(void*);
void printPostorder(void*);
void btadd(Tree**,int);
void btremove(Tree**,int);