#include "main.h"
#include <stdio.h>

int main(void)
{
    int number = 98;
    int result;

    result = print_sign(number);
    printf("\nSign of %d is %d\n", number, result);

    number = 0;
    result = print_sign(number);
    printf("\nSign of %d is %d\n", number, result);

    number = -10;
    result = print_sign(number);
    printf("\nSign of %d is %d\n", number, result);

    return (0);
}

