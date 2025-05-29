/*
** EPITECH PROJECT, 2024
** display shoot
** File description:
** display_shoot
*/

#include "my.h"

void add_node_bullet(linked_list_t **pos,
    bullet_fight_t *data_added, int i)
{
    linked_list_t *element = malloc(sizeof(linked_list_t));

    data_added->time->offset = (float)i / 10.5;
    element->data = data_added;
    element->next = *pos;
    element->prev = NULL;
    if (*pos)
        (*pos)->prev = element;
    *pos = element;
}

static bullet_fight_t *check_ranged_weapons_miss(game_t *game, int type,
    sfFloatRect tas, bool first_hit)
{
    bullet_fight_t *data_added = NULL;

    if (type == PISTOL || type == HPISTOL || type == RIFLE || type == SMG ||
        type == SNIPER) {
        if (first_hit == false)
            type = -1;
        data_added = init_fight_ranged_bullets(game, bullet_pos(tas),
        get_angle_degree((sfVector2f){tas.width, tas.height},
        (sfVector2f){tas.left, tas.top}) + compute_no_hit(), type);
        data_added->lifetime = get_distance((sfVector2f){tas.left, tas.top},
            (sfVector2f){tas.width, tas.height}) / 300;
        data_added->explosion = false;
    }
    return data_added;
}

static bullet_fight_t *check_ranged_weapons_hit(game_t *game, int type,
    sfFloatRect tas, bool first_hit)
{
    bullet_fight_t *data_added = NULL;

    if (type == PISTOL || type == HPISTOL || type == RIFLE || type == SMG ||
        type == SNIPER) {
        if (first_hit == false)
            type = -1;
        data_added = init_fight_ranged_bullets(game, bullet_pos(tas),
        get_angle_degree((sfVector2f){tas.width, tas.height},
        (sfVector2f){tas.left, tas.top}), type);
        data_added->lifetime = get_distance((sfVector2f){tas.left, tas.top},
            (sfVector2f){tas.width, tas.height}) / 300;
        data_added->explosion = false;
    }
    return data_added;
}

static bullet_fight_t *check_rocket_weapons_miss(game_t *game, int type,
    sfFloatRect tas, bool first_hit)
{
    bullet_fight_t *data_added = NULL;
    map_t *map = ((map_t *)(game->guis->map->ui_content));

    if (type == ROCKET_L || type == NADL) {
        if (first_hit == false)
            type = -1;
        data_added = init_fight_rocket_bullets(game, bullet_pos(tas),
        (sfCircleShape_getRotation(map->fight->gui->aoe) -
        180 + compute_no_hit()), type);
        data_added->lifetime = get_distance(sfCircleShape_getPosition(map->
        fight->gui->aoe), (sfVector2f){tas.width, tas.height}) / 300;
        data_added->explosion = true;
        }
    return data_added;
}

static bullet_fight_t *check_rocket_weapons_hit(game_t *game, int type,
    sfFloatRect tas, bool first_hit)
{
    bullet_fight_t *data_added = NULL;
    map_t *map = ((map_t *)(game->guis->map->ui_content));

    if (type == ROCKET_L || type == NADL) {
        if (first_hit == false)
            type = -1;
        data_added = init_fight_rocket_bullets(game, bullet_pos(tas),
        (sfCircleShape_getRotation(map->fight->gui->aoe) -
        180), type);
        data_added->lifetime = get_distance(sfCircleShape_getPosition(map->
        fight->gui->aoe), (sfVector2f){tas.width, tas.height}) / 300;
        data_added->explosion = true;
    }
    return data_added;
}

static bullet_fight_t *check_shotgun_weapons_miss(game_t *game, int type,
    sfFloatRect tas, bool first_hit)
{
    bullet_fight_t *data_added = NULL;
    map_t *map = ((map_t *)(game->guis->map->ui_content));

    if (type == SHOTGUN) {
        if (first_hit == false)
            type = -1;
        data_added = init_fight_shotgun_bullets(game->assets, bullet_pos(tas),
        (sfRectangleShape_getRotation(map->fight->gui->
        aoe_shotgun) - 180 + compute_no_hit2()), type);
        data_added->lifetime = get_distance(sfRectangleShape_getPosition(map->
        fight->gui->aoe_shotgun), (sfVector2f){tas.width, tas.height}) / 300;
        data_added->explosion = false;
    }
    return data_added;
}

static bullet_fight_t *check_shotgun_weapons_hit(game_t *game, int type,
    sfFloatRect tas, bool first_hit)
{
    bullet_fight_t *data_added = NULL;
    map_t *map = ((map_t *)(game->guis->map->ui_content));

    if (type == SHOTGUN) {
        if (first_hit == false)
            type = -1;
        data_added = init_fight_shotgun_bullets(game->assets, bullet_pos(tas),
        (sfRectangleShape_getRotation(map->fight->gui->
        aoe_shotgun) - 180), type);
        data_added->lifetime = get_distance(sfRectangleShape_getPosition(map->
        fight->gui->aoe_shotgun), (sfVector2f){tas.width, tas.height}) / 300;
        data_added->explosion = false;
    }
    return data_added;
}

bool display_shoot(game_t *game, sfFloatRect tas, int typ, bool f_hit)
{
    static int i = 0;
    bullet_fight_t *new = NULL;
    map_t *map = ((map_t *)(game->guis->map->ui_content));

    if (f_hit == true)
        i = 0;
    if (typ < 0) {
        new = NOT_NULL(check_shotgun_weapons_hit(game, -typ, tas, f_hit), new);
        new = NOT_NULL(check_ranged_weapons_hit(game, -typ, tas, f_hit), new);
        new = NOT_NULL(check_rocket_weapons_hit(game, -typ, tas, f_hit), new);
        new->hit = true;
    } else {
        new = NOT_NULL(check_shotgun_weapons_miss(game, typ, tas, f_hit), new);
        new = NOT_NULL(check_ranged_weapons_miss(game, typ, tas, f_hit), new);
        new = NOT_NULL(check_rocket_weapons_miss(game, typ, tas, f_hit), new);
        new->hit = false;
    }
    add_node_bullet(&(map->fight_tools), new, i);
    i++;
    return 0;
}

void animation_shoot(game_t *game, sfVector2i hits,
    sfFloatRect tas, int wpn_type)
{
    int i = 0;
    bool first_hit = true;

    for (; i < hits.x; i++)
        first_hit = display_shoot(game, tas, -wpn_type,
            first_hit);
    for (; i < hits.y; i++)
        first_hit = display_shoot(game, tas, wpn_type,
            first_hit);
}
