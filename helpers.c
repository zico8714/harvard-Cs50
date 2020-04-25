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
    // Creating a copy of image with an extra border of black layer
    RGBTRIPLE copy[height + 2][width + 2];
    for (int i = 0; i < height + 2; i++)
    {
        for (int j = 0; j < width + 2; j++)
        {
            if (i == 0 || j == 0 || i == height + 1 || j == width + 1)
            {
                copy[i][j].rgbtRed = 0;
                copy[i][j].rgbtGreen = 0;
                copy[i][j].rgbtBlue = 0;
            }
            else
            {
                copy[i][j] = image[i - 1][j - 1];
            }
        }
    }
    // Create the matrix Gx and Gy
    int Gx[3][3] =
    {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}
    };
    int Gy[3][3] =
    {
        {-1, -2, -1},
        {0, 0, 0},
        {1, 2, 1}
    };
    for (int i = 1; i < height + 1; i++)
    {
        for (int j = 1; j < width + 1; j++)
        {
            // Total values for red-x, green-x, blue-x, red-y, green-y and blue-y
            int aRx = 0;
            int aGx = 0;
            int aBx = 0;
            int aRy = 0;
            int aGy = 0;
            int aBy = 0;
            for (int a = -1; a < 2; a++)
            {
                for (int b = -1; b < 2; b++)
                {
                    aRx += (copy[i + a][j + b].rgbtRed * Gx[a + 1][b + 1]);
                    aGx += (copy[i + a][j + b].rgbtGreen * Gx[a + 1][b + 1]);
                    aBx += (copy[i + a][j + b].rgbtBlue * Gx[a + 1][b + 1]);
                    aRy += (copy[i + a][j + b].rgbtRed * Gy[a + 1][b + 1]);
                    aGy += (copy[i + a][j + b].rgbtGreen * Gy[a + 1][b + 1]);
                    aBy += (copy[i + a][j + b].rgbtBlue * Gy[a + 1][b + 1]);
                }
            }
            int redG = round(sqrt(pow(aRx, 2) + pow(aRy, 2)));
            int greenG = round(sqrt(pow(aGx, 2) + pow(aGy, 2)));
            int blueG = round(sqrt(pow(aBx, 2) + pow(aBy, 2)));
            // Wrapping values over 255 to within 1 to 255
            if (redG > 255)
            {
                redG = 255;
            }
            if (greenG > 255)
            {
                greenG = 255;
            }
            if (blueG > 255)
            {
                blueG = 255;
            }
            image[i - 1][j - 1].rgbtRed = redG;
            image[i - 1][j - 1].rgbtGreen = greenG;
            image[i - 1][j - 1].rgbtBlue = blueG;
        }
    }
    return;
}
