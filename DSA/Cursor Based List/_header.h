#ifndef DATASTRUCTURE_IMPLEMENTATIONNAME
#define DATASTRUCTURE_IMPLEMENTATIONNAME
#include <stdio.h>
#include <stdlib.h>

// * MACROS HERE
#define MAX 10

// * TYPE DEFINITIONS HERE
typedef int LIST;
typedef struct node{
	char data;
	int link;
}Node;

typedef struct {
	Node *nodes;
	LIST avail;
}VirtualHeap;

// * OPERATIONS HERE
#define MAX 10

VirtualHeap init();

void displayList(VirtualHeap VH, LIST L);

int alloc(VirtualHeap* VH);
void insertFirst(VirtualHeap *VH, LIST *L, char elem);
void dealloc(VirtualHeap *VH, LIST *L, int index);

void insertRear(VirtualHeap *VH, LIST *L, char elem);

void insertSorted(VirtualHeap *VH, LIST *L, char elem);
  

#endif