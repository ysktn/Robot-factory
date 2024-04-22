/*
** EPITECH PROJECT, 2024
** project
** File description:
** my_strcat
*/

#include "../includes/my.h"

char *my_strcat(char *dest, char const *src)
{
    int len_src = my_strlen(src);
    int len = my_strlen(dest);
    char *finish = malloc(sizeof(char) * (len + len_src + 1));

    for (int i = 0; dest[i] != '\0'; i += 1) {
        finish[i] = dest[i];
    }
    for (int i = 0; src[i] != '\0'; i += 1) {
        finish[len] = src[i];
        len += 1;
    }
    finish[len] = '\0';
    return (finish);
}
