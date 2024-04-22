/*
** EPITECH PROJECT, 2024
** stumper5
** File description:
** my_put_str
*/

#include "../includes/my.h"

int my_put_str(char const *string)
{
    if (string == NULL)
        return 84;
    for (int i = 0; string[i] != '\0'; i++) {
        my_putchar(string[i]);
    }
    return 0;
}
