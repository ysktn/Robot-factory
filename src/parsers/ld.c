/*
** EPITECH PROJECT, 2024
** robot_factory
** File description:
** ld
*/

#include "../../includes/my.h"

static void write_line_ld(char **tab, read_t *read, int id_opcode)
{
    read->buffer[read->pos] = id_opcode;
    read->pos += 1;
    if (tab[1][0] == DIRECT_CHAR) {
        read->buffer[read->pos] = 144;
        read->pos += 1;
        write_direct_nbr(tab, read, 1, 0);
    }
    if (tab[1][0] < '9' && tab[1][0] > '0') {
        read->buffer[read->pos] = 208;
        read->pos += 1;
        write_indirect_nbr(tab, read, 1);
    }
    write_registre(tab, read, 2);
}

int check_ld2(char **tab)
{
    char *temp;

    if (tab[1][0] <= '9' && tab[1][0] >= '0') {
        if (my_str_is_num(tab[1]) == 1)
            return ERROR;
    }
    if (tab[2][0] != 'r')
        return ERROR;
    temp = my_strncpy(tab[2], 1);
    temp[my_strlen(temp)] = '\0';
    if (my_getnbr(temp) > REG_NUMBER || my_getnbr(temp) < 1)
        return ERROR;
    return OK;
}

int check_ld(char **tab, read_t *read)
{
    int cpt = 0;

    for (int i = 0; tab[i] != NULL; i++)
        cpt++;
    if (my_strcmp(tab[0], "ld") == 0) {
        if (cpt != 3)
            return ERROR;
        if (tab[1][0] != DIRECT_CHAR && (tab[1][0] > '9' || tab[1][0] < '0'))
            return ERROR;
        if (check_direct(tab, 1) == ERROR)
            return ERROR;
        if (check_ld2(tab) == ERROR)
            return ERROR;
        write_line_ld(tab, read, op_tab[1].code);
    }
    return OK;
}
