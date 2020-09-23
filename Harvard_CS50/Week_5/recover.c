#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t  BYTE;
#define BLOCK 512 //size of a block of memory

int main(int argc, char *argv[])
{
    //define buffer for checking memory card
    BYTE buffer[BLOCK];
    
    //declaration of character array that is name of file, starting from 000
    char fname[8];
    
    //declaration of jpgcount, starting from 0
    int jpgcount = 0;

    //if no argument, remind proper usage
    if (argc != 2)
    {
        printf("Incorrect usage. Use: ./recover card.raw\n");

        return 1;
    }

    //define files, one for card, the other for jpgs
    FILE *card;
    FILE *jpg;

    //define the file "card" as the argument of the command line (aka "card.raw"), and then open it
    card = fopen(argv[1], "r");

    //Check for file
    if (card == NULL)
    {
        printf("Error: no file found.\n");
        return 1;
    }

    //read the the card with buffer
    while (fread(buffer, 512, 1, card) != 0)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            for (int i = 0; i < BLOCK; i++)
            {
                //Write to string the name of a new file named ###.jpg where ### is defined by jpgcount
                sprintf(fname, "%03i.jpg", jpgcount);
                
                //Update count of jpg images
                jpgcount++;
                
                //write buffer to new file
                jpg = fopen(fname, "w");
                
                //write to file information in jpg information in buffer
                fwrite(buffer, 512, 1, jpg);
                
                //close the last jpg
                fclose(jpg);
            }
        }
    }
    
    //close file
    fclose(card);
}
