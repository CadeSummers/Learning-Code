#include <stdio.h>
#include <cs50.h>
#include <math.h>
// ensure that getcount != EOF

int main()
{
    int c;
    
    c = (getchar() != EOF);
    printf("%d\n", c); // Finds c value
    printf("%d\n", EOF); //Finds end of file value
}