/*
** EPITECH PROJECT, 2024
** robot
** File description:
** convert_int
*/

#include "../includes/my.h"

char *reverse_string(char *str)
{
    char *reversed = malloc(sizeof(char) * my_strlen(str));

    for (int i = 0; i < my_strlen(str); i++) {
        reversed[i] = str[my_strlen(str) - i - 1];
    }
    return (reversed);
}

char *convert_deci(int decimal, int base)
{
    char *number = "0123456789ABCDEF";
    char *hexa = malloc(sizeof(char) * 10000);
    char *finish;

    for (int i = 0; decimal > 0; i++) {
        hexa[i] = number[decimal % base];
        decimal = decimal / base;
    }
    finish = reverse_string(hexa);
    free(hexa);
    if (my_strlen(finish) == 1) {
        finish = my_strcat("0", finish);
    }
    return (finish);
}
