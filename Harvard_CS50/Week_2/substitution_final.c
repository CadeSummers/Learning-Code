#include <stdio.h>
#include <cs50.h>
#include <math.h>

//define size as 52 (lower case alphabet + uppercase alphabet + null terminator)
#define SIZE 52

int main(int argc, char *argv[ ])
{
    //ensure key exists
    if (argc != 2)
    {
        printf("No key found. Program failed, try again.\n");
        return 1;
    }
    
    //declaration of four ints, all equivalent to 0
    int i, n, c, x;
    
    i = n = c = x = 0;
    
    //Declaration of a 52 character array, with 1 extra for null terminator, which contains lowercase and uppercase alphabet
    char abc [SIZE + 1];
    
    //set string equivalent to the command line argument, which serves as our encryption key
    string s = argv[1];
    
    //Declaration of an array to contain user input
    char phrase[999];
    
    //count all alphabetical characters in string
    while (s[n] != '\0' && n < SIZE)
    {
        //if the string (encryption key) has any of these characters, return a program failure
        if (s[n] == '!' || s[n] == '.' || s[n] == '?'|| (s[n] >= '0' && s[n] <= '9'))
        {
            printf("Invalid Encryption Key. Program Failed, Try Again\n");
            
            return 1;
        }
        
        //n will return either 26 or 52
        n++;
    }
    
    /*int start = 0;
    
    for (int y = start; y < n; y++)
    {
        if (s[start] == s[y] && start != y)
        {
            printf("No duplicates allowed in key. Program failed. Try again\n");
            return 1;
        }
        
        start++;
    }*/
    
    for (int y = 0; y < n; y++)
    {
        for (int z = y + 1; z < n; z++)
        {
            if (s[z] == s[y])
            {
                printf("No duplicates allowed in key. Program failed. Try again\n");
                return 1;
            }
        }
    }
    
    
    char str_arr[n*2 + 1];
    
    /*//Declare an array of twice the size of s, if the key is exactly 26
    if (n == SIZE/2)
    {
        str_arr[n*2];
    }*/
    
    for (int j = 0; j < n; j++)
    {
        
        if (s[j] >= 'A' && s[j] <= 'Z')
        {
            //copy the value in string to the new array starting from index 0
            str_arr[j] = s[j];
            
            //copy the lower case value in string to the new array
            str_arr[j + n] = s[j] + 32;
        }
        else if (s[j] >= 'a' && s[j] <= 'z')
        {
            //Insert the lower case values of the the key starting from index 26 (j = 0, n = 26)
            str_arr[j + n] = s[j];
            
            //copy the upper case value in string to the new array
            str_arr[j % n] = s[j] - 32;
        }
    }
    
    /*for (int j = 0; j < n*2; j++)
    {
        printf("%c", str_arr[j]);
    }
    printf("\n");*/
    
    //populate array with uppercase letters
    for (i = 0; i < 26; i++)
    {
        abc[i] = 'A' + i;
    }
    
    //populate array with lowercase letters
    for (i = 26; i < SIZE; i++)
    {
        abc[i] = 'a' + (i - 26);
    }
    
    /*printf("abc array: \n");
    
    int j = 0;
    
    while (abc[j] != '\0')
    {
        printf("%c ", abc[j]);
        j++;
    }
    printf("\n");
    
    //if string was of size 52, populate the array starting from element 26 with lower case letters
    if (n == SIZE || (s[n] >= 'a' || s[n] <= 'z'))
    {
        for (i = 26; i < SIZE; i++)
        {
            abc[i] = 'a' + (i - 26);
        }
    }*/
    
    //if n is of a valid size (26 or 52), begin the encryption
    if (n == 26 || n == SIZE)
    {
        printf("Enter the message you would like to encrypt: \n");
        fgets(phrase, 999, stdin);
        
        //count up the characters in phrase
        while (phrase[c] != '\0' && c < 999)
        {
            c++;
        }
        c--;
        
        //if phrase is too long, report program failure
        if (c >= 999)
        {
            printf("Your phrase is too long! Cannot encrypt, please try again with shorter input.\n");
            
            return 1;
        }
        
        //create an int named index to keep track of place in phrase 
        int index = 0;
        
        //printf("c:  %i\n", c);
        
        //printf("last element of phrase: %c\n", phrase[c - 2]);

        //while c is greater than or equal to 0, encrypt from the last character of phrase down to the first (index 0)
        while (index < c || phrase[index] != '\0')
        {
            
            /*//if phrase at element index is a space or number, move onto the next character
            if (phrase[index] == ' ' || (phrase[index] >= '0' && phrase[index] <= '9'))
            {
                index++;
                
                //printf("145 Index : %i\n", index);
            }
            
            //if phrase at element index is a space or number, move onto the next character
            if (phrase[index] == ' ' || (phrase[index] >= '0' && phrase[index] <= '9'))
            {
                index++;
                
                //printf("153 Index : %i\n", index);
            }*/
            
            //while the indexed element in phrase is not the same as the x element in our alphabet array, increment x by 1 and keep searching
            while (phrase[index] != abc[x])
            {
                //increment x by 1 until we have checked all of alphabet list
                //if phrase at element index is a space or number, move onto the next character
                if (phrase[index] == ' ' || (phrase[index] >= '0' && phrase[index] <= '9'))
                {
                    index++;
                    
                    if (phrase[c] == str_arr[x] || index == c)
                    {
                        printf("ciphertext: %s\n", phrase);
                        return 0;
                    }
                
                    //printf("153 Index : %i\n", index);
                }
                
                
                x++;
            }
            
            //once we have identified the letter character based on it's index in our alphabet array, swap it's value with the character's same index in our encryption key
            if (phrase[index] == abc[x])
            {
                //printf("letter %c in phrase is element %i / letter %c in abc!\n", phrase[index], x, abc[x]);
                
                //printf("Setting %c character in %s to %c\n", phrase[index], phrase, s[x]);
                
                //printf("Making letter %c in %s letter %c from str_arr\n", phrase[index], phrase, str_arr[x]);
                
                //set the element at index c to the value of the encryption at index x
                phrase[index] = str_arr[x];
                
                
                //increment index by 1 to move onto next element of array
                index++;
                //printf("167 Index : %i\n", index);
                
                if (phrase[c] == str_arr[x] && index == c)
                {
                    phrase[c] = '\0';
                    printf("ciphertext: %s", phrase);
                    return 0;
                }
                
                /*if (index == c - 2)
                {
                    phrase[index] = str_arr[x];
                    
                    printf("ciphertext: %s\n", phrase);
                    return 0;
                }*/
                
            }
            
            //return x's value to zero for the next c value of phrase
            x = 0;
        }
        
        //return phrase
        phrase[c] = '\0';
        printf("ciphertext: %s", phrase);
        
    }
    else
    {
        //remind user of correct usage of program
        printf("Command line argument must be 26 or 52 characters. \n");
        printf("Command line argument must not containt punctuation marks ('.', '?', or '!') or numbers (0 - 9). \n");
        
        //return program failure
        return 1;
    }
    
    //return program success
    return 0;
}
