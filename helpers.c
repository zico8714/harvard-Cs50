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
    RGBTRIPLE image2[height][width];

    //Get every pixel
    for (int i  = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int GxsumB;
            int GxsumG;
            int GxsumR;
            int GysumB;
            int GysumG;
            int GysumR;

            //Get every 3x3 grid
            //Gx
            for (int hGx = i - 1; hGx < i + 2; hGx++)
            {
                for (int wGx = j - 1; wGx < j + 2; wGx++)
                {
                    if (hGx < 0 || wGx < 0 || hGx > height || wGx > width || wGx == j)
                    {
                        GxsumB += 0;
                        GxsumG += 0;
                        GxsumR += 0;
                    }
                    else if (wGx == j - 1)
                    {
                        if (hGx != i)
                        {
                            GxsumB += image[hGx][wGx].rgbtBlue * -1;
                            GxsumG += image[hGx][wGx].rgbtGreen * -1;
                            GxsumR += image[hGx][wGx].rgbtRed * -1;
                        }
                        else
                        {
                            GxsumB += image[hGx][wGx].rgbtBlue * -2;
                            GxsumG += image[hGx][wGx].rgbtGreen * -2;
                            GxsumR += image[hGx][wGx].rgbtRed * -2;
                        }
                    }
                    else if (wGx == j + 1)
                    {
                        if (hGx != i)
                        {
                            GxsumB += image[hGx][wGx].rgbtBlue * 1;
                            GxsumG += image[hGx][wGx].rgbtGreen * 1;
                            GxsumR += image[hGx][wGx].rgbtRed * 1;
                        }
                        else
                        {
                            GxsumB += image[hGx][wGx].rgbtBlue * 2;
                            GxsumG += image[hGx][wGx].rgbtGreen * 2;
                            GxsumR += image[hGx][wGx].rgbtRed * 2;
                        }
                    }
                }

                if (GxsumB > 255)
                {
                    GxsumB = 255;
                }

                if (GxsumG > 255)
                {
                    GxsumG = 255;
                }

                if (GxsumR > 255)
                {
                    GxsumR = 255;
                }
            }
            //Gy
            for (int hGy = i - 1; hGy < i + 2; hGy++)
            {
                for (int wGy = j - 1; wGy < j + 2; wGy++)
                {
                    if (hGy < 0 || wGy < 0 || hGy > height || wGy > width || hGy == i)
                    {
                        GysumB += 0;
                        GysumG += 0;
                        GysumR += 0;
                    }
                    else if (hGy == i - 1)
                    {
                        if (wGy != j)
                        {
                            GysumB += image[hGy][wGy].rgbtBlue * -1;
                            GysumG += image[hGy][wGy].rgbtGreen * -1;
                            GysumR += image[hGy][wGy].rgbtRed * -1;
                        }
                        else
                        {
                            GysumB += image[hGy][wGy].rgbtBlue * -2;
                            GysumG += image[hGy][wGy].rgbtGreen * -2;
                            GysumR += image[hGy][wGy].rgbtRed * -2;
                        }
                    }
                    else if (hGy == i + 1)
                    {
                        if (wGy != j)
                        {
                            GysumB += image[hGy][wGy].rgbtBlue * 1;
                            GysumG += image[hGy][wGy].rgbtGreen * 1;
                            GysumR += image[hGy][wGy].rgbtRed * 1;
                        }
                        else
                        {
                            GysumB += image[hGy][wGy].rgbtBlue * 2;
                            GysumG += image[hGy][wGy].rgbtGreen * 2;
                            GysumR += image[hGy][wGy].rgbtRed * 2;
                        }
                    }
                }
                if (GysumB > 255)
                {
                    GysumB = 255;
                }

                if (GysumG > 255)
                {
                    GysumG = 255;
                }

                if (GysumR > 255)
                {
                    GysumR = 255;
                }
            }
            int B = round(sqrt(pow(GxsumB, 2) + pow(GysumB, 2)));
            int G = round(sqrt(pow(GxsumG, 2) + pow(GysumG, 2)));
            int R = round(sqrt(pow(GxsumR, 2) + pow(GysumR, 2)));

            image2[i][j].rgbtBlue = B;
            image2[i][j].rgbtGreen = G;
            image2[i][j].rgbtRed = R;
        }
    }

    for (int a = 0; a < height; a++)
    {
        for (int l = 0; l < width; l++)
        {
            image[a][l] = image2[a][l];
        }
    }
    return;
}
