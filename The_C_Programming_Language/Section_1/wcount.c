#include <stdio.h>
#include <cs50.h>
#include <math.h>

// program that counts lines, words and character inputs
int main()
{
    #define IN  1
    #define OUT  0
    
    int c, state, nl, nw, nc; // character, state, new line, new word, new charachter
    state = OUT;  //alternating states to detect if word is present
    nl = nw = nc = 0;
    
    while ((c = getchar()) != EOF)
    {
        nc++;
        
        if (c == '\n')
        {
            state = OUT;
            nl++;
        }
        if (c == ' ' || c == '\t' || c == '\n')
        {
            state = OUT;   // why would I just count nw++; here?
        }
        else if (state == OUT)
        {
            state = IN;
            nw++;
        }
    printf("Chars, lines & words: %i  %i  %i\n", nc, nl, nw);
    }
    // 1-11 I would test this program by using hyphenated words (ie, spider-man), and other uncommon grammar situations.
    // I find this only generates one word when it is two words. 
}