#include <cs50.h>
#include <stdio.h>
#include <string.h>
int main(void)
{
// Ingresamos el numero de la tarjeta a verificar
    long n = get_long("Number: ");
    // Calculamos  la longitud
    int i = 0;
    long l = n;
    while (l > 0)
    {
        l = l / 10;
        i++;
    }
    // Comprobar si la longitud es válida
    if (i != 13 && i != 15 && i != 16)
    {
        printf("INVALID\n");
        return 0;
    }
 //calcular la suma
    int sum1 = 0;
    int sum2 = 0;
    long x = n;
    int total = 0;
    int d1;
    int d2;
    int mod1;
    int mod2;
    do
    {
        // Elimina el ultimo digito
        mod1 = x % 10;
        x = x / 10;
        sum1 = sum1 + mod1;
       // Elimina el penúltimo dígito
        mod2 = x % 10;
        x = x / 10;
     // 2 veces el penúltimo dígito y sumamos dígitos a sum2
        mod2 = mod2 * 2;
        d1 = mod2 % 10;
        d2 = mod2 / 10;
        sum2 = sum2 + d1 + d2;
    }
    while (x > 0);
    total = sum1 + sum2;
  // Comprobando el algoritmo de Luhn
    if (total % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }
    // Cifras iniciales
    long start = n;
    do
    {
        start = start / 10;
    }
    while (start > 100);
    // Comprobación de dígitos iniciales para el tipo de tarjeta
    if ((start / 10 == 5) && (0 < start % 10 && start % 10 < 6))
    {
        printf("MASTERCARD\n");
    }
    else if ((start / 10 == 3) && (start % 10 == 4 || start % 10 == 7))
    {
        printf("AMEX\n");
    }
    else if (start / 10 == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}