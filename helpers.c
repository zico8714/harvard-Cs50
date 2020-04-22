#include "helpers.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float B, G, R;
    int qty = 3;

    float *avg = malloc(sizeof(float));
    if (avg == NULL)
    {
        return;
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            B = image[i][j].rgbtBlue;
            G = image[i][j].rgbtGreen;
            R = image[i][j].rgbtRed;

            *avg = (B + G + R) / qty;
            int Avg = round(*avg);

            image[i][j].rgbtBlue = Avg;
            image[i][j].rgbtGreen = Avg;
            image[i][j].rgbtRed = Avg;
        }
        free(avg);
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //Set a float to get the middle of the
    float phase = width / 2;

    for (int i = 0; i < height; i++)
    {
        //Set counter to number of pixels -1
        int count = width - 1;
        for (int j = 0; j < phase; j++)
        {
            if (image[i][j].rgbtRed != image[i][count].rgbtRed || image[i][j].rgbtBlue != image[i][count].rgbtBlue
            || image[i][j].rgbtGreen != image[i][count].rgbtGreen)
            {
                RGBTRIPLE tmp;
                tmp = image[i][count];
                image[i][count] = image[i][j];
                image[i][j] = tmp;
                count--;
            }
            else
            {
                count--;
                break;
            }
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE image2[height][width];

    for (int i  = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float sumB = 0;
            float sumG = 0;
            float sumR = 0;
            int count = 0;
            for (int h = i - 1; h < i + 2; h++)
            {
                for (int w = j - 1; w < j + 2; w++)
                {
                    if (h >= 0 && w >= 0 && h < height && w < width)
                    {
                        sumB += image[h][w].rgbtBlue;
                        sumG += image[h][w].rgbtGreen;
                        sumR += image[h][w].rgbtRed;
                        count++;
                    }
                }
            }
            //Barbi te amo
            float avgB = sumB / count;
            float avgG = sumG / count;
            float avgR = sumR / count;

            int B = round(avgB);
            int G = round(avgG);
            int R = round(avgR);

            image2[i][j].rgbtBlue = B;
            image2[i][j].rgbtGreen = G;
            image2[i][j].rgbtRed = R;
        }
    }
    //Barbi te amooooooooooooooooooooooooo
    for (int a = 0; a < height; a++)
    {
        for (int l = 0; l < width; l++)
        {
            image[a][l] = image2[a][l];
        }
    }
    //BARBI TE AMO
//BARBI TE AMO
//BARBI TE AMO
//BARBI TE AMO
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
