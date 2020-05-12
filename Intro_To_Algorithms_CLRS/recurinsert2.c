#include <stdio.h>

#define N 7

//used internet tutorial
void InsertionSort(int i, int array[], int size)
{
    if (i < size)
    {
        int j;
        int temp = array[i];

        for (j = i; j > 0 && array[j-1] > temp; j--)
        {
            array[j] = array[j-1];
        }
        array[j] = temp;

        InsertionSort(++i, array, size);
    }
}

int main(void)
{
    int p;
    int array[N] = {37,23,17,12,72,31,46};

    InsertionSort(0, array, N);
    printf("The list of sorted numbers is\n");
    
    for (p = 0; p < N; p++)
    {
        printf("%d ",array[p]);
    }
    printf("\n\n");

    return 0;
}