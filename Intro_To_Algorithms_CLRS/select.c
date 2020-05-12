#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

int main()
{
    #define ARRSIZE 9
    
    int arr1[ARRSIZE] = {2, 3, 4, 5, 6, 7, 9, 8, 0};
    int arr2[ARRSIZE];
    
    int largest = arr1[0];
    int x = 0;
    
    for (int i = 0; i < ARRSIZE; i++)
    {
        if (arr1[i] > largest)
        {
            largest = arr1[i];
        }
    }
    
    largest++;
    
    for (int j = 0; j < ARRSIZE; j++)
    {
    
        int smallest = largest;
        
        for (int i = 0; i < ARRSIZE; i++)
        {
            if (arr1[i] < smallest)
            {
                smallest = arr1[i];
                x = i;
            }
        }
        arr2[j] = smallest;
        arr1[x] = largest;
    }
    
    for (int i = 0; i < ARRSIZE; i++)
    {
        printf("%i\n", arr2[i]);
    }
}