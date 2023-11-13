#include "_header.h"

// * FUNCTION DEFINITIONS HERE
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Heapify(pQueue *q, int index) {
   int left = LeftChild(index);
   int right = RightChild(index);
   int smallest = index;

   if(left <= q->lastIndex && q->heap[smallest] > q->heap[left]) {
     smallest = left;
   }

   if(right <= q->lastIndex && q->heap[smallest] > q->heap[right]) {
    smallest = right;
   }

   if(smallest != index) {
      int temp = q->heap[index];
      q->heap[index] = q->heap[smallest];
      q->heap[smallest] = temp;
      Heapify(q, smallest);
   }
}


void Insert(int elem, pQueue *q){
  int index, temp;
  if(q->lastIndex < MAX) {
    q->heap[++q->lastIndex] = elem;

    for(index = q->lastIndex; q->heap[index] < q->heap[(index-1)/2]; index = (index-1)/2){
      temp = q->heap[index];
      q->heap[index] = q->heap[(index-1)/2];
      q->heap[(index-1)/2] = temp;
    }
  }
}

void Display(pQueue q){
    int x, y;
    for(x = 0; x <= q.lastIndex; x++){
       printf("[%d] => ", q.heap[x]);

       if(LeftChild(x) <= q.lastIndex) {
           printf("%d => ", q.heap[(x * 2) + 1]);
           if(RightChild(x) <= q.lastIndex) printf("%d", q.heap[(x * 2) + 2]);       
        }

       printf("\n");
    } 
}

int LeftChild(int index) {
   return (index * 2) + 1;
}

int RightChild(int index) {
    return (index * 2) + 2;
}

int SmallestChild(pQueue q, int index) {
  int left = LeftChild(index);
  int right = RightChild(index);

  return left > right ? left : right;
}

int DeleteMin(pQueue *q) {
  int retval = q->heap[0];
  q->heap[0] = q->heap[q->lastIndex--];
  Heapify(q, 0);
  return retval;
}

void Initialize(pQueue *q) {
  int x;
    for(x = 0; x < MAX; x++) {
        q->heap[x] = DNE;
    }
  q->lastIndex = -1;
}

void MakeNull(pQueue *q){
  int x;
    for(x = 0; x < MAX; x++) {
        q->heap[x] = DNE;
    }
}

void heapsort(int *arr, int size) {
  int x;
  pQueue q;
  Initialize(&q);

  for(x = 0; x < size; x++) {
    Insert(arr[x], &q);
  }

  for(x = 0; x < size; x++) {
    arr[x] = DeleteMin(&q);
  }
}



void heapifyArr(int *arr, int size, int index) {}

void heapsort2(int *arr, int size){}

int main(void) 
{   
    // int arr [9]= {9,2,18,23,5,1,8,27,7};
    pQueue q;
    Initialize(&q);
    Insert(3, &q);
    Insert(10, &q);
    Insert(2, &q);
    Insert(39, &q);
    Insert(9, &q);
    Insert(15, &q);
    Insert(23, &q);
    Insert(4, &q);
    Insert(1, &q);
    Insert(20, &q);
    Insert(7, &q);
    Insert(15, &q);
    Insert(0, &q);
    DeleteMin(&q);
    DeleteMin(&q);
    DeleteMin(&q);
    DeleteMin(&q);
    DeleteMin(&q);
    // DeleteMin(&q);
    Display(q);
    // heapsort(arr, 9);
    // for(int x = 0; x < 9; x ++) {
    //     printf("%d ", arr[x]);
    // }
    return 0;
}

