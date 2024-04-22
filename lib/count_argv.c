/*
** EPITECH PROJECT, 2024
** project
** File description:
** count_argv
*/

static void cd_count_argv(char *str, int *i, int *count)
{
    if (str[(*i)] == '"') {
        (*i) += 1;
        while (str[(*i)] != '"') {
            (*i) += 1;
        }
        (*count) += 1;
    }
    return;
}

int count_argv(char *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i ++) {
        cd_count_argv(str, &i, &count);
        if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'
        || str[i + 1] == '\n' || str[i + 1] == '\t' || str[i + 1] == ','))
            count += 1;
    }
    return count;
}
