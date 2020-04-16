#include <stdio.h>
#include <cs50.h>
#include <math.h>

//This program counts (b)lanks, (t)abs and (n)ew (l)ines
int main() 
{
    int c, b, t, nl;
    
    b = 0;
    t = 0;
    nl = 0;
    
    while ((c = getchar()) != EOF)
    {
        if (c == '\n') 
        {
            nl++;
            printf("The number of lines in this program is: %i\n", nl);
        }
        if (c == '\t')
        {
            t++;
            printf("The number of tabs in this program is: %i\n", t);
        }
        if (c == ' ')
        {
            b++;
            printf("The number of blanks in this program is: %i\n", b);   
        }
    }
}