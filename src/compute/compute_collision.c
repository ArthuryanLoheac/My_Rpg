/*
** EPITECH PROJECT, 2024
** update_menu_start
** File description:
** update_menu_start
*/

#include "my.h"

bool sight_collision(map_t *map, sfVector2f pos1, sfVector2f pos2)
{
    sfVector2f direction = normalize(sub2(pos2, pos1));
    float step = 10;

    while ((pos2.x - pos1.x) * direction.x > 0) {
        if (no_collision(map, pos1) == false)
            return false;
        pos1 = add(pos1, step * direction.x, step * direction.y);
    }
    return true;
}

bool no_collision(map_t *map, sfVector2f pos)
{
    sfVector2u coord;
    sfColor px;

    pos.x = (int)(pos.x) / 4;
    pos.y = (int)(pos.y) / 4;
    if (pos.x < 0 || pos.y < 0 || pos.x > 17280 / 4 || pos.y > 11880 / 4)
        return false;
    coord = (sfVector2u){(unsigned int)pos.x, (unsigned int)pos.y};
    px = sfImage_getPixel(map->map->map[coord.y / (1080 / 4)][coord.x / (1920 /
        4)]->col, coord.x % (1920 / 4), coord.y % (1080 / 4));
    if (!((px.a == sfBlack.a && px.b == sfBlack.b &&
        px.g == sfBlack.g && px.r == sfBlack.r)))
        return true;
    return false;
}

static bool no_collision_civils_one_pos(map_t *map, sfVector2f pos,
    entity_t *civil)
{
    sfVector2u coord;
    sfColor px;

    pos.x = (int)(pos.x) / 4;
    pos.y = (int)(pos.y) / 4;
    if (pos.x < 0 || pos.y < 0 || pos.x > 17280 || pos.y > 11880)
        return false;
    coord = (sfVector2u){(unsigned int)pos.x, (unsigned int)pos.y};
    if (coord.y / (1080 / 4) >= 11 || coord.x / (1920 / 4) >= 9)
        return false;
    px = sfImage_getPixel(map->map->map[coord.y / (1080 / 4)][coord.x / (1920 /
        4)]->col, coord.x % (1920 / 4), coord.y % (1080 / 4));
    if ((px.b == 119 && px.r == 119 && px.g == 119 && px.a == 255) ||
        (px.b == 0 && px.r == 0 && px.g == 0 && px.a == 255)) {
        check_change_dir(civil, sfSprite_getPosition(civil->civ->civ->sprite));
        return false;
    }
    return true;
}

bool no_collision_civils(map_t *map, sfVector2f pos,
    entity_t *civil)
{
    sfVector2f coord1 = (sfVector2f){pos.x - 16, pos.y + 32};
    sfVector2f coord2 = (sfVector2f){pos.x + 16, pos.y + 62};
    sfVector2f coord3 = (sfVector2f){pos.x + 16, pos.y + 32};
    sfVector2f coord4 = (sfVector2f){pos.x - 16, pos.y + 62};

    if (no_collision_civils_one_pos(map, coord1, civil) &&
        no_collision_civils_one_pos(map, coord2, civil) &&
        no_collision_civils_one_pos(map, coord3, civil) &&
        no_collision_civils_one_pos(map, coord4, civil))
        return true;
    return false;
}

static bool check_entity_collision(linked_list_t *element, sfVector2f pos)
{
    sfSprite *sprite = NULL;
    sfFloatRect viewRect_sprite;

    sprite = get_sprite(((entity_t *)(element->data)));
    viewRect_sprite = sfSprite_getGlobalBounds(sprite);
    if (sfFloatRect_contains(&viewRect_sprite, pos.x, pos.y) == sfTrue)
        return false;
    return true;
}

bool no_collision_entity(map_t *map, sfVector2f pos)
{
    linked_list_t *element = map->entity_all;

    while (element) {
        if (!check_entity_collision(element, pos))
            return false;
        element = element->next;
    }
    return true;
}

static bool pc_collision(map_t *map, sfVector2f pos)
{
    sfVector2f coord1 = (sfVector2f){pos.x - 16, pos.y + 32};
    sfVector2f coord2 = (sfVector2f){pos.x + 16, pos.y + 32};

    if (no_collision(map, coord1) == true && no_collision(map, coord2) == true)
        return true;
    return false;
}

sfVector2f compute_pc_collision(map_t *map, sfVector2f pos, sfVector2f old)
{
    if (pc_collision(map, pos) == true)
        return pos;
    if (pc_collision(map, (sfVector2f){pos.x, old.y}) == true)
        return (sfVector2f){pos.x, old.y};
    if (pc_collision(map, (sfVector2f){old.x, pos.y}) == true)
        return (sfVector2f){old.x, pos.y};
    return old;
}
