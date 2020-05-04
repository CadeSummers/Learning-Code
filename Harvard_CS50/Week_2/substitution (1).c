#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(int argc, char *argv[ ])
{
    int i, n, c, x;
    
    i = n = c = x = 0;
    
    char abc [52];
    
    string s = argv[1];
    
    char phrase[999];
    
    while (s[n] != '\0' && n < 52)
    {
        if (s[n] == '!' || s[n] == '.' || s[n] == '?'|| (s[n] >= '0' && s[n] <= '9'))
        {
            n = 52;
        }
        n++;
    }
    
    for (i = 0; i < 26; i++)
    {
        abc[i] = 'a' + i;
    }
    if (n == 52)
    {
        for (i = 26; i < 52; i++)
        {
            abc[i] = 'A' + (i - 26);
        }
    }
    
    if (n == 26 || n == 52)
    {
        printf("Enter the message you would like to encrypt: \n");
        fgets(phrase, 999, stdin); 
        
        while (phrase[c] != '\0' && c < 999)
        {
            c++; 
        }
        
        for (; c > 0; c--)
        {
            while (phrase[c] != abc[x])
            {
                x++;
            }
            
            if (phrase[c] == abc[x])
            
            {
                phrase[c] = s[x];
            }
            
            x = 0;
        }
        
        printf("%s", phrase);
        
    }
    else
    {
        printf("Command line argument must be 26 or 52 characters. \n");
        printf("Command line argument must not containt punctuation marks ('.', '?', or '!'). \n");
    }
}
