#include <stdio.h>
#include <math.h>
#include <cs50.h>

int main()
{
    int c;
    
    while ((c = getchar()) !=EOF)
    {
        if (c == ' ')
            {
                printf("\n");
            }
        else
            {
                putchar(c);
            }
    }
}