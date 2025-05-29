/*
** EPITECH PROJECT, 2024
** init_assets()
** File description:
** init_assets()
*/
#include "my.h"

void wrong_savefile(char *file, char *place)
{
    if (place) {
        fprintf(stderr, "%s is an invalid save file because of %s\n",
            file, place);
        exit(84);
    }
    fprintf(stderr, "%s is an invalid save file\n", file);
    exit(84);
}

static char *get_save(char **file, int i)
{
    char *result = NULL;

    while (my_strcmpstart(file[i], "###") != 0 && file[i] != NULL) {
            result = append_str2(result, my_strdup(file[i]));
            result = append_str1f(result, '\n');
            i++;
        }
    return result;
}

char *import_from_save(char *part, char *savefile)
{
    char **file = my_str_to_word_array(getmap(savefile), "\n", 0);
    char *target = append_str("###", part);
    char *result = NULL;

    for (int i = 0; i < my_pointlen(file); i++) {
        if (my_strcmp(target, file[i]) == 0) {
            i++;
            result = get_save(file, i);
            break;
        }
    }
    free_array(file);
    return result;
}
