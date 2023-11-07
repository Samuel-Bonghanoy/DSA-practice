#include "_header.h"

// * FUNCTION DEFINITIONS HERE
void Display(TREE T) {
   int x;
   Nodetype trav;
   for(x = 0; x < MAX; x++){
        printf("[%d] ->", x);
        if(T.Header[x] == NULL) {
            printf(" NULL");
        }

        for(trav = T.Header[x]; trav != NULL; trav = trav->link){
            printf(" %d ->",  trav->key);
        } 
        printf("\n");
   }
}

void Children(node N, TREE T) {
    if(N >= 0 && N < MAX) {
        Nodetype trav;
        printf("[%d] => ", N);
        for(trav = T.Header[N]; trav != NULL; trav = trav->link){
        printf("%d->", trav->key);
        }
    }
    
}

node Parent(int N, TREE T){
    int x, retVal = -1;
    Nodetype trav;
    for(x = 0; x < MAX; x++) {
        for(trav = T.Header[x]; trav != NULL && trav->key != N; trav = trav->link){}
    }

    return trav == NULL ? retVal : x;
}

node Leftmost_Child(node N, TREE T) {
    return T.Header[N] == NULL ? -1 : T.Header[N]->key;
}

node Right_Sibling(node N, TREE T) {
    Nodetype trav;
    for(trav = T.Header[N]; trav->link != NULL; trav = trav->link){}
    return trav->key;
}


label Label(node N, TREE T){
    return T.Header[N] == NULL ? -1 : N;
}

node Root(TREE T) {
    return T.root;
}


void Initialize(TREE *T){
    int x;
    for(x = 0; x < MAX; x++) {
        T->Header[x] = NULL;
    }
    T->root = -1;
}

void MakeNULL(TREE *T) {
    int x;
    Nodetype *trav, temp;
    for(x = 0; x < MAX; x++) {
        for(trav = &(T->Header[x]); *trav != NULL;) {
            temp = *trav;
            *trav = temp->link;
            free(temp);
        }
    }
}

void Insert(node N, TREE *T, int key) {
        Nodetype newNode = (Nodetype)malloc(sizeof(Nodetype));
        newNode->key = key;
        newNode->link = NULL;
    if(T->Header[N] == NULL) {
        T->Header[N] = newNode;
    } else {
        Nodetype* trav;
        for(trav = &(T->Header[N]); *trav != NULL; trav = &(*trav)->link) {}
       
        newNode->key = key;
        newNode->link = NULL;
        *trav = newNode;
    }
}

int main(void)
{
    TREE T;
    Initialize(&T);
    Insert(3, &T, 11);
    Insert(3, &T, 69);
    Insert(3, &T, 23);
    Insert(2, &T, 9);
    Insert(2, &T, 19);
    Insert(2, &T, 4);
    Insert(5, &T, 4);
    Insert(4, &T, 5);
    Insert(4, &T, 6);
    Insert(4, &T, 9);
    Insert(7, &T, 6);
    Insert(9, &T, 2);
    Insert(8, &T, 3);
    Display(T);
    printf("AFTER MAKENULL ------------\n");
    MakeNULL(&T);
    Display(T);
}
