#ifndef STACK
#define STACK
#endif

struct node{
  int data;
  struct node *next;
};

struct stack{
  int depth;
  struct node *head;
};

typedef struct node Node;
typedef struct stack Stack;

void print_val(Node *);
void print_depth(Stack *);
void push(Stack *,int);
void pop(Stack *);
void reverse_ll(Node **);
