#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}

void selectionSort(int arr[], int size)
{
  int x, y, smallIndex;

  for(x = 0; x < size - 1; x++)
  {
    smallIndex = x;
    for(y = x + 1; y < size; y++)
    {
      if(arr[y] < arr[smallIndex])
        smallIndex = y;
    }

    if(x != smallIndex) swap(arr + x, arr + smallIndex);
  }
}

void insertionSort(int a[], int n)
{
    int i, j, temp;
    
     for(i = 1; i <= n - 1; i++)
    {
        for(j = i; j > 0 && a[j - 1] > a[j]; j--)
        {
                temp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = temp;
        }
    }
}

void shiftInsertionSort(int a[], int n)
{
  int i, j, temp;

  for(i = 2; i < n; i++)
  {
    temp = a[i];

    for(j = i - 2; j >= 1 && temp > a[j]; j--)
    {
      a[j] = a[j - 1];
    }

    a[i] = temp;
  }
}

void insertionSort2(int a[], int size)
{
  int x, y, temp;

  for(x = 0; x < size; x++)
  {
    temp = a[x];
    for(y = x; y >= 1 && temp > a[y]; y--)
    {
      a[y] = a[y - 1];
    }
  }
}


void bubbleSort(int array[], int size) {
  for (int step = 0; step < size - 1; ++step) {
      
    for (int i = 0; i < size - step - 1; ++i) {
      
      if (array[i] > array[i + 1]) {
        int temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
      }
    }
  }
}

int main(void)
{
  int arr[7] = {7, 9, 3, 4,2, 1, 6};

  for(int i = 0; i < 7; i++)
    printf("%d ", arr[i]);

  printf("\n");

  shiftInsertionSort(arr, 7);
  
  for(int i = 0; i < 7; i++)
    printf("%d ", arr[i]);
}  