#include <stdio.h>
#include <cs50.h>
#include <math.h>

// Finds Greatest Common Denominator of two non-negative integers
int main()
{
    int d, g; //divisor, greatest known divisor
    d = g = 1; //set to one as all numbers are divisible by 1, and cannot be divided properly by zero
    
    int n1 = get_int("Enter a number\n");
    int n2 = get_int("Enter another number\n");
    
        if (n1 == n2)
            {
                printf("Number is the same.\n");
                printf("The greatest common denominator is %i", n1);
            }
        else if (n1 != n2)
            {
                while (n1/d != n2/d && d <= n1 && d <= n2) //Should I just initialize D as 1?
                {
                    d++;
                        if (n1 % d == 0 && n2 % d == 0 && d > g)
                        {
                            g = d;
                        }
                }
            printf("The Greatest Common Denominator of %i & %i is %i\n", n1, n2, g);
            }
            
}