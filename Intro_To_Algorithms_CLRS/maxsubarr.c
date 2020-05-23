#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <math.h>

#define MAX 10

int MaxSubarray();

int main() //find the greatest value
{
    int arr[MAX] = {-9, 19, -33, 14, 1, 8, -7, -2, 6, 10}; //make another version of this that summs array differences and adds them together. Consider adding all changes by a var
    MaxSubarray(arr);    
}

int MaxSubarray(int arr[])
{
    int largest = 0;
    int startpos, endpos;
    
    startpos = endpos = 0;
    
    for (int i = 0; i < MAX; i++)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
            endpos = i;
        }
    }
    printf("Largest = %i\n", largest);
    
    int smallest = largest;
    smallest++;
    
    for (int i = 0; i < MAX; i++)
    {
        if (arr[i] < smallest)
        {
            smallest = arr[i];
            startpos = i;
        }
    }
    printf("Smallest = %i\n", smallest);
    
    if (endpos > startpos) //if the end position element is further down the line of the start position element
    {
        printf("Max Subarray is %i\n", (largest - smallest));
    }
    else if (endpos == startpos || smallest == largest) //if the smallest element is the last element in the array then no gains can be made
    {
        printf("All elements in array are of same value\n Max subbaray is 0\n");
        return 1;
    }
    else
    {
        largest = smallest;
        for (int i = startpos; i < MAX; i++)
        {
            if (arr[i] > largest)
            {
                largest = arr[i];
            }
        }
        printf("Max Subarray is %i\n", (largest - smallest));
    }
    return 0;
}