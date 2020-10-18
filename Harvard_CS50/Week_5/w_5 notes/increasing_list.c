#include <stdio.h>
#include <stdlib.h>

#define LSIZE 3 //lsize == size of list

//Program which illustrates how to increase the number of elements in a pointer
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
    
    //Resizing of array
    int *tmp = malloc(4 * sizeof(int));
    
    //Checking for NULL value to ensure memory remains
    if (tmp == NULL)
    {
        return 1;
    }
    
    //Assignment of data to new array
    for (int i = 0; i < LSIZE; i++)
    {
        tmp[i] = list[i];
    }
    
    //Store in last cell of tmp, a new value of 4
    tmp[3] = 4;
    
    //Free list as we are no longer using it
    free(list);
    
    //Rename the pointer tmp as list
    list = tmp;
    
    //Print list for visualization
    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", list[i]);
    }
    
    //Freeing memory (best practice, keeps everything lightweight)
    free(list);
    free(tmp);
}