/*
** EPITECH PROJECT, 2024
** robot_factory
** File description:
** and
*/

#include "../../includes/my.h"

static void write_line_cond_direct2(char **tab, read_t *read, int id_opcode)
{
    if (tab[2][0] <= '9' && tab[2][0] >= '0') {
        read->buffer[read->pos] = id_opcode;
        read->pos += 1;
        read->buffer[read->pos] = 180;
        read->pos += 1;
        write_direct_nbr(tab, read, 1, 0);
        write_indirect_nbr(tab, read, 2);
    }
    return;
}

void write_line_cond_direct(char **tab, read_t *read, int id_opcode)
{
    if (tab[1][0] == DIRECT_CHAR) {
        if (tab[2][0] == 'r') {
            read->buffer[read->pos] = id_opcode;
            read->pos += 1;
            read->buffer[read->pos] = 148;
            read->pos += 1;
            write_direct_nbr(tab, read, 1, 0);
            write_registre(tab, read, 2);
        }
        if (tab[2][0] == DIRECT_CHAR) {
            read->buffer[read->pos] = id_opcode;
            read->pos += 1;
            read->buffer[read->pos] = 164;
            read->pos += 1;
            write_direct_nbr(tab, read, 1, 0);
            write_direct_nbr(tab, read, 2, 0);
        }
        write_line_cond_direct2(tab, read, id_opcode);
    }
}

static void write_line_cond_indirect2(char **tab, read_t *read, int id_opcode)
{
    if (tab[2][0] <= '9' && tab[2][0] >= '0') {
        read->buffer[read->pos] = id_opcode;
        read->pos += 1;
        read->buffer[read->pos] = 244;
        read->pos += 1;
        write_indirect_nbr(tab, read, 1);
        write_indirect_nbr(tab, read, 2);
    }
    return;
}

void write_line_cond_indirect(char **tab, read_t *read, int id_opcode)
{
    if (tab[1][0] <= '9' && tab[1][0] >= '0') {
        if (tab[2][0] == 'r') {
            read->buffer[read->pos] = id_opcode;
            read->pos += 1;
            read->buffer[read->pos] = 212;
            read->pos += 1;
            write_indirect_nbr(tab, read, 1);
            write_registre(tab, read, 2);
        }
        if (tab[2][0] == DIRECT_CHAR) {
            read->buffer[read->pos] = id_opcode;
            read->pos += 1;
            read->buffer[read->pos] = 228;
            read->pos += 1;
            write_indirect_nbr(tab, read, 1);
            write_direct_nbr(tab, read, 2, 0);
        }
        write_line_cond_indirect2(tab, read, id_opcode);
    }
}

void write_line_cond_registre2(char **tab, read_t *read, int id_opcode)
{
    if (tab[2][0] <= '9' && tab[2][0] >= '0') {
        read->buffer[read->pos] = id_opcode;
        read->pos += 1;
            read->buffer[read->pos] = 116;
        read->pos += 1;
        write_registre(tab, read, 1);
        write_indirect_nbr(tab, read, 2);
    }
    return;
}

void write_line_cond_registre(char **tab, read_t *read, int id_opcode)
{
    if (tab[1][0] == 'r') {
        if (tab[2][0] == 'r') {
            read->buffer[read->pos] = id_opcode;
            read->pos += 1;
            read->buffer[read->pos] = 84;
            read->pos += 1;
            write_registre(tab, read, 1);
            write_registre(tab, read, 2);
        }
        if (tab[2][0] == DIRECT_CHAR) {
            read->buffer[read->pos] = id_opcode;
            read->pos += 1;
            read->buffer[read->pos] = 100;
            read->pos += 1;
            write_registre(tab, read, 1);
            write_direct_nbr(tab, read, 2, 0);
        }
        write_line_cond_registre2(tab, read, id_opcode);
    }
}

static void write_line_and(char **tab, read_t *read, int id_opcode)
{
    write_line_cond_direct(tab, read, id_opcode);
    write_line_cond_indirect(tab, read, id_opcode);
    write_line_cond_registre(tab, read, id_opcode);
    write_registre(tab, read, 3);
}

static int check_and2(char **tab, char *temp)
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
    if (tab[3][0] != 'r' || check_direct(tab, 2) == ERROR)
        return ERROR;
    temp = my_strncpy(tab[3], 1);
    temp[my_strlen(temp)] = '\0';
    if (my_getnbr(temp) > REG_NUMBER || my_getnbr(temp) < 1)
        return ERROR;
    return OK;
}

static int check_error_and(char **tab, int cpt, char *temp)
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
    if (check_and2(tab, temp) == ERROR)
        return ERROR;
    return OK;
}

int check_and(char **tab, read_t *read)
{
    int cpt = 0;
    char *temp = NULL;

    for (int i = 0; tab[i] != NULL; i++)
        cpt++;
    if (my_strcmp(tab[0], "and") == 0) {
        if (check_error_and(tab, cpt, temp) == ERROR)
            return ERROR;
        write_line_and(tab, read, op_tab[5].code);
    }
    return OK;
}
