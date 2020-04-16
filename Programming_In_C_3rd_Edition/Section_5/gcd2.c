#include <stdio.h>
#include <cs50.h>
#include <math.h>

//alternative to gcd with first practice using gcd
//uses the Euclidean Algorithm, which I had never seen until now.
int main()
{
    int u, v, temp;
    
    printf("Please type in two nonnegative integers\n");
    scanf("%i%i", &u, &v);
    
    while (v != 0)
    {
        temp = u % v;
        u = v;
        v = temp;
    }
    printf("Their greatest common divisor is %i\n", u);
    
}