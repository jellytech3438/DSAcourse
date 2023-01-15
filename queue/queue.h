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
  int length;
  struct node *head;
  struct node *tail;
};

typedef struct node Node;
typedef struct queue Queue;

Queue* newQueue();
bool isQEmpty(void*);
void printQueue(Queue *);
int qlen(Queue *);
void qpush(void*,void*);
void* qpop(void*);