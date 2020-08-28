#include <stdio.h>

int main ()
{
    char *s = "EMMA";
    
    int end_of_string = 0;
    
    printf("%p\n", s);
    for (int i = 0; s[i] != '\0'; i++)
    {
        printf("The address of the character at position %i in string s is %p\n", i, &s[i]);
        end_of_string = i;
    }
    
    printf("\nFull String: ");
    
    for (int i = 0; i <= end_of_string; i++)
    {
        printf("%c", s[i]);
    }
    printf("\n");
}