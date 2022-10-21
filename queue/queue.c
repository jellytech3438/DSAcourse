#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

// int main(int argc, char const *argv[]) {
//   Node a,b,c;
//   Queue q;

//   Node *b_ptr = &b;

//   a.data = 3;
//   a.next = &b;
//   b.data = 2;
//   b.next = &c;
//   c.data = 1;
//   c.next = NULL;

//   q.head = &a;
//   q.length = 3;
//   q.tail = &c;

//   push(&q,0);
//   peek(&q);
//   pop(&q);
//   print_val(q.head);
//   print_length(&q);

//   return 0;
// }

void print_val(Node *t){
  Node *n = t, *temp = t->next;
  while (temp != NULL) {
    printf("%d\n", n->data);
    n = temp;
    temp = n->next;
  }
  printf("%d\n", n->data);
}

void print_length(Queue *q){
  printf("%d\n", q->length);
}

void peek(Queue *q){
  printf("%d\n", q->head->data);
}

void push(Queue *q,int val){
  Node **t = &q->head;
  Node *a = (Node*)malloc(sizeof(Node));
  a->data = val;
  a->next = *t;
  *t = a;
  q->length++;
}

void pop(Queue *q){
  Node **t = &q->head;
  Node *buffer = *t;
  while (buffer->next->next != NULL) {
    buffer = buffer->next;
  }
  buffer->next = NULL;
  q->tail = buffer;
  q->length--;
}

void reverse_ll(Node **t){
  Node **pre = t;
  Node *cur = (*t)->next;
  (*pre)->next = NULL;
  while (cur != NULL) {
    Node *next = cur->next;
    cur->next = *pre;
    *pre = cur;
    cur = next;
  }
}
