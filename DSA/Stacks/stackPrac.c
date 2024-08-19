#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10 // can change this, it's private

struct Stack
{
  char data[MAX];
  int top;
};

typedef struct Stack *Stack;

Stack init() {
  Stack s = (Stack)malloc(sizeof(struct Stack));
  s->top = -1;
  return s;
}

void pop(Stack s) {
  if(s->top >= 0) s->top--;
}

void push(Stack s, char elem) {
  if(s->top < MAX) {
    s->data[++s->top] = elem;
  }
}

char top(Stack s){
  return (s->top != -1 ? s->data[s->top] : '\0');
}

int isEmpty(Stack s) {
  return s->top == -1 ? 1 : 0;
}

int isFull(Stack s) {
  return (s->top > MAX - 1) ? 1 : 0;
}

void insertBottom(Stack s, char elem) {
  Stack temp = init();

  if(s->top < MAX - 1) {
    while(!isEmpty(s)){
      push(temp, top(s));
      pop(s);
    }

    push(s, elem);

    while(!isEmpty(temp)){
      push(s, top(temp));
      pop(temp);
    }

    free(temp);
  }
}

void displayStack(Stack s){
  Stack temp = init();

  while(!isEmpty(s)){
    printf("|%3c%3c\n", top(s), '|');
    push(temp, top(s));
    pop(s);
  }

  while(!isEmpty(temp)){
    push(s, top(temp));
    pop(temp);
  }

  if (isEmpty(s))
  {
    printf("|     |\n");
  }
  printf("-------\n");
}

int main()
{
  Stack s = init();
  push(s, 'a');
  push(s, 'b');
  push(s, 'c');
  push(s, 'd');
  displayStack(s);
  pop(s);
  displayStack(s);
  insertBottom(s, 'f');
  displayStack(s);  
}