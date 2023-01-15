#ifndef STACK
#define STACK
#endif

#ifndef QUEUE
struct node{
  int data;
  struct node *next;
};
#endif

struct stack{
  int depth;
  struct node *top;
};

typedef struct node Node;
typedef struct stack Stack;

Stack* newStack();
bool isSEmpty(void*);
void printStack(Stack *);
void spush(void*,int);
void spop(void*);