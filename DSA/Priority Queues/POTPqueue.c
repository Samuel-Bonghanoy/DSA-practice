#include "_header.h"

// * FUNCTION DEFINITIONS HERE
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
    int x;
    for(x = 0; x <= q.lastIndex; x++) {
        printf("%d", q.heap[x]);
    }
}

void DeleteMin(pQueue *q);

void Initialize(pQueue *q) {
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