/*
** EPITECH PROJECT, 2024
** robot
** File description:
** create_new_file
*/

#include "../includes/my.h"

int avance(char *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '/') {
            count = i + 1;
        }
    }
    return count;
}

char *create_file(char *file_param)
{
    char *new_name = malloc(sizeof(char) * my_strlen(file_param));
    int pos = 0;

    if (new_name == NULL || file_param == NULL)
        return NULL;
    for (int i = avance(file_param); file_param[i] != '.'; i++) {
        new_name[pos] = file_param[i];
        pos += 1;
        if (file_param[i + 1] == '.') {
            new_name[pos] = '\0';
            break;
        }
    }
    new_name = my_strcat(new_name, ".cor");
    return new_name;
}
