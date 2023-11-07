#include "_header.h"

// * FUNCTION DEFINITIONS HERE
void Insert(int elem, pQueue *q){
    int x, temp, index = ++q->lastIndex;
    q->heap[index] = elem;
    while(q->heap[index] > q->heap[(index - 1)/2]){
        temp = q->heap[(index - 1)/2];
        q->heap[(index - 1)/2] = q->heap[index];
        q->heap[index] = temp;
    }
}

void Display(pQueue q){
    int x;
    for(x = 0; x < q.lastIndex; x++) {
        printf("%d=>", q.heap[x]);
    }
}

void DeleteMin(pQueue *q);

void Initialize(pQueue *q) {
    q->lastIndex = -1;
}

void MakeNull(pQueue *q);

int main(void) 
{
    return 0;
}