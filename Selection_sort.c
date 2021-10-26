//Selection Sorted

#include <stdio.h>
#define MAX 100
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
void selectionSort(int arr[], int n)
{
    int i, j, min;
 
    for (i = 0; i < n-1; i++)
    {
        min = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min])
            min= j;
 
        swap(&arr[min], &arr[i]);
    }
}
 
void printArray(int arr[], int n)
{
    int i;
    for (i=0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int main ()
{
    int arr[MAX] , n , m;
    printf("Enter the limit of the array: ");
    scanf("%d",&n);
    
    printf("Enter the elements of the array: ");
    for(m=0;m<n;m++)
    {
    scanf("%d",&arr[m]);
    }
    selectionSort(arr, n);
    printf("Sorted array is: ");
    printArray(arr, n);
    return 0 ;
}
