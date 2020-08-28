#include <stdio.h>
#include <ctype.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *s = get_string("s: ");
    
    char *t = malloc(strlen(s) + 1); //allocates an ammount of memory, equal to that of s, to variable (char array) t
    
    strcpy(t, s);
    
    t[0] = toupper(t[0]);
    
    printf("%s\n", s);
    printf("%s\n", t);
    
    free(t);
}