#include <stdio.h>
#include <cs50.h>
int main(void)
{
    // Pedimos que ingrese el nombre.
    string nombre = get_string("Cual es tu nombre:?\n");
    //concatenamos el nombre con el hello word
    printf("hello, word %s\n", nombre);
}