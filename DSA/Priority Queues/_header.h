#ifndef DATASTRUCTURE_IMPLEMENTATIONNAME
#define DATASTRUCTURE_IMPLEMENTATIONNAME

#include <stdio.h>
#include <stdlib.h>

// * MACROS HERE
#define MAX 20
#define DNE -100

// * TYPE DEFINITIONS HERE
typedef struct {
	int heap[MAX];
	int lastIndex;
}pQueue;

// * OPERATIONS HERE
void swap(int *a, int *b);

void Heapify(pQueue *q, int index);

void Insert(int elem, pQueue *q);

void Display(pQueue q);

int LeftChild(int index);

int RightChild(int index);

int SmallestChild(pQueue q, int index);

int DeleteMin(pQueue *q);

void Initialize(pQueue *q);

#endif