#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    int v;
    printf("Enter a number: ");
    scanf("%i", &v);
    
    for (int i = 0; i < 10; i++)
    {
        if (v == arr[i])
        {
            printf("Your number is the number %i element in our array\n", v);
            return 0;
        }
    }
    printf("Value not in our array\n");
    return 1;
}