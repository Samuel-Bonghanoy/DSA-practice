#include "_header.h"

// * FUNCTION DEFINITIONS HERE
void displayList(LIST head) {
    LIST trav;
    for(trav = head; trav != NULL; trav = trav->link) {
        printf("%d => ", trav->data);
    }
    printf("\n");
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
    int x = 0;

    temp = (LIST)malloc(sizeof(struct node));
    if(temp != NULL) {
        for(trav = head; *trav != NULL && x < index; x++, trav = &(*trav)->link){}
        temp->data = data;
        temp->link = *trav;
        *trav = temp;
    }
}

void deleteFirst(LIST* head) {
    LIST temp = *head;
    if(*head != NULL) {
        *head =  (*head)->link;
        free(temp);
    }
}

void deleteAtPos(LIST* head, int pos) {
    LIST *trav, temp;
    int x = 0;
    for(trav = head; *trav != NULL && x < pos; x++, trav = &(*trav)->link){}
    temp = *trav;
    *trav = temp->link;
    free(temp);
}

int search(LIST head, int data) {
    LIST trav;
    int x = 1;
    for(trav = head; trav != NULL && trav->data != data; trav = trav->link, x++){}

    return (trav == NULL) ? -1 : x;
}

void deleteAllOccurences(LIST *head, int elem) {
    LIST *trav, temp;

    for(trav = head; *trav != NULL;) {
        if((*trav)->data == elem) {
            temp = *trav;
            *trav = temp->link;
        } else {
            trav = &(*trav)->link;
        }
    }
}

int main(void)
{
  LIST head = NULL;
  insertSorted(&head, 16);
  insertSorted(&head, 14);
  insertSorted(&head, 13);
  insertSorted(&head, 12);
  insertSorted(&head, 69);
  insertSorted(&head, 69);
  // insertAtPos(&head, 420, 4);
  insertSorted(&head, 42);
  insertSorted(&head, 15);
  displayList(head);
  deleteFirst(&head);
  displayList(head);
  deleteAtPos(&head, 3);
  displayList(head);
  deleteAllOccurences(&head, 69);
  displayList(head);

  printf("\n-------------* %d\n", search(head, 12312));
  printf("\n-------------* %d\n", search(head, 15));
  return 0;
}