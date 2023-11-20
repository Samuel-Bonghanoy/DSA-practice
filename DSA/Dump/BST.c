#include <stdio.h>
#include <stdlib.h>
#define EMP -1

typedef enum {FALSE, TRUE} Boolean;

typedef struct Node {
    int key;
    struct Node *left;
    struct Node *right;
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

int main()
{
    BSTPtr myBST;
    int mySet[] = {15, 13, 18, 19, 5, 14, 4, 10, 7, 2, 12, 3};

    //Initialize my BST;
    Initialize(&myBST);

    //Insert into my BST
    int x;
    for (x = 0; x < 12; ++x) {
        Insert(&myBST, mySet[x]);
    }

    //Display Preorder
    Preorder(myBST);

    //Delete from my BST
    Delete(&myBST, 19);

    //Display updated BST
    printf("\n");
    Preorder(myBST);
    printf("\n");
    Postorder(myBST);
    printf("\n");
    Inorder(myBST);

    //Checking to see if my Member function worked
    printf("\n[%d] => %s", Member(myBST, 19), Member(myBST, 19) == TRUE ? "True" : "False");

    //Finding out what are the highest and lowest values
    printf("\nLOWEST: [%d]...\tHIGHEST:[%d]...", Min(myBST), Max(myBST));
    return 0;
}

void Initialize(BSTPtr *B) {
    *B = NULL;
}

void Preorder(BSTPtr B) {
    printf("%d ", B->key);
    if (B->left != NULL) {
        Preorder(B->left);
    } 

    if (B->right != NULL){
        Preorder(B->right);
    }
}

void Postorder(BSTPtr B) {
    if (B->left != NULL) {
        Postorder(B->left);
    } 

    if (B->right != NULL){
        Postorder(B->right);
    }
    printf("%d ", B->key);
}

void Inorder(BSTPtr B) {
    if (B->left != NULL) {
        Inorder(B->left);
    } 

    printf("%d ", B->key);

    if (B->right != NULL){
        Inorder(B->right);
    }
}

void Insert(BSTPtr *B, node N) {
    BSTPtr *trav;
    for (trav = B; *trav != NULL; ) {
        if (N > (*trav)->key) {
            trav = &(*trav)->right;
        } else {
            trav = &(*trav)->left;
        }
    }
    BSTPtr newNode = (BSTPtr)malloc(sizeof(struct Node));
    newNode->key = N;
    newNode->left = NULL;
    newNode->right = NULL;
    *trav = newNode;
}

void Delete(BSTPtr *B, node N) {
    BSTPtr *trav, trav2;
    for (trav = B; *trav != NULL && (*trav)->key != N; ) {
        if (N > (*trav)->key) {
            trav = &(*trav)->right;
        } else {
            trav = &(*trav)->left;
        }
    }

    //printf("[%d]", (*trav)->key);

    if ((*trav)->key == N) {
        for (trav2 = *trav; trav2->left != NULL; trav2 = trav2->left, (*trav)->key = trav2->key, trav = &(*trav)->left) {}
        if ((*trav)->right != NULL || trav2->left == NULL) {
            trav2 = *trav;
            *trav = (*trav)->right;
            free(trav2);
        } 
    }
}

Boolean Member(BSTPtr B, node N) {
    for (; B != NULL && B->key != N; ) {
        if (N > B->key) {
            B = B->right;
        } else {
            B = B->left;
        }
    }
    return B == NULL ? FALSE : TRUE;
}

node Min(BSTPtr B) {
    node retVal = B->key;
    for (; B->left != NULL; B = B->left) {}
    return B->key == retVal ? retVal : B->key;
}

node Max(BSTPtr B) {
    node retVal = B->key;
    for (; B->right != NULL; B = B->right) {}
    return B->key == retVal ? retVal : B->key;
}