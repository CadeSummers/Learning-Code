#include <cs50.h>
#include <stdio.h>

int main()
{
    char a[999], b[999];
    
    bool same = false;
    
    printf("Enter a word: ");
    scanf("%s", a);
    printf("\n");
    printf("Enter another word: ");
    scanf("%s", b);
    printf("\n");
    
    
    for (int i = 0; a[i] != '\0' || b[i] != '\0'; i++)
    {
        //printf("Checking %c against %c\n", a[i], b[i]);
        
        if (a[i] != b[i])
        {
            same = false;
        }
        else if (a[i] == '\0' && b[i] != '\0')
        { 
            same = false;
        }
        else if (b[i] == '\0' && a[i] != '\0')
        {
            same = false;
        }
        else
        {
            same = true;
        }
        
        if (!same)
        {
            printf("Different\n");
            return 1;
        }
        else
        {
            printf("Same\n");
            return 0;
        }
    }
}