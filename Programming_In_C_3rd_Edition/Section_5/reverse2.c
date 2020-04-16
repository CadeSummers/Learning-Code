#include <stdio.h>
#include <cs50.h>
#include <math.h>

//prints the digits fo a number in reverse using do statement
int main()
{
    int n = get_int("Enter a number:");
    int r_digit;
    
    do
    {
        r_digit = n % 10;
        printf("%i", r_digit);
        n = n/10;
        
    } while (n != 0);
    
    printf("\n"); // statement revises to print out 0
    
    return 0;
}