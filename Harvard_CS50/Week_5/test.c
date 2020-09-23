#include <stdio.h>

int main()
{
    int i; 
    
    printf("Enter a number: ");
    
    scanf("%i", &i);
    
    if (i == 0xff)
    {
        printf("Number is 255\n");
    }
    else
    {
        printf("Number is not 255\n");
    }
    
    int hex = 0xe0;
    
    printf("Integer hex is %i\n", hex);
}