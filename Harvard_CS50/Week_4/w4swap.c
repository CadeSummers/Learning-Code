#include <stdio.h>

void swap(int, int);

int main(void)
{
    int a = 1; 
    
    int b = 2;
    
    printf("The Value of A is %i\n", a);
    printf("The Value of B is %i\n", b);
    
    swap(a, b);
}

void swap(a, b)
{
    
    printf("Swapping...\n");   
    
    if (a != b)
    {
        int holder = a;
        
        a = b;
        
        b = holder; 
        
        printf("The Value of A is %i\n", a);
        printf("The Value of B is %i\n", b);
    }
    else
    {
        printf("The Value of A & B are equal.\n");
        
        printf("The Value of A is %i\n", a);
        printf("The Value of B is %i\n", b);
    }
}
