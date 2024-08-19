#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10
#define EMPTY -1

typedef char String[30];

typedef struct{
	int elems[MAX];
	int front;
	int rear;
} Queue;

void initQueue(Queue *q){
  q->front = EMPTY;
  q->rear = EMPTY;
  int x;
  for(x=0; x<MAX; x++){
		q->elems[x] = EMPTY;
	}
}

void enqueue(Queue *q, int item){ 
  if (isEmpty(*q)){
    q->front = 0;
  }
  q->rear = (q->rear + 1) % MAX;
    q->elems[q->rear] = item;
}

void dequeue(Queue *q){
	q->elems[q->front] = EMPTY;
  q->front = (q->front + 1) % MAX;
}

int front(Queue q){
	if(!isEmpty(q)){
		return q.elems[q.front];
	}
	return EMPTY;
}

bool isEmpty(Queue q){
	return (q.rear == EMPTY) && (q.front == EMPTY);
}

bool isFull(Queue q){
	return (q.rear + 1)% MAX == q.front;
}

void visualize(Queue q){
	printf("%5s | %5s | %s\n", "INDEX", "VALUE", "POSITION");
	printf("------------------------\n");
	int i;
	for(i=0; i<MAX; i++){
		printf("%5d | ", i);
		if(q.elems[i] != EMPTY){
			printf("%5d | ", q.elems[i]);
		}else{
			printf("%5s | ", " ");
		}
			if(i == q.front){
				printf("Front");
			} if(i == q.rear){
				printf("Rear");
			}
		
		printf("\n");
	}
	printf("------------------------\n");
}

void display(Queue q){
	int i;
	printf("{");
	for(i=0; i<MAX; i++){
		if(q.elems[i] != EMPTY){
			printf("%d ", q.elems[i]);
		}else{
			printf("");
		}
	}
	printf("}\n\n");
}

void removeItem(Queue* q, int item) {
    int trav = q->front;
    int i;
    int count = 0;
    while(count < MAX) {
        if(q->elems[trav] == item) {
            for(i = trav; i != q->rear; i = (i + 1) % MAX) {
                q->elems[i] = q->elems[(i + 1) % MAX];
            }
            q->elems[q->rear] = EMPTY;
            q->rear = (q->rear - 1 + MAX) % MAX;
            return;
        }
        trav = (trav + 1) % MAX;
        count++;
    }
}


Queue removeEven(Queue *q) {
    Queue newQueue;
    initQueue(&newQueue);
    if (isEmpty(*q)) {
        printf("QUEUE EMPTY\n");
        return newQueue;
    }
    int i = q->front;
    while(i != q->rear) {
        if(q->elems[i] % 2 == 0) {
            enqueue(&newQueue, q->elems[i]);
            removeItem(q, q->elems[i]);
        }else{
            i = (i + 1) % MAX;
        }
    }
    if(q->elems[i] % 2 == 0) {
        enqueue(&newQueue, q->elems[i]);
        removeItem(q, q->elems[i]);
    }
    return newQueue;
}

int doubleTheValue(Queue *q, int value) {
    int changedCount = 0;
    int i, size;
    size = (q->rear - q->front + MAX + 1) % MAX;
    
    for (i = 0; i < size; i++) {
        int currentIndex = (q->front + i) % MAX;
        if (q->elems[currentIndex] % value == 0) {
            q->elems[currentIndex] *= 2;
            changedCount++;
        }
    }
    return changedCount;
}


