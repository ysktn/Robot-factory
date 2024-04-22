/*
** EPITECH PROJECT, 2024
** robot
** File description:
** reverse_int
*/

int reverse_int(int num)
{
    int reversed = 0;

    for (long unsigned int i = 0; i < sizeof(int); i++) {
        reversed |= ((num >> (8 * (sizeof(int) - 1 - i))) & 0xFF) << (8 * i);
    }
    return reversed;
}
