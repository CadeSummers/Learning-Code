#include <stdio.h>
#include <cs50.h>
#include <math.h>

//make a program that keeps track of each digit that is printed, each white space (\t, \n, ' '), and each other char
int main()
{
    int c, i, w, o; // char, int, white space, other char
    int num[ 10 ]; //declares the name and number of cells in the array. These always start with zero and go upwards
    
    w = o = 0;
    for (i = 0; i < 10; i++)
        num[ i ] = 0;
    
    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\n' || c == '\t')
            {
                w++;
                printf("%i", w);
            }
        else if (c >= '0' && c <= '9') //note how we use the string / ASCII versions of the integers, not the integers themselves, to detect nums.
        {
            num[c -'0']++; // this function declares the starting point of the array. chars (with ' ') and ints are identical, so we have declared
            // that the array starts at the ASCII '0', and previously where we declared there would be 10 cells, we declared that including and
            // starting with zero we will have an arry of 10 cells, which store consecutive values. This format only works with consecutive values.
        }
        else 
        {
            o++;
        }
        printf("digits =");
    for (i = 0; i < 10; i++)
        printf(" %i", num[ i ]);
    printf(" white space = %i, other characters =  %i\n", w, o);
    }
}