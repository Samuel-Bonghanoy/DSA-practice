#ifndef DATASTRUCTURE_IMPLEMENTATIONNAME
#define DATASTRUCTURE_IMPLEMENTATIONNAME
#include <stdio.h>
#include <stdlib.h>
// * MACROS HERE
#define MAX 10

// * TYPE DEFINITIONS HERE
typedef struct Node {
    int key;
    struct Node* link;
} *Nodetype;

typedef struct {
    Nodetype Header[MAX];
    int root;
} TREE;

typedef int node;
typedef int label;

// * OPERATIONS HERE
void Display(TREE T);
void Children(node N, TREE T);
node Parent(int N, TREE T);
node Leftmost_Child(node N, TREE T);
node Right_Sibling(node N, TREE T);
label Label(node N, TREE T);
node Root(TREE T);
void Initialize(TREE *T);
void MakeNULL(TREE *T);
void Insert(node N, TREE *T, int key);

#endif