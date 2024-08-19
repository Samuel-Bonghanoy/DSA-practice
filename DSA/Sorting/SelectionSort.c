void selectionSort(int arr[], int size)
{
  int CE, y, smallIndex;

  for(CE = 0; CE < size - 1; CE++)
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