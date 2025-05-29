/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-matthieu.guillet-arnaud
** File description:
** TODO: add description
*/

#include "my.h"

static void move_sprite(sfVector2f vector, img_t *img)
{
    sfVector2f movement = {vector.x * 10, vector.y * 10};

    sfSprite_move(img->sprite, movement);
}

static void update_dir(sfVector2f vector, sfVector2f vector_2, img_t *img)
{
    sfVector2f movement = {vector_2.x - vector.x, vector_2.y - vector.y};

    if (movement.x > 0 && movement.x > abs((int)(movement.y)))
        img->animate->state = 2;
    if (movement.x < 0 && abs((int)movement.x) > abs((int)(movement.y)))
        img->animate->state = 1;
    if (movement.y > 0 && movement.y > abs((int)(movement.x)))
        img->animate->state = 0;
    if (movement.y < 0 && abs((int)movement.y) > abs((int)(movement.x)))
        img->animate->state = 3;
    img->animate->rect.top = img->animate->rect.height * img->animate->state;
}

static void new_direction(entity_t *civil, sfVector2f curent_pos)
{
    sfVector2f rand_pos = {0, 0};
    sfVector2f pos_actual = sfSprite_getPosition(civil->civ->civ->sprite);

        civil->civ->time_move_dir = (rand() % 30);
    rand_pos = (sfVector2f) {pos_actual.x + randf(-400, 400),
        pos_actual.y + randf(-400, 400)};
    civil->civ->vector = (sfVector2f){cos(get_angle(rand_pos, curent_pos)),
        sin(get_angle(rand_pos, curent_pos))};
    update_dir(rand_pos, curent_pos, civil->civ->civ);
}

static void compute_not_moving(entity_t *civil, sfVector2f curent_pos,
    sfVector2f curent_pos_cpy)
{
    if (curent_pos.x - curent_pos_cpy.x == 0 &&
        curent_pos.y - curent_pos_cpy.y == 0 &&
        civil->civ->civ->animate->state <= 3) {
        civil->civ->civ->animate->state += 4;
        civil->civ->civ->animate->rect.top =
            civil->civ->civ->animate->state *
            civil->civ->civ->animate->rect.height;
        new_direction(civil, curent_pos);
    } else if (civil->civ->civ->animate->state > 3 &&
        (curent_pos.x - curent_pos_cpy.x != 0 ||
        curent_pos.y - curent_pos_cpy.y != 0)) {
        civil->civ->civ->animate->state -= 4;
        civil->civ->civ->animate->rect.top =
            civil->civ->civ->animate->state *
            civil->civ->civ->animate->rect.height;
    }
}

void check_change_dir(entity_t *civil, sfVector2f curent_pos)
{
    if (civil->civ->time_move_dir <= 0) {
        new_direction(civil, curent_pos);
    }
}

static void check_change_dir_previous(entity_t *civil, sfVector2f curent_pos,
    sfVector2f curent_pos_cpy)
{
    linked_list_t *lst = civil->civ->clothes;

    check_change_dir(civil, curent_pos);
    compute_not_moving(civil, curent_pos, curent_pos_cpy);
    while (lst) {
        ((img_t *)(lst->data))->animate->rect.top =
            civil->civ->civ->animate->rect.top;
        ((img_t *)(lst->data))->animate->rect.left =
            civil->civ->civ->animate->rect.left;
        sfSprite_setPosition(((img_t *)(lst->data))->sprite,
            sfSprite_getPosition(civil->civ->civ->sprite));
        lst = lst->next;
    }
}

static void compute_animation_civ(entity_t *civil)
{
    linked_list_t *lst = civil->civ->clothes;

    compute_animation_img(civil->civ->civ->animate, false);
    while (lst) {
        ((img_t *)(lst->data))->animate->rect.top =
            civil->civ->civ->animate->rect.top;
        ((img_t *)(lst->data))->animate->rect.left =
            civil->civ->civ->animate->rect.left;
        ((img_t *)(lst->data))->animate->state =
            civil->civ->civ->animate->state;
        lst = lst->next;
    }
}

int compute_civilian(entity_t *civil, map_t *map)
{
    sfVector2f curent_pos = sfSprite_getPosition(civil->civ->civ->sprite);
    sfVector2f curent_pos_cpy = curent_pos;

    update_time(civil->civ->own_clock);
    civil->civ->time_move_dir -= (sfTime_asMilliseconds(
        sfClock_getElapsedTime(civil->civ->own_clock->clock)) * 0.001);
    sfClock_restart(civil->civ->own_clock->clock);
    civil->position = sfSprite_getPosition(civil->civ->civ->sprite);
    if (my_strcmp(map->map->current_map, "Night_City/") == 0 &&
        no_collision_civils(map, add2(civil->civ->vector, civil->position),
            civil)) {
        move_sprite(mult3(civil->civ->vector, civil->civ->
            own_clock->seconds * 6), civil->civ->civ);
        curent_pos = sfSprite_getPosition(civil->civ->civ->sprite);
        civil->position = curent_pos;
    }
    check_change_dir_previous(civil, curent_pos, curent_pos_cpy);
    compute_animation_civ(civil);
    return 1;
}

void compute_all_civilians(game_t *game, linked_list_t **entity_all)
{
    linked_list_t *element = *entity_all;
    entity_t *entity;

    while (element) {
        entity = element->data;
        if (entity->type == CIVILIAN)
            compute_civilian(entity, game->guis->map->ui_content);
        element = element->next;
    }
}
