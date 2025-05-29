/*
** EPITECH PROJECT, 2024
** compute_health_bar
** File description:
** compute_health_bar
*/

#include "my.h"

void compute_health_bar(gui_inventory_t *inventory, sfView *view)
{
    float frame = 0.0;
    float x = (float)inventory->player->hp->x;
    float y = (float)inventory->player->hp->y;
    sfVector2f pos_view = sfView_getCenter(view);

    if (x < 0)
        x = 0;
    if (y < 0)
        y = 0;
    frame = round((x / y) *
        (float)inventory->stats->health_bar->animate->nb_images);
    if (frame > (float)inventory->stats->health_bar->animate->nb_images)
        frame = (float)inventory->stats->health_bar->animate->nb_images;
    inventory->stats->health_bar->animate->rect.top = frame *
        inventory->stats->health_bar->animate->rect.height;
    if (inventory->is_display == false)
        sfSprite_setPosition(inventory->stats->health_bar->sprite,
            (sfVector2f){pos_view.x - 960, pos_view.y - 540 + 20});
}
