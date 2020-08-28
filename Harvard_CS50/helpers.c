#include <stdio.h>
#include <cs50.h>
#include <math.h>

#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float rgbtavg = round(((float) image[i][j].rgbtRed + (float) image[i][j].rgbtBlue + (float) image[i][j].rgbtGreen)/3); //average value of RGB values, which is basically the grayscale intensity
            
            rgbtavg = (int) rgbtavg; //we calculated the average as a float to be able to round up, but rgbt BYTE values are incompatible with floats, so we recast to an int

            image[i][j].rgbtRed = rgbtavg;
            image[i][j].rgbtBlue = rgbtavg;
            image[i][j].rgbtGreen = rgbtavg;
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Identify horizantal and vertical axis
    // If # of pixels is even
    // If # of pixels is odd, the row/column represent an axis that does not shift

    //OR

    //take image[height - 1] through image[0] and image[width - 1] through image[0], and swap the values using a temporary holding variable, until the halfway mark.


    //NULLIFYING below for later usage if %2 method does not succeed

    /*int v_axis = 0;
    int h_axis = 0;*/

    if ((width % 2) == 0)
    {
        for (int i = 0; i < height; i++) //we do not divide height by 2 because we are going reflecting left-to-right. Use width in i for loop and height in j for up-to-down swap.
        {
            for (int j = 0; j < width / 2; j++) //swap rightmost and leftmost, approaching the center and stopping
            {
                RGBTRIPLE holder = image[i][j];                         //IF ERROR: holder needs to be in array format to hold RGBTRIPLE data of image
                image[i][j] = image[(height - 1) - i][(width - 1) - j]; // we use height/width - 1 because otherwise we would have a buffer overflow
                image[(height - 1) - i][(width - 1) - j] = holder;
            }
        }
    }
    else
    {
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                if (j == (width - 1) / 2) //if width % 2 == 1, then we have a midpoint, which will always be identifiable as (width - 1) / 2, or the floored half of width, former easier
                {
                    ;
                }
                else
                {
                    RGBTRIPLE holder = image[i][j];                         //IF ERROR: holder needs to be in array format to hold RGBTRIPLE data of image
                    image[i][j] = image[(height - 1) - i][(width - 1) - j]; // we use height/width - 1 because otherwise we would have a buffer overflow
                    image[(height - 1) - i][(width - 1) - j] = holder;
                }
            }
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //create a 3x3 array, with duplicate values to some amount of the screen, and unavailable values set to NULL
    //get the average of these values, and get and store it as an RGBTTRIPLE
    //put the average back at the corresponding pixel, and repeat for all pixels

    #define SIZE 3  //SIZE is 3, because we are taking a 3x3 array of pixels around our center pixel, and applying the average value of the 3x3 to that pixel

    RGBTRIPLE blur_array[SIZE][SIZE]; //array to calculate values for blurring
    RGBTRIPLE edge_blur_array[SIZE][SIZE - 1];
    RGBTRIPLE corner_blur_array[SIZE - 1][SIZE - 1];
    
    RGBTRIPLE blur_value[height][width]; //array that stores values of a blurred photo
    
    //Declare a varaible with a border of all 0 RGBTRIPLE values, and have the divisor of the average account for these "de facto null" values?

    for (int i = 0; i < height; i++)
    {
        //CREATE AN IF STATEMENT, WHERE ONCE WE HAVE CALCULATE A CERTAIN NUMBER OF PIXELS, WE CAN BEGIN TO ASSIGN VALUES TO PAST PIXELS. WE CAN BLUR IMAGE[0][0] WHEN WE HAVE PASSED
        //IMAGE[1][1], ALL PIXELS AFTERWARDS NEVER REQUIRE THE INFORMATION FROM IMAGE[0][0]
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE avg;
            avg.rgbtRed = avg.rgbtBlue = avg.rgbtGreen = 0;
            
            int avgcount = 0; //value of how many terms to divide for in average. Normally 9 for a 3x3 matrix, but edges can be 4 & 6
            
                for (int k = 0; k < SIZE; k++)
                {
                    for (int l = 0; l < SIZE; l++)
                    {
                        if (i + k == 0 || j + l == 0) //avoids us grabbing pixels before the 0 height or 0 width pixel
                        {
                            blur_array[k][l] = avg;
                        }   
                        else if (i + k == height - 1 || j + l == width - 1) //avoids us going over the pixel limit
                        {
                            blur_array[k][l] = avg;
                        }
                        else
                        {
                            blur_array[k][l] = image[k + (i - 1)][l + (j - 1)]; //k/l is index of subarray, i/j is position in image, -1 represents we are pulling from the array 1 behind & above
                            avgcount++; //MAX VALUE OF AVGCOUNT IS 9
                        }
                    }
                }
                
                //summ all values of blur array
                for (int k = 0; k < SIZE; k++)
                {
                    for (int l = 0; l < SIZE; l++)
                    {
                       avg.rgbtRed += blur_array[k][l].rgbtRed;
                       avg.rgbtBlue += blur_array[k][l].rgbtBlue;
                       avg.rgbtGreen += blur_array[k][l].rgbtGreen;
                    }
                }
                
                //calculate average
                avg.rgbtRed = round((float) avg.rgbtRed / avgcount); // avgcount is only increased when 0 values come from within the image, 0's in place of array outside of the image have no effect
                avg.rgbtBlue = round((float) avg.rgbtBlue / avgcount);
                avg.rgbtGreen =  round((float) avg.rgbtGreen / avgcount); //if this doesn't work, remove round and round below values
                           
                avg.rgbtRed = (int)  avg.rgbtRed;
                avg.rgbtBlue = (int) avg.rgbtBlue;
                avg.rgbtGreen = (int) avg.rgbtGreen;
                           
                blur_value[i][j] = avg;
        }
    }
    
    image = blur_value; //blur value contains all of the image's calculated blurred values

    //
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
