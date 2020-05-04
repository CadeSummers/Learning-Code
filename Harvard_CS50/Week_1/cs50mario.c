#include <stdio.h>
#include <math.h>
#include <cs50.h>

int main()
{
    int blocks, null, i, n, blocks2, null2;

    do
    {
        n = get_int("Enter height: ");
    }
    while (1 > n || n > 8);

    i = blocks = null = 0;

    while (n > i)
    {
        blocks2 = blocks;
        null2 = null;

        while (n - i > null + 1)
        {
            printf(" ");
            null++;
        }
        while (i >= blocks)
        {
            printf("#");
            blocks++;
        }

        printf("  ");

        while (i >= blocks2)
        {
            printf("#");
            blocks2++;
        }
        while (n - i > null2 + 1)
        {
            printf(" ");
            null2++;
        }

        blocks = null = 0;
        i++;
        printf("\n");
    }
}
