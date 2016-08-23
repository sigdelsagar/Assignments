#include<stdio.h>
void quicksort(int *arr, int lowerbase, int higherbase)
{
  int pivot, i, j, temp;
  if(higherbase > lowerbase) {
    pivot = higherbase; // select a pivot element as high
    i = lowerbase;
    j = higherbase;
    while(i < j) {
      while(arr[j] <= arr[pivot] && j >= lowerbase){
	  
        j--;                 // decrement j till you get a number greater than the pivot element
		}
      
      while(arr[i] > arr[pivot] && i <= higherbase)
        i++;
      
      if(j > i) {           // if j > i swap the elements in locations i and j
        temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
      }
    }

    // when j >= i it means the i-th position is the correct position
    // of the pivot element, hence swap the pivot element with the
    // element in the i-th position
    temp = arr[i];
    arr[i] = arr[pivot];
    arr[pivot] = temp;
    // Repeat quicksort for the two sub-arrays, one to the left of i
    // and one to the right of i
    
	quicksort(arr, lowerbase, i-1);
    quicksort(arr, i+1, higherbase);
  }
}
int main()
{
  int n, i;
  printf("Enter the size of the array\n");
  scanf("%d", &n);
int arr[n];
  printf("Enter the elements to be sorted\n");
  for(i = 0; i < n; i++)
    scanf("%d", &arr[i]);

  quicksort(arr, 0, n-1);

  printf("Sorted array\n");
  for(i = 0; i < n; i++)
    printf("%d ", arr[i]);

  return 0;
}
