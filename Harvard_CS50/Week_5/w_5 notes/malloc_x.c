#include <stdio.h>
#include <stdlib.h>

//Program illustrates The necessity of pointers to have pointees (memory they point to)
int main()
{
    //Declaration of 2 pointers
    int *x;
    int *y;
    
    //Assign a piece of memory, which is the size of an int, and the address of that memory the value of x
    x = malloc(sizeof(int));
    
    //Print the address of x in memory
    printf("x: %p\n", (void *) &x);
    
    //Assign the memory located at the address pointer x points to, the value 42
    *x = 42;
    
    //Print pointer x
    printf("x: %i\n", *x);
    
    //Assign y, a pointer which leads to an undeclared place in memory, to the address stored in x
    y = x;
    
    //Make the memory located at the address which y points to, the value 13
    *y = 13;
    
    //Print the memory pointed to by y
    printf("y: %i\n", *y);
    
    //Print the memory pointed to by x (which shares the same address as y)
    printf("x: %i\n", *x);
    
    //Free the memory at the address of x (best practice)
    free(x);
}