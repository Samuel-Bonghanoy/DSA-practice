#include "_header.h"

// * FUNCTION DEFINITIONS HERE
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Insert(int elem, pQueue *q){
    int x, temp, index = ++q->lastIndex;
    q->heap[index] = elem;
    while(q->heap[index] < q->heap[(index - 1)/2]){
        temp = q->heap[(index - 1)/2];
        q->heap[(index - 1)/2] = q->heap[index];
        q->heap[index] = temp;
        index = (index - 1)/2;
    }
}

void Display(pQueue q){
    int x, y;
    for(x = 0; x < q.lastIndex; x++){
       printf("[%d] =>", q.heap[x]);

       if(q.heap[(x * 2) + 1] != DNE && (x * 2) + 1 < MAX ) {
           printf("%d => ", q.heap[(x * 2) + 1]);
           printf("%d", q.heap[(x * 2) + 2]);       
        }

       printf("\n");
    } {

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

void DeleteMin(pQueue *q) {
    int temp, index = 0, left = LeftChild(index), right = RightChild(index);
    q->heap[index] = q->heap[q->lastIndex--];
    while(q->heap[index] > q->heap[left] || q->heap[index] > q->heap[right]) {
        if(SmallestChild(*q, index) == left){

        }
    }
    
}

void Initialize(pQueue *q) {
    int x;
    for(x = 0; x < MAX; x++) {
        q->heap[x] = DNE;
    }
    q->lastIndex = -1;
}

void MakeNull(pQueue *q);

int main(void) 
{   
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
    Display(q);
    return 0;
}