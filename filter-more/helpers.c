#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int average = (image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen)/3;
            image[i][j].rgbtRed = average;
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width/2; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j]= image[i][width-j-1];
            image[i][width-j-1] = temp;
        }
    }
    return;
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
            int sumRed=0, sumGreen=0, sumBlue=0, count=0;

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
            // Calculate the average values and assign them to the current pixel
            image[i][j].rgbtRed = sumRed / count;
            image[i][j].rgbtGreen = sumGreen / count;
            image[i][j].rgbtBlue = sumBlue / count;
        }
    }

    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    // Create a copy of the original image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    // Define Sobel operators
    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    // Iterate through each pixel in the image
    for (int i = 1; i < height - 1; i++)
    {
        for (int j = 1; j < width - 1; j++)
        {
            int GxRed = 0, GyRed = 0;
            int GxGreen = 0, GyGreen = 0;
            int GxBlue = 0, GyBlue = 0;

            // Apply the Sobel operator to calculate gradients in both x and y directions
            for (int ni = -1; ni <= 1; ni++)
            {
                for (int nj = -1; nj <= 1; nj++)
                {
                    GxRed += temp[i + ni][j + nj].rgbtRed * Gx[ni + 1][nj + 1];
                    GyRed += temp[i + ni][j + nj].rgbtRed * Gy[ni + 1][nj + 1];

                    GxGreen += temp[i + ni][j + nj].rgbtGreen * Gx[ni + 1][nj + 1];
                    GyGreen += temp[i + ni][j + nj].rgbtGreen * Gy[ni + 1][nj + 1];

                    GxBlue += temp[i + ni][j + nj].rgbtBlue * Gx[ni + 1][nj + 1];
                    GyBlue += temp[i + ni][j + nj].rgbtBlue * Gy[ni + 1][nj + 1];
                }
            }

            // Calculate the combined gradient magnitude
            int newRed = fmin(255, (int)sqrt(GxRed * GxRed + GyRed * GyRed));
            int newGreen = fmin(255, (int)sqrt(GxGreen * GxGreen + GyGreen * GyGreen));
            int newBlue = fmin(255, (int)sqrt(GxBlue * GxBlue + GyBlue * GyBlue));

            // Assign the new values to the current pixel
            image[i][j].rgbtRed = newRed;
            image[i][j].rgbtGreen = newGreen;
            image[i][j].rgbtBlue = newBlue;
        }
    }
    return;
}
