/*
** EPITECH PROJECT, 2024
** robot_factory
** File description:
** live
*/

#include "../../includes/my.h"

static void write_line_live(char **tab, read_t *read, char id_opcode)
{
    read->buffer[read->pos] = id_opcode;
    read->pos += 1;
    write_direct_nbr(tab, read, 1, 0);
}

int check_live(char **tab, read_t *read)
{
    int cpt = 0;

    for (int i = 0; tab[i] != NULL; i++)
        cpt++;
    if (my_strcmp(tab[0], "live") == 0) {
        if (cpt != 2)
            return ERROR;
        if (tab[1][0] != DIRECT_CHAR)
            return ERROR;
        if (check_direct(tab, 1) == ERROR)
            return ERROR;
        write_line_live(tab, read, op_tab[0].code);
    }
    return OK;
}
