#include <stdio.h>

void swap(int *a, int *b);

int main()
{
    int x = 1;
    int y = 2;
    
    printf("x is %i, y is %i\n", x, y);
    swap(&x, &y);
    printf("x is %i, y is %i\n", x, y);
}

void swap(int *a, int *b) //casts any variables that is an int to new variables, a & b, and variables as address into pointers with data cast into them as *a & *b
{
    printf("Swapping...\n");
    
    int holder = *a;
    
    *a = *b;
    
    *b = holder;
}