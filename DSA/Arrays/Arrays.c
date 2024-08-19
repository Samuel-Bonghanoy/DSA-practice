#include <stdio.h>
#include <stdlib.h>
#define MAX 15

void initialize(int arr[], int *count)
{
  int x;

  for (x = 0; x < *count; x++)
  {
    arr[x] = 0;
  }

  *count = 0;
}

void display(int arr[], int count)
{
  int x;
  for (x = 0; x < count; x++)
    printf("%d ", arr[x]);
  printf("\n");
}

int searchElem(int arr[], int count, int elem)
{
  int x;
  for (x = 0; x < count && arr[x] != elem; x++)
  {
  }

  return (arr[x] == elem) ? arr[x] : -1;
}

int insertLast(int arr[], int *count, int elem)
{
  if (*count != MAX)
  {
    arr[(*count)++] = elem;
  }
}

int insertFirst(int arr[], int *count, int elem)
{
  if (*count != MAX)
  {
    int x;
    for (x = *count; x > 0; x--)
    {
      arr[x] = arr[x - 1];
    }

    arr[0] = elem;
    (*count)++;
  }
}

int insertAtPos(int arr[], int *count, int elem, int pos)
{
  if (*count != MAX || count - 1 < pos)
  {
    int x;
    for (x = *count; x > pos; x--)
    {
      arr[x] = arr[x - 1];
    }

    arr[pos] = elem;
    (*count)++;
  }
}

int removeLast(int arr[], int *count)
{
  if (*count != 0)
    (*count)--;
}

int removeFirst(int arr[], int *count)
{
  if (*count != 0)
  {
    int x;
    for (x = 0; x < *count - 1; x++)
    {
      arr[x] = arr[x + 1];
    }
    (*count)--;
  }
}

int removeAtPos(int arr[], int *count, int pos)
{
  if (*count != 0)
  {
    int x;
    for (x = pos; x < *count - 1; x++)
    {
      arr[x] = arr[x + 1];
    }

    (*count)--;
  }
}

int removeElem(int arr[], int *count, int elem)
{
  int x, y;
  for (x = 0; x < *count - 1 && arr[x] != elem; x++)
  {
  }

  for (y = x; y < *count - 1; y++)
  {
    arr[x] = arr[x + 1];
  }
  (*count)--;
}

int *getEven(int arr[], int count)
{
  int x, numEven = 0;
  for (x = 0; x < count; x++)
  {
    if (arr[x] % 2 == 0)
      numEven++;
  }

  int *newArr = (int *)malloc(sizeof(int) * numEven);
  int y = 0;

  for (x = 0; x < count; x++)
  {
    if (arr[x] % 2 == 0)
    {
      newArr[y++] = arr[x];
    }
  }

  return newArr;
}

int isSortedAscending(int arr[], int count)
{
  int x;

  for (x = 0; x < count && arr[x] <= arr[x + 1]; x++)
  {
  }

  return (x == count - 1) ? 1 : 0;
}

void moveSmallestToFirst(int arr[], int count)
{
  int smallest = arr[0], x, temp = arr[0];
  for (x = 0; x < count; x++)
  {
    if (arr[x] < smallest)
    {
      smallest = arr[x];
      temp = x;
    }
  }

  arr[temp] = arr[0];
  arr[0] = smallest;
}

void sortArray(int arr[], int count)
{
  int x, y;
  for (x = 0; x < count - 1; x++)
  {
    for (y = 0; y < count - x - 1; y++)
    {
      if (arr[y] > arr[y + 1])
      {
        int temp = arr[y];
        arr[y] = arr[y + 1];
        arr[y + 1] = temp;
      }
    }
  }
}

int main(void)
{
  int arr[MAX];
  int count = MAX;

  initialize(arr, &count);
  insertLast(arr, &count, 2);
  insertLast(arr, &count, 3);
  insertLast(arr, &count, 6);
  insertLast(arr, &count, 2);
  display(arr, count);
  insertFirst(arr, &count, 1);
  display(arr, count);
  printf("%d\n", searchElem(arr, count, 3));
  insertAtPos(arr, &count, 4, 3);
  display(arr, count);
  insertAtPos(arr, &count, 19, 0);
  display(arr, count);
  // removeFirst(arr, &count);
  display(arr, count);
  // removeAtPos(arr, &count, 3);
  display(arr, count);
  // removeElem(arr, &count, 3);
  display(arr, count);
  int *arr2 = getEven(arr, count);
  // sortArray(arr, count);
  display(arr, count);

  // display(arr2, 4);

  // printf("%d\n", isSortedAscending(arr,count));
  printf("%d\n", isSortedAscending(arr2, 4));

  moveSmallestToFirst(arr, count);
  display(arr, count);

  return 0;
}