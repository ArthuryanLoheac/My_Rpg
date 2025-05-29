/*
** EPITECH PROJECT, 2024
** init_map
** File description:
** init_map
*/

#include "my.h"

static sfVector2u find_map_size(char *map_name)
{
    if (my_strcmp(map_name, "Night_City/") == 0)
        return (sfVector2u){11, 9};
    if (my_strcmp(map_name, "QueenHouse/") == 0 ||
        my_strcmp(map_name, "Briefing/") == 0)
        return (sfVector2u){1, 1};
    return (sfVector2u){0, 0};
}

map_panel_image_t *init_game_map(game_t *game, bool is_new, map_t *map)
{
    char **res;

    if (!is_new) {
        res = my_str_to_word_array(import_from_save("Map",
            game->savefilepath), "\n", 0);
        if (my_pointlen(res) != 1 || find_map_size(res[0]).x == 0)
            wrong_savefile(game->savefilepath, "###Map");
        if (my_strcmp("Night_City/", res[0]) == 0)
            return map->map;
        return load_map(game, res[0], find_map_size(res[0]), true);
    } else
        return map->map;
}
