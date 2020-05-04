#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main ()
{
    int c; // counter
    float s, w, l, as, al, lp, sp; //sentences, words, letters, avg sentences, avg words, avg letters, letters per 100, sentences per 100
    
    s = l = c = 0;
    w = 1; //we are counting words, not spaces. spaces are in between words, which causes and off by one error. A space implies a word before, initializing @ 1
    
    char text[999];
    
    printf("Text: \n");
    
    fgets(text, 999, stdin);
    
    while (text[c] != '\n' && c < 999)
    {
        c++;
    }
    
    while (c > 0)
    {
        if (text[c] == ' ')
        {
            w++;
        }
        else if (text[c] == '.' || text[c] == '!' || text[c] == '?')
        {
            s++;
        }
        else
        {
            l++;
        }
        c--;
    }
    
    al = (l)/w; //average letters per word
    
    lp = al*100; //rate of average per one hundred words
    
    as = (s)/w; //average sentences per word
    
    sp = as*100; //rate of average per one hundred words
    
    int index;
    
    index = ((0.0588 * lp) - (0.296 * sp) - 15.8);
    
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade: %i\n", index);
    }
}