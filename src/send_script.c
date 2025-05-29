/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** the main file
*/

#include "my.h"

char *getmap2(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    int n;
    char *buf = malloc(get_filesize(filepath) + 1);

    if (fd == -1) {
        fprintf(stderr, "Error opening file %s\n", filepath);
        return NULL;
    }
    n = read(fd, buf, get_filesize(filepath));
    if (n == -1) {
        fprintf(stderr, "Error reading file %s\n", filepath);
        return NULL;
    }
    buf[get_filesize(filepath)] = '\0';
    close(fd);
    return buf;
}

char *getmap(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    int n;
    char *buf = malloc(get_filesize(filepath) + 1);

    if (fd == -1) {
        fprintf(stderr, "Error opening file %s\n", filepath);
        exit(84);
    }
    n = read(fd, buf, get_filesize(filepath));
    if (n == -1) {
        fprintf(stderr, "Error reading file %s\n", filepath);
        exit(84);
    }
    buf[get_filesize(filepath)] = '\0';
    close(fd);
    return buf;
}

static img_t *get_img_from_portrait(char *name, portrait_t *portraits)
{
    if (my_strcmp(name, "protagonist") == 0)
        return portraits->protagonist;
    if (my_strcmp(name, "alter") == 0)
        return portraits->alter;
    if (my_strcmp(name, "cryspi") == 0)
        return portraits->cryspi;
    if (my_strcmp(name, "dyn") == 0)
        return portraits->dyn;
    if (my_strcmp(name, "puddle") == 0)
        return portraits->puddle;
    if (my_strcmp(name, "queen") == 0)
        return portraits->queen;
    if (my_strcmp(name, "???") == 0)
        return portraits->man;
    return portraits->alter;
}

void send_script(char *path, portrait_t *portraits, diag_pipe_t *diag_pipe,
    int *answer_loc)
{
    char *newpath = path;
    char *file = getmap2(newpath);
    char **lines = my_str_to_word_array(file, "\n", 4);
    char **temp = NULL;

    if (!file)
        return;
    for (int i = 0; i < my_pointlen(lines); i++) {
        temp = remove_inhibitor(my_str_to_word_array(lines[i], "|", 4));
        my_insert_back_list(&(diag_pipe->ll), (void *)init_queue_diag(
            my_strdup(temp[1]), dup_image(get_img_from_portrait(temp[0],
            portraits)), answer_loc, my_strdup(temp[0])));
        free_array(temp);
    }
    free_array(lines);
    free(file);
    free(newpath);
}
