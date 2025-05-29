/*
** EPITECH PROJECT, 2024
** My_Rpg
** File description:
** compute_echap
*/
#include "my.h"

static void reset_pos_healthbar(game_t *game)
{
    map_t *map = game->guis->map->ui_content;
    sfVector2f pos_view = sfView_getCenter(map->view);

    if (map->inventory->is_display == true)
        sfSprite_setPosition(map->inventory->stats->health_bar->sprite,
            (sfVector2f){pos_view.x - 960, pos_view.y - 540 + 20});
}

void compute_echap(game_t *game)
{
    map_t *map = ((map_t *)(game->guis->map->ui_content));

    reset_pos_healthbar(game);
    if (game->events->type == sfEvtKeyReleased &&
        game->events->key.code == sfKeyEscape) {
        map->inventory->is_display = false;
        reset_postion_items(map);
        map->inventory->is_picked = false;
        map->inventory->items_slots_picked = -1;
        game->espace_active = !game->espace_active;
        game->events->key.code = sfKeyCount;
    }
}
