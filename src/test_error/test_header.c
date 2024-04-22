/*
** EPITECH PROJECT, 2024
** robot
** File description:
** test_header
*/

#include "../../includes/my.h"

static int cd_test_error(global_t *global, header_t *header)
{
    if (my_strcmp(STING_LINE[0], NAME_CMD_STRING) == 0) {
        my_strcpy(header->prog_name, STING_LINE[1]);
        return OK;
    }
    if (my_strcmp(STING_LINE[0], COMMENT_CMD_STRING) == 0) {
        my_strcpy(header->comment, STING_LINE[1]);
        return OK;
    }
    return OK;
}

int test_error(global_t *global, header_t *header)
{
    if (STING_LINE[0] == NULL)
        return OK;
    if (cd_test_error(global, header) == ERROR)
        return ERROR;
    return OK;
}
