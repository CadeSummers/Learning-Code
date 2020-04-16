#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main()
{
    int c, nl;
    nl = 0;
    
    
    while ((c = getchar()) != EOF)
    {
        if (c == '\n')  //characters written in between single quotes represent the integer/ numerical value in ASCII. You can compare integers to chars using single quotes. v smart.
        {
            nl++;
        }
        printf("%i\n", nl);
    }
}