/*
** EPITECH PROJECT, 2024
** test
** File description:
** test_head_file
*/

#include "../../includes/my.h"

static int detect_quote(char *line)
{
    int count_quote = 0;

    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] == '"')
            count_quote++;
    }
    return count_quote;
}

int test_error_name(my_t *my, char *line)
{
    int count_quote = 0;
    int count_com = 0;

    if (my->tour == 0 && str_in_str(line, NAME_CMD_STRING) == 1) {
        count_quote = detect_quote(line);
        if (count_quote != 2)
            return ERROR;
    }
    if (my->tour == 1 && str_in_str(line, COMMENT_CMD_STRING) == 1) {
        count_com = detect_quote(line);
        if (count_com != 2)
            return ERROR;
    }
    return OK;
}

int test_name_file(char **try, my_t *my)
{
    if (try[0] != NULL && my_strcmp(try[0], NAME_CMD_STRING) == 0) {
        my->pos_name += 1;
        if (my_strlen(try[1]) > PROG_NAME_LENGTH || try[2] != NULL
            || try[1] == NULL || try[1][0] == '\0')
            return ERROR;
    }
    if (try[0] != NULL && my_strcmp(try[0], COMMENT_CMD_STRING) == 0 &&
        my->tour == 1) {
        my->pos_comment += 1;
        if (my_strlen(try[1]) > COMMENT_LENGTH || try[2] != NULL ||
            try[1] == NULL || try[1][0] == '\0')
            return ERROR;
    }
    if (try[0] != NULL) {
        if (try[0][0] != COMMENT_CHAR)
            my->tour += 1;
    }
    return OK;
}
