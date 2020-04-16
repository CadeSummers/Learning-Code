#include <stdio.h>
#include <cs50.h>
#include <math.h>


//Exercise #2 from Section 5
int main()
{
    int i = 0;
    
    printf("\tn\t\t");
    printf("n^2\t\n");
    while (i < 10)
    {
        printf("\t%i\t\t", i);
        printf(" %i\t\n", i*i);
        i++;
    }
}