#include <stdio.h>
#include <math.h>
#include <cs50.h>

int main()
{
    float fahr, celsius;
    float lower, upper, step;
    
    /* print fahrenheit-celsius table, for fahr = 0, 20, ... 300 */
    lower = 0; //floor of temp. table
    upper = 300; //ceiling of table
    step = 20; //change in table size
    
    fahr = lower;
    printf("Fahrenehit to Celsius Conversion\n");
    printf("Fahrenheit\tCelsius\n");
    while (fahr <= upper)
    {
        celsius = 5 * (fahr -32)/ 9;
        printf("   %3.0f\t \t%6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}
