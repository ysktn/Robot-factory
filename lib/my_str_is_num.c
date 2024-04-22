/*
** EPITECH PROJECT, 2024
** robot_factory
** File description:
** my_str_is_num
*/

#include "../includes/my.h"

int my_str_is_num(char *str)
{
    int i = 0;

    if (str[0] == '-')
        i++;
    while (str[i] != '\0') {
        if (str[i] < '0' || str[i] > '9')
            return 1;
        i++;
    }
    return 0;
}
