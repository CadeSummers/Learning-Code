#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int arraymaker(int n1);

int fcount = 0;

#define ARRSIZE 8 

int sumarr[ARRSIZE]; //sum array
int arr1[ARRSIZE]; //array for sum 1
int arr2[ARRSIZE]; //array for sum 2

int main() // binary addition calculator
{
    int n1 = 0;

    printf("Enter the first number you would like to add in binary: ");
    scanf("%i", &n1);
    arraymaker(n1);
    printf("\nEnter the second number you would like to add in binary: ");
    scanf("%i", &n1);
    arraymaker(n1);
    
    printf("Binary Sum: ");
    for (int l = 0; l < ARRSIZE; l++)
    {
        printf("%i", sumarr[l]);
    }
    printf("\n");
}

int arraymaker(int n1)
{
    fcount++;
    int binarr[ARRSIZE];
    
    if (n1 > 255) 
    {
        printf("Too large for 8 bit\n");
        return 1;
    }
    else
    {   
        for (int i = ARRSIZE - 1; i >= 0; i--)
        {
            if (n1 < (pow (2, i)))
            {
                binarr[ARRSIZE - i] = 0;
            }
            else
            {
                binarr[ARRSIZE - i] = 1;
                n1 = n1 - (pow(2, i));
            }
            printf("%i", binarr[ARRSIZE - i]);
        }
        printf("\n");
    }
    
    if (fcount > 1)
    {
        for (int j = 0; j < ARRSIZE; j++)
        {
             arr2[j] = binarr[j];
        }
    }
    else
    {
        for (int j = 0; j < ARRSIZE; j++)
        {
            arr1[j] = binarr[j];
        }
    }
    
    for (int k = ARRSIZE - 1; k >= 0; k--)
    {
        if (arr2[k] == 1 && arr1[k] == 1)
        {
            sumarr[k] = 0;
            sumarr[k - 1]++;
        }
        else if (arr2[0] + arr1[0] == 2)
        {
            printf("Number sume too large for eight-bit addition.\n");
            printf("Numbers must sum less than 256. Try again.\n");
            return 1;
        }
        else
        {
            printf("%i + %i + %i", arr2[k], arr1[k], sumarr[k]);
            sumarr[k] = sumarr[k] + arr2[k] + arr1[k];
            printf(" = %i\n", sumarr[k]);
            
            if (sumarr[k] > 1)
            {
                sumarr[k] = 0;
                sumarr[k - 1]++;
            }
        }
    }
    return 0;
}
