#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

int main()
{
    #define ARRSIZE 10
    
    int arr[ARRSIZE] = {4, 8, 5, 1, 9, 0, 7, 2, 6, 3};
    
    int largest = 0;
    
    for (int i = 0; i < 10; i++)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
        }
    }
    
    int smallest = largest;
    smallest++;
    
    for (int i = 0; i < 10; i++)
    {
        if (arr[i] < smallest)
        {
            smallest = arr[i];
        }
    }
    
    printf("Largest number in the array is:\t\t%i\n", largest);
    printf("Smallest number in the array is:\t%i\n", smallest);
    printf("The range of the array is:\t\t%i\n", (largest - smallest));
}