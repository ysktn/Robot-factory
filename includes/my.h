/*
** EPITECH PROJECT, 2024
** stumper5
** File description:
** include
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#ifndef MY_H_
    #define MY_H_
    #include "macro.h"
    #include "op.h"
    #include "struct.h"

int my_putchar(char c);
int my_put_str(char const *str);
int my_strlen(char const *str);
char *my_strcat(char *dest, char const *src);
int my_strcmp(const char *str, const char *str2);
char **str_to_word(char *str);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
int count_argv(char *str);
char *my_strcpy(char *dest, const char *src);
int reverse_int(int num);
char *create_file(char *file_param);
int test_error(global_t *global, header_t *header);
int my_str_is_num(char *str);
char *my_strncpy(char *str, int decal);
int my_getnbr(char *str);
int check_aff(char **tab, read_t *read);
int check_lfork(char **tab, read_t *read);
int check_lldi(char **tab, read_t *read);
int check_lld(char **tab, read_t *read);
int check_fork(char **tab, read_t *read);
int check_sti(char **tab, read_t *read);
int check_ldi(char **tab, read_t *read);
int check_zjmp(char **tab, read_t *read);
int check_xor(char **tab, read_t *read);
int check_or(char **tab, read_t *read);
int check_and(char **tab, read_t *read);
int check_sub(char **tab, read_t *read);
int check_add(char **tab, read_t *read);
int check_st(char **tab, read_t *read);
int check_ld(char **tab, read_t *read);
int check_live(char **tab, read_t *read);
int check_line(char **tab, read_t *read);
void write_registre(char **tab, read_t *read, int id_opcode);
void write_indirect_nbr(char **tab, read_t *read, int id_opcode);
void write_direct_nbr(char **tab, read_t *read, int id_opcode, int index);
void write_line_ld_register(char **tab, read_t *read);
void write_line_ld_direct(char **tab, read_t *read);
void write_line_ld_indirect(char **tab, read_t *read);
void write_line_cond_direct(char **tab, read_t *read, int id_opcode);
void write_line_cond_indirect(char **tab, read_t *read, int id_opcode);
void write_line_cond_registre(char **tab, read_t *read, int id_opcode);
char *convert_deci(int decimal, int base);
int compare_char_str(char *str, char not_wanted);
int test_lable_char_file(char *file_name);
int check_direct(char **tab, int pos);
int str_in_str(char *s1, char *s2);
int test_error_name(my_t *my, char *line);
int test_name_file(char **try, my_t *my);

#endif
