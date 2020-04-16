#include <stdio.h>
#include <math.h>
#include <cs50.h>

int main()
{
    float fahr, celsius;
    float lower, upper, step;
    
    /* print celsius-fahrenheit table, for celsius = 0, 20, ... 300 */
    lower = 0; //floor of temp. table
    upper = 300; //ceiling of table
    step = 20; //change in table size
    
    celsius = lower;
    printf("Celsius to Fahrenheit Conversion\n");
    printf("Celsius\t\tFahrenheit\n");
    while (celsius <= upper)
    {
        fahr = 9 * (celsius + 32)/ 5;
        printf(" %3.0f\t \t %6.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
}
