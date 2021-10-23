//Bubble sort

#include<stdio.h>

#define MAX 100 


void bubblesort(int arr[], int n)
{
    int i , j ;
    for(i=0 ; i < n ; i++)
        for(j= 0 ; j < n - i - 1 ; j++)
            if(arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
}

int swap(int *x, int *y)
{
    int temp = *x ;
    *x = *y ;
    *y = temp ;
}

void printarray(int arr[], int n)
{
    int i ; 
    for(i = 0 ; i < n ; i++)
    printf("%d ",arr[i]);
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
    bubblesort(arr, n);
    printf("Sorted array is: ");
    printarray(arr, n);
    return 0 ;
}
