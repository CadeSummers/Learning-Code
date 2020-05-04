#include <stdio.h>
#include <math.h>

void insertionsort(int arr[], int n) //sorts array, and argument such that I can implement array to sort
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
    
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n)
{
    int i; 
    for (i = 0; i < n; i++)
    {
        printf("%i", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {8, 5, 2, 9, 3, 1, 6, 4, 7, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    insertionsort(arr, n);
    printArray(arr, n);
    
    return 0;
}

