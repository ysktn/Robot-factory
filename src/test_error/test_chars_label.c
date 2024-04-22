/*
** EPITECH PROJECT, 2024
** robot_factory
** File description:
** test_chars_label
*/

#include "../includes/my.h"

int check_label_chars3(char **label, int i, int j, int is_valid)
{
    for (int k = 0; LABEL_CHARS[k] != '\0'; k++) {
        if (label[i][j] == LABEL_CHARS[k]) {
            is_valid = 1;
            break;
        }
    }
    if (is_valid == 0)
        return ERROR;
    return OK;
}

int check_label_chars2(char **label, int i)
{
    int is_valid = 0;

    for (int j = 0; label[i][j] != '\0'; j++) {
        is_valid = 0;
        if (check_label_chars3(label, i, j, is_valid) == ERROR)
            return ERROR;
    }
    return OK;
}

int check_label_chars(char **label)
{
    for (int i = 0; label[i] != NULL; i++) {
        if (check_label_chars2(label, i) == ERROR)
            return ERROR;
    }
    return OK;
}
