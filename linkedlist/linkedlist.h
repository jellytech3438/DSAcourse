#ifndef LL
#define LL
#endif

struct node{
  int data;
  struct node *next;
};

struct linkedlist{
  struct node *head;
};

struct dnode{
  int data;
  struct dnode *next;
  struct dnode *prev;
};

struct doublylinkedlist{
  struct dnode *head;
};

struct cnode{
  int data;
  struct cnode* next;
};

struct circularlinkedlist{
  struct cnode* head;
};

typedef struct node Node;
typedef struct linkedlist ll;
typedef struct doublylinkedlist dll;
typedef struct circularlinkedlist cll;

void print_val(Node *);
void add_first(Node **,int);
void add_last(Node **,int);
void remove_list_node_v3(ll*, Node*);
void delete_first(Node **);
void delete_last(Node **);
void reverse_ll(Node **);
void concrete_ll(ll *l1, ll *l2);