#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

void print_val(Node* t){
  Node* n = t, *temp = t->next;
  while (temp != NULL) {
    printf("%d\n", n->data);
    n = temp;
    temp = n->next;
  }
  printf("%d\n", n->data);
}

void add_first(Node** t,int val){
  Node* a = (Node*)malloc(sizeof(Node));
  a->data = val;
  a->next = *t;
  *t = a;
}

void add_last(Node** t,int val){
  Node* a = (Node*)malloc(sizeof(Node)), *buffer = *t;
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

void delete_first(Node** t){
  Node *buffer = *t;
  *t = buffer->next;
}

void delete_last(Node** t){
  Node *buffer = *t;
  while (buffer->next->next != NULL) {
    buffer = buffer->next;
  }
  buffer->next = NULL;
}

void reverse_ll(Node** t){
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

void concrete_ll(ll* l1, ll* l2){
  Node *tail = l1->head;
  for(; tail != NULL; tail = tail->next) continue;

  Node *node_in_l2 = l2->head;
  for(; node_in_l2 != NULL; node_in_l2 = node_in_l2->next){
    tail->next = node_in_l2;
    tail = tail->next;
  }
}