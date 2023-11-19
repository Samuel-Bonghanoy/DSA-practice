#ifndef DATASTRUCTURE_IMPLEMENTATIONNAME
#define DATASTRUCTURE_IMPLEMENTATIONNAME
#include <stdio.h>
#include <stdlib.h>

// * MACROS HERE
#define MAX 10

// * TYPE DEFINITIONS HERE
typedef enum boolean{FALSE, TRUE} Boolean;
 
typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}*BSTPtr;

typedef int node;

void Initialize(BSTPtr *B);
void Preorder(BSTPtr B);
void Postorder(BSTPtr B);
void Inorder(BSTPtr B);
void Insert(BSTPtr *B, node N);
void Delete(BSTPtr *B, node N);
Boolean Member(BSTPtr B, node N);
node Min(BSTPtr B);
node Max(BSTPtr B);


#endif