#include "_header.h"

// * FUNCTION DEFINITIONS HERE
VirtualHeap init() {
   VirtualHeap VH;
   int x;

  VH.nodes = (Node *)malloc(MAX * sizeof(struct node));

   for(x = MAX - 1; x >= 0; x--){
    VH.nodes[x].link = x - 1;
   }

   VH.avail = MAX - 1;

   return VH;
}

void displayList(VirtualHeap VH, LIST L) {
    int trav; 

    for(trav = L; trav != -1; trav = VH.nodes[trav].link){
        printf("[%c]=> ", VH.nodes[trav].data);
    }
    printf("\n");
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

  if(index != -1){
    VH->nodes[index].data = elem;
    VH->nodes[index].link = *L;
    *L = index;
  }
}
void dealloc(VirtualHeap *VH, LIST *L, int index) {
    // int x, trav;

    // for(x = 0, trav = *L; trav != -1 && x < index; trav = VH->nodes[trav].link, x++){}

    // VH->nodes[trav].link = VH->nodes[index].link;
    VH->nodes[index].link = VH->avail;
    VH->avail = index;
}

void insertRear(VirtualHeap *VH, LIST *L, char elem) {
   int index = alloc(VH), *trav;

   if(index != -1) {
    for(trav = L; *trav != -1; trav = &(VH->nodes[*trav].link)){}

    VH->nodes[index].data = elem;
    VH->nodes[index].link = -1;
    *trav = index;
   }
}

void insertSorted(VirtualHeap *VH, LIST *L, char elem) {
    int index = alloc(VH), *trav;
    
    if(index != -1) {
        VH->nodes[index].data = elem;
        for(trav = L; *trav != -1 && elem > VH->nodes[VH->nodes[*trav].link].data; trav = &(VH->nodes[*trav].link)){}

        if(trav == L) {
          VH->nodes[index].link = *L;
          *L = index;
        } else {
          VH->nodes[index].link = *trav;
          *trav = index;
        } 
    }

  
}

int main()
{
  VirtualHeap VH = init();
  LIST L = -1;
  // insertFirst(&VH, &L, 'd');
  // displayList(VH, L);
  
//   puts("Avail at the start:");
//   displayList(VH, VH.avail); // prints VH->Avail list
//   puts("");

  insertFirst(&VH, &L, 'c');
  // displayList(VH, L);
//   puts("");
  insertFirst(&VH, &L, 'b');
//   displayList(VH, L);
//   puts("");
  insertFirst(&VH, &L, 'a');
//   displayList(VH, L);
//   puts("");
//   insertFirst(&VH, &L, 'b');
//   displayList(VH, L);
//   puts("");
//   // insertRear(&VH, &L, 'a');
//   // displayList(VH, L);
//   // puts("");
  // insertRear(&VH, &L, 'f'); 
  // insertRear(&VH, &L, 'f');
  // insertRear(&VH, &L, 'f');
  // insertRear(&VH, &L, 'f');
//   displayList(VH, L);
//   puts("");
  insertSorted(&VH, &L, 'd');
  insertSorted(&VH, &L, 'e');
  // dealloc(&VH,&L, 2);
  insertRear(&VH, &L, 'f');
  displayList(VH, L);
  displayList(VH, L);
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