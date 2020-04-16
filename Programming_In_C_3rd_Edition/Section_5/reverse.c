#include <stdio.h>
#include <cs50.h>
#include <math.h>

//prints the digits fo a number in reverse
int main()
{
    int n = get_int("Enter a number:");
    int r_digit;
    
    while (n != 0)
    {
        r_digit = n % 10;
        printf("%i", r_digit);
        n = n/10;
    }
    printf("\n");
}