/*
** EPITECH PROJECT, 2024
** robot_factory
** File description:
** sti
*/

#include "../../includes/my.h"

void write_line_sti_registre(char **tab, read_t *read)
{
    if (tab[2][0] == 'r') {
        if (tab[3][0] == 'r') {
            read->buffer[read->pos] = 0x54;
            read->pos += 1;
            write_registre(tab, read, 1);
            write_registre(tab, read, 2);
            write_registre(tab, read, 3);
        }
        if (tab[3][0] == DIRECT_CHAR) {
            read->buffer[read->pos] = 0x58;
            read->pos += 1;
            write_registre(tab, read, 1);
            write_registre(tab, read, 2);
            write_direct_nbr(tab, read, 3, 1);
        }
    }
}

void write_line_sti_direct(char **tab, read_t *read)
{
    if (tab[2][0] == DIRECT_CHAR) {
        if (tab[3][0] == 'r') {
            read->buffer[read->pos] = 0x64;
            read->pos += 1;
            write_registre(tab, read, 1);
            write_direct_nbr(tab, read, 2, 1);
            write_registre(tab, read, 3);
        }
        if (tab[3][0] == DIRECT_CHAR) {
            read->buffer[read->pos] = 0x68;
            read->pos += 1;
            write_registre(tab, read, 1);
            write_direct_nbr(tab, read, 2, 1);
            write_direct_nbr(tab, read, 3, 1);
        }
    }
}

void write_line_sti_indirect(char **tab, read_t *read)
{
    if (tab[2][0] < '9' && tab[2][0] > '0') {
        if (tab[3][0] == 'r') {
            read->buffer[read->pos] = 0x74;
            read->pos += 1;
            write_registre(tab, read, 1);
            write_indirect_nbr(tab, read, 2);
            write_registre(tab, read, 3);
        }
        if (tab[3][0] == DIRECT_CHAR) {
            read->buffer[read->pos] = 0x78;
            read->pos += 1;
            write_registre(tab, read, 1);
            write_indirect_nbr(tab, read, 2);
            write_direct_nbr(tab, read, 3, 1);
        }
    }
}

static void write_line_sti(char **tab, read_t *read, int id_opcode)
{
    read->buffer[read->pos] = id_opcode;
    read->pos += 1;
    write_line_sti_registre(tab, read);
    write_line_sti_direct(tab, read);
    write_line_sti_indirect(tab, read);
}

static int check_sti3(char **tab, char *temp)
{
    if (tab[3][0] != DIRECT_CHAR && tab[3][0] != 'r')
        return ERROR;
    if (tab[3][0] == 'r') {
        temp = my_strncpy(tab[3], 1);
        temp[my_strlen(temp)] = '\0';
        if (my_getnbr(temp) > REG_NUMBER || my_getnbr(temp) < 1)
            return ERROR;
    }
    if (check_direct(tab, 3) == ERROR)
        return ERROR;
    return OK;
}

static int check_sti2(char **tab, char *temp)
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
    if (check_sti3(tab, temp) == ERROR)
        return ERROR;
    return 0;
}

int check_sti(char **tab, read_t *read)
{
    int cpt = 0;
    char *temp;

    for (int i = 0; tab[i] != NULL; i++)
        cpt++;
    if (my_strcmp(tab[0], "sti") == 0) {
        if (cpt != 4)
            return ERROR;
        if (tab[1][0] != 'r')
            return ERROR;
        temp = my_strncpy(tab[1], 1);
        if (my_getnbr(temp) > REG_NUMBER || my_getnbr(temp) < 1)
            return ERROR;
        if (check_sti2(tab, temp) == ERROR)
            return ERROR;
        write_line_sti(tab, read, op_tab[10].code);
    }
    return OK;
}
