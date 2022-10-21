#include <stdio.h>
#include "queue/queue.h"

int main(int argc, char const *argv[]) {
  Node a,b,c;
  Queue q;

  Node *b_ptr = &b;

  a.data = 3;
  a.next = &b;
  b.data = 2;
  b.next = &c;
  c.data = 1;
  c.next = NULL;

  q.head = &a;
  q.length = 3;
  q.tail = &c;

  push(&q,0);
  peek(&q);
  pop(&q);
  print_val(q.head);
  print_length(&q);

  return 0;
}
