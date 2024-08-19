#include <stdio.h>
#include <stdlib.h>

typedef enum {FALSE, TRUE} Boolean;

typedef struct Node {
    char data;
    struct Node *link;
}*SET;

void initSet(SET *S);
void insertElem(SET *S, char elem);
void deleteElem(SET *S, char elem);
void displaySet(SET S);
Boolean isMember(SET S, char elem);

SET unionSet(SET A, SET B);
SET intersectionSet(SET A, SET B);
SET differenceSet(SET A, SET B);
Boolean isDisjoint(SET A, SET B);
Boolean isSubset(SET A, SET B);

int main()
{
    SET A, B;

    //initialize the set
    initSet(&A);
    initSet(&B);

    //insert elements into the set
    insertElem(&A, 'A');
    insertElem(&A, 'D');
    insertElem(&A, 'B');

    insertElem(&B, 'A');
    insertElem(&B, 'C');
    insertElem(&B, 'M');
    insertElem(&B, 'M');
    insertElem(&B, 'J');
    insertElem(&B, 'B');

    //display initial set
    displaySet(A);
    displaySet(B);

    //union of A and B
    SET C = unionSet(A, B);
    displaySet(C);

    //intersection of A and B
    SET D = intersectionSet(A, B);
    displaySet(D);

    //difference of A and B
    SET E = differenceSet(A, B);
    displaySet(E);

    //checking if A and B are disjoint or not
    printf("%d\n", isDisjoint(A, B));

    //checking if B is a subset of A
    printf("%d\n", isSubset(A, B));
    return 0;
}

void initSet(SET *S) {
    *S = NULL;
}

void insertElem(SET *S, char elem) {
    SET *trav;
    for (trav = S; *trav != NULL && (*trav)->data != elem; trav = &(*trav)->link) {}
    if (*trav == NULL || (*trav)->data != elem) {
        SET newNode = (SET)malloc(sizeof(struct Node));
        if (newNode != NULL) {
            newNode->data = elem;
            newNode->link = *trav;
            *trav = newNode;
        }
    } else {
        printf("This element already exists!...\n");
    }
}

void deleteElem(SET *S, char elem) {
    SET *trav, temp;
    for (trav = S; *trav != NULL && (*trav)->data != elem; trav = &(*trav)->link) {}
    if ((*trav)->data == elem) {
        temp = *trav;
        *trav = temp->link;
        free(temp);
    }
}

void displaySet(SET S) {
    for (; S != NULL; S = S->link) {
        printf("[%c]", S->data);
    }
    printf("\n");
}

Boolean isMember(SET S, char elem) {
    for (; S != NULL && S->data != elem; S = S->link) {}
    return S->data == elem ? TRUE : FALSE;
}

SET unionSet(SET A, SET B) {
    SET C = NULL, *trav, travA, travB;

    //for loop that will traverse through the first set and place it within the new set
    for (trav = &C, travA = A; travA!= NULL; travA = travA->link) {
        SET newNode = (SET)malloc(sizeof(struct Node));
        if (newNode != NULL) {
            newNode->data = travA->data;
            newNode->link = *trav;
            *trav = newNode;
        }
    }

    //for loop that will traverse through and add new unique items within set C
    for (travB = B; travB != NULL; travB = travB->link) {
        for (travA = A; travA != NULL && travA->data != travB->data; travA = travA->link) {}
        //NOTE: || is used because the loop will terminate when it finds an element same of that
        // in the data, meaning that it cannot be the same even if trav is NULL
        if (travA == NULL || travA->data != travB->data) {
            SET newNode = (SET)malloc(sizeof(struct Node));
            if (newNode != NULL) {
                newNode->data = travB->data;
                newNode->link = *trav;
                *trav = newNode;
            }
        }
    }
    return C;
}

SET intersectionSet(SET A, SET B) {
    SET C = NULL, *trav, travA, travB;

    for (trav = &C, travA = A; travA != NULL; travA = travA->link) {
        //make sure to use trav->link
        for (travB = B; travB->link != NULL && travB->data != travA->data; travB = travB->link) {}
        if (travA->data == travB->data) {
            SET newNode = (SET)malloc(sizeof(struct Node));
            if (newNode != NULL) {
                newNode->data = travA->data;
                newNode->link = *trav;
                *trav = newNode;
            }
        }
    }
    return C;
}

SET differenceSet(SET A, SET B) {
    SET C = NULL, *trav, travA, travB, temp;

    //for loop that places all of the elements of A within the new set
    for (trav = &C, travA = A; travA != NULL; travA = travA->link) {
        SET newNode = (SET)malloc(sizeof(struct Node));
        if (newNode != NULL) {
            newNode->data = travA->data;
            newNode->link = *trav;
            *trav = newNode;
        }
    }

    //for loop that will delete certain elements form B that are found in A within the new set
    for(trav = &C; *trav != NULL; ) {
        for (travB = B; travB->link != NULL && travB->data != (*trav)->data; travB = travB->link) {}
        if (travB->data == (*trav)->data) {
            temp = *trav;
            *trav = temp->link;
            free(temp);
        } else {
            trav = &(*trav)->link;
        }
    }
    return C;
}

Boolean isDisjoint(SET A, SET B) {
    return intersectionSet(A, B) == NULL ? TRUE : FALSE;
}

Boolean isSubset(SET A, SET B) {
    SET C = differenceSet(A, B);
    return isDisjoint(A, B) == NULL ? TRUE : FALSE;
}
