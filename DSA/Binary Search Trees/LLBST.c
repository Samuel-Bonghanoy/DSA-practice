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
    
}

void Delete(BSTPtr *B, node N);

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
    
node Min(BSTPtr B);
node Max(BSTPtr B);
