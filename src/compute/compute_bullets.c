/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-matthieu.guillet-arnaud
** File description:
** compute_bullets
*/

#include "my.h"

static void move_sprite(sfVector2f vector, sfSprite *sprite)
{
    sfVector2f movement = {vector.x * 10, vector.y * 10};

    sfSprite_move(sprite, movement);
}

static void delete_node(linked_list_t **element, bullet_fight_t **data_blt)
{
    linked_list_t *next = (*element)->next;

    (*element)->prev->next = next;
    if (next)
        next->prev = (*element)->prev;
    destroy_image((*data_blt)->bullet);
    if ((*data_blt)->weapon)
        destroy_image((*data_blt)->weapon);
    destroy_time((*data_blt)->time);
    free((*data_blt));
    free((*element));
    *element = next;
}

static void delete_node_bullet(map_t *map, linked_list_t **element,
    bullet_fight_t **data_blt)
{
    linked_list_t *next = (*element)->next;

    if (map->fight_tools == (*element)) {
        map->fight_tools = next;
        if (map->fight_tools)
            map->fight_tools->prev = NULL;
        destroy_image((*data_blt)->bullet);
        if ((*data_blt)->weapon)
            destroy_image((*data_blt)->weapon);
        destroy_time((*data_blt)->time);
        free((*data_blt));
        free((*element));
        (*element) = map->fight_tools;
    } else
        delete_node(element, data_blt);
}

static bool check_delete_node(map_t *map, bullet_fight_t **data_blt,
    linked_list_t **element, game_t *game)
{
    sfVector2f pos = sfSprite_getPosition((*data_blt)->bullet->sprite);

    if (!no_collision(map, pos) || (!no_collision_entity(map, pos) &&
        (*data_blt)->hit == true)) {
        if ((*data_blt)->explosion == true)
            my_insert_front_list(&map->fight_fx, init_explosion(game, pos));
        else
            my_insert_front_list(&map->fight_fx, init_bullet(game, pos,
                (*data_blt)->hit, sfSprite_getRotation((*data_blt)->bullet
                ->sprite)));
        delete_node_bullet(map, element, data_blt);
        return true;
    }
    return false;
}

static void pan_view(map_t *map, linked_list_t *element)
{
    static bool reset = true;

    if (((bullet_fight_t *)element->data)->time->offset + ((bullet_fight_t
        *)element->data)->lifetime > 0) {
        map->target_view = sfSprite_getPosition(((bullet_fight_t *)element
            ->data)->bullet->sprite);
        reset = false;
    } else {
        if (!reset && (bullet_fight_t *)element &&
            ((bullet_fight_t *)element->data)->weapon) {
            sfSprite_setColor(((bullet_fight_t *)element->data)->weapon
                ->sprite, sfTransparent);
            map->target_view = sfSprite_getPosition(map->player->sprite->temp
            ->sprite);
            reset = true;
        }
    }
}

void compute_bullets(bool has_del, map_t *map, game_t *game)
{
    linked_list_t *element = map->fight_tools;
    bullet_fight_t *data_blt = NULL;

    if (element != NULL)
        pan_view(map, element);
    while (element) {
        data_blt = element->data;
        update_time2(data_blt->time);
        sfClock_restart(data_blt->time->clock);
        data_blt->time->offset -= data_blt->time->seconds;
        if (data_blt->time->offset < 0) {
            move_sprite(mult3(data_blt->vector, data_blt->time->seconds * 30),
            data_blt->bullet->sprite);
        }
        if (data_blt->time->offset < -0.5)
            has_del = check_delete_node(map, &data_blt, &element, game);
        if (has_del == false)
            element = element->next;
    }
}
