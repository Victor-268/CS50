#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int average = round((image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen) / 3.0);
            image[i][j].rgbtRed = average;
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sumRed = 0, sumGreen = 0, sumBlue = 0, count = 0;

            for (int ni = -1; ni <= 1; ni++)
            {
                for (int nj = -1; nj <= 1; nj++)
                {
                    int newI = i + ni;
                    int newJ = j + nj;

                    if (newI >= 0 && newI < height && newJ >= 0 && newJ < width)
                    {
                        sumRed += temp[newI][newJ].rgbtRed;
                        sumGreen += temp[newI][newJ].rgbtGreen;
                        sumBlue += temp[newI][newJ].rgbtBlue;
                        count++;
                    }
                }
            }

            image[i][j].rgbtRed = round(sumRed / (float)count);
            image[i][j].rgbtGreen = round(sumGreen / (float)count);
            image[i][j].rgbtBlue = round(sumBlue / (float)count);
        }
    }
}



// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int GxRed = 0, GyRed = 0;
            int GxGreen = 0, GyGreen = 0;
            int GxBlue = 0, GyBlue = 0;

            for (int ni = -1; ni <= 1; ni++)
            {
                for (int nj = -1; nj <= 1; nj++)
                {
                    int newI = i + ni;
                    int newJ = j + nj;

                    if (newI >= 0 && newI < height && newJ >= 0 && newJ < width)
                    {
                        GxRed += temp[newI][newJ].rgbtRed * Gx[ni + 1][nj + 1];
                        GyRed += temp[newI][newJ].rgbtRed * Gy[ni + 1][nj + 1];

                        GxGreen += temp[newI][newJ].rgbtGreen * Gx[ni + 1][nj + 1];
                        GyGreen += temp[newI][newJ].rgbtGreen * Gy[ni + 1][nj + 1];

                        GxBlue += temp[newI][newJ].rgbtBlue * Gx[ni + 1][nj + 1];
                        GyBlue += temp[newI][newJ].rgbtBlue * Gy[ni + 1][nj + 1];
                    }
                }
            }

            int newRed = round(sqrt(GxRed * GxRed + GyRed * GyRed));
            int newGreen = round(sqrt(GxGreen * GxGreen + GyGreen * GyGreen));
            int newBlue = round(sqrt(GxBlue * GxBlue + GyBlue * GyBlue));

            image[i][j].rgbtRed = fmin(255, newRed);
            image[i][j].rgbtGreen = fmin(255, newGreen);
            image[i][j].rgbtBlue = fmin(255, newBlue);
        }
    }
}
