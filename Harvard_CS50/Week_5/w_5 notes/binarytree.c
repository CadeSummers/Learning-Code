#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Creation of doubly-linked list (for binary tree)
typedef struct node
{
    //Contains data
    int number; 
    
    //Contains address of next node
    struct node* right; 
    
    //Contains address of previous node
    struct node* left; 
}
node;

bool search(node *tree);

//Program which illustrates usages and functions of doubly-linked lists
int main()
{
    //Define a binarytree
    node *tree = malloc(sizeof(node));
    
    //Define root of binarytree
    node *root = malloc(sizeof(node));
    
    //Define first non-root node
    node *n = malloc(sizeof(node));
}

//Boolean function representing the recursive searching of a tree
bool search(node *tree)
{
    //Declaration of a number to seek in a binary tree
    int seek = 50;
    
    //Ensure data was successfull allocated with malloc for *tree
    if (tree == NULL)
    {
        //Return program failure
        printf("Tree contains no data. Program failed.\n");
        return false;
    }
    else if (tree->number > seek)
    {
        //Don't do the below. This causes us to lose the root of tree as we redesignate
        //tree = tree->right;
        
        //Do this instead, this lets us explore the next branch of the tree, w/o losing the root
        search(tree);
    }
    else if (tree->number < seek)
    {
        //Don't do the below. This causes us to lose the root of tree as we redesignate
        //tree = tree->left;
        
        //Do this instead, this lets us explore the next branch of the tree, w/o losing the root
        search(tree->left);
    }
    else //(tree->number == seek).
    {
        //Success return statement
        printf("Success! Tree contains %i!\n", 50);
        return true;
    }
    
    //Program failure statement
    printf("All nodes searched. Number not found\n");
    
    //End of non-void function
    return false;
}
