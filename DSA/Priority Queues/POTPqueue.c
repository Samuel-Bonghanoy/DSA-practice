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

    if(left <= q->lastIndex && q->heap[left] < q->heap[smallest]) {
        smallest = left;
    }

    if(right <= q->lastIndex && q->heap[right] < q->heap[smallest]) {
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
  int temp, index;
  q->heap[++q->lastIndex] = elem;
  for(index = q->lastIndex; q->heap[index] < q->heap[(index-1)/2]; index = (index-1)/2){
    temp = q->heap[index];
    q->heap[index] = q->heap[(index - 1)/2];
    q->heap[(index-1)/2] = temp;
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

    return q.heap[left] < q.heap[right] ? left : right;
}

int DeleteMin(pQueue *q) {
    // int temp, index = 0, retVal = q->heap[index], isSmallest = 0;
    // q->heap[index] = q->heap[q->lastIndex];
    // q->heap[q->lastIndex--] = DNE;
    // while(q->heap[index] > SmallestChild(*q, index) && (index * 2) - 1 <= q->lastIndex) {
    //     int left = LeftChild(index), right = RightChild(index), temp = q->heap[index];

    //     if(SmallestChild(*q, index) == left) {
    //         q->heap[index] = q->heap[(index *2) - 1];
    //         q->heap[(index * 2) - 1] = temp;
    //         index = (index * 2) - 1;
    //     }

    //     if(SmallestChild(*q, index) == right) {
    //         q->heap[index] = q->heap[(index*2) + 2];
    //         q->heap[(index*2) + 2]= temp;
    //         index = (index*2) + 2;
    //     }
    // }
    // return retVal;

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
    for(x = 0; x <= q->lastIndex; x++){
        q->heap[x] = DNE;
    }
}

//heap sort psuedo
// turn an array into a heap
// deletemin from your heap
// store it in an array

void heapsort(int *arr, int size) {
    pQueue q;
    Initialize(&q);
    int x;
    for(x = 0; x < size; x++) {
        Insert(arr[x], &q);
    }

    for(x=0;x < size ;x++){
        arr[x] = DeleteMin(&q);
    }
}

void heapifyArr(int *arr, int size, int index) {
    int smallest = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    if (leftChild < size && arr[leftChild] > arr[smallest]) {
      smallest = leftChild;
    }

    if (rightChild < size && arr[rightChild] > arr[smallest]) {
      smallest = rightChild;
    }

    if (smallest != index) {
      swap(&arr[index], &arr[smallest]);
      heapifyArr(arr, size, smallest);
    }
}

void heapsort2(int *arr, int size){
    int x;
    for (x = size / 2 - 1; x >= 0; x--) {
    heapify(arr, size, x);
  }

    for(x = 0; x < size; x++) {
        heapifyArr(arr, size, x);
    }
}

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

// int temp, index = 0;
//     q->heap[index] = q->heap[q->lastIndex];
//     q->heap[q->lastIndex--] = DNE;
//     while((index * 2) + 1 < q->lastIndex && (q->heap[index] > q->heap[LeftChild(index)] || q->heap[index] > q->heap[RightChild(index)])) {
//         int smallestChild = SmallestChild(*q, index), left = LeftChild(index), right = RightChild(index);
//         if(smallestChild == left){
//             swap(&(q->heap[index]), &(q->heap[left]));
//             index = (index * 2) + 1;
//         }

//         if(smallestChild == right){
//             swap(&(q->heap[index]), &(q->heap[right]));
//             index = (index * 2) + 2;
//         }
//     }
    