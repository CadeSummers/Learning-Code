#include <stdio.h>
#include <math.h>
#include <cs50.h>

#define MAX 10

int sum = 1;
int arr[MAX];

int MeanSort(int num); //create recursive meansort, which takes average of two sets recursively, and arranges them as the lower and upper sets

int main()
{
    int num;
    
    int arrsize = MAX + 1;
    
    while (arrsize > 10)
    {
        printf("Define array size (less than 10) \n");
        scanf("%d", &arrsize);   
    }
    
    for (int i = 0; i < arrsize; i++)
    {
        arr[i] = 0;
    }
    
    for (int i = 0; i < arrsize; i++)
    {
        printf("Enter a number: ");
        scanf("%d", &num);
    }
    
    MeanSort(num);
}

int MeanSort(int num)
{
        
    if (num == 1)
    {
        return 1;
    }
    else
    {
        sum = sum * num;
        num--;
        printf("Current value: %i \n", sum);
        MeanSort(num);
    }
    return 0;
}