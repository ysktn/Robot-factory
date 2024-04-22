/*
** EPITECH PROJECT, 2024
** robot_factory
** File description:
** utils
*/

#include "../../includes/my.h"

void write_registre(char **tab, read_t *read, int pos)
{
    char *temp = NULL;
    int nbr = 0;

    for (int i = 0; i < T_REG - 1; i += 1) {
        read->buffer[read->pos] = 0;
        read->pos += 1;
    }
    temp = my_strncpy(tab[pos], 1);
    nbr = my_getnbr(temp);
    read->buffer[read->pos] = nbr;
    read->pos += 1;
}

void write_indirect_nbr(char **tab, read_t *read, int pos)
{
    int nbr = 0;

    for (int i = 0; i < IND_SIZE - 1; i += 1) {
        read->buffer[read->pos] = 0;
        read->pos += 1;
    }
    nbr = my_getnbr(tab[pos]);
    read->buffer[read->pos] = nbr;
    read->pos += 1;
}

static void write_index(read_t *read, int index)
{
    if (index == 0) {
        for (int i = 0; i < DIR_SIZE - 1; i += 1) {
            read->buffer[read->pos] = 0;
            read->pos += 1;
        }
    } else {
        for (int i = 0; i < IND_SIZE - 1; i += 1) {
            read->buffer[read->pos] = 0;
            read->pos += 1;
        }
    }
}

void write_direct_nbr(char **tab, read_t *read, int pos, int index)
{
    char *temp = NULL;
    int nbr = 0;

    if (tab[pos][1] <= '9' && tab[pos][1] >= '0') {
        write_index(read, index);
        temp = my_strncpy(tab[pos], 1);
        nbr = my_getnbr(temp);
        read->buffer[read->pos] = nbr;
        read->pos += 1;
    }
    if (tab[pos][1] == LABEL_CHAR) {
        read->pos_label[read->cpt_label] = read->pos;
        read->cpt_label += 1;
    }
}

char *my_strncpy(char *str, int decal)
{
    int index = decal;
    char *str_final = malloc(sizeof(char) * my_strlen(str) - (decal));

    for (int i = 0; str[i] != '\0'; i++) {
        str_final[i] = str[index];
        index++;
    }
    str_final[index] = '\0';
    return str_final;
}

int check_direct(char **tab, int pos)
{
    char *temp;

    if (tab[pos][0] == DIRECT_CHAR) {
        if (tab[pos][1] != LABEL_CHAR &&
        (tab[pos][1] > '9' || tab[pos][1] < '0'))
            return ERROR;
    }
    if (tab[pos][0] == DIRECT_CHAR &&
    (tab[pos][1] <= '9' && tab[pos][1] >= '0')) {
        temp = my_strncpy(tab[pos], 1);
        if (my_str_is_num(temp) == 1)
            return ERROR;
    }
    return OK;
}
