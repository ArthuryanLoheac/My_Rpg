/*
** EPITECH PROJECT, 2024
** compute_guis
** File description:
** compute_guis
*/

#include "my.h"

void compute_pause(guis_t *guis)
{
    float offset;
    map_t *map = (map_t *)(guis->map->ui_content);

    update_time(guis->pause);
    offset = guis->pause->seconds;
    if (map->dialogue_pipeline->clock != NULL)
        map->dialogue_pipeline->clock->offset -= offset;
    sfClock_restart(guis->pause->clock);
}
