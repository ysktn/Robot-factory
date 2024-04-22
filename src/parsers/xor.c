/*
** EPITECH PROJECT, 2024
** robot_factory
** File description:
** xor
*/

#include "../../includes/my.h"

static void write_line_xor(char **tab, read_t *read, int id_opcode)
{
    write_line_cond_direct(tab, read, id_opcode);
    write_line_cond_indirect(tab, read, id_opcode);
    write_line_cond_registre(tab, read, id_opcode);
    write_registre(tab, read, 3);
}

static int check_xor2(char **tab, char *temp)
{
    if (tab[2][0] != 'r' && tab[2][0] != DIRECT_CHAR &&
    (tab[2][0] > '9' || tab[2][0] < '0'))
        return ERROR;
    if (tab[2][0] == 'r') {
        temp = my_strncpy(tab[2], 1);
        if (my_getnbr(temp) > REG_NUMBER || my_getnbr(temp) < 1)
            return ERROR;
    }
    if (tab[2][0] <= '9' && tab[2][0] >= '0') {
        if (my_str_is_num(tab[2]) == 1)
            return ERROR;
    }
    if (check_direct(tab, 2) == ERROR)
        return ERROR;
    if (tab[3][0] != 'r')
        return ERROR;
    temp = my_strncpy(tab[3], 1);
    if (my_getnbr(temp) > REG_NUMBER || my_getnbr(temp) < 1)
        return ERROR;
    return OK;
}

static int check_error_xor(char **tab, int cpt, char *temp)
{
    if (cpt != 4)
        return ERROR;
    if (tab[1][0] != 'r' && tab[1][0] != DIRECT_CHAR &&
    (tab[1][0] > '9' || tab[1][0] < '0'))
        return ERROR;
    if (tab[1][0] == 'r') {
        temp = my_strncpy(tab[1], 1);
        if (my_getnbr(temp) > REG_NUMBER || my_getnbr(temp) < 1)
            return ERROR;
    }
    if (tab[1][0] <= '9' && tab[1][0] >= '0') {
        if (my_str_is_num(tab[1]) == 1)
            return ERROR;
    }
    if (check_direct(tab, 1) == ERROR)
        return ERROR;
    if (check_xor2(tab, temp) == ERROR)
        return ERROR;
    return OK;
}

int check_xor(char **tab, read_t *read)
{
    int cpt = 0;
    char *temp = NULL;

    for (int i = 0; tab[i] != NULL; i++)
        cpt++;
    if (my_strcmp(tab[0], "xor") == 0) {
        if (check_error_xor(tab, cpt, temp) == ERROR)
            return ERROR;
        write_line_xor(tab, read, op_tab[7].code);
    }
    return OK;
}
