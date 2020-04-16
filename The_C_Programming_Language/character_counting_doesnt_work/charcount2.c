#include <stdio.h>
#include <math.h>
#include <cs50.h>

int main()
{
    double nc;
    
    for (nc = 0; getchar() != EOF; nc++)
            ; // <<this is a null statement
    printf("%.0f\n", nc);
}