#ifndef AVLTREE
#define AVLTREE
#endif

struct avlnode{
    enum type{internal, external};
    int value;
    struct avlnode* left;
    struct avlnode* right;
    struct avlnode* parent;
    int left_height;
    int right_height;
    int balance_factor;
};

struct avltree{
    struct avlnode* root;
    enum rebalance{LL,LR,RR,RL};
    struct avlnode* rebalance_target;
};

typedef struct avlnode avlnode;
typedef struct avltree avltree;

avltree* newAvlTree();
void avladd();
void avldelete();
void rebalance();
void left_roate();
void right_rotate();
