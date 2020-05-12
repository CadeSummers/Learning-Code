#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1; // first subarray arr[l..m]
    int n2 = r - m; // second subarray is arr[m+1..r]
    
    
    int L[n1], R[n2];  //creation of left and right arrays
    
    for (i = 0; i < n1; i++)
    {
        L[i] = arr[1+i]; //assigns first half of arr to L
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = arr[m + 1 + j]; //assigns second half of arr to R
    }
    
    //Merge the temp arrays back into arr[l..r]
    i = 0; //initial index of subarray 1
    j = 0; //initial index of subarray 2
    k = l; //initial index of merged subarray
    
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    // copy the remaining element L[], if there are anny
    
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    // copy the remaing elements of R[], if there are any
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

//l is for left index and r is right index of the sub-array of arr to be sorted

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l + r/2, but avoids overflow for)
        // large l and h
        int m = l + (r - 1)/2;
        
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        
        merge(arr, l, m, r);
    }
}

//printarray function for utility

void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%i ", A[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {7, 4, 5, 8, 0, 2, 6, 3, 9, 1};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    
    printf("Given arrary is\n");
    printArray(arr, arr_size);
    
    mergeSort(arr, 0, arr_size - 1);
    
    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    return 0;
}