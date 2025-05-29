/*
** EPITECH PROJECT, 2024
** update_menu_start
** File description:
** update_menu_start
*/

#include "my.h"

float randf(float min, float max)
{
    return min + (rand() / (RAND_MAX / (max - min)));
}

sfVector2f find_pos_ai(map_t *map, sfVector2f target_pos,
    sfVector2f my_pos)
{
    sfVector2f tmp;

    for (int i = 0; i < 100000; i++) {
        tmp = normalize((sfVector2f){randf(-1, 1), randf(-1, 1)});
        tmp = add(my_pos, tmp.x * randf(0, 500), tmp.y * randf(0, 500));
        if (sight_collision(map, tmp, target_pos) == true &&
            sight_collision(map, tmp, my_pos) == true) {
            return tmp;
        }
    }
    for (int i = 0; i < 100000; i++) {
        tmp = normalize((sfVector2f){randf(-1, 1), randf(-1, 1)});
        tmp = add(my_pos, tmp.x * randf(500, 2000), tmp.y * randf(500, 2000));
        if (sight_collision(map, tmp, target_pos) == true &&
            sight_collision(map, tmp, my_pos) == true) {
            return tmp;
        }
    }
    return target_pos;
}

sfVector2f find_ideal_pos_ai(map_t *map, sfVector2f target_pos,
    npc_t *npc)
{
    sfVector2f my_pos = sfSprite_getPosition(npc->npc->sprite);
    sfVector2f target_direction = normalize(sub2(target_pos, my_pos));

    if (npc->melee && get_distance(target_pos, my_pos) <
        npc->stats->MOVE * 50)
        return target_pos;
    if (npc->ranged)
        return add2(my_pos, mult3(target_direction, get_distance(target_pos,
            my_pos) - (float)npc->ranged->weapon->opt_distance));
    return my_pos;
    (void) map;
}
