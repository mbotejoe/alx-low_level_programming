#include "main.h"

/**
 * print_last_digit - prints the last digit of an integer
 * @n: The integer to extract the last digit from
 *
 * Return: The value of the last digit
 */
int print_last_digit(int n)
{
    int last_digit;

    /* Get the last digit (can handle negative numbers) */
    last_digit = n % 10;

    /* Convert to positive if negative */
    if (last_digit < 0)
        last_digit = -last_digit;

    /* Print the last digit */
    _putchar('0' + last_digit);

    /* Return the last digit */
    return last_digit;
}

