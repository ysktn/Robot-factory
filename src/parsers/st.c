/*
** EPITECH PROJECT, 2024
** robot_factory
** File description:
** st
*/

#include "../../includes/my.h"

static void write_line_st(char **tab, read_t *read, int id_opcode)
{
    read->buffer[read->pos] = id_opcode;
    read->pos += 1;
    if (tab[2][0] == 'r') {
        read->buffer[read->pos] = 0x50;
        read->pos += 1;
        write_registre(tab, read, 1);
        write_registre(tab, read, 2);
    }
    if (tab[2][0] < '9' && tab[1][0] > '0') {
        read->buffer[read->pos] = 0x70;
        read->pos += 1;
        write_registre(tab, read, 1);
        write_indirect_nbr(tab, read, 2);
    }
}

static int check_st2(char **tab, char *temp)
{
    if (tab[2][0] == 'r') {
        temp = my_strncpy(tab[2], 1);
        temp[my_strlen(temp)] = '\0';
        if (my_getnbr(temp) > REG_NUMBER || my_getnbr(temp) < 1)
            return ERROR;
    }
    if (tab[2][0] <= '9' && tab[2][0] >= '0') {
        if (my_str_is_num(tab[2]) == 1)
            return ERROR;
    }
    return OK;
}

int check_st(char **tab, read_t *read)
{
    int cpt = 0;
    char *temp;

    for (int i = 0; tab[i] != NULL; i++)
        cpt++;
    if (my_strcmp(tab[0], "st") == 0) {
        if (cpt != 3)
            return ERROR;
        if (tab[1][0] != 'r')
            return ERROR;
        temp = my_strncpy(tab[1], 1);
        if (my_getnbr(temp) > REG_NUMBER || my_getnbr(temp) < 1)
            return ERROR;
        if (tab[2][0] != 'r' && (tab[2][0] < '0' || tab[2][0] > '9'))
            return ERROR;
        if (check_st2(tab, temp) == ERROR)
            return ERROR;
        write_line_st(tab, read, op_tab[2].code);
    }
    return OK;
}
