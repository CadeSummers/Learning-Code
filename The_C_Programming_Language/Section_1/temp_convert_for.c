#include <stdio.h>
#include <cs50.h>
#include <math.h>

/* print fahr- cels table */

int main()
{
    int fahr; 
    
    for (fahr = 300; fahr >= 0; fahr -= 20)
    {
        printf("%3d, %6.1f", fahr, (5.0/9.0) * (fahr-32));
    }
}
