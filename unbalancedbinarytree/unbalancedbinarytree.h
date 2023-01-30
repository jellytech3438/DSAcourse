#ifndef UBBINTREE
#define UBBINTREE
#endif

struct binseartnode{
  int value;
  struct binseartnode *left;
  struct binseartnode *right;
};

struct binseartree{
  struct binseartnode* root;
};

typedef struct binseartnode binseartNode;
typedef struct binseartree binsearTree;

binseartNode* newBinSTNode();
binsearTree* newBinSTree();
void binseartadd(binsearTree** t, int val);
