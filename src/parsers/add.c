/*
** EPITECH PROJECT, 2024
** robot_factory
** File description:
** add
*/

#include "../../includes/my.h"

static void write_line_add(char **tab, read_t *read, int id_opcode)
{
    read->buffer[read->pos] = id_opcode;
    read->pos += 1;
    read->buffer[read->pos] = 84;
    read->pos += 1;
    write_registre(tab, read, 1);
    write_registre(tab, read, 2);
    write_registre(tab, read, 3);
}

static int check_add2(char **tab, char *temp)
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

int check_add(char **tab, read_t *read)
{
    int cpt = 0;
    char *temp = NULL;

    for (int i = 0; tab[i] != NULL; i++)
        cpt++;
    if (my_strcmp(tab[0], "add") == 0) {
        if (cpt != 4)
            return ERROR;
        if (tab[1][0] != 'r')
            return ERROR;
        temp = my_strncpy(tab[1], 1);
        if (my_getnbr(temp) > REG_NUMBER || my_getnbr(temp) < 1) {
            return ERROR;
        }
        if (check_add2(tab, temp) == ERROR)
            return (ERROR);
        write_line_add(tab, read, op_tab[3].code);
    }
    return OK;
}
