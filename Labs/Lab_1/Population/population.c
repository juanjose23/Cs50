#include <stdio.h>
#include <cs50.h>
int main(void)
{
    int star = 0, end = 0, year = 0;
    do
    {
        star = get_int("poblacion inicial de llamas:\n");
    }
    while (star < 9);
    do
    {
        end = get_int("poblacion final de llamas:\n");
    }
    while (star > end);
    while (star < end)
    {
        star = star + (star / 3) - (star / 4);
        year++;
    }

    printf("Years: %i", year);
}