#include <stdio.h>
#include <cs50.h>
#include <math.h>

// create a program that finds the number of characters in a string
int main()
{
    long nc;

    nc = 0;
    while (getchar() != EOF)
        nc++;
    printf("%ld\n", nc);
}
