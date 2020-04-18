#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(int argc, char *argv[ ])
{
    int i, n, c, x; //alphabet counter, key counter, phrase counter, conversion counter
    
    i = n = c = x = 0;
    
    char abc [52];
    
    string s = argv[1];
    
    char phrase[999]; // to pull a specific point in the matrix, use %c, to pull the entire string matrix, use %s
    //pressing enter to end the input also stores the \n, so printing a matrix does not require \n
    
    while (s[n] != '\0' && n < 52) // strings arrays of characters, so i can count up to the final charachter as s[n] is the initial character and \0 the last
    {
        if (s[n] == '!' || s[n] == '.' || s[n] == '?'|| (s[n] >= '0' && s[n] <= '9'))
        {
            n = 52; //sets n to a value causing the while loop to break and create and invalid check for the rest of the program
        }
        n++;
        //find way to check for duplicate elements
    }
    
    for (i = 0; i < 26; i++) //stores the values of the alphabet in lower case and uper case in an array called abc
    {
        abc[i] = 'a' + i;
    }
    if (n == 52) //only if there is a case-sensitive and extended key, store the upper case version of the alphabet.
    {
        for (i = 26; i < 52; i++)
        {
            abc[i] = 'A' + (i - 26);
        }
    }
    
    if (n == 26 || n == 52) //these are the only valid sizes of the argument value that can be accepted
    {
        printf("Enter the message you would like to encrypt: \n");
        fgets(phrase, 999, stdin); // format for getting a string and putting it into an array
        
        while (phrase[c] != '\0' && c < 999)
        {
            c++; //counts the number of loop iterations we need to change
        }
        
        for (; c >= 0; c--) //assigns the key value in place on the the key value in the final place of c // c > 0 or c>= 0?
        {
            if (phrase[c] == ',')
            {
                phrase[c] = ',';
            }
            else if (phrase[c] == ' ')
            {
                phrase[c] = ' ';
            }
            else
            {
                while (phrase[c] != abc[x])
                {
                    x--;
                }
                if (phrase[c] == abc[x])
                {
                    phrase[c] = s[x];
                }
            }
            x = 52;
        }
        // create conversion of phrase based on command-line argument
        printf("%s\n", phrase);
    }
    else
    {
        printf("Command line argument must be 26 or 52 characters. \n");
        printf("Command line argument must not containt punctuation marks ('.', '?', or '!'). \n");
    }
    //you have to add an asterisk to change the argv variable type from char to a string pointer, or, an array of characters contruent to a str
    // *argv will point pback to the name of the program, as will argv[0]. With an "*" however, you will need to give the expected print type %c
    //above is %s, because i am prepping argv to be a string input for substitution
}
