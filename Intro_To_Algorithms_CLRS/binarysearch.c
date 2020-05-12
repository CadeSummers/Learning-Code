#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

#define MAX 10

int BinarySearch();

int main() //implement a binary search algorithm
{
    int arr[MAX] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; // takes in sorted array, if necessary, add sorting array algorithm from other code here. 
    
    int num = 0;
    
    printf("Enter the number you want to search for: ");
    scanf("%i", &num);
    
    BinarySearch(arr, num);
    
    return 0;
}

int BinarySearch(int arr[], int num)
{
    int start = MAX/2;
    int searchcount = 0;
    int maxsearches = 1;
    int count = 0;
    
    while (maxsearches < MAX)
    {
        maxsearches = maxsearches*2;
        count++;
    }
    
    if (count > 0)
    {
        maxsearches = maxsearches/count;
    }
    
    //printf("Max Searches: %i\n", maxsearches);
    //printf("Start: %i\n", start);
    
    do
    {
        if (num > arr[start])
        {
            start = start + (MAX - start)/2;
            searchcount++;
            //printf("start value: %i \n", start);
        }
        else if (num < arr[start])
        {
            start = start - (MAX - start)/2;
            searchcount++;
            //printf("start value: %i \n", start);
        }
        
        if (searchcount > maxsearches)  // > or >=?
        {
            printf("Number not found in array.\nTry again.\n");
            return 1;
        }
        
        if (num == arr[start])
        {
            printf("Number found in array!\n");
            printf("Number %i is the %i element in array.\n", num, start);
            return 0;
        }
    } while (num != start);
    
return 1;
}
