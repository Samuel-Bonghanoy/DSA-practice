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

void push(Stack s, char elem);
void pop(Stack s);
char top(Stack s);
bool isEmpty(Stack s);
bool isFull(Stack s);
Stack init(void);
void displayStack(Stack s);


void push(Stack s, char elem)
{
  if (s->top < MAX - 1)
  {
    s->data[++s->top] = elem;
  }
}


void insertBottom(Stack s, char elem)
{
  if (!isFull(s))
  {
    Stack temp = init();

    while (!isEmpty(s))
    {
      push(temp, top(s));
      pop(s);
    }

    push(s, elem);

    while (!isEmpty(temp))
    {
      push(s, top(temp));
      pop(temp);
    }

    free(temp);
  }
}

void pop(Stack s)
{
  if (s->top >= 0)
  {
    s->top--;
  }
}


char top(Stack s)
{
  return (!isEmpty(s) ? s->data[s->top] : '\0');
}


bool isEmpty(Stack s)
{
  return s->top == -1;
}


bool isFull(Stack s)
{
  return s->top >= MAX - 1;
}


Stack init(void)
{
  Stack s = (Stack)malloc(sizeof(struct Stack));
  s->top = -1;
  return s;
}

/**
 * @brief Pretty prints the stack's elements, starting from the top-most element to the bottom.
 */
void displayStack(Stack s)
{
  puts("");

  Stack temp = init();

  while (!isEmpty(s))
  {
    char element = top(s);
    printf("|%3c%3c\n", element, '|');
    push(temp, element);
    pop(s);
  }

  while (!isEmpty(temp))
  {
    char element = top(temp);
    push(s, element);
    pop(temp);
  }

  free(temp);

  if (isEmpty(s))
  {
    puts("|     |");
  }
  puts("-------");
}

/**
 * @brief Returns the length of the stack
 */
int length(Stack s)
{
  return s->top + 1;
}

/**
 * @brief Clears the stack.
 */
void makeNull(Stack s)
{
  s->top = -1;
}

/**
 * @brief Prints a statement to debug the connection between main.c and stack.h with their private implementations.
 */
void debugPrint(void)
{
  printf("\e[0;34m");
  puts("I'm in /src/stack/array/stack.c!\n");
  printf("\e[0m");
}