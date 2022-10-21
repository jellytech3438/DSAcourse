#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

// int main(int argc, char const *argv[]) {
//   Node a,b,c;
//   ll l;

//   Node *b_ptr = &b;

//   a.data = 3;
//   a.next = &b;
//   b.data = 2;
//   b.next = &c;
//   c.data = 1;
//   c.next = NULL;

//   l.head = &a;

//   add_last(&l.head,0);
//   delete_last(&l.head);
//   add_first(&l.head,0);
//   delete_first(&l.head);
//   remove_list_node_v3(&l,b_ptr);
//   reverse_ll(&l.head);
//   print_val(l.head);

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

void add_first(Node **t,int val){
  Node *a = (Node*)malloc(sizeof(Node));
  a->data = val;
  a->next = *t;
  *t = a;
}

void add_last(Node **t,int val){
  //remeber that we need to allocate a new Node space to a
  Node *a = (Node*)malloc(sizeof(Node)), *buffer = *t;
  a->data = val;
  a->next = NULL;
  while (buffer->next != NULL) {
    buffer = buffer->next;
  }
  buffer->next = a;
}

void remove_list_node_v3(ll* list, Node* target){
  // The "indirect" pointer points to the *address*
  // of the thing we'll update.
  Node** indirect = &list->head;
  // Walk the list, looking for the thing that
  // points to the node we want to remove.
  while (*indirect != target)
    indirect = &(*indirect)->next;
  *indirect = target->next;
}

void delete_first(Node **t){
  // why this cannot be
  // Node *buffer = t;
  // t = buffer->next; (input is Node *t)
  Node *buffer = *t;
  *t = buffer->next;
}

void delete_last(Node **t){
  Node *buffer = *t;
  // why this cannot be while (buffer->next != NULL) ????
  while (buffer->next->next != NULL) {
    // why this cannot be *buffer = *buffer->next; ????
    buffer = buffer->next;
  }
  buffer->next = NULL;
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
