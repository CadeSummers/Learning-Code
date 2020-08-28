#include <stdio.h>
#include <cs50.h>

int main()
{
    string s = get_string("s: ");
    string t = get_string("t: ");
    
    /*if (*s == *t) //variables will show as different because string contains an address, s and t's addresses are different, pointers will mitigate this issue
    {
        printf("Same\n");
    }
    else
    {
        printf("Different\n");
    }*/
    
    printf("%p\n", s);
    printf("%p\n", t);
}