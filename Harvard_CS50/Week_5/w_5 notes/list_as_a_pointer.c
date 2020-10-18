#include <stdio.h>
#include <stdlib.h>

#define LSIZE 3 //lsize == size of list

int main()
{
    //Declare a pointer to a chunk of memory designated by pinter *list
    int *list = malloc(LSIZE * sizeof(int));

    //Ensure that if list returns null (ie if no memory remains) return a program failure
    if (list == NULL)
    {
        return 1;
    }

    //Populate the cells of that chunk of memory with values 0 through LSIZE (see line 4)
    for (int i = 0; i < LSIZE; i++)
    {
        list[i] = i + 1;
    }
    
    //Print *list for visualization
    for (int i = 0; i < LSIZE; i++)
    {
        printf("%i\n", list[i]);
    }
    
    //Freeing memory (best practice, keeps everything lightweight)
    free(list);
}