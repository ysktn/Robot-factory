/*
** EPITECH PROJECT, 2024
** tests_ta
** File description:
** main
*/

#include "../../includes/my.h"

static
void cd_detect_label(char *label, char *found, int *i, int *j)
{
    if (found[(*i)] == DIRECT_CHAR)
        (*i) = (*i) + 1;
    if (label[(*j)] == DIRECT_CHAR)
        (*j) = (*j) + 1;
    if (found[(*i)] == LABEL_CHAR)
        (*i) = (*i) + 1;
    if (label[(*j)] == LABEL_CHAR)
        (*j) = (*j) + 1;
    return;
}

static
int detect_label(char *label, char *found)
{
    int i = 0;
    int j = 0;

    if (my_strlen(label) - my_strlen(found) != 0 &&
    my_strlen(label) - my_strlen(found) != -1) {
        return -1;
    }
    for (; found[i] != '\0'; i++) {
        cd_detect_label(label, found, &i, &j);
        if (found[i] == '\0' && label[j] == '\0')
            return 0;
        if (found[i] != label[j])
            return -1;
        j++;
    }
    return 0;
}

static int test_char_label(char **label, char **label_found, int i)
{
    int go = 0;
    int pos_label = 0;

    while (go == 0) {
        if (detect_label(label[pos_label], label_found[i]) == 0)
            go = 1;
        pos_label++;
        if (label[pos_label] == NULL && go == 0)
            return -1;
    }
    return 0;
}

static int test_label(char **label, char **label_found)
{
    for (int i = 0; label_found[i] != NULL; i++) {
        if (test_char_label(label, label_found, i) == -1)
            return -1;
    }
    return 0;
}

static
int creation_array_char(char **try, char ***label, char ***label_found,
    my_t *my)
{
    for (int o = 0; try[o] != NULL; o++) {
        if (try[o][my_strlen(try[o]) - 1] == LABEL_CHAR) {
            my->size_label++;
            *label = realloc(*label, sizeof(char *) * my->size_label);
            (*label)[my->pos_label] = malloc(sizeof(char) * my_strlen(try[o]));
            my_strcpy((*label)[my->pos_label], try[o]);
            my->pos_label++;
        }
        if (try[o][0] == LABEL_CHAR || try[o][1] == LABEL_CHAR) {
            my->size_label_found++;
            *label_found = realloc(*label_found,
            sizeof(char *) * my->size_label_found);
            (*label_found)[my->pos_label_found] =
            malloc(sizeof(char) * my_strlen(try[o]));
            my_strcpy((*label_found)[my->pos_label_found], try[o]);
            my->pos_label_found++;
        }
    }
    return 0;
}

int cd_error_label(char ***label, char ***label_found)
{
    if (test_label((*label), (*label_found)) == -1) {
        for (int i = 0; (*label)[i] != NULL; i++)
            free((*label)[i]);
        free((*label));
        for (int i = 0; (*label_found)[i] != NULL; i++)
            free((*label_found)[i]);
        free((*label_found));
        return ERROR;
    }
    return OK;
}

static void free_label(char ***label, char ***label_found)
{
    for (int i = 0; (*label)[i] != NULL; i++)
        free((*label)[i]);
    free((*label));
    for (int i = 0; (*label_found)[i] != NULL; i++)
        free((*label_found)[i]);
    free((*label_found));
    return;
}

int cd_all_head(char *line, my_t *my, char ***try)
{
    if (test_error_name(my, line) == ERROR)
        return ERROR;
    if (line != NULL && line[0] != '\0')
        (*try) = str_to_word(line);
    if (test_name_file((*try), my) == ERROR)
        return ERROR;
    return OK;
}

int final_test(my_t *my, char ***label, char ***label_found)
{
    if (my->pos_name != 1 || my->pos_comment != 1)
        return ERROR;
    if (cd_error_label(label, label_found) == ERROR)
        return ERROR;
    free_label(label, label_found);
    return OK;
}

int test_lable_char_file(char *file_name)
{
    FILE *file = fopen(file_name, "r");
    char *line = NULL;
    size_t len = 0;
    ssize_t read = getline(&line, &len, file);
    char **try;
    my_t my = {1, 0, 1, 0, 0, 0, 0};
    char **label = malloc(sizeof(char *) * my.size_label);
    char **label_found = malloc(sizeof(char *) * my.size_label_found);

    while ((read) != -1) {
        if (cd_all_head(line, &my, &try) == ERROR)
            return ERROR;
        creation_array_char(try, &label, &label_found, &my);
        read = getline(&line, &len, file);
    }
    free(line);
    fclose(file);
    return final_test(&my, &label, &label_found);
}
