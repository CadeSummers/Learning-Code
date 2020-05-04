#include <stdio.h>
#include <cs50.h>
#include <math.h>

// program which prints out a string, with one more character of the total string until the full string, and then one less charachter until first char
int main()
{
    char arr[11] = {'h', 'e', 'l', 'l', 'o', '_', 'w', 'o', 'r', 'l', 'd'};

    for (int i = 0; i <= 10; i++)
    {
        int x = 0;
        while (x <= i)
        {
            printf("%c", arr[x]);
            x++;
        }
        printf("\n");
    }
    
    printf("hello_world!\n");

    for (int j = 10; j >= 0; j--)
    {
        int y = 0;
        while (y <= j)
        {
            printf("%c", arr[y]);
            y++;
        }
        printf("\n");
    }
}
