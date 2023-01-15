#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"

Queue* newQueue(){
  return malloc(sizeof(Queue));
}

bool isQEmpty(void* q){
  Queue* queue = (Queue*)q;
  return queue->head == NULL;
}

void printQueue(Queue *q){
  printf("head: ");
  for(Node *n = q->head; n != NULL; n = n->next){
    printf("%d->",n->data);
  }
  printf("NULL\n");
}

int qlen(Queue *q){
  return q->length;
}

void qpush(void* q,void* val){
  Queue* queue = (Queue*)q;
  // create new node
  Node *newnode = (Node*)malloc(sizeof(Node));
  newnode->data = val;

  if(isQEmpty(q)){
    queue->head = newnode;
  }else{
    queue->tail->next = newnode;
  }
  queue->tail = newnode;
  queue->length++;
}

void* qpop(void* q){
  Queue* queue = (Queue*)q;
  struct node* ret;
  if(isQEmpty(queue))
    return NULL;
  ret = queue->head;
  if(queue->head == queue->tail){
    queue->head = NULL;
    queue->tail = NULL;
  }else{
    queue->head = queue->head->next;
  }
  queue->length--;
  return ret;
}