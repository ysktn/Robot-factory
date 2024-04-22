/*
** EPITECH PROJECT, 2024
** robot_factory
** File description:
** ldi
*/

#include "../../includes/my.h"

void write_line_ld_register(char **tab, read_t *read)
{
    if (tab[1][0] == 'r') {
        if (tab[2][0] == 'r') {
            read->buffer[read->pos] = 0x54;
            read->pos += 1;
            write_registre(tab, read, 1);
            write_registre(tab, read, 2);
        }
        if (tab[2][0] == DIRECT_CHAR) {
            read->buffer[read->pos] = 0x94;
            read->pos += 1;
            write_registre(tab, read, 1);
            write_direct_nbr(tab, read, 2, 1);
        }
    }
}

void write_line_ld_direct(char **tab, read_t *read)
{
    if (tab[1][0] == DIRECT_CHAR) {
        if (tab[2][0] == 'r') {
            read->buffer[read->pos] = 0x94;
            read->pos += 1;
            write_direct_nbr(tab, read, 1, 1);
            write_registre(tab, read, 2);
        }
        if (tab[2][0] == DIRECT_CHAR) {
            read->buffer[read->pos] = 0xa4;
            read->pos += 1;
            write_direct_nbr(tab, read, 1, 1);
            write_direct_nbr(tab, read, 2, 1);
        }
    }
}

void write_line_ld_indirect(char **tab, read_t *read)
{
    if (tab[1][0] <= '9' && tab[1][0] >= '0') {
        if (tab[2][0] == 'r') {
            read->buffer[read->pos] = 0xd4;
            read->pos += 1;
            write_indirect_nbr(tab, read, 1);
            write_registre(tab, read, 2);
        }
        if (tab[2][0] == DIRECT_CHAR) {
            read->buffer[read->pos] = 0xe4;
            read->pos += 1;
            write_indirect_nbr(tab, read, 1);
            write_direct_nbr(tab, read, 2, 1);
        }
    }
}

static void write_line_ldi(char **tab, read_t *read, int id_opcode)
{
    read->buffer[read->pos] = id_opcode;
    read->pos += 1;
    write_line_ld_register(tab, read);
    write_line_ld_direct(tab, read);
    write_line_ld_indirect(tab, read);
    write_registre(tab, read, 3);
}

static int check_ldi2(char **tab, char *temp)
{
    if (tab[2][0] != DIRECT_CHAR && tab[2][0] != 'r')
            return ERROR;
    if (tab[2][0] == 'r') {
        temp = my_strncpy(tab[2], 1);
        if (my_getnbr(temp) > REG_NUMBER || my_getnbr(temp) < 1)
            return ERROR;
    }
    if (check_direct(tab, 2) == ERROR)
        return ERROR;
    if (tab[3][0] != 'r')
        return ERROR;
    temp = my_strncpy(tab[3], 1);
    temp[my_strlen(temp)] = '\0';
    if (my_getnbr(temp) > REG_NUMBER || my_getnbr(temp) < 1)
        return ERROR;
    return OK;
}

static int check_error_ldi(char **tab, int cpt, char *temp)
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
    if (check_ldi2(tab, temp) == 84)
        return ERROR;
    return OK;
}

int check_ldi(char **tab, read_t *read)
{
    int cpt = 0;
    char *temp = NULL;

    for (int i = 0; tab[i] != NULL; i++)
        cpt++;
    if (my_strcmp(tab[0], "ldi") == 0) {
        if (check_error_ldi(tab, cpt, temp) == 84)
            return 84;
        write_line_ldi(tab, read, op_tab[9].code);
    }
    return 0;
}
