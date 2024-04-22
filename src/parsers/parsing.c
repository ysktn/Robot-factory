/*
** EPITECH PROJECT, 2024
** robot_factory
** File description:
** parsing
*/
#include "../../includes/my.h"

int check_line(char **tab, read_t *read)
{
    if (tab == NULL || read == NULL || tab[0] == NULL)
        return OK;
    if (my_strcmp(tab[0], NAME_CMD_STRING) == 0
    || my_strcmp(tab[0], COMMENT_CMD_STRING) == 0 ||
    tab[0][my_strlen(tab[0])] == LABEL_CHAR)
        return OK;
    if ((check_live(tab, read) == ERROR) || (check_ld(tab, read) == ERROR) ||
    (check_st(tab, read) == ERROR) || (check_add(tab, read) == ERROR) ||
    (check_sub(tab, read) == ERROR) || (check_and(tab, read) == ERROR) ||
    (check_or(tab, read) == ERROR) || (check_xor(tab, read) == ERROR) ||
    (check_zjmp(tab, read) == ERROR) || (check_ldi(tab, read) == ERROR) ||
    (check_sti(tab, read) == ERROR) || (check_fork(tab, read) == ERROR) ||
    (check_lld(tab, read) == ERROR) || (check_lldi(tab, read) == ERROR) ||
    (check_lfork(tab, read) == ERROR) || (check_aff(tab, read) == ERROR))
        return ERROR;
    return OK;
}
