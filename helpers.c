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
    //Create a second base
    RGBTRIPLE image2[height + 2][width + 2];

    for (int a = 0; a < height + 2; a++)
    {
        for (int m = 0; m < width + 2; m++)
        {
            if (m == 0 || a == 0 || a == height + 1 || a == width + 1)
            {
                image2[a][m].rgbtBlue = 0;
                image2[a][m].rgbtGreen = 0;
                image2[a][m].rgbtRed = 0;
            }
            else
            {
                image2[a][m].rgbtBlue = image[a][m].rgbtBlue;
                image2[a][m].rgbtGreen = image[a][m].rgbtGreen;
                image2[a][m].rgbtRed = image[a][m].rgbtRed;
            }
        }
    }
    //Get every pixel
    for (int i  = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int GxsumB = 0;
            int GxsumG= 0;
            int GxsumR=0;
            int GysumB=0;
            int GysumG=0;
            int GysumR=0;

            //Get every 3x3 grid
            //Gx
            for (int hGx = i - 1; hGx < i + 2; hGx++)
            {
                for (int wGx = j - 1; wGx < j + 2; wGx++)
                {
                    if (hGx < 0 || wGx < 0 || hGx >= height || wGx >= width || wGx == j)
                    {
                        GxsumB += image2[hGx][wGx].rgbtBlue * 0;
                        GxsumG += image2[hGx][wGx].rgbtGreen * 0;
                        GxsumR += image2[hGx][wGx].rgbtRed * 0;
                    }
                    if (wGx == j - 1)
                    {
                        if (hGx != i)
                        {
                            GxsumB += image2[hGx][wGx].rgbtBlue * -1;
                            GxsumG += image2[hGx][wGx].rgbtGreen * -1;
                            GxsumR += image2[hGx][wGx].rgbtRed * -1;
                        }
                        else
                        {
                            GxsumB += image2[hGx][wGx].rgbtBlue * -2;
                            GxsumG += image2[hGx][wGx].rgbtGreen * -2;
                            GxsumR += image2[hGx][wGx].rgbtRed * -2;
                        }
                    }
                    else
                    {
                        if (hGx != i)
                        {
                            GxsumB += image2[hGx][wGx].rgbtBlue * 1;
                            GxsumG += image2[hGx][wGx].rgbtGreen * 1;
                            GxsumR += image2[hGx][wGx].rgbtRed * 1;
                        }
                        else
                        {
                            GxsumB += image2[hGx][wGx].rgbtBlue * 2;
                            GxsumG += image2[hGx][wGx].rgbtGreen * 2;
                            GxsumR += image2[hGx][wGx].rgbtRed * 2;
                        }
                    }
                }
            }
            //Gy
            for (int hGy = i - 1; hGy < i + 2; hGy++)
            {
                for (int wGy = j - 1; wGy < j + 2; wGy++)
                {
                    if (hGy < 0 || wGy < 0 || hGy >= height || wGy >= width || hGy == i)
                    {
                        GysumB += image2[hGy][wGy].rgbtBlue * 0;
                        GysumG += image2[hGy][wGy].rgbtGreen * 0;
                        GysumR += image2[hGy][wGy].rgbtRed * 0;
                    }

                    if (hGy == i - 1)
                    {
                        if (wGy != j)
                        {
                            GysumB += image2[hGy][wGy].rgbtBlue * -1;
                            GysumG += image2[hGy][wGy].rgbtGreen * -1;
                            GysumR += image2[hGy][wGy].rgbtRed * -1;
                        }
                        else
                        {
                            GysumB += image2[hGy][wGy].rgbtBlue * -2;
                            GysumG += image2[hGy][wGy].rgbtGreen * -2;
                            GysumR += image2[hGy][wGy].rgbtRed * -2;
                        }
                    }
                    else
                    {
                        if (wGy != j)
                        {
                            GysumB += image2[hGy][wGy].rgbtBlue * 1;
                            GysumG += image2[hGy][wGy].rgbtGreen * 1;
                            GysumR += image2[hGy][wGy].rgbtRed * 1;
                        }
                        else
                        {
                            GysumB += image2[hGy][wGy].rgbtBlue * 2;
                            GysumG += image2[hGy][wGy].rgbtGreen * 2;
                            GysumR += image2[hGy][wGy].rgbtRed * 2;
                        }
                    }
                }
            }
            int B = round(sqrt(pow(GxsumB, 2) + pow(GysumB, 2)));
            int G = round(sqrt(pow(GxsumG, 2) + pow(GysumG, 2)));
            int R = round(sqrt(pow(GxsumR, 2) + pow(GysumR, 2)));

            if (B > 255)
            {
                B = 255;
            }

            if (G > 255)
            {
                G = 255;
            }

            if (R > 255)
            {
                R = 255;
            }


            image2[i][j].rgbtBlue = B;
            image2[i][j].rgbtGreen = G;
            image2[i][j].rgbtRed = R;
        }
    }

    for (int a = 1; a < height + 1; a++)
    {
        for (int l = 1; l < width + 1; l++)
        {
            image[a - 1][l - 1].rgbtRed = image2[a - 1][l - 1].rgbtRed;
            image[a - 1][l - 1].rgbtGreen = image2[a - 1][l - 1].rgbtGreen;
            image[a - 1][l - 1].rgbtBlue = image2[a - 1][l - 1].rgbtBlue;
        }
    }
    return;
}
