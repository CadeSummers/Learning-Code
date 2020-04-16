#include <stdio.h>
#include <cs50.h>
#include <math.h>


//Exercise #4 from Section 5
int main()
{
    int i, f; 
    i = 0;
    f = 1;
    
    printf("\tn\t\t");
    printf(" n!\t\n");
    
    do //handles edge case for 0!
    {
        printf("\t%i\t\t", i);
        printf(" %i\t\n", f);
        i++;
    } while (i == 0);
    
    while (0 < i && i <= 10)
    {
        f*=i;
        printf("\t%i\t\t", i);
        printf(" %i\t\n", f);
        i++;
    }
}
