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

void spush(void* s,int val){
  Stack* stack = (Stack*)s;
  // create a new node
  Node *newnode = (Node*)malloc(sizeof(Node));
  newnode->data = val;

  // push by change address
  Node **t = &stack->top;
  newnode->next = *t;
  *t = newnode;
  stack->depth++;
}

void spop(void* s){
  Stack* stack = (Stack*)s;
  if(isSEmpty(s))
    return;
  Node **t = &stack->top;
  Node *buffer = *t;
  *t = buffer->next;
  stack->depth--;
}