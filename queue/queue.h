#ifndef QUEUE
#define QUEUE
#endif

#ifndef STACK
struct node{
  void* data;
  struct node *next;
};
#endif

struct queue{
  unsigned length;
  struct node *head;
  struct node *tail;
};

typedef struct node Node;
typedef struct queue Queue;

Queue* newQueue();
bool isQEmpty(void*);
void printQueue(Queue*);
int qlen(Queue*);
void qclear(Queue*);
void qpush(void*,void*);
void** qpop(void*);

#define PRINTQUEUE(q, struct_name,symbol ) \
printf("head: "); \
for(Node *n = q->head; n != NULL; n = n->next){ \
  printf("%d->",(*(struct_name**)(n->data))->symbol); \
} \
printf("NULL\n");
