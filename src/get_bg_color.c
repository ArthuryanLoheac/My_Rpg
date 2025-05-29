/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** to get the background color
*/

#include "my.h"

sfColor get_bg_color(game_t *game)
{
    map_t *map = ((map_t *)(game->guis->map->ui_content));

    if (map && map->map &&
        my_strcmp(map->map->current_map, "Night_City/") == 0)
        return sfColor_fromRGBA(121, 183, 193, 255);
    else
        return sfColor_fromRGBA(30, 30, 30, 255);
}
