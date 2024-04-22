/*
** EPITECH PROJECT, 2024
** project
** File description:
** my_compare
*/

#include "../includes/my.h"

int compare_char_str(char *str, char not_wanted)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == not_wanted)
            return ERROR;
    }
    return OK;
}
