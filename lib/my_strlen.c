/*
** EPITECH PROJECT, 2024
** stumper
** File description:
** strlen
*/

#include "../includes/my.h"

int my_strlen(char const *const str)
{
    int i = 0;

    if (str == NULL)
        return -1;
    while (str[i] != '\0')
        i++;
    return i;
}
