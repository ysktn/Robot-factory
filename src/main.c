/*
** EPITECH PROJECT, 2024
** robot_factory
** File description:
** main
*/

#include "../includes/my.h"

static void info(void)
{
    my_put_str("USAGE\n ./asm file_name[.s]\nDESCRIPTION\n");
    my_put_str("file_name file in assembly language to be converted into");
    my_put_str(" file_name.cor, an executable in the Virtual Machine.\n");
    return;
}

static int error_input(int ac, char **av)
{
    int rd = 0;
    struct stat s;
    int size = 0;
    char *str;

    if (ac != 2 || av == NULL)
        return ERROR;
    if (rd < 0)
        return ERROR;
    rd = open(av[1], O_RDONLY);
    stat(av[1], &s);
    size = s.st_size;
    str = malloc(sizeof(char) * size + 1);
    read(rd, str, size);
    if (str[0] == '\0')
        return ERROR;
    if (av[1][my_strlen(av[1]) - 1] != 's' ||
    av[1][my_strlen(av[1]) - 2] != '.')
        return ERROR;
    return OK;
}

static int cd_read_file(global_t *global, int *tour, header_t *header)
{
    size_t len = 100;

    if (test_error(global, header) == 84) {
        return ERROR;
    }
    (*tour) += 1;
    global->read_file->read = getline(&(LINE), &len, FILE_OPEN);
    if (global->read_file->read == -1)
        return OK;
    global->read_file->tab = str_to_word(LINE);
    if (check_line(global->read_file->tab, global->read_file) == ERROR)
        return ERROR;
    return OK;
}

static int read_file(char *name_file, global_t *global, header_t *header)
{
    size_t len = 100;
    int tour = 0;

    global->read_file->file = fopen(name_file, "r");
    global->read_file->line = NULL;
    global->read_file->read = getline(&LINE, &len, global->read_file->file);
    global->read_file->tab = str_to_word(LINE);
    global->read_file->buffer = malloc(sizeof(char) * MEM_SIZE);
    global->read_file->pos = 0;
    global->read_file->pos_label = malloc(sizeof(int) * MEM_SIZE);
    global->read_file->cpt_label = 0;
    while (global->read_file->read != -1) {
        if (cd_read_file(global, &tour, header) == ERROR)
            return ERROR;
    }
    free(global->read_file->line);
    return OK;
}

int launch(char *file_param, global_t *global, header_t *header)
{
    char *new_file = create_file(file_param);
    FILE *fichier = fopen(new_file, "wh");

    header->prog_size = reverse_int(global->read_file->pos);
    header->magic = reverse_int(COREWAR_EXEC_MAGIC);
    fwrite(header, sizeof(header_t), 1, fichier);
    fwrite(global->read_file->buffer, 1, global->read_file->pos, fichier);
    fclose(fichier);
    global->name_file = new_file;
    return OK;
}

int main(int ac, char **av)
{
    global_t global = {};
    header_t header = {};

    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0') {
        info();
        return OK;
    }
    header.magic = COREWAR_EXEC_MAGIC;
    global.read_file = malloc(sizeof(read_t));
    if (error_input(ac, av) == 84)
        return ERROR;
    if (test_lable_char_file(av[1]) == ERROR)
        return ERROR;
    if (read_file(av[1], &global, &header) == ERROR)
        return ERROR;
    if (launch(av[1], &global, &header) == ERROR)
        return ERROR;
    return OK;
}
