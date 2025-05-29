/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** my_rpg
*/

#include "my.h"
#include "gui_struct.h"
#include <stdlib.h>

static char *return_previous_file(int i, char *number,
    char *start_name, char *end_name)
{
    char *file_try = malloc(sizeof(char) * 27);

    if (i == 2)
        return NULL;
    file_try[0] = '\0';
    if (number != NULL)
        free(number);
    number = int_to_str(i - 2);
    file_try = strcat(file_try, start_name);
    file_try = strcat(file_try, number);
    file_try = strcat(file_try, end_name);
    free(start_name);
    free(end_name);
    free(number);
    return (file_try);
}

char *last_filepath_choose(void)
{
    char *start_name = strdup("./save/Save_file");
    char *number = NULL;
    char *end_name = strdup(".rtb");
    char *file_try = malloc(sizeof(char) * 27);
    bool not_found_file = false;
    int i = 0;

    for (i = 1; not_found_file == false; i++) {
        file_try = malloc(sizeof(char) * 27);
        file_try[0] = '\0';
        if (number != NULL)
            free(number);
        number = int_to_str(i);
        file_try = strcat(file_try, start_name);
        file_try = strcat(file_try, number);
        file_try = strcat(file_try, end_name);
        if (open_file(file_try) == NULL)
            not_found_file = true;
    }
    return (return_previous_file(i, number, start_name, end_name));
}

static void free_chars(char *start_name, char *end_name, char *number)
{
    free(start_name);
    free(end_name);
    free(number);
}

char *next_filepath_choose(void)
{
    char *start_name = strdup("./save/Save_file");
    char *number = NULL;
    char *end_name = strdup(".rtb");
    char *file_try = malloc(sizeof(char) * 25);
    bool not_found_file = false;

    for (int i = 1; not_found_file == false; i++) {
        file_try = malloc(sizeof(char) * 25);
        file_try[0] = '\0';
        if (number != NULL)
            free(number);
        number = int_to_str(i);
        file_try = strcat(file_try, start_name);
        file_try = strcat(file_try, number);
        file_try = strcat(file_try, end_name);
        if (open_file(file_try) == NULL)
            not_found_file = true;
    }
    free_chars(start_name, end_name, number);
    return (file_try);
}
