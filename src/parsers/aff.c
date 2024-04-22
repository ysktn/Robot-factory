/*
** EPITECH PROJECT, 2024
** robot_factory
** File description:
** aff
*/

#include "../../includes/my.h"

static void write_line_aff(char **tab, read_t *read, int id_opcode)
{
    read->buffer[read->pos] = id_opcode;
    read->pos += 1;
    read->buffer[read->pos] = 64;
    read->pos += 1;
    write_registre(tab, read, 1);
}

int check_aff(char **tab, read_t *read)
{
    int cpt = 0;
    char *temp;

    for (int i = 0; tab[i] != NULL; i++)
        cpt++;
    if (my_strcmp(tab[0], "aff") == 0) {
        if (cpt != 2)
            return ERROR;
        if (tab[1][0] != 'r')
            return ERROR;
        temp = my_strncpy(tab[1], 1);
        temp[my_strlen(temp)] = '\0';
        if (my_getnbr(temp) > REG_NUMBER || my_getnbr(temp) < 1)
            return ERROR;
        write_line_aff(tab, read, op_tab[15].code);
    }
    return OK;
}
