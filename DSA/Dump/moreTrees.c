/* * * * * * * * * * * * * * * * * * 
* AUTHOR: MODESTO, MARY CHEVEL P.   *
* SCHOOL YEAR: 2023 - 2024          *
* DSA PROF: MA'AM PINEAPPLE         *
* DATE: NOVEMBER 1, 2023            *
* * * * * * * * * * * * * * * * * */

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct Node{
    int key;
    struct Node *link;
}*NodeType;

typedef struct {
    NodeType Header[MAX];
    int Root;
}TREE;

typedef int node;
typedef int label;

void Display(TREE T);
void Children(node N, TREE T);
node Parent(node N, TREE T);
node Leftmost_Child(node N, TREE T);
node Right_Sibling(node N, TREE T);
label Label(node N, TREE T);
node Root(TREE T);
void Initialize(TREE *T);
void MakeNULL(TREE *T);

void Insert(node N, int Key, TREE *T);

int main()
{
    TREE myTree;

    //INITIALIZE MY TREE
    Initialize(&myTree);
    Display(myTree);

    //INSERT INTO MY TREE
    Insert(3, 1, &myTree);
    Insert(3, 8, &myTree);
    Insert(1, 9, &myTree);
    Insert(3, 2, &myTree);
    Display(myTree);

    //DISPLAY ALL CHILDREN OF A NODE
    Children(1, myTree);

    //DISPLAY PARENT OF A NODE
    printf("\n%d\n", Parent(1, myTree));

    //DISPLAY THE LEFT MOST CHILD OF ALL THE NODES
    int x;
    for (x = 0; x < MAX; ++x) {
        printf("[%d] => %d\n", x, Leftmost_Child(x, myTree));
    }
    printf("\n");

    //DISPLAY THE RIGHT SIBLING OF ALL NODES
    for (x = 0; x < MAX; ++x) {
        printf("[%d] => %d\n", x, Right_Sibling(x, myTree));
    }
    printf("\n");
    return 0;
}

void Display(TREE T) {
    printf("ROOT: %d...\n", T.Root);

    int x;
    NodeType trav;
    for (x = 0; x < MAX; ++x) {
        printf("[%d] => ", x);
        for (trav = T.Header[x]; trav != NULL; trav = trav->link) {
            printf("%d ", trav->key);
        }
        printf("\n");
    }
    printf("\n");
}

void Children(node N, TREE T) {
    if (N >= 0 && N < MAX) {
        NodeType trav;
        printf("[%d] => ", N);
        for (trav = T.Header[N]; trav != NULL; trav = trav->link) {
            printf("%d ", trav->key);
        }
        printf("\n");
    }
}

node Parent(node N, TREE T) {
    int x, retVal = -1;
    NodeType trav = NULL;
    for (x = 0; x < MAX && trav == NULL; ++x) {
        for (trav = T.Header[x]; trav != NULL && trav->key != N; trav = trav->link) {}
    }
    return trav == NULL ? retVal : x - 1;
}

node Leftmost_Child(node N, TREE T) {
    return T.Header[N] == NULL ? -1 : T.Header[N]->key;
}

node Right_Sibling(node N, TREE T) {
    int x, retVal = -1;
    NodeType trav = NULL;
    for (x = 0; x < MAX && trav == NULL; ++x) {
        for (trav = T.Header[x]; trav != NULL && trav->key != N; trav = trav->link) {}
    }
    return trav == NULL ? retVal : trav->link == NULL ? retVal : trav->link->key;
}

label Label(node N, TREE T) {
    return T.Header[N] == NULL ? -1 : N;
}

node Root(TREE T) {
    return T.Root;
}

void Initialize(TREE *T) {
    int x;
    for (x = 0; x < MAX; ++x) {
        T->Header[x] = NULL;
    }
    T->Root = -1;
}

void MakeNULL(TREE *T) {
    int x;
    for (x = 0; x < MAX; ++x) {
        T->Header[x] = NULL;
    }
    T->Root = -1;
}

void Insert(node N, int Key, TREE *T) {
    if (N >= 0 && N < MAX) {
        NodeType newNode = (NodeType)malloc(sizeof(struct Node));
        newNode->key = Key;
        newNode->link = NULL;
        if (T->Root == -1) {
            T->Header[N] = newNode;
            T->Root = N; 
        } else {
            NodeType *trav;
            for (trav = &(T->Header[N]); *trav != NULL; trav = &(*trav)->link) {}
            *trav = newNode;
        }
    }
}