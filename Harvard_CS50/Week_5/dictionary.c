// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 66536; //Size is 2^16 which is almost as large as (26 (letters) + 10 (digits) + 5 (!, ?, ., -, ') the 41 characters raised to the third for fast searching of words.

// Hash table
node *table[N];

// Word count
int wcount = 0;

// Hashes word to a number
unsigned int hash(const char *word)
{
    //declaration of hashindex value
    unsigned int hashindex = 0;
    
    //Hashing of a word, using primes of course
    for (int i = 0; word[i] != '\0'; i++)
    {
        //The hashing of number using 709, which is the sum of ascii value of a character * 17, modulo 2^16
        hashindex += ((int) word[i] * 709) % N;
    }
    
    //return hashindex to the the load function, (it remains named hashindex)
    return hashindex % N;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    //Open dictionary file to read
    FILE *dict = fopen(dictionary, "r");

    //If dictionary file failed to open, report failure
    if (dict == NULL)
    {
        return false;
    }

    //Declaration of a character array to read the file
    char reader[LENGTH + 1];
    
    //Declaration of a while loop to check characters of dictionary file, until EOF
    while (fscanf(dict, "%s", reader) != EOF)
    {
        
        //Declaration of a node
        node *n = malloc(sizeof(node));
        
        //Ensure sufficient memory for node
        if (n == NULL)
        {
            //Free memory
            unload();
            
            //Report program failure
            return false;
        }
        
        //Copying of the word captured in the reader buffer to n
        strcpy(n->word, reader);
        
        //create an int that serves as the index of where we will place a hashed word
        int hashindex = hash(reader);
        
        //Set the head of a linked list to be found at the index of a hashed word
        node *head = table[hashindex];
        
        //if the table at the value of the hashindex is null, start the head of a linked list
        if (head == NULL)
        {
            //set the first value of the table at hashindex to n
            table[hashindex] = n;
            
            //Increment word count
            wcount++;
        }
        else
        {
            //set the value of n's next address to be equal to the table at hashindex (the head)
            n->next = table[hashindex];
            
            //set the value of node n to be the value of node table at hashindex
            table[hashindex] = n;
            
            //Increment word count
            wcount++;
        }
    }
    
    //close dictionary
    fclose(dict);

    //return success
    return true;
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    /*//create a variable for the word we are going to copy, and set it's values to NULL
    char *wordcopy = NULL;
    
    //declaration of index
    int i = 0;
    
    //while not at end of word...
    while (word[i] != '\0')
    {
        //copy the lower case value of word to wordcopy
        wordcopy[i] = tolower(word[i]);
        
        //increment i to proceed to next character
        i++;
        
        //hard coded case for the null terminating character
        if (word[i] == '\0')
        {
            wordcopy[i] = '\0';
        }
    }*/
    
    //Hash the wordcopy we are checking to get an integer index where we can check for the correct spelling of the word in the hash table
    int checkindex = hash(word);
    
    //Declaration of a node named temp to traverse linked list
    node *temp = malloc(sizeof(node));
    
    //If insufficient memory, report failure
    if (temp == NULL)
    {
        unload();
        
        return false;
    }
    
    //Assign that value of temp to be the value of the table at the checkindex
    temp = table[checkindex];
    
    //While not at the end of a linked list, check to see if element in linked list is same as temp word
    while (temp != NULL)
    {
        //compare strings to ensure word is valid
        if (strcasecmp(temp->word, word) == 0)
        {
            return true;
        }
        else
        {
            //if temp's word is not the same, go down the list
            temp = temp->next;
            
            //hard coded check for last element of linked list
            /*if (temp->next == NULL)
            {
                if (strcmp(temp->word, wordcopy) == 0)
                {
                    return true;
                }
            }*/
        }
    }
    
    //Freeing temp preliminarily as I can't do it in unload
    free(temp);
    
    //If program reaches this point, word not in dictionary, program has incorrect spelling
    return false;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return wcount;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    
    //for loop to go down list of cells in table (NOT WORDS, CELLS ARE DESIGNATED BY N)
    for (int i = 0; i < N; i++)
    {
        //set head's value to the head of the linked list
        node *head = table[i];
        
        //while not at the end of the list...
        while (head != NULL)
        {
            
            //set temp's value to the next value down the list
            node *temp = head;
            
            //set the next address of head to head's next address
            head = head->next;
            
            //free the value of temp
            free(temp);
        }
        
        //once finished with all value of temp, free the head
        free(head);
        
        //set table at index i to null
        table[i] = NULL;
    }
    
    //if program reaches the end, report success
    return true;
}
