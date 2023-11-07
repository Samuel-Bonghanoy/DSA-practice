#ifndef DATASTRUCTURE_IMPLEMENTATIONNAME
#define DATASTRUCTURE_IMPLEMENTATIONNAME

#include <stdio.h>
#include <stdlib.h>

// * MACROS HERE
#define MAX 20

// * TYPE DEFINITIONS HERE

 
typedef struct {
	int heap[MAX];
	int lastIndex;
}pQueue;

// * OPERATIONS HERE
void Insert(int elem, pQueue *q);
void Display(pQueue q);
void DeleteMin(pQueue *q);
void Initialize(pQueue *q);
void MakeNull(pQueue *q);

#endif