#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <cs50.h>

MaxSub();
int base = 0;
int pos_sum = 0;
int neg_sum = 0;

int main()
{
    int arr[MAX] = {-4, -7, 8, 2, 0, 13, -9, 10, 3, -10};
    
    MaxSub(arr);
}

int MaxSub (int arr)
{
    int startpos, endpos;
    startpos = endpos = 0;
    
    for (int i = 0; i < MAX; i++)
    {
        if (arr[i] < 0)
        {
            neg_sum += arr[i];
        }
        else
        {
            pos_sum += arr[i];
        }
        
        for (int j = 0; j < MAX; j++)
        {
            
        }
    }
}