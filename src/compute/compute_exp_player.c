/*
** EPITECH PROJECT, 2024
** compute_xp
** File description:
** compute_exp_player
*/

#include "my.h"

static void level_up_player(map_t *map, game_t *game)
{
    map->inventory->is_display = false;
    reset_postion_items(map);
    map->inventory->is_picked = false;
    map->inventory->items_slots_picked = -1;
    game->level_up_active = true;
    game->events->key.code = sfKeyCount;
}

void compute_exp_player(map_t *map, game_t *game)
{
    xp_data_t *xp = map->player->xp_data;
    sfVector2f pos_view = sfView_getCenter(map->view);
    double value = 0;

    if (xp->xp_player.x >= xp->xp_player.y) {
        xp->xp_player.x -= xp->xp_player.y;
        xp->level++;
        xp->xp_player.y += (int) (xp->xp_player.y / 4);
        level_up_player(map, game);
    }
    value = (double)((double) xp->xp_player.x / (double) xp->xp_player.y);
    sfRectangleShape_setSize(xp->xp_bg, (sfVector2f){260 * value, 20});
    sfRectangleShape_setPosition(xp->xp_bg, (sfVector2f){pos_view.x - 960
        + 250, pos_view.y - 540 + 477});
    sfRectangleShape_setPosition(xp->background, (sfVector2f){pos_view.x - 960
        + 250, pos_view.y - 540 + 477});
    sfText_setPosition(xp->niv_label, (sfVector2f){pos_view.x - 960
        + 225, pos_view.y - 540 + 485});
    sfText_setString(xp->niv_label, int_to_str(xp->level));
}
