#include <stdio.h>
#include <stdlib.h>

#define MAX 10
#define EMPTY -1

typedef char Dictionary[MAX];

void init(Dictionary dict);
void printDictionary(Dictionary dict);
void insert(Dictionary dict, char ch);
int hash(char val);

int main(void) {
  Dictionary dict;
  init(dict);
  insert(dict, 'E');
  insert(dict, 'O');
  insert(dict, 'C');
  insert(dict, 'D');
  insert(dict, 'E');
  insert(dict, 'F');
  insert(dict, 'G');
  insert(dict, 'H');
  printDictionary(dict);
}

void insert(Dictionary dict, char ch) {
  int x, count = 0, index = hash(ch);

  for (x = index; count < MAX - 1 && dict[x % MAX] != EMPTY && dict[x % MAX] != ch; x++, count++) {}

  if (dict[x % MAX] == EMPTY) {
    dict[x % MAX] = ch;
  }
}

int hash(char val) {
  return val % MAX;
}
 
void init(Dictionary dict) {
  for (int i = 0; i < MAX; i++) {
    dict[i] = EMPTY;
  }
}

void printDictionary(Dictionary dict) {
  for (int i = 0; i < MAX; i++) {
    printf("%d\n", dict[i]);
  }
}