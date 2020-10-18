#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

//Illustrates the inefficiency in redeclaring arrays when improper size is initally declared
int main()
{
    //Define an array of 3 values
    int list[3];
    
    //Assign the array as 1, 2, & 3
    for (int i = 0; i < 3; i++)
    {
        list[i] = i + 1;
    }
    
    //Print for visualization
    for (int i = 0; i < 3; i++)
    {
        printf("%i\n", list[i]);
    }
    
}