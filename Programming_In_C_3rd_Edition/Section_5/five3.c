#include <stdio.h>
#include <cs50.h>
#include <math.h>


//prints table of num and triangular num
int main()
{
    int n,tn; // num, triangular num
    n = tn = 0; 
    
    printf("\tn\t\t");
    printf("triangular n\t\n");
    while (n <= 50)
    {
        tn = n * (n + 1)/2;
        printf("\t%i\t\t", n);
        printf("    %i \t\n", tn);
        n+=5;
    }
}