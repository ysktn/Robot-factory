/*
** EPITECH PROJECT, 2024
** robot_factory
** File description:
** sub
*/

#include "../../includes/my.h"

static void write_line_sub(char **tab, read_t *read, int id_opcode)
{
    read->buffer[read->pos] = id_opcode;
    read->pos += 1;
    read->buffer[read->pos] = 0x54;
    read->pos += 1;
    write_registre(tab, read, 1);
    write_registre(tab, read, 2);
    write_registre(tab, read, 3);
}

static int check_sub2(char **tab, char *temp)
{
    if (tab[2][0] != 'r')
        return ERROR;
    temp = my_strncpy(tab[2], 1);
    if (my_getnbr(temp) > REG_NUMBER || my_getnbr(temp) < 1)
        return ERROR;
    if (tab[3][0] != 'r')
        return ERROR;
    temp = my_strncpy(tab[3], 1);
    temp[my_strlen(temp)] = '\0';
    if (my_getnbr(temp) > REG_NUMBER || my_getnbr(temp) < 1)
        return ERROR;
    return OK;
}

int check_sub(char **tab, read_t *read)
{
    int cpt = 0;
    char *temp;

    for (int i = 0; tab[i] != NULL; i++)
        cpt++;
    if (my_strcmp(tab[0], "sub") == 0) {
        if (cpt != 4)
            return ERROR;
        if (tab[1][0] != 'r')
            return ERROR;
        temp = my_strncpy(tab[1], 1);
        if (my_getnbr(temp) > REG_NUMBER || my_getnbr(temp) < 1)
            return ERROR;
        if (check_sub2(tab, temp) == ERROR)
            return ERROR;
        write_line_sub(tab, read, op_tab[4].code);
    }
    return OK;
}
