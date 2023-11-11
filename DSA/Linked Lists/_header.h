#ifndef DATASTRUCTURE_IMPLEMENTATIONNAME
#define DATASTRUCTURE_IMPLEMENTATIONNAME
#include <stdio.h>
#include <stdlib.h>

// * MACROS HERE
#define MAX 10

// * TYPE DEFINITIONS HERE
typedef enum boolean{FALSE, TRUE}BOOLEAN;
 
typedef struct node{
	int data;
	struct node *link;
}*LIST;

// * OPERATIONS HERE
void displayList(LIST head);

void insertFirst(LIST* head, int data);

void insertLast(LIST* head, int data);

void insertSorted(LIST* head, int data);

void insertAtPos(LIST* head, int data, int index);

void deleteFirst(LIST* head);

void deleteAtPos(LIST* head, int pos) ;

int search(LIST head, int data);

#endif