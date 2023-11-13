#include "_header.h"

// * FUNCTION DEFINITIONS HERE
VirtualHeap init() {
    VirtualHeap VH;
    int x;

    VH.nodes = (Node *)malloc(sizeof(struct node));

    for(x = MAX - 1; x <= 0; x--) {
        VH.nodes[x].link = x - 1;
    }

    VH.avail = MAX - 1;

    return VH;
}

void displayList(VirtualHeap VH, LIST L) {
    int trav;

    for(trav = L; trav != -1; trav = VH.nodes[trav].link) {
        printf("[%d]=> ", VH.nodes[trav].data);
    }
}

int alloc(VirtualHeap* VH) {
    int retval = -1;

    if(VH->avail != -1) {
        retval = VH->avail;
        VH->avail = VH->nodes[VH->avail].link;
    }

    return retval;
}

void insertFirst(VirtualHeap *VH, LIST *L, char elem) {
    int index = alloc(VH);

    if(index != -1) {

    }
}
void dealloc(VirtualHeap *VH, LIST *L, int index);

void insertRear(VirtualHeap *VH, LIST *L, char elem);

void insertSorted(VirtualHeap *VH, LIST *L, char elem);

int main()
{
  VirtualHeap VH = init();
  LIST L = -1;
  
  puts("Avail at the start:");
  displayList(VH, VH.avail); // prints VH->Avail list
  puts("");

  insertFirst(&VH, &L, 'e');
  displayList(VH, L);
  puts("");
  insertFirst(&VH, &L, 'd');
  displayList(VH, L);
  puts("");
  insertFirst(&VH, &L, 'c');
  displayList(VH, L);
  puts("");
  insertFirst(&VH, &L, 'b');
  displayList(VH, L);
  puts("");
  // insertRear(&VH, &L, 'a');
  // displayList(VH, L);
  // puts("");
  insertSorted(&VH, &L, 'f');
  displayList(VH, L);
  puts("");
  // dealloc(&VH,&L, 9);
  // insertFirst(&VH, &L, 'j');
  // displayList(VH, L);
  // printf("%d", L);
  // puts("");
  // insertFirst(&VH, &L, 'c');
  // puts("New List L:");
  // displayList(VH, L); // prints L list
  // puts("Avail:");
  // displayList(VH, VH.avail); // prints VH->Avail list
  // puts("");
  return 0;
}