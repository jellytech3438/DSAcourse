#ifndef STACK
#define STACK
#endif

#ifndef QUEUE
struct node{
  void* data;
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
void spush(void*,void*);
void** spop(void*);

#define PRINTSTACK(s, struct_name, symbol) \
printf("top: "); \
for(Node *n = s->top; n != NULL; n = n->next){ \
  printf("%d->",(*(struct_name**)(n->data))->symbol); \
} \
printf("NULL\n");
