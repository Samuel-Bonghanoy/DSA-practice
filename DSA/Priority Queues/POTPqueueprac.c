#include "_header.h"

// * FUNCTION DEFINITIONS HERE
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Heapify(pQueue *q, int index) {
   
}


void Insert(int elem, pQueue *q){
  
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

int DeleteMin(pQueue *q) {}

void Initialize(pQueue *q) {}

void MakeNull(pQueue *q){}

void heapsort(int *arr, int size) {}

void heapifyArr(int *arr, int size, int index) {}

void heapsort2(int *arr, int size){}

int main(void) 
{   
    int arr [9]= {9,2,18,23,5,1,8,27,7};
    pQueue q;
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
    // // DeleteMin(&q);
    // // DeleteMin(&q);
    // Display(q);
    heapsort2(arr, 9);
    for(int x = 0; x < 9; x ++) {
        printf("%d ", arr[x]);
    }
    return 0;
}

