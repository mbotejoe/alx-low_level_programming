#include "main.h"
#include <stdio.h>

/**
 * print_times_table - Print the times table for a given number.
 * @n: The number to generate the times table for.
 */
void print_times_table(int n)
{
    if (n < 1 || n > 10)
    {
        printf("Number out of range. Please choose a number between 1 and 10.\n");
        return;
    }

    printf("Times table for %d:\n", n);
    for (int i = 1; i <= 10; i++)
    {
        printf("%d x %d = %d\n", n, i, n * i);
    }
}

