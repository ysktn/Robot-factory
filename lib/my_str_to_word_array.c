/*
** EPITECH PROJECT, 2024
** project
** File description:
** my_str_to_word_array
*/

#include "../includes/my.h"

static
int count_word(int *i, char *str)
{
    int count = 0;

    for (int o = (*i); str[o] != '\0'; o += 1) {
        count += 1;
        if (str[o + 1] == ' ' || str[o + 1] == '\0') {
            (*i) = o;
            count += 1;
            return count;
        }
    }
    return count;
}

int compt_max_quote(int i, char *str, int len_str, int count)
{
    len_str += 1;
    i += 1;
    while (str[i] != '"') {
        len_str += 1;
        i += 1;
        if (str[i] == '\0')
            return ERROR;
    }
    len_str += 1;
    if (len_str > count)
                count = len_str;
            len_str = 0;
    return OK;
}

static int cd_count_all_char(int *i, char *str, int *len_str, int *count)
{
    if (str[(*i)] == '"') {
        if (compt_max_quote((*i), str, (*len_str), (*count)) == ERROR)
            return ERROR;
        (*i) += 1;
    }
    return OK;
}

static void bigger_int(int *len_str, int *count)
{
    if ((*len_str) > (*count))
        (*count) = (*len_str);
    return;
}

int count_all_char(char *str)
{
    int count = 0;
    int len_str = 0;

    for (int i = 0; str[i] != '\0'; i ++) {
        if (cd_count_all_char(&i, str, &len_str, &count) == ERROR)
            return ERROR;
        if (str[i] != ' ' && str[i] != '\t') {
            len_str = count_word(&i, str);
            bigger_int(&len_str, &count);
            len_str = 0;
            continue;
        }
    }
    return count;
}

static
int placement_quote(char *str, char **all_string, int *index_str, int *i)
{
    int index_char = 0;

    if (str[(*i)] == '"') {
        (*i) += 1;
        while (str[(*i)] != '"') {
            all_string[(*index_str)][index_char] = str[(*i)];
            (*i) += 1;
            index_char += 1;
        }
        all_string[(*index_str)][index_char] = '\0';
        index_char = 0;
        (*index_str) += 1;
        return OK;
    }
    return ERROR;
}

void placement_word(char *str, char **all_string, int *index_str, int *i)
{
    int index_char = 0;

    if (str[(*i)] != ' ' && str[(*i)] != '\t' && str[(*i)] != '\0'
        && str[(*i)] != '\n') {
        while (str[(*i)] != ' ' && str[(*i)] != '\t' && str[(*i)] != '\0'
        && str[(*i)] != '\n' && str[(*i)] != ',') {
            all_string[(*index_str)][index_char] = str[(*i)];
            index_char += 1;
            (*i) += 1;
        }
        all_string[(*index_str)][index_char] = '\0';
        index_char = 0;
        (*index_str) += 1;
    }
    return;
}

char **str_to_word(char *str)
{
    int len_str = count_argv(str);
    char **all_string = malloc(sizeof(char *) * (len_str + 1));
    int index_str = 0;
    int max_len = count_all_char(str);

    if (all_string == NULL || max_len == ERROR || len_str == 0)
        return NULL;
    for (int i = 0; i != len_str; i ++)
        all_string[i] = malloc(sizeof(char) * (max_len));
    for (int i = 0; str[i] != '\0'; i ++) {
        if (str[i] == ' ' || str[i] == '\t')
            continue;
        if (placement_quote(str, all_string, &index_str, &i) == OK)
            continue;
        placement_word(str, all_string, &index_str, &i);
        if (str[i] == '\0')
            break;
    }
    all_string[index_str] = NULL;
    return all_string;
}
