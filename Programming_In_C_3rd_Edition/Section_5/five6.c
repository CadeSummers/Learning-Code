#include <stdio.h>



int main()
{
    int n, trinum;
    
    trinum = 0;
    
    for (n = 1; n <= 200; n = n + 1)
    {
        trinum = trinum + n;
    }
    printf("%-2i        %i\n", n, trinum);
    
    return 0;
}