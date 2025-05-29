/*
** EPITECH PROJECT, 2024
** init_assets()
** File description:
** init_assets()
*/
#include "my.h"
#include "rpg_struct.h"

static int load_asset(assets_t **asset, int i, char **line)
{
    char **parsed = my_str_to_word_array(line[i], ":", 63);

    asset[i] = malloc(sizeof(assets_t));
    if (my_pointlen(parsed) != 2)
        return 1;
    asset[i]->name = my_strdup(parsed[0]);
    asset[i]->path = my_strdup(parsed[1]);
    return 0;
}

void check_assets(game_t *game)
{
    if (game->assets == NULL) {
        fprintf(stderr, "Error loading assets\n");
        exit(84);
    }
}

assets_t **init_assets(void)
{
    char *path = my_strdup("./Assets");
    char *str = open_file(path);
    char **parsed_str = NULL;
    assets_t **assets = NULL;
    int len = 0;

    if (!str)
        return NULL;
    parsed_str = my_str_to_word_array(str, "\n\0", 0);
    if (my_pointlen(parsed_str) < 1)
        return NULL;
    len = my_pointlen(parsed_str);
    assets = malloc(sizeof(assets_t *) * (len + 1));
    assets[len] = NULL;
    for (int i = 0; i < len; i++) {
        if (load_asset(assets, i, parsed_str) == 1)
            return NULL;
    }
    return assets;
}
