/*
** EPITECH PROJECT, 2024
** update_menu_start
** File description:
** update_menu_start
*/

#include "my.h"

void compute_fade(map_t *map)
{
    float delta = 0;

    update_time(map->fade->clock);
    if (map->fade->clock->seconds > 0.1) {
        delta = map->fade->clock->seconds;
        sfClock_restart(map->fade->clock->clock);
    }
    if (map->fade->overlay.a == 255)
        map->fade->is_active = false;
    if (map->fade->is_active && map->fade->overlay.a < 254) {
        map->fade->overlay.a = MIN(map->fade->overlay.a +
            (int)(delta * 50), 255);
    } else if (map->fade->overlay.a > 0)
        map->fade->overlay.a = MAX(map->fade->overlay.a -
            (int)(delta * 50), 0);
    sfSprite_setColor(map->fade->img->sprite, map->fade->overlay);
}
