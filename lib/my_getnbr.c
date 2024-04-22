/*
** EPITECH PROJECT, 2023
** get
** File description:
** nbr
*/

#include "../includes/my.h"

int my_compute_power_rec(int nb, int p)
{
    if (p < 0) {
        return 0;
    } else if (p == 0) {
        return 1;
    } else {
        return nb * my_compute_power_rec(nb, p - 1);
    }
}

int my_getnbr(char *str)
{
    int nb = 0;
    int tmp = 0;

    for (int i = 1; i < my_strlen(str); i++) {
        tmp = str[i - 1];
        nb += (tmp - 48) * my_compute_power_rec(10, my_strlen(str) - i);
    }
    nb += str[my_strlen(str) - 1] - 48;
    return nb;
}
