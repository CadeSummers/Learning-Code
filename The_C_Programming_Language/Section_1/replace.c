#include <stdio.h>
#include <math.h>
#include <cs50.h>

//copies input to output, replacing more than 1 blanks with one blank
//replaces tabs with "\t", backspaces with "\b" and each "\" with "\\"

int main()
{
    int c, bl, t, b, s; //character, blanks (counter), tabs, backspaces, slashes
    
    bl = 0;
    t = 0;
    b = 0;
    s = 0;
    
    while ((c = getchar()) != EOF)
    {
        if (c == ' ') // update this
        {
            bl++;
            while (bl == 1)
            {
                printf(" ");
                bl++;
            }
        }
        else if (c == '\t')
        {
            printf("\\t");
        }
        else if (c == '\b') // After exploring, it seems like I need to #include <conio.h> in order to be able to detect key inputs rather than codes to make *backspace* print \b
        {
            printf("\\b"); // Get Max insight
        }
        else if (c == '\\') // 2 backslases is the conditional check for a single backslash
        {
            printf("\\\\");
        }
        else if ((c != ' ') || (c != '\t') || (c != '\b') || (c != '\\'))
        {
            putchar(c);
        }
    }
}