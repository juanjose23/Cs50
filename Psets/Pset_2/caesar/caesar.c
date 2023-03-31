#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
bool check_valid_key(string s);
int main(int argc, string argv[])
{
// Verificamos que tenga do argumentos
    if (argc != 2)
    {
        //si no  cumple mostrara el mensaje.
        printf("Usage: ./caesar key\n");
        return 1;
    }
    //mandamos a llamar la funcion de validar si es digito
    if (!check_valid_key(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
//Convertimos la key en entero mediante atoi.
    int key = atoi(argv[1]);
    //Pedimos que ingrese el texto a incriptar
    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");
    int len = strlen(plaintext);
    //Con el ciclo for recorro el la longitud del texto
    for (int i = 0; i < len; i++)
    {
        //mandamos  el texto plano  a char
        char c = plaintext[i];
        //validamos si el texto si alfanumerico
        if (isalpha(c))
        {
            // creamos  un if para validar si el texto esta en mayuscula.
            if (islower(c))
            {
// aplicamos la formula para encriptar
                printf("%C", (c + key - 97) % 26 + 97);
            }
//validamos con un if añadido si el texto esta en minuscula
            else if (isupper(c))
            {
                // aplicamos la formula para encriptar
                printf("%C", (c + key - 65) % 26 + 65);
            }
        }
        else
        {
            printf("%c", c);
        }
    }
    printf("\n");
}
// Funcion para validar si es un digito.
bool check_valid_key(string s)
{
//creamos un ciclo for para recorrer los caracter e identificar si hay un caracter con letra
    for (int i = 0, len = strlen(s); i < len; i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}