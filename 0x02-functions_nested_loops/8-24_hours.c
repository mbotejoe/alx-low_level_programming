#include "main.h"
#include <stdio.h>

/**
 * is_palindrome - Check if a number is a palindrome.
 * @num: The number to check.
 * Return: 1 if the number is a palindrome, 0 otherwise.
 */
int is_palindrome(int num)
{
    int reversed = 0, original = num;

    while (num != 0)
    {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }

    return (original == reversed);
}

/**
 * print_all_times - Prints all 24-hour times that are palindromes.
 */
void print_all_times(void)
{
    int hour, minute;

    printf("Palindrome times in a 24-hour digital clock:\n");

    for (hour = 0; hour < 24; hour++)
    {
        for (minute = 0; minute < 60; minute++)
        {
            int time = hour * 100 + minute;
            if (is_palindrome(time))
            {
                printf("%02d:%02d\n", hour, minute);
            }
        }
    }
}

