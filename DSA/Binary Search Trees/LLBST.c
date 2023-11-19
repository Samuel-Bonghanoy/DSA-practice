#include "_header.h"

// * FUNCTION DEFINITIONS HERE
void Initialize(BSTPtr *B) {
    *B = NULL;
}

void Preorder(BSTPtr B){
    printf("%d ", B->data);

    if(B->left != NULL) Preorder(B->left);

    if(B->right != NULL) Preorder(B->right);
}

void Postorder(BSTPtr B) {
    if(B->left != NULL) Postorder(B->left);

    if(B->right != NULL) Postorder(B->right);

    printf("%d ", B->data);
}

void Inorder(BSTPtr B) {
    if(B->left != NULL) Postorder(B->left);

    printf("%d ", B->data);

    if(B->right != NULL) Postorder(B->right);
}

    
void Insert(BSTPtr *B, node N) {
    BSTPtr *trav, temp = (BSTPtr)malloc(sizeof(struct node));

    for(trav = B; *trav != NULL;) {
        if(N > (*trav)->data){
            trav = &(*trav)->right;
        } else {
            trav = &(*trav)->left;
        }
    }

    temp->data = N;
    temp->left = NULL;
    temp->right = NULL;
    *trav = temp;
}

void Delete(BSTPtr *B, node N) {
    BSTPtr *trav, temp;

    for(trav = B; *trav != NULL && (*trav)->data != N;){
        if(N > (*trav)->data){
            trav = &(*trav)->right;
        } else {
            trav = &(*trav)->left;
        }
    }

     if ((*trav)->data == N) {
        for (temp = *trav; temp->left != NULL; temp = temp->left, (*trav)->data = temp->data, trav = &(*trav)->left) {}
        if ((*trav)->right != NULL || temp->left == NULL) {
            temp = *trav;
            *trav = (*trav)->right;
            free(temp);
        } 
    }
}

Boolean Member(BSTPtr B, node N) {
    for(;B != NULL && B->data != N;){
        if(N > B->data){
            B = B->right;
        } else {
            B = B->left;
        }
    }

    return B == NULL ? FALSE : TRUE;
}
    
node Min(BSTPtr B) {
    int retval = B->data;
    for(;B != NULL; B = B->left){} 
    return retval == B->data ? retval : B->data;
}

node Max(BSTPtr B){
    int retval = B->data;
    for(;B != NULL; B = B->right){}
    return retval == B->data ? retval : B->data;
}
