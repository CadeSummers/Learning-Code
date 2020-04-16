#include <stdio.h>
#include <math.h>
#include <cs50.h>

int main()
{
    int blocks, null, i, n, blocks2, null2; //blocks, null spaces, integer counter, received number, second save of blocks, second save of null
    
    do
    {
        n = get_int("Enter height: ");   
    } while ( 0 > n || n > 12);
    
    printf("\n");
    
    i = blocks = null = 0;
    
    while (n > i)  // basically we are doing is printing a block of charachers ("_" or "#"), and each row we want 1 less "_" and 1 more "#" 
    {
        blocks2 = blocks; // using a second blocks and null variable to keep track of desired print amount
        null2 = null;
        
        while (n - i > null)  //i serves as a counter, ajust the number (n) spaces we wish to print i
        {
            printf("_");
            null++;
        }
        while (i >= blocks) // reduces by one the number of null spaces we are printing. We can print blocks up until that point to fill the block with "#"
        {
            printf("#");
            blocks++;
        }
        
    printf("   ");
    
        while (i >= blocks2) // does blocks in reverse
        {
            printf("#");
            blocks2++;
        }
        while (n - i > null2) // does null in reverse
        {
            printf("_");
            null2++;
        }
        
    blocks = null = 0; // return these values to zero
    i++; //change the counter and update the difference between null and block space
    printf("\n");
    }   
}