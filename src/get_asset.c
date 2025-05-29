/*
** EPITECH PROJECT, 2024
** get_asset
** File description:
** get_asset
*/

#include "my.h"

static void error_finding_asset(char *name)
{
    fprintf(stderr, "Error finding the asset : %s\n", name);
    exit(84);
}

static char *check_path(char *path, char *name)
{
    int fd = open(path, O_RDONLY);

    if (fd == -1) {
        printf("name : %s, path : %s\n", name, path);
        error_finding_asset(name);
    }
    close(fd);
    return path;
}

char *get_asset(char *name, assets_t **assets)
{
    int i = 0;

    if (assets == NULL)
        error_finding_asset(name);
    while (assets[i] != NULL) {
        if (!my_strcmp(assets[i]->name, name))
            return my_strdup(check_path(assets[i]->path, name));
        i++;
    }
    error_finding_asset(name);
    return NULL;
}
