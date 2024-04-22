/*
** EPITECH PROJECT, 2024
** stumper5
** File description:
** my_putchar
*/

#include "../includes/my.h"

int my_putchar(char letter)
{
    if (write(1, &letter, 1) == -1)
        return 84;
    return 0;
}
