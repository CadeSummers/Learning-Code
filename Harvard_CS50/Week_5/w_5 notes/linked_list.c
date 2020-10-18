#include <stdio.h>
#include <stdlib.h>

//Creation of nodes for linked lists
typedef struct node
{
    int number; //represents numbers (ints) we are storing
    
    struct node* next; //represents address of the next node we are storing
}
node;

//Implements a list of numbers with a linked list
int main()
{
    //Initialize a list of size 0
    node *list = NULL;
    
    //Add a number to the list
    node *n = malloc(sizeof(node));
    
    //Ensure memory is not full and that program can function
    if (n == NULL)
    {
        return 1;
    }
    
    //Set the value of this node equivalent to 1
    n->number = 1;
    
    //Initialize the address of the next node to be NULL (no further addresses)
    n->next = NULL;
        
    //Set the value of n, an address, as the value of our list (start the list at address n)
    list = n;
    
    //Check to ensure the 1st node has value 1
    //printf("The value stored in the first node of our linked list is %i\n", n->number);
    
    //Creation of a new node, n
    n = malloc(sizeof(node));
    
    if (n == NULL)
    {
        return 1;
    }
    
    //Set the value of this node equivalent to 2
    n->number = 2;
    
    //Initialize the address of the next node to be NULL (no further addresses)
    n->next = NULL;
    
    //Set the next address in list to be the address of n
    list->next = n;
    
    //Creation of a new node, n
    n = malloc(sizeof(node));
    
    if (n == NULL)
    {
        return 1;
    }
    
    //Set the value of this node equivalent to 3
    n->number = 3;
    
    //Initialize the address of the next node to be NULL (no further addresses)
    n->next = NULL;
    
    //Set the next addresses' next address to be equivalent to the address of this new n
    list->next->next = n;
    
    //////////////////////////////////////////// --Printing of values-- ////////////////////////////////////////////

    //Initialize a variable named count for printing of node values in below while statement
    int count = 0;
    
    //While statement to print out the values of the nodes
    /*while (list->next != NULL)
    {
        //Increment count to indicate the first index of the list exists
        count++;
        
        //Print statement to return values of the linked list to console
        printf("The value of node %i is %i\n", count, list->number);
        
        //Set the value of the list to the next address carried in the list
        list = list->next;
        
        //Statement to print specificially the final value in the linked list
        if (list->next == NULL)
        {
            //Increment count a final time
            count++;
            
            //Print the final value
            printf("The value of node %i is %i\n", count, list->number);
            
            //Note: we do not repeat list = list->next because the next value is NULL showing this is the last node
        }
        
    }*/
    
    //Way to print list using a for loop rather than a while loop
    for (node *tmp = list; tmp != NULL; tmp = tmp->next)
    {
        printf("%i\n", tmp->number);
    }
    
    //While the memory allocate in list is not equivalent to NULL, do the following
    while (list != NULL)
    {
        //create a node called tmp and set it equivalent to the next node in the list
        node *tmp = list->next;
        
        //Free the memory allocated by list
        free(list);
        
        //set the value of list equal to it's next node, previously declared by tmp
        list = tmp;
        
        //This program is a more efficient way of freeing each node using a while loop, rather than individual statements
    }
    
    //Program success
    return 0;
}
