#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() // binary addition calculator
{
    int binarr[8]; //binary array

    int n1, n2, n3;

    printf("Enter the first number you would like to add in binary: ");
    scanf("%i", &n1);
    printf("\nEnter the second number you would like to add in binary: ");
    scanf("%i", &n2);
    
    n3 = n1 + n2;
    
    if (n3 > 255) //if you desired to change the original numbers to binary as well, implement the below code for said numbers additionally. 
    {
        printf("Too large for 8 bit\n");
        return 1;
    }
    else
    {   
        for (int i = 7; i >= 0; i--)
        {
            if (n3 < (pow (2, i)))
            {
                binarr[7 - i] = 0;
            }
            else
            {
                binarr[7 - i] = 1;
                n3 = n3 - (pow(2, i));
            }
            printf("%i", binarr[7 - i]);
        }
        printf("\n");
    }
}