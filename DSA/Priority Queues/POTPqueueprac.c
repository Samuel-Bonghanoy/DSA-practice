#include "_header.h"

// * FUNCTION DEFINITIONS HERE
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Heapify(pQueue *q, int index) {
  int left = (index * 2) +1;
  int right = left + 1;
  int smallest = index;

  if(left <= q->lastIndex && q->heap[left] < q->heap[smallest]) {
    smallest = left;
  }

  if(right <= q->lastIndex && q->heap[right] < q->heap[smallest]) {
    smallest = right;
  }

  if(smallest != index) {
    int temp = q->heap[smallest];
    q->heap[smallest] = q->heap[index];
    q->heap[index] = temp;
    Heapify(q, smallest);
  }
}

void Insert(int elem, pQueue *q){
  int index, temp;
  q->heap[++q->lastIndex] = elem;

  for(index = q->lastIndex; q->heap[(index -1)/2] > elem; index = (index - 1)/2){
    int temp = q->heap[index];
    q->heap[index] = q->heap[(index - 1)/2];
    q->heap[(index - 1)/2] = temp;
  }
}

void Display(pQueue q){
    
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

  return left < right ? left : right;
}

int DeleteMin(pQueue *q) {
  int retval = q->heap[0];
  q->heap[0] = q->heap[q->lastIndex--];
  Heapify(q, 0);
  return retval;
}


void Initialize(pQueue *q) {
  
}

void MakeNull(pQueue *q){
  
}

void heapsort(int *arr, int size) {
  int x;
  pQueue q;

  for(x = 0; x < size; x++){
    Insert(&q, arr[x]);
  }

  for(x = 0; x < size; x++) {
    arr[x] = DeleteMin(&q);
  }
}


void heapifyHeap(pQueue *q) {
 
}

void insertHeapifyHeap(pQueue *q) {
 
}


void heapifyArr(int *arr, int size, int index) {}

void heapsort2(int *arr, int size){}

int main(void) 
{   
    // int arr [9]= {9,2,18,23,5,1,8,27,7};
    pQueue q;
    q.heap[0] = 3;
    q.heap[1] = 10;
    q.heap[2] = 2;
    q.heap[3] = 39;
    q.heap[4] = 9;
    q.heap[5] = 15;
    q.heap[6] = 23;
    q.heap[7] = 4;
    q.heap[8] = 1;
    q.heap[9] = 20;
    q.heap[10] = 7;
    q.heap[11] = 15;
    q.heap[12] = 0;
    q.lastIndex = 12;
    heapify2(&q);

    Display(q);
    // Initialize(&q);
    // Insert(3, &q);
    // Insert(10, &q);
    // Insert(2, &q);
    // Insert(39, &q);
    // Insert(9, &q);
    // Insert(15, &q);
    // Insert(23, &q);
    // Insert(4, &q);
    // Insert(1, &q);
    // Insert(20, &q);
    // Insert(7, &q);
    // Insert(15, &q);
    // Insert(0, &q);
    // DeleteMin(&q);
    // DeleteMin(&q);
    // DeleteMin(&q);
    // DeleteMin(&q);
    // DeleteMin(&q);
    // DeleteMin(&q);
    // Display(q);
    // heapsort(arr, 9);
    // for(int x = 0; x < 9; x ++) {
    //     printf("%d ", arr[x]);
    // }
    return 0;
}

