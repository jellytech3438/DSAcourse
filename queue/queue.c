#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"

Queue* newQueue(){
    Queue* newQ = malloc(sizeof(Queue));
    newQ->length = 0;
    return newQ;
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

void qclear(Queue* q){
    while(q->head != NULL){
        Node* temp = q->head;
        q->head = q->head->next;
        free(temp);
    }
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

void** qpop(void* q){
  Queue* queue = (Queue*)q;
  Node* ret;
  if(isQEmpty(queue))
    return NULL;
  ret = (queue->head);
  if(queue->head == queue->tail){
    queue->head = NULL;
    queue->tail = NULL;
  }else{
    queue->head = queue->head->next;
  }
  queue->length--;
  return &*((ret)->data);
}