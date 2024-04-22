/*
** EPITECH PROJECT, 2024
** test
** File description:
** str_in_str
*/

#include "../includes/my.h"

int str_in_str(char *s1, char *s2)
{
    int current = 0;
    int count = my_strlen(s2);
    int i = 0;

    if (s1 == NULL || s2 == NULL || my_strlen(s1) < my_strlen(s2))
        return 0;
    for (; *s1; s1++) {
        if (*s1 != s2[i] && current != 0) {
            i = 0;
            current = 0;
        }
        if (*s1 == s2[i]) {
            current += 1;
            i += 1;
        }
        if (current == count)
            return 1;
    }
    return 0;
}
