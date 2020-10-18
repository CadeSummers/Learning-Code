#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node //In order to include the datatype in the definition of your typedef, you must use this syntax. The datatype node consists of nodes, so we must use this syntax.
{
    //Value store in linked list
    int number;

    //Address of the next node, which is stored as a node struct called next
    struct node *next;
}
node;

int main()
{
    bool end_of_list = false;
    
    int count = 0;

    //Designate an address in memory named list of type node and sett it's value equivalent to NULL
    node *list = NULL;

    //Ensure that the value of list is NULL
    if (list == NULL)
    {
        printf("List is empty.\n");
    }

    //Designate memory for a node and call the address of the memory n
    node *n = malloc(sizeof(node));

    //Create a check to ensure that memory allocated for n did not return NULL
    if (n != NULL)
    {
        n->number = 2;
        n->next = NULL;
    }

    //Designate to have the same address as n (list begins where n starts)
    list = n;

    //Print Check
    //printf("The first value in list is: %i\n", list->number);

    //Designate memory for a node and call the address of that memory n
    node *m = malloc(sizeof(node));

    //Create a check to ensure that memory allocated for n did not return NULL
    if (m != NULL)
    {
        m->number = 4;
        m->next = n;
    }

    list = m;

    //Designate memory for a node and call the address of the memory n
    node *o = malloc(sizeof(node));

    //Create a check to ensure that memory allocated for n did not return NULL
    if (o != NULL)
    {
        o->number = 5;
        o->next = m;
    }

    list = o;

    //Designate memory for a node and call the address of the memory n
    node *p = malloc(sizeof(node));

    //Create a check to ensure that memory allocated for n did not return NULL
    if (p != NULL)
    {
        p->number = 1;
        p->next = o;
    }

    list = p;
    
    //Declaration of node named tmp to be equivalent to list (the address of our first node)
    node *tmp = list;
    while (end_of_list == false)
    {
        count++;
        printf("The number stored in this node is: %i\n", tmp->number);
        tmp = tmp->next;
        
        if (tmp->next == NULL)
        {
            //Hack-ish way to print end of list, but it works so eh ¯\_(ツ)_/¯
            count++;
            printf("The number stored in this node is: %i\n", tmp->number);
            printf("The number of nodes in this linked list is: %i\n", count);
            end_of_list = true;
        }
    }
    tmp->next = p;

    free(list);
    free(tmp);
    //free(n); //freeing n and p does nothing, why is this?
    free(m); //these blocks are the only ones that seemingly leak memory, why is this?
    free(o); //these blocks are the only ones that seemingly leak memory, why is this?
    //free(p); //freeing n and p does nothing, why is this?
    return 0;
}