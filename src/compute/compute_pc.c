/*
** EPITECH PROJECT, 2024
** update_menu_start
** File description:
** update_menu_start
*/

#include "my.h"

static bool do_sleep(map_t *map)
{
    static time2_t *clock = NULL;

    if (clock == NULL)
        clock = init_time();
    update_time(clock);
    map->night->time_mult = 60;
    map->player->movmult = 0;
    if (map->night->clock->seconds > 340 && map->night->clock->seconds < 500) {
        map->player->movmult = 1;
        map->night->time_mult = 1;
        sfSprite_setPosition(map->player->sprite->temp->sprite,
            (sfVector2f){11727, 10756});
        return false;
    }
    if (clock->seconds > 1) {
        map->player->hp->x = MIN(map->player->hp->y, map->player->hp->x +
            (clock->seconds * 5));
        sfClock_restart(clock->clock);
    }
    return true;
}

static void compute_sleep(game_t *game, map_t *map)
{
    static bool is_sleep = false;
    sfFloatRect player_bound = sfSprite_getGlobalBounds(map->player->sprite
        ->temp->sprite);

    if (my_strcmp(map->map->current_map, "Night_City/") == 0 &&
        sfFloatRect_intersects(&player_bound, map->night->sleep_zone, NULL)
        && sfKeyboard_isKeyPressed(game->keybinds->interact)) {
        if ((map->night->clock->seconds < 100 || map->night->clock->seconds
            > 1000)) {
            is_sleep = true;
            sfSprite_setPosition(map->player->sprite->temp->sprite,
                (sfVector2f){11727, 10756});
        } else
            send_info(game, 2, "Can't sleep now !");
    }
    if (is_sleep == true)
        is_sleep = do_sleep(map);
}

void compute_pc(map_t *map, game_t *game)
{
    compute_exp_player(map, game);
    compute_cyberware(map);
    compute_health_bar(map->inventory, map->view);
    compute_sleep(game, map);
    compute_inventory(map, game);
}
