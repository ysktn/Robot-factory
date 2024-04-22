/*
** EPITECH PROJECT, 2023
** Test
** File description:
** test stumper5
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../includes/my.h"

Test(test_add, test_add_valid)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"add", "r1", "r2", "r3", NULL};
    int i = check_add(test, read);
    cr_assert_eq(i, 0);
}

Test(test_add, test_add_nb_arg_invalid)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"add", "r1", "r2", NULL};
    int i = check_add(test, read);
    cr_assert_eq(i, 84);
}

Test(test_add, test_add_invalid_arg1)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"add", "%3", "r2", "r3", NULL};
    int i = check_add(test, read);
    cr_assert_eq(i, 84);
}

Test(test_add, test_add_invalid_arg2)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"add", "r1", "%3", "r3", NULL};
    int i = check_add(test, read);
    cr_assert_eq(i, 84);
}

Test(test_add, test_add_invalid_arg3)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"add", "r1", "r2", "%3", NULL};
    int i = check_add(test, read);
    cr_assert_eq(i, 84);
}

Test(test_add, test_add_invalid_registre_arg1)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"add", "r17", "r2", "r3", NULL};
    int i = check_add(test, read);
    cr_assert_eq(i, 84);
}

Test(test_add, test_add_invalid_registre_arg2)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"add", "r1", "r25", "r3", NULL};
    int i = check_add(test, read);
    cr_assert_eq(i, 84);
}

Test(test_add, test_add_invalid_registre_arg3)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"add", "r1", "r2", "r31", NULL};
    int i = check_add(test, read);
    cr_assert_eq(i, 84);
}


Test(test_sub, test_sub_valid)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"sub", "r1", "r2", "r3", NULL};
    int i = check_sub(test, read);
    cr_assert_eq(i, 0);
}

Test(test_sub, test_sub_nb_arg_invalid)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"sub", "r1", "r2", NULL};
    int i = check_sub(test, read);
    cr_assert_eq(i, 84);
}

Test(test_sub, test_sub_invalid_arg1)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"sub", "%3", "r2", "r3", NULL};
    int i = check_sub(test, read);
    cr_assert_eq(i, 84);
}

Test(test_sub, test_sub_invalid_arg2)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"sub", "r1", "%3", "r3", NULL};
    int i = check_sub(test, read);
    cr_assert_eq(i, 84);
}

Test(test_sub, test_sub_invalid_arg3)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"sub", "r1", "r2", "%3", NULL};
    int i = check_sub(test, read);
    cr_assert_eq(i, 84);
}

Test(test_sub, test_sub_invalid_registre_arg1)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"sub", "r17", "r2", "r3", NULL};
    int i = check_sub(test, read);
    cr_assert_eq(i, 84);
}

Test(test_sub, test_sub_invalid_registre_arg2)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"sub", "r1", "r25", "r3", NULL};
    int i = check_sub(test, read);
    cr_assert_eq(i, 84);
}

Test(test_sub, test_sub_invalid_registre_arg3)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"sub", "r1", "r2", "r31", NULL};
    int i = check_sub(test, read);
    cr_assert_eq(i, 84);
}

Test(test_aff, test_aff_valid)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"aff", "r1", NULL};
    int i = check_aff(test, read);
    cr_assert_eq(i, 0);
}

Test(test_aff, test_aff_nb_arg_invalid)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"aff", "r1", "r2", NULL};
    int i = check_aff(test, read);
    cr_assert_eq(i, 84);
}

Test(test_aff, test_aff_invalid_arg)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"aff", "%3", NULL};
    int i = check_aff(test, read);
    cr_assert_eq(i, 84);
}

Test(test_aff, test_aff_invalid_registre)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"aff", "r17", NULL};
    int i = check_aff(test, read);
    cr_assert_eq(i, 84);
}

Test(test_and, test_and_valid)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"and", "%4", "23", "r3", NULL};
    int i = check_and(test, read);
    cr_assert_eq(i, 0);
}

Test(test_and, test_and_nb_arg_invalid)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"and", "%4", "23", NULL};
    int i = check_and(test, read);
    cr_assert_eq(i, 84);
}

Test(test_and, test_and_invalid_arg1)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"and", "kl", "23", "r3", NULL};
    int i = check_and(test, read);
    cr_assert_eq(i, 84);
}

Test(test_and, test_and_invalid_arg2)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"and", "%4", "kl", "r3", NULL};
    int i = check_and(test, read);
    cr_assert_eq(i, 84);
}

Test(test_and, test_and_invalid_arg3)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"and", "%4", "23", "%4", NULL};
    int i = check_and(test, read);
    cr_assert_eq(i, 84);
}

Test(test_and, test_and_invalid_registre_arg1)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"and", "r17", "23", "r3", NULL};
    int i = check_and(test, read);
    cr_assert_eq(i, 84);
}

Test(test_and, test_and_invalid_registre_arg2)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"and", "r1", "r25", "r3", NULL};
    int i = check_and(test, read);
    cr_assert_eq(i, 84);
}

Test(test_and, test_and_invalid_registre_arg3)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"and", "r1", "23", "r31", NULL};
    int i = check_and(test, read);
    cr_assert_eq(i, 84);
}

Test(test_and, test_and_invalid_direct_arg1)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"and", "%4c", "23", "r3", NULL};
    int i = check_and(test, read);
    cr_assert_eq(i, 84);
}

Test(test_and, test_and_invalid_direct_arg2)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"and", "%4", "%23c", "r3", NULL};
    int i = check_and(test, read);
    cr_assert_eq(i, 84);
}

Test(test_and, test_and_invalid_indirect_arg1)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"and", "4c", "23", "%4c", NULL};
    int i = check_and(test, read);
    cr_assert_eq(i, 84);
}

Test(test_and, test_and_invalid_indirect_arg2)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"and", "4", "23c", "%4", NULL};
    int i = check_and(test, read);
    cr_assert_eq(i, 84);
}

Test(test_and, test_valid_registre1)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"and", "r1", "r2", "r3", NULL};
    int i = check_and(test, read);
    cr_assert_eq(i, 0);
}

Test(test_and, test_valid_registre2)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"and", "r1", "%4", "r3", NULL};
    int i = check_and(test, read);
    cr_assert_eq(i, 0);
}

Test(test_and, test_valid_registre3)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"and", "r1", "23", "r3", NULL};
    int i = check_and(test, read);
    cr_assert_eq(i, 0);
}

Test(test_and, test_valid_directe1)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"and", "%4", "r2", "r3", NULL};
    int i = check_and(test, read);
    cr_assert_eq(i, 0);
}

Test(test_and, test_valid_directe2)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"and", "%4", "%4", "r3", NULL};
    int i = check_and(test, read);
    cr_assert_eq(i, 0);
}

Test(test_and, test_valid_directe3)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"and", "%4", "23", "r3", NULL};
    int i = check_and(test, read);
    cr_assert_eq(i, 0);
}

Test(test_and, test_valid_indirecte1)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"and", "4", "r2", "r3", NULL};
    int i = check_and(test, read);
    cr_assert_eq(i, 0);
}

Test(test_and, test_valid_indirecte2)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"and", "4", "%4", "r3", NULL};
    int i = check_and(test, read);
    cr_assert_eq(i, 0);
}

Test(test_and, test_valid_indirecte3)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"and", "4", "23", "r3", NULL};
    int i = check_and(test, read);
    cr_assert_eq(i, 0);
}

Test(test_fork, test_valid_fork)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"fork", "%4", NULL};
    int i = check_fork(test, read);
    cr_assert_eq(i, 0);
}

Test(test_fork, test_invalid_nb_arg_fork)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"fork", "%4", "r3", NULL};
    int i = check_fork(test, read);
    cr_assert_eq(i, 84);
}

Test(test_fork, test_invalid_arg_fork)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"fork", "r3", NULL};
    int i = check_fork(test, read);
    cr_assert_eq(i, 84);
}

Test(test_fork, test_invalid_direct_fork)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"fork", "%43c", NULL};
    int i = check_fork(test, read);
    cr_assert_eq(i, 84);
}

Test(test_ld, test_valid_ld)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"ld", "%4", "r3", NULL};
    int i = check_ld(test, read);
    cr_assert_eq(i, 0);
}

Test(test_ld, test_invalid_nb_arg_ld)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"ld", "%4", "r3", "r3", NULL};
    int i = check_ld(test, read);
    cr_assert_eq(i, 84);
}

Test(test_ld, test_invalid_arg1_ld)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"ld", "r3", "r3", NULL};
    int i = check_ld(test, read);
    cr_assert_eq(i, 84);
}

Test(test_ld, test_invalid_arg2_ld)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"ld", "%43", "45", NULL};
    int i = check_ld(test, read);
    cr_assert_eq(i, 84);
}

Test(test_ld, test_invalid_direct_ld)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"ld", "%43c", "r3", NULL};
    int i = check_ld(test, read);
    cr_assert_eq(i, 84);
}

Test(test_ld, test_invalid_registre_ld)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"ld", "%43", "r43", NULL};
    int i = check_ld(test, read);
    cr_assert_eq(i, 84);
}

Test(test_ld, test_invalid_indirect_ld)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"ld", "43c", "r3", NULL};
    int i = check_ld(test, read);
    cr_assert_eq(i, 84);
}

Test(test_ld, test_valid_indirect_ld)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"ld", "42", "r3", NULL};
    int i = check_ld(test, read);
    cr_assert_eq(i, 0);
}

Test(test_lfork, test_valid_lfork)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"lfork", "%4", NULL};
    int i = check_lfork(test, read);
    cr_assert_eq(i, 0);
}

Test(test_lfork, test_invalid_nb_arg_lfork)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"lfork", "%4", "r3", NULL};
    int i = check_lfork(test, read);
    cr_assert_eq(i, 84);
}

Test(test_lfork, test_invalid_arg_lfork)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"lfork", "r3", NULL};
    int i = check_lfork(test, read);
    cr_assert_eq(i, 84);
}

Test(test_lfork, test_invalid_direct_lfork)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"lfork", "%43c", NULL};
    int i = check_lfork(test, read);
    cr_assert_eq(i, 84);
}

Test(test_live, test_valid_live)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"live", "%43", NULL};
    int i = check_live(test, read);
    cr_assert_eq(i, 0);
}

Test(test_live, test_invalid_nb_arg_live)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"live", "%4", "r3", NULL};
    int i = check_live(test, read);
    cr_assert_eq(i, 84);
}

Test(test_live, test_invalid_arg_live)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"live", "r3", NULL};
    int i = check_live(test, read);
    cr_assert_eq(i, 84);
}

Test(test_live, test_invalid_direct_live)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"live", "%43c", NULL};
    int i = check_live(test, read);
    cr_assert_eq(i, 84);
}

Test(test_ldi, test_valid_ldi)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"ldi", "4", "%33", "r3", NULL};
    int i = check_ldi(test, read);
    cr_assert_eq(i, 0);
}

Test(test_ldi, test_invalid_nb_arg_ldi)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"ldi", "4", "%33", "r3", "r3", NULL};
    int i = check_ldi(test, read);
    cr_assert_eq(i, 84);
}

Test(test_ldi, test_invalid_arg1_ldi)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"ldi", "hk", "%33", "r3", NULL};
    int i = check_ldi(test, read);
    cr_assert_eq(i, 84);
}

Test(test_ldi, test_invalid_arg2_ldi)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"ldi", "4", "5", "r3", NULL};
    int i = check_ldi(test, read);
    cr_assert_eq(i, 84);
}

Test(test_ldi, test_invalid_arg3_ldi)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"ldi", "4", "%33", "%10", NULL};
    int i = check_ldi(test, read);
    cr_assert_eq(i, 84);
}

Test(test_ldi, test_invalid_indirect_arg1_ldi)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"ldi", "4c", "%33", "r3", NULL};
    int i = check_ldi(test, read);
    cr_assert_eq(i, 84);
}

Test(test_ldi, test_invalid_direct_arg1_ldi)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"ldi", "%45c", "%3", "r3", NULL};
    int i = check_ldi(test, read);
    cr_assert_eq(i, 84);
}

Test(test_ldi, test_invalid_registre_arg1_ldi)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"ldi", "r17", "%3", "r3", NULL};
    int i = check_ldi(test, read);
    cr_assert_eq(i, 84);
}

Test(test_ldi, test_invalid_registre_arg2_ldi)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"ldi", "4", "r25", "r3", NULL};
    int i = check_ldi(test, read);
    cr_assert_eq(i, 84);
}

Test(test_ldi, test_invalid_registre_arg3_ldi)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"ldi", "4", "%3", "r31", NULL};
    int i = check_ldi(test, read);
    cr_assert_eq(i, 84);
}

Test(test_ldi, test_invalid_directe_arg2_ldi)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"ldi", "4", "%3c", "r3", NULL};
    int i = check_ldi(test, read);
    cr_assert_eq(i, 84);
}

Test(test_ldi, test_valid_registre1_ldi)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"ldi", "r1", "%3", "r3", NULL};
    int i = check_ldi(test, read);
    cr_assert_eq(i, 0);
}

Test(test_ldi, test_valid_registre2_ldi)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"ldi", "r1", "r2", "r3", NULL};
    int i = check_ldi(test, read);
    cr_assert_eq(i, 0);
}

Test(test_ldi, test_valid_directe1_ldi)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"ldi", "%4", "r2", "r3", NULL};
    int i = check_ldi(test, read);
    cr_assert_eq(i, 0);
}

Test(test_ldi, test_valid_directe2_ldi)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"ldi", "%4", "%4", "r3", NULL};
    int i = check_ldi(test, read);
    cr_assert_eq(i, 0);
}

Test(test_ldi, test_valid_indirecte1_ldi)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"ldi", "4", "r2", "r3", NULL};
    int i = check_ldi(test, read);
    cr_assert_eq(i, 0);
}

Test(test_ldi, test_valid_indirecte2_ldi)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"ldi", "4", "%4", "r3", NULL};
    int i = check_ldi(test, read);
    cr_assert_eq(i, 0);
}

Test(test_st, test_valid_st)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"st", "r1", "r2", NULL};
    int i = check_st(test, read);
    cr_assert_eq(i, 0);
}

Test(test_st, test_invalid_nb_arg_st)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"st", "r1", "r2", "r3", NULL};
    int i = check_st(test, read);
    cr_assert_eq(i, 84);
}

Test(test_st, test_invalid_arg1_st)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"st", "%3", "r2", NULL};
    int i = check_st(test, read);
    cr_assert_eq(i, 84);
}

Test(test_st, test_invalid_arg2_st)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"st", "r1", "%3", NULL};
    int i = check_st(test, read);
    cr_assert_eq(i, 84);
}

Test(test_st, test_invalid_registre_arg1_st)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"st", "r17", "r2", NULL};
    int i = check_st(test, read);
    cr_assert_eq(i, 84);
}

Test(test_st, test_invalid_registre_arg2_st)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"st", "r1", "r25", NULL};
    int i = check_st(test, read);
    cr_assert_eq(i, 84);
}

Test(test_st, test_invalid_indirecte_arg2_st)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"st", "r1", "45c", NULL};
    int i = check_st(test, read);
    cr_assert_eq(i, 84);
}

Test(test_lld, test_valid_lld)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"lld", "4", "r3", NULL};
    int i = check_lld(test, read);
    cr_assert_eq(i, 0);
}

Test(test_lld, test_invalid_nb_arg_lld)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"lld", "4", "r3", "r3", NULL};
    int i = check_lld(test, read);
    cr_assert_eq(i, 84);
}

Test(test_lld, test_invalid_arg1_lld)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"lld", "r4", "r3", NULL};
    int i = check_lld(test, read);
    cr_assert_eq(i, 84);
}

Test(test_lld, test_invalid_arg2_lld)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"lld", "4", "5", NULL};
    int i = check_lld(test, read);
    cr_assert_eq(i, 84);
}

Test(test_lld, test_invalid_direct_lld)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"lld", "%43c", "r3", NULL};
    int i = check_lld(test, read);
    cr_assert_eq(i, 84);
}

Test(test_lld, test_invalid_registre_lld)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"lld", "4", "r37", NULL};
    int i = check_lld(test, read);
    cr_assert_eq(i, 84);
}

Test(test_lld, test_invalid_indirect_lld)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"lld", "4c", "r3", NULL};
    int i = check_lld(test, read);
    cr_assert_eq(i, 84);
}

Test(test_lld, test_valid_directe_lld)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"lld", "%4", "r3", NULL};
    int i = check_lld(test, read);
    cr_assert_eq(i, 0);
}

Test(test_st, test_valid_indirecte_st)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"st", "r1", "45", NULL};
    int i = check_st(test, read);
    cr_assert_eq(i, 0);
}

Test(test_lldi, test_valid_lldi)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"lldi", "4", "%4", "r3", NULL};
    int i = check_lldi(test, read);
    cr_assert_eq(i, 0);
}

Test(test_lldi, test_invalid_nb_arg_lldi)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"lldi", "4", "%4", "r3", "r3", NULL};
    int i = check_lldi(test, read);
    cr_assert_eq(i, 84);
}

Test(test_lldi, test_invalid_arg1_lldi)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"lldi", "hk", "%33", "r3", NULL};
    int i = check_lldi(test, read);
    cr_assert_eq(i, 84);
}

Test(test_lldi, test_invalid_arg2_lldi)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"lldi", "4", "5", "r3", NULL};
    int i = check_lldi(test, read);
    cr_assert_eq(i, 84);
}

Test(test_lldi, test_invalid_arg3_lldi)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"lldi", "4", "%33", "%10", NULL};
    int i = check_lldi(test, read);
    cr_assert_eq(i, 84);
}

Test(test_lldi, test_invalid_indirect_arg1_lldi)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"lldi", "4c", "%33", "r3", NULL};
    int i = check_lldi(test, read);
    cr_assert_eq(i, 84);
}

Test(test_lldi, test_invalid_direct_arg1_lldi)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"lldi", "%45c", "%3", "r3", NULL};
    int i = check_lldi(test, read);
    cr_assert_eq(i, 84);
}

Test(test_lldi, test_invalid_registre_arg1_lldi)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"lldi", "r17", "%3", "r3", NULL};
    int i = check_lldi(test, read);
    cr_assert_eq(i, 84);
}

Test(test_lldi, test_invalid_registre_arg2_lldi)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"lldi", "4", "r25", "r3", NULL};
    int i = check_lldi(test, read);
    cr_assert_eq(i, 84);
}

Test(test_lldi, test_invalid_registre_arg3_lldi)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"lldi", "4", "%3", "r31", NULL};
    int i = check_lldi(test, read);
    cr_assert_eq(i, 84);
}

Test(test_lldi, test_invalid_directe_arg2_lldi)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"lldi", "4", "%3c", "r3", NULL};
    int i = check_lldi(test, read);
    cr_assert_eq(i, 84);
}

Test(test_lldi, test_valid_registre1_lldi)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"lldi", "r1", "%3", "r3", NULL};
    int i = check_lldi(test, read);
    cr_assert_eq(i, 0);
}

Test(test_lldi, test_valid_registre2_lldi)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"lldi", "r1", "r2", "r3", NULL};
    int i = check_lldi(test, read);
    cr_assert_eq(i, 0);
}

Test(test_lldi, test_valid_directe1_lldi)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"lldi", "%4", "r2", "r3", NULL};
    int i = check_lldi(test, read);
    cr_assert_eq(i, 0);
}

Test(test_lldi, test_valid_directe2_lldi)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"lldi", "%4", "%4", "r3", NULL};
    int i = check_lldi(test, read);
    cr_assert_eq(i, 0);
}

Test(test_lldi, test_valid_indirecte1_lldi)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"lldi", "4", "r2", "r3", NULL};
    int i = check_lldi(test, read);
    cr_assert_eq(i, 0);
}

Test(test_lldi, test_valid_indirecte2_lldi)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"lldi", "4", "%4", "r3", NULL};
    int i = check_lldi(test, read);
    cr_assert_eq(i, 0);
}

Test(test_or, test_valid_or)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"or", "r1", "r2", "r3", NULL};
    int i = check_or(test, read);
    cr_assert_eq(i, 0);
}

Test(test_or, test_invalid_nb_arg_or)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"or", "r1", "r2", "r3", "r3", NULL};
    int i = check_or(test, read);
    cr_assert_eq(i, 84);
}

Test(test_or, test_invalid_arg1_or)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"or", "hk", "r2", "r3", NULL};
    int i = check_or(test, read);
    cr_assert_eq(i, 84);
}

Test(test_or, test_invalid_arg2_or)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"or", "r1", "hk", "r3", NULL};
    int i = check_or(test, read);
    cr_assert_eq(i, 84);
}

Test(test_or, test_invalid_arg3_or)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"or", "r1", "r2", "14", NULL};
    int i = check_or(test, read);
    cr_assert_eq(i, 84);
}

Test(test_or, test_invalid_registre_arg1_or)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"or", "r17", "r2", "r3", NULL};
    int i = check_or(test, read);
    cr_assert_eq(i, 84);
}

Test(test_or, test_invalid_registre_arg2_or)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"or", "r1", "r25", "r3", NULL};
    int i = check_or(test, read);
    cr_assert_eq(i, 84);
}

Test(test_or, test_invalid_registre_arg3_or)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"or", "r1", "r2", "r31", NULL};
    int i = check_or(test, read);
    cr_assert_eq(i, 84);
}

Test(test_or, test_invalid_directe1_or)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"or", "%42c", "r2", "r3", NULL};
    int i = check_or(test, read);
    cr_assert_eq(i, 84);
}

Test(test_or, test_invalid_directe2_or)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"or", "%42", "%42c", "r3", NULL};
    int i = check_or(test, read);
    cr_assert_eq(i, 84);
}

Test(test_or, test_invalid_indirecte1_or)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"or", "42c", "r2", "r3", NULL};
    int i = check_or(test, read);
    cr_assert_eq(i, 84);
}

Test(test_or, test_invalid_indirecte2_or)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"or", "42", "42c", "r3", NULL};
    int i = check_or(test, read);
    cr_assert_eq(i, 84);
}

Test(test_or, test_valide_registr1_or)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"or", "r1", "r2", "r3", NULL};
    int i = check_or(test, read);
    cr_assert_eq(i, 0);
}

Test(test_or, test_valide_registr2_or)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"or", "r1", "%2", "r3", NULL};
    int i = check_or(test, read);
    cr_assert_eq(i, 0);
}

Test(test_or, test_valide_registr3_or)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"or", "r1", "42", "r3", NULL};
    int i = check_or(test, read);
    cr_assert_eq(i, 0);
}

Test(test_or, test_valide_directe1_or)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"or", "%4", "r2", "r3", NULL};
    int i = check_or(test, read);
    cr_assert_eq(i, 0);
}

Test(test_or, test_valide_directe2_or)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"or", "%4", "%4", "r3", NULL};
    int i = check_or(test, read);
    cr_assert_eq(i, 0);
}

Test(test_or, test_valide_indirecte1_or)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"or", "4", "r2", "r3", NULL};
    int i = check_or(test, read);
    cr_assert_eq(i, 0);
}

Test(test_or, test_valide_indirecte2_or)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"or", "4", "%4", "r3", NULL};
    int i = check_or(test, read);
    cr_assert_eq(i, 0);
}

Test(test_or, test_valide_directe3_or)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"or", "%4", "42", "r3", NULL};
    int i = check_or(test, read);
    cr_assert_eq(i, 0);
}

Test(test_or, test_valide_indirecte3_or)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"or", "4", "42", "r3", NULL};
    int i = check_or(test, read);
    cr_assert_eq(i, 0);
}

Test(test_xor, test_valid_xor)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"xor", "4", "%42", "r3", NULL};
    int i = check_xor(test, read);
    cr_assert_eq(i, 0);
}

Test(test_xor, test_invalid_nb_arg_xor)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"xor", "4", "%42", "r3", "r3", NULL};
    int i = check_xor(test, read);
    cr_assert_eq(i, 84);
}

Test(test_xor, test_invalid_arg1_xor)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"xor", "hk", "%42", "r3", NULL};
    int i = check_xor(test, read);
    cr_assert_eq(i, 84);
}

Test(test_xor, test_invalid_arg2_xor)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"xor", "4", "hk", "r3", NULL};
    int i = check_xor(test, read);
    cr_assert_eq(i, 84);
}

Test(test_xor, test_invalid_arg3_xor)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"xor", "4", "%42", "14", NULL};
    int i = check_xor(test, read);
    cr_assert_eq(i, 84);
}

Test(test_xor, test_invalid_registre_arg1_xor)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"xor", "r17", "%42", "r3", NULL};
    int i = check_xor(test, read);
    cr_assert_eq(i, 84);
}

Test(test_xor, test_invalid_registre_arg2_xor)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"xor", "r1", "r25", "r3", NULL};
    int i = check_xor(test, read);
    cr_assert_eq(i, 84);
}

Test(test_xor, test_invalid_registre_arg3_xor)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"xor", "r1", "%42", "r31", NULL};
    int i = check_xor(test, read);
    cr_assert_eq(i, 84);
}

Test(test_xor, test_invalid_directe1_xor)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"xor", "%42c", "%42", "r3", NULL};
    int i = check_xor(test, read);
    cr_assert_eq(i, 84);
}

Test(test_xor, test_invalid_directe2_xor)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"xor", "%42", "%42c", "r3", NULL};
    int i = check_xor(test, read);
    cr_assert_eq(i, 84);
}

Test(test_xor, test_invalid_indirecte1_xor)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"xor", "42c", "%42", "r3", NULL};
    int i = check_xor(test, read);
    cr_assert_eq(i, 84);
}

Test(test_xor, test_invalid_indirecte2_xor)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"xor", "42", "42c", "r3", NULL};
    int i = check_xor(test, read);
    cr_assert_eq(i, 84);
}

Test(test_xor, test_valide_registr1_xor)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"xor", "r1", "r2", "r3", NULL};
    int i = check_xor(test, read);
    cr_assert_eq(i, 0);
}

Test(test_xor, test_valide_registr2_xor)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"xor", "r1", "%2", "r3", NULL};
    int i = check_xor(test, read);
    cr_assert_eq(i, 0);
}

Test(test_xor, test_valide_registr3_xor)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"xor", "r1", "42", "r3", NULL};
    int i = check_xor(test, read);
    cr_assert_eq(i, 0);
}

Test(test_xor, test_valide_directe1_xor)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"xor", "%4", "r2", "r3", NULL};
    int i = check_xor(test, read);
    cr_assert_eq(i, 0);
}

Test(test_xor, test_valide_directe2_xor)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"xor", "%4", "%4", "r3", NULL};
    int i = check_xor(test, read);
    cr_assert_eq(i, 0);
}

Test(test_xor, test_valide_directe3_xor)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"xor", "%4", "42", "r3", NULL};
    int i = check_xor(test, read);
    cr_assert_eq(i, 0);
}

Test(test_xor, test_valide_indirecte1_xor)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"xor", "4", "r2", "r3", NULL};
    int i = check_xor(test, read);
    cr_assert_eq(i, 0);
}

Test(test_xor, test_valide_indirecte2_xor)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"xor", "4", "%4", "r3", NULL};
    int i = check_xor(test, read);
    cr_assert_eq(i, 0);
}

Test(test_xor, test_valide_indirecte3_xor)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"xor", "4", "42", "r3", NULL};
    int i = check_xor(test, read);
    cr_assert_eq(i, 0);
}

Test(test_zjmp, test_valid_zjmp)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"zjmp", "%4", NULL};
    int i = check_zjmp(test, read);
    cr_assert_eq(i, 0);
}

Test(test_zjmp, test_invalid_nb_arg_zjmp)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"zjmp", "%4", "r3", NULL};
    int i = check_zjmp(test, read);
    cr_assert_eq(i, 84);
}

Test(test_zjmp, test_invalid_arg1_zjmp)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"zjmp", "r3", NULL};
    int i = check_zjmp(test, read);
    cr_assert_eq(i, 84);
}

Test(test_zjmp, test_invalid_directe_zjmp)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"zjmp", "%4c", NULL};
    int i = check_zjmp(test, read);
    cr_assert_eq(i, 84);
}

Test(test_sti, test_valid_sti)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"sti", "r1", "04", "%3", NULL};
    int i = check_sti(test, read);
    cr_assert_eq(i, 0);
}

Test(test_sti, test_invalid_nb_arg_sti)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"sti", "r1", "04", "%3", "r3", NULL};
    int i = check_sti(test, read);
    cr_assert_eq(i, 84);
}

Test(test_sti, test_invalid_arg1_sti)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"sti", "%4", "04", "%3", NULL};
    int i = check_sti(test, read);
    cr_assert_eq(i, 84);
}

Test(test_sti, test_invalid_arg2_sti)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"sti", "r1", "hk", "r3", NULL};
    int i = check_sti(test, read);
    cr_assert_eq(i, 84);
}

Test(test_sti, test_invalid_arg3_sti)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"sti", "r1", "04", "04", NULL};
    int i = check_sti(test, read);
    cr_assert_eq(i, 84);
}

Test(test_sti, test_invalid_registre_arg1_sti)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"sti", "r17", "04", "%3", NULL};
    int i = check_sti(test, read);
    cr_assert_eq(i, 84);
}

Test(test_sti, test_invalid_registre_arg2_sti)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"sti", "r1", "r25", "%3", NULL};
    int i = check_sti(test, read);
    cr_assert_eq(i, 84);
}

Test(test_sti, test_invalid_registre_arg3_sti)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"sti", "r1", "04", "r31", NULL};
    int i = check_sti(test, read);
    cr_assert_eq(i, 84);
}

Test(test_sti, test_invalid_directe_arg2_sti)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"sti", "r1", "%4c", "%3", NULL};
    int i = check_sti(test, read);
    cr_assert_eq(i, 84);
}

Test(test_sti, test_invalid_directe_arg3_sti)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"sti", "r1", "04", "%3c", NULL};
    int i = check_sti(test, read);
    cr_assert_eq(i, 84);
}

Test(test_sti, test_invalid_indirecte_arg2_sti)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"sti", "r1", "04c", "r3", NULL};
    int i = check_sti(test, read);
    cr_assert_eq(i, 84);
}

Test(test_sti, test_valid_registre1_sti)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"sti", "r1", "r2", "%3", NULL};
    int i = check_sti(test, read);
    cr_assert_eq(i, 0);
}

Test(test_sti, test_valid_registre2_sti)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"sti", "r1", "r2", "r3", NULL};
    int i = check_sti(test, read);
    cr_assert_eq(i, 0);
}

Test(test_sti, test_valid_directe1_sti)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"sti", "r1", "%4", "r3", NULL};
    int i = check_sti(test, read);
    cr_assert_eq(i, 0);
}

Test(test_sti, test_valid_directe2_sti)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"sti", "r1", "%4", "%3", NULL};
    int i = check_sti(test, read);
    cr_assert_eq(i, 0);
}

Test(test_sti, test_valid_indirecte1_sti)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"sti", "r1", "4", "r3", NULL};
    int i = check_sti(test, read);
    cr_assert_eq(i, 0);
}

Test(test_sti, test_valid_indirecte2_sti)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"sti", "r1", "4", "%3", NULL};
    int i = check_sti(test, read);
    cr_assert_eq(i, 0);
}

Test(test_parsing, test_valid_parsing)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"live", "%4", NULL};
    int i = check_line(test, read);
    cr_assert_eq(i, 0);
}

Test(test_parsing, test_invalid_parsing)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {"live", "4", NULL};
    int i = check_line(test, read);
    cr_assert_eq(i, 84);
}

Test(test_parsing, test_valide_parsing2)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char **test = NULL;
    int i = check_line(test, read);
    cr_assert_eq(i, 0);
}

Test(test_parsing, test_valide_parsing3)
{
    read_t *read = malloc(sizeof(read_t));
    read->buffer = malloc(sizeof(char) * 100);
    read->pos = 0;
    char *test[] = {".name", "4", NULL};
    int i = check_line(test, read);
    cr_assert_eq(i, 0);
}

Test(test_utils, test_write_direct_nbr)
{
    read_t *read = malloc(sizeof(read_t));
    read->pos_label = malloc(sizeof(int) * 100);
    read->cpt_label = 0;
    read->pos = 0;
    char *test[] = {"fork", "%:live", NULL};
    write_direct_nbr(test, read, 1, 0);
}


Test(test_utils, test_check_direct)
{
    char *test[] = {"%-42", NULL};
    int i = check_direct(test, 0);
    cr_assert_eq(i, 84);
}



Test(test_putchar, test_putchar, .init = cr_redirect_stdout)
{
    my_putchar('c');
    cr_assert_stdout_eq_str("c");
}

Test(test_put_str, test_char_null)
{
    char *str = NULL;
    cr_assert_eq(my_put_str(str), 84);
}

Test(test_strcmp, test_char)
{
    char *str = "test";
    char *str2 = "test";
    cr_assert_eq(my_strcmp(str, str2), 0);
}

Test(test_strcmp, test_char2)
{
    char *str = "test";
    char *str2 = "test2";
    cr_assert_eq(my_strcmp(str, str2), -1);
}

Test(test_strcat, test_char)
{
    char *str = "test";
    char *str2 = "test2";
    cr_assert_str_eq(my_strcat(str, str2), "testtest2");
}

Test(test_strlen, test_char)
{
    char *str = "test";
    cr_assert_eq(my_strlen(str), 4);
}

Test(test_strlen, test_char2)
{
    char *str = NULL;
    cr_assert_eq(my_strlen(str), -1);
}

Test(test_create_file, test_char)
{
    char *str = "test.s";
    cr_assert_str_eq(create_file(str), "test.cor");
}

Test(test_create_file, test_char2)
{
    char *str = NULL;
    cr_assert_eq(create_file(str), NULL);
}

Test(test_convert_deci, test_char)
{
    cr_assert_str_eq(convert_deci(10, 16), "0A");
}

Test(test_compare_char_str, test_char)
{
    char *str = "test";
    cr_assert_eq(compare_char_str(str, 't'), 84);
}

Test(test_compare_char_str, test_char2)
{
    char *str = "test";
    cr_assert_eq(compare_char_str(str, 'a'), 0);
}

Test(test_my_getnbr, test_char)
{
    char *str = "10";
    cr_assert_eq(my_getnbr(str), 10);
}

