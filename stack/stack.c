#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

// int main(int argc, char const *argv[]) {
//   Node a,b,c;
//   Stack s;

//   Node *b_ptr = &b;

//   a.data = 3;
//   a.next = &b;
//   b.data = 2;
//   b.next = &c;
//   c.data = 1;
//   c.next = NULL;

//   s.head = &a;
//   s.depth = 3;

//   push(&s,0);
//   pop(&s);
//   // reverse_ll(&s.head);
//   print_val(s.head);
//   print_depth(&s);

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

void print_depth(Stack *s){
  printf("%d\n", s->depth);
}

void push(Stack *s,int val){
  Node **t = &s->head;
  Node *a = (Node*)malloc(sizeof(Node));
  a->data = val;
  a->next = *t;
  *t = a;
  s->depth++;
}

void pop(Stack *s){
  Node **t = &s->head;
  Node *buffer = *t;
  *t = buffer->next;
  s->depth--;
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
