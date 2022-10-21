#ifndef QUEUE
#define QUEUE
#endif

struct node{
  int data;
  struct node *next;
};

struct queue{
  int length;
  struct node *head;
  struct node *tail;
};

typedef struct node Node;
typedef struct queue Queue;
void print_val(Node *);
void print_length(Queue *);
void peek(Queue *);
void push(Queue *,int);
void pop(Queue *);
void reverse_ll(Node **);
