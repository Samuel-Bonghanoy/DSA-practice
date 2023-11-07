#ifndef DATASTRUCTURE_IMPLEMENTATIONNAME
#define DATASTRUCTURE_IMPLEMENTATIONNAME

// * MACROS HERE
#define MAX 10

// * TYPE DEFINITIONS HERE
typedef enum boolean{FALSE, TRUE}BOOLEAN;
 
typedef struct node_b_tree{
	char data;
	struct node_b_tree* left;
	struct node_b_tree* right;
}*b_tree_p, b_tree;

// * OPERATIONS HERE
void initializeBTree();
void display();
void deleteFromStruct();
void updateStruct();
void displayStruct();

#endif