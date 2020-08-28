#include <stdio.h>
#include <math.h>
#include <cs50.h>

#include "bmp.h"

#define SIZE 3  //SIZE is 3, because we are taking a 3x3 array of pixels around our center pixel, and applying the average value of the 3x3 to that pixel

void blur(int height, int width, RGBTRIPLE image[height][width]);

int main()
{
    //RGBTRIPLE 
    /*int a = 110;
    int b = 130;
    int c = 140;
    
    float f = round((a + b + c) / 3);
    
    f = (int) f;
    
    printf("\nThe average value is: %f\n", f); */
    
    RGBTRIPLE image[SIZE][SIZE];
    
    blur(SIZE, SIZE, image);
}

void blur(int height, int width, RGBTRIPLE image[height][width])
{

    RGBTRIPLE blur_array[SIZE][SIZE]; //array to calculate values for blurring
    RGBTRIPLE blur_value[height][width]; //array that stores values of a blurred photo
    
    RGBTRIPLE avg;
    
    avg.rgbtRed = avg.rgbtBlue = avg.rgbtGreen = 0;
    
    int avgcount = 0; //value of how many terms to divide for in average. Normally 9 for a 3x3 matrix, but edges can be 4 & 6

    //TESTING PRE-BLUR VALUES
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            printf("The pre-blur RGB value of image at pixel %i, %i is R: %i G: %i B: %i \n", i, j, blur_array[i][j].rgbtRed, blur_array[i][j].rgbtGreen, blur_array[i][j].rgbtBlue);
        }
    }
    
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
                //Populating array for calculation
                for (int k = 0; k < SIZE; k++)
                {
                    for (int l = 0; l < SIZE; l++)
                    {
                        
                        if (i + k < 1 || i + k > height - 2) //if the index of i + k is 0 or less, avoid populating array with data outside of image
                        {
                            blur_array[k][l] = avg; //averge currently equal to zero as an RGBTRIPLE
                            
                            //printf("Calculating pixel %i, %i of image\n", i, j);
                            //printf("Giving Blur_Array at %i, %i RGB value %i (corner or edge pixel) \n\n", k, l, avg.rgbtRed);
                        }
                        
                        if (j + l < 1 || j + l > width - 2) //if the index of j + l is 0 or less, avoid populating array with data outside of image
                        {
                            blur_array[k][l] = avg; //average currently equal to zero as an RGBTRIPLE
                            //printf("Calculating pixel %i, %i of image\n", i, j);
                            //printf("Giving Blur_Array at %i, %i RGB value %i (corner or edge pixel) \n\n", k, l, avg.rgbtRed);
                        }
                        
                        if ((j + l > 0 && i + k > 0) || (j + l < width - 2 && i + k < height - 2))
                        {
                            blur_array[k][l] = image[(i + k) - 1][(j + l) - 1]; //populates a 3x3 array, starting from an index at the top left of image, and grabs all pixels from 1 before k & l
                            avgcount++; //max value is 9, does not count a variable for blur_array values that == avg
                            
                            //printf("Calculating pixel %i, %i of image\n", i, j);
                            //printf("Giving Blur_Array at %i, %i value R: %i G: %i B: %i\n\n", k, l, image[(i + k) - 1][(j + l) - 1].rgbtRed, image[(i + k) - 1][(j + l) - 1].rgbtGreen, image[(i + k) - 1][(j + l) - 1].rgbtBlue);
                        }
                    }
                }
                
                //FINDING SPECIFIC VALUES OF RGBT RED 
                /*for (int k = 0; k < SIZE; k++)
                {
                    for (int l = 0; l < SIZE; l++)
                    {
                        printf("The red value of blur_array at cell %i, %i is %i\n", k, l, blur_array[k][l].rgbtRed);
                    }
                }*/
                
                //Calculating Average
                for (int k = 0; k < SIZE; k++)
                {
                    for (int l = 0; l < SIZE; l++)
                    {
                       avg.rgbtRed += blur_array[k][l].rgbtRed;
                       avg.rgbtBlue += blur_array[k][l].rgbtBlue;
                       avg.rgbtGreen += blur_array[k][l].rgbtGreen;
                       
                       if (k == SIZE - 1 && l == SIZE - 1)
                       {
                           avg.rgbtRed = (float) avg.rgbtRed / avgcount; // avgcount is only increased when 0 values come from within the image, 0's in place of array outside of the image have no effect
                           avg.rgbtBlue = (float) avg.rgbtBlue / avgcount;
                           avg.rgbtGreen =  (float) avg.rgbtGreen / avgcount;
                           
                           avg.rgbtRed = (int) (round(avg.rgbtRed));
                           avg.rgbtBlue = (int) (round(avg.rgbtBlue));
                           avg.rgbtGreen = (int) (round(avg.rgbtGreen));
                           
                           blur_value[i][j] = avg;
                           avg.rgbtRed = avg.rgbtBlue = avg.rgbtGreen = 0;
                           avgcount = 0;
                       }
                    }
                }
        }
    }
    
    printf("\n\n ----------- Blurring Complete -----------\n\n");
    
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            printf("The post-blur RGB value of image at pixel %i, %i is R: %i G: %i B: %i, \n", i, j, blur_array[i][j].rgbtRed, blur_array[i][j].rgbtGreen, blur_array[i][j].rgbtBlue);
        }
    }
    
    image = blur_value; //blur value contains all of the image's calculated blurred values

    return;
    
}