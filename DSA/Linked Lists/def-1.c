#include "_header.h"

// * FUNCTION DEFINITIONS HERE
void displayList(LIST head) {
    LIST trav;
    for(trav = head; trav != NULL; trav = trav->link) {
        printf("%d => ", trav->data);
    }
}

void insertFirst(LIST* head, int data) {
    LIST temp = (LIST)malloc(sizeof(struct node));
    if(temp != NULL) {
        temp->data = data; 
        temp->link = *head;
        *head = temp;
    }
}

void insertLast(LIST* head, int data) {
    LIST *trav, temp;

    temp = (LIST)malloc(sizeof(struct node));

    if(temp != NULL) {
        temp->data = data;
        if(*head != NULL) {
            for(trav = head; *trav != NULL; trav = &(*trav)->link) {}
            *trav = temp;
            temp->link = NULL;
        } else {
            temp->link = *head;
            *head = temp;
        }
    }
}

void insertSorted(LIST* head, int data) {
    LIST *trav, temp;
    temp = (LIST)malloc(sizeof(struct node));

    if(temp != NULL) {
        temp->data = data;
        if(*head != NULL) {
            for(trav = head; *trav != NULL && data > (*trav)->data; trav = &(*trav)->link){}
            temp->link = *trav;
            *trav = temp;
        } else {
            temp->link = *head;
            *head = temp;
        }
    }
}

void insertAtPos(LIST* head, int data, int index) {
    LIST *trav, temp;

    temp = (LIST)malloc(sizeof(struct node));
    if(temp != NULL) {
        
    }
}

void deleteFirst(LIST* head);

void deleteAtPos(LIST* head, int pos) ;

int search(LIST head, int data);
