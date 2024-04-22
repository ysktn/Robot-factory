/*
** EPITECH PROJECT, 2024
** robot_factory
** File description:
** or
*/

#include "../../includes/my.h"


static void write_line_or(char **tab, read_t *read, int id_opcode)
{
    write_line_cond_direct(tab, read, id_opcode);
    write_line_cond_indirect(tab, read, id_opcode);
    write_line_cond_registre(tab, read, id_opcode);
    write_registre(tab, read, 3);
}

static int check_or3(char **tab, char *temp)
{
    if (tab[2][0] == 'r') {
        temp = my_strncpy(tab[2], 1);
        if (my_getnbr(temp) > REG_NUMBER || my_getnbr(temp) < 1)
            return 84;
    }
    if (tab[2][0] <= '9' && tab[2][0] >= '0') {
        if (my_str_is_num(tab[2]) == 1)
            return 84;
    }
    if (tab[3][0] != 'r')
        return 84;
    temp = my_strncpy(tab[3], 1);
    temp[my_strlen(temp)] = '\0';
    if (my_getnbr(temp) > REG_NUMBER || my_getnbr(temp) < 1)
        return 84;
    return 0;
}

static int check_or2(char **tab)
{
    char *temp;

    if (tab[1][0] <= '9' && tab[1][0] >= '0') {
        if (my_str_is_num(tab[1]) == 1)
            return ERROR;
    }
    if (tab[1][0] == 'r') {
        temp = my_strncpy(tab[1], 1);
        if (my_getnbr(temp) > REG_NUMBER || my_getnbr(temp) < 1)
            return ERROR;
    }
    if (tab[2][0] != 'r' && tab[2][0] != DIRECT_CHAR &&
    (tab[2][0] > '9' || tab[2][0] < '0'))
        return ERROR;
    if (check_direct(tab, 2) == ERROR)
        return ERROR;
    if (check_or3(tab, temp) == ERROR)
        return ERROR;
    return OK;
}

int check_or(char **tab, read_t *read)
{
    int cpt = 0;

    for (int i = 0; tab[i] != NULL; i++)
        cpt++;
    if (my_strcmp(tab[0], "or") == 0) {
        if (cpt != 4)
            return ERROR;
        if (tab[1][0] != 'r' && tab[1][0] != DIRECT_CHAR &&
        (tab[1][0] > '9' || tab[1][0] < '0'))
            return ERROR;
        if (check_direct(tab, 1) == ERROR)
            return ERROR;
        if (check_or2(tab) == ERROR)
            return ERROR;
        write_line_or(tab, read, op_tab[6].code);
    }
    return OK;
}
