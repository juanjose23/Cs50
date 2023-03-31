#include <stdio.h>
#include <cs50.h>
int main(void)
{
    int altura = 0;
    // Ciclo do-while para validar la entrada de la altura tiene que ser mayor de uno y menor que 8
    do
    {
        altura = get_int("Altura:\n");
    }
    while (altura < 1 || altura > 8);
    // ciclo for para imprimir los #
    for (int i = 0; i < altura; i++)
    {
        for (int j = 0; j < altura; j++)
        {
            // If para validar y dar espacio sin necesidad de crear una variable espaciadora.
            if (i + j < altura - 1)
            {
                // condicionamos los espacios
                printf(" ");
            }
            else
            {
                // imprimos piramide
                printf("#");
            }
        }

        printf("\n");
    }
}
