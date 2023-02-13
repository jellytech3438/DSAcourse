#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

Stack* newStack(){
  return malloc(sizeof(Stack));
}

bool isSEmpty(void* s){
  Stack* stack = (Stack*)s;
  return stack->top == NULL;
}

void printStack(Stack *s){
  printf("top: ");
  for(Node *n = s->top; n != NULL; n = n->next){
    printf("%d->",n->data);
  }
  printf("NULL\n");
}

void sclear(Stack* s){
    while(s->top != NULL){
        Node* temp = s->top;
        s->top = s->top->next;
        free(temp);
    }
}

void spush(void* s,void* val){
  Stack* stack = (Stack*)s;
  // create a new node
  Node *newnode = (Node*)malloc(sizeof(Node));
  newnode->data = val;

  Node** t = &stack->top;
  newnode->next = *t;
  *t = newnode;
  stack->depth++;
}

void** spop(void* s){
  Stack* stack = (Stack*)s;
  if(isSEmpty(s))
    return NULL;
  // return ptr
  Node* ret = stack->top;
  // pop check null
  Node* t = stack->top;
  if(t->next == NULL)
    stack->top = NULL;
  else
    stack->top = t->next;
  stack->depth--;
  return &*((ret)->data);
}