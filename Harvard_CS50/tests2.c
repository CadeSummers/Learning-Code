#include <stdio.h>
#include <cs50.h>
#include <math.h>

#include "bmp.h"

#define MAX 9
#define SUBMAX 3

float arravg;

int global_array[MAX][MAX];
int postop_array[MAX][MAX];
int subarray[SUBMAX][SUBMAX];

int array_population();
int grab_subarray(int i, int j);
int print_array();
int print_subarray();
int calc_subarray();
//int assign_arrayavg();

int main()
{
    //Populates a global array with increasing and different values. This array is similar to bmp image
    array_population();
    
    //Grabs a 3x3 array from global array, to later average their values in calc_subarray
    //grab_subarray(i, j); with arguments use for loop
    
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            grab_subarray(i, j); //Does this repeat for all values?
            print_subarray(); //this only captures the first subarray
        }
    }
    
    //calc_subarray();
    
    //assign_arrayavg();
    
    //Prints the value of global array
    //print_array();
    
    //Prints the value of a 3x3 subarray, 
    //print_subarray();
    
    //Calculate the value of a single cell by averaging a subarray
    calc_subarray();
}

int array_population()
{
    int value = 0;
    
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            global_array[i][j] = value;
            value++;
        }
    }
    
    return 0;
}

int grab_subarray(int i, int j)
{
    
    for (int k = i; k < i + SUBMAX; k++)
    {
        for (int l = j; l < j + SUBMAX; l++)
        {
            if (i + k == 0 || j + l == 0)
            {
                subarray[k][l] = 0;
            }
            else if (i + k == MAX || j + l == MAX)
            {
                subarray[k][l] = 0;
            }
            else
            {
                subarray[k][l] = global_array[k + (i - 1)][l + (j - 1)];
            }
        }
    }
    return 0;
}

int print_array()
{
    printf("---------------------------------------------------- Printing Initial Array ----------------------------------------------------\n\n");
    
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            printf("(%i, %i) = %i\t", i, j, global_array[i][j]);
        }
        printf("\n\n");
    }
    
    return 0;
}

int print_subarray()
{
    printf("---------------------------------------------------- Printing 3x3 Subarray ----------------------------------------------------\n\n");
    
    for (int i = 0; i < SUBMAX; i++)
    {
        for (int j = 0; j < SUBMAX; j++)
        {
            printf("(%i, %i) = %i\t", i, j, subarray[i][j]);
        }
        printf("\n\n");
    }
    
    return 0;
}

int calc_subarray()
{
    int arrsum = 0;
    
    for (int i = 0; i < SUBMAX; i++)
    {
        for (int j = 0; j < SUBMAX; j++)
        {
            arrsum += subarray[i][j];
        }
    }
    
    //Convert to float for accurate average value
    arrsum = (float) arrsum;
    arravg = round(arrsum/MAX);
    
    //Assign subarray with average values
    /*for (int i = 0; i < SUBMAX; i++)
    {
        for (int j = 0; j < SUBMAX; j++)
        {
            subarray[i][j] = arravg;
        }
    }
    
    //Duplicating subarray print here for view
    printf("---------------------------------------------------- Printing NEW 3x3 Subarray ----------------------------------------------------\n\n");
    
    for (int i = 0; i < SUBMAX; i++)
    {
        for (int j = 0; j < SUBMAX; j++)
        {
            printf("(%i, %i) = %i\t", i, j, subarray[i][j]);
        }
        printf("\n\n");
    }*/
    
    return 0;
}

/*int assign_arrayavg()
{
    postop_array[i][j] = arravg;
    arravg = 0;
    
    return 0;
}*/