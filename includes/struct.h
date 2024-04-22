/*
** EPITECH PROJECT, 2024
** robot
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_
    #include "my.h"

typedef struct read_s {
    char *line;
    FILE *file;
    ssize_t read;
    char **tab;
    char *buffer;
    int pos;
    int *pos_label;
    int cpt_label;
} read_t;

typedef struct global_s {
    read_t *read_file;
    char *name_file;
} global_t;

typedef struct my_s {
    int size_label_found;
    int pos_label_found;
    int size_label;
    int pos_label;
    int tour;
    int pos_name;
    int pos_comment;
} my_t;

#endif
