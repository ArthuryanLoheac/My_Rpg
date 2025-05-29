/*
** EPITECH PROJECT, 2024
** stumper_duo_1
** File description:
** a header for my library
*/

#pragma once
#include <stdarg.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include "lib.h"
#include <stdarg.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdarg.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct linked_list {
    void *data;
    struct linked_list *next;
    struct linked_list *prev;
} linked_list_t;

int absolue(int x);
void close_window(sfRenderWindow *);
int my_pointlen(char **);
int my_pointlen3(void **str);
int my_put_nbr(int);
void my_putchar(char);
int my_putstr(char const *);
char *my_strcpy(char *, char const *);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strdup(char const *);
char *my_strndup(char const *src, int n);
char *my_strndup(char const *src, int n);
char *my_strcat(char *, char const *);
void my_putchar(char);
char *concat_params(int, char *const *);
int my_strlen(char const *);
char **append_to_array(char **src, char *to_append);
char **append_to_array2(char *to_append, char **src);
int my_putsterr(char const *);
char *append_str(char *src, char *src2);
char *append_str1(char *src, char ch);
char *append_str1f(char *src, char ch);
char *append_1str(char ch, char *src);
char *append_str2(char *src, char *src2);
char *insert_stri(char *src, int index, char to_insert);
char *remove_str1(char *src);
char *remove_stri(char *src, int index);
int my_strcmp(char const *, char const *);
int is_substring(const char *src, const char *target);
int my_strcmp_array(char const *, char const **);
int my_strcmpstart(char *, char *);
void my_show_linked_list(struct linked_list *);
linked_list_t *my_params_to_list(int, char *const *);
int my_list_size(linked_list_t const *);
int linked_list_len(linked_list_t **entity);
void my_rev_list(linked_list_t **);
int my_delete_nodes(linked_list_t **, void const *, int (*)());
int my_delete_nodes2(linked_list_t **begin, int index);
int my_del_list_current(linked_list_t **begin);
int my_insert_back_list(struct linked_list **, void *);
int my_insert_front_list(struct linked_list **, void *);
int my_invert_list_next(struct linked_list *list);
int my_invert_list_prev(struct linked_list *list);
int my_getnbr(char *str);
int my_nbrlen(int nb);
int my_show_word_array(char *const *);
int overflow_add(int, int);
int overflow_mult(int, int);
char *my_strstr(char *, char const *);
char *int_to_str(int);
char *my_revstr(char *);
char **my_str_to_word_array(char *str, char *delimiter, int inhibitors);
int my_show_word_array(char *const *);
void free_array(char **array);
int get_filesize(char const *filepath);
char *my_strcat_assets(char *start);
char *my_strcat_data(char *start);
char *my_strcat_desc(char *start, char *middle, char *middle2,
    char *end);
char *open_file(char *file);
char *read_fd(int fd, char *file);
char **str_to_word_array(char *src, const char *separator);
char *my_str_cpy(char *src);
