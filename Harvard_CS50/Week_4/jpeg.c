#include <stdio.h>
#include <cs50.h>

int main(int argc, char *argv[]) //argv[1] is on the command line after ./f(x)
{
    if (argc != 2)
    {
        return 1;
    }
    
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        return 2;
    }
    
    unsigned char bytes[3];
    
    fread(bytes, 3, 1, file);
    
    //check for .jpg
    
    if (bytes[0] == 0xff && bytes[1] == 0xd8 && bytes[2] == 0xff)
    {
        printf("File is in .jpg format\n");
        return 0;
    }
    
    printf("File is not in .jpg format\n");
    
    return -1;
    
}
