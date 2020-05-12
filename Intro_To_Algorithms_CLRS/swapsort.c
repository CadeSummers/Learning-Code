#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

int main() // program which sorts values using selection sort algorithm
{
    int arr[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    
    int holder = 0;
    
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (arr[i] < arr[j])
            {
                holder = arr[i];
                arr[i] = arr[j];
                arr[j] = holder;
            }
        }
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%i\n", arr[i]);
    }
}