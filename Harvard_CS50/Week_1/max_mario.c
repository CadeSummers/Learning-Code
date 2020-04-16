#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    int x;

    do
    {
        x = get_int("height: ");
    }
    while ((x < 0)||(x >= 24));

    for(int i = 2; i <= x+1; i++)
    {
        for(int j = x-i+1; j > 0; j--)
        {
            printf(" ");
        }
        for(int j = 2; j <= i+1; j++)
        {
            printf("#");
        }
        printf("\n");
    }

    return 0;
}