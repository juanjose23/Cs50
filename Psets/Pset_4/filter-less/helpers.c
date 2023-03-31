#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Calcula el promedio y conviete cada pixel en byte
            int promedio = round(((float)image[i][j].rgbtRed + (float)image[i][j].rgbtBlue + (float)image[i][j].rgbtGreen) / 3);
            // Asignamos los colores obtenidos del promedio.
            image[i][j].rgbtRed = promedio;
            image[i][j].rgbtBlue = promedio;
            image[i][j].rgbtGreen = promedio;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Calculamos los colores sepia con la funcion de los valores originales de la imagen
            int sepiaRed = round(0.393 * (int)image[i][j].rgbtRed + 0.769 * (int)image[i][j].rgbtGreen + 0.189 * (int)image[i][j].rgbtBlue);
            int sepiaGreen = round(0.349 * (int)image[i][j].rgbtRed + 0.686 * (int)image[i][j].rgbtGreen + 0.168 * (int)image[i][j].rgbtBlue);
            int sepiaBlue = round(0.272 * (int)image[i][j].rgbtRed + 0.534 * (int)image[i][j].rgbtGreen + 0.131 * (int)image[i][j].rgbtBlue);
            // Asignamos que sobre pase el valor 255.
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            // Asignamos los colores sepia obtenidos ala imagen.
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            // Asignamos el valor de RGBTRIPLE A UNA VARIABLE TEMPORAL
            RGBTRIPLE tmp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = tmp;
        }
    }
    return;
}
RGBTRIPLE averagePixel(int count, RGBTRIPLE x[count])
{
    float avgr = 0;
    float avgg = 0;
    float avgb = 0;
    for (int i = 0; i < count; i++)
    {
        avgr += (float)x[i].rgbtRed;
        avgg += (float)x[i].rgbtGreen;
        avgb += (float)x[i].rgbtBlue;
    }
    RGBTRIPLE pixel;
    pixel.rgbtRed = round(avgr / count);
    pixel.rgbtGreen = round(avgg / count);
    pixel.rgbtBlue = round(avgb / count);
    return pixel;
}
// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE holdingImage[height][width];

    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {

            int blurAmount = 1;

            RGBTRIPLE avg[(int)pow((1 + (blurAmount * 2)), 2)];

            int index = 0;

            for (int lrShift = -blurAmount; lrShift <= blurAmount; lrShift++)
            {

                if ((x + lrShift < 0) || (x + lrShift >= width))
                {
                    continue;
                }

                for (int udShift = -blurAmount; udShift <= blurAmount; udShift++)
                {

                    if ((y + udShift < 0) || (y + udShift >= height))
                    {
                        continue;
                    }

                    avg[index] = image[y + udShift][x + lrShift];
                    index++;
                }
            }

            holdingImage[y][x] = averagePixel(index, avg);
        }
    }

    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            image[y][x] = holdingImage[y][x];
        }
    }
    return;
}
