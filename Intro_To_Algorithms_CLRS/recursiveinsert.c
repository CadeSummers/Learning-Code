#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

#define MAX 7

//used internet tutorial
void InsertionSort(int i, int array[], int size)
{
    if (i < size)
    {
        int j;
        int temp = array[i];
        
        for (j = i; j > 0 && array[j - 1] > temp; j--)
        {
            array[j] = array[j - 1];
        }
        array[j] = temp;
        
        InsertionSort(++i, array, size);
    }
}

int main()
{
    int p;
    
    int array[MAX] = {3, 9, 7, 2, 5, 1, 8};
    
    InsertionSort(0, array, MAX);
    
    for (p = 0; p < MAX; p++)
    {
        printf("%i ", array[p]);    
    }
    printf("\n");
    
    return 0;
}