#ifndef SORTING
#define SORTING
#endif

#define MAXSIZE 1000
#define COMPARE(a,b) if((a) == (b)) 0 \
else if((a) < (b)) 1 \
else if((a) > (b)) -1

typedef struct {
  int key;
} element;

element list[MAXSIZE];

int seqSearch(element a[], int k, int n ){
  int i;
  for (i = 1; i <= n && a[i].key != k; i++)
    ;
  if (i > n) return 0;
  return i;
}

int binSearch(element list[], int k, int n){
  int left = 1, right = n, middle;
  while (left <= right) {
    middle = (left + right)/2;
    switch (COMPARE(list[middle].key, k)) {
        case -1: left = middle + 1;   // list[middle] < k
          break;
        case  0: return middle;
        case  1: right = middle - 1;
    }
  }
  return 0;
}