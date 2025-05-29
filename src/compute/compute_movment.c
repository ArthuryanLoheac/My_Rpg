/*
** EPITECH PROJECT, 2024
** update_menu_start
** File description:
** update_menu_start
*/

#include "my.h"

static bool pressed(sfKeyCode key)
{
    return sfKeyboard_isKeyPressed(key);
}

static sfVector2f move_diago(map_t *map, sfVector2f center, game_t *game)
{
    float speed = map->player->mov->seconds * 50 * map->player->movmult;

    if (sfKeyboard_isKeyPressed(sfKeyLShift))
        speed *= 1.8;
    if (map->fight->dep_mouv.x == 0)
        return center;
    if (pressed(game->keybinds->up) && (pressed(game->keybinds->right) ||
        pressed(game->keybinds->left)))
        center.y -= map->view_speed / sqrt(2) * speed;
    if (pressed(game->keybinds->down) && (pressed(game->keybinds->right) ||
        pressed(game->keybinds->left)))
        center.y += map->view_speed / sqrt(2) * speed;
    if (pressed(game->keybinds->right) && (pressed(game->keybinds->up) ||
        pressed(game->keybinds->down)))
        center.x += map->view_speed / sqrt(2) * speed;
    if (pressed(game->keybinds->left) && (pressed(game->keybinds->up) ||
        pressed(game->keybinds->down)))
        center.x -= map->view_speed / sqrt(2) * speed;
    return center;
}

static sfVector2f move_line(map_t *map, sfVector2f center, game_t *game)
{
    float speed = map->player->mov->seconds * 50 * map->player->movmult;

    if (sfKeyboard_isKeyPressed(sfKeyLShift))
        speed *= 1.8;
    compute_animation_hero(map->player->sprite, game);
    if (map->fight->dep_mouv.x == 0)
        return center;
    if (pressed(game->keybinds->up) && !(pressed(game->keybinds->right) ||
        pressed(game->keybinds->left)))
        center.y -= map->view_speed * speed;
    if (pressed(game->keybinds->down) && !(pressed(game->keybinds->right) ||
        pressed(game->keybinds->left)))
        center.y += map->view_speed * speed;
    if (pressed(game->keybinds->left) && (!(pressed(game->keybinds->up)
        || pressed(game->keybinds->down))))
        center.x -= map->view_speed * speed;
    if (pressed(game->keybinds->right) && (!(pressed(game->keybinds->up)
        || pressed(game->keybinds->down))))
        center.x += map->view_speed * speed;
    return center;
}

static void move_clothes(player_character_t *player, sfVector2f pos)
{
    linked_list_t *lst = player->sprite->clothes;

    while (lst) {
        sfSprite_setPosition(((img_t *)(lst->data))->sprite, pos);
        lst = lst->next;
    }
}

void compute_movement_free(ui_obj_t *obj, game_t *game)
{
    map_t *map = (map_t *)obj->ui_content;
    sfVector2f pos = sfSprite_getPosition(map->player->sprite->temp->sprite);

    if (empty_diag(map) == false) {
        sfClock_restart(map->player->mov->clock);
        return;
    }
    update_time(map->player->mov);
    pos = compute_pc_collision(map, move_diago(map,
        move_line(map, pos, game), game), pos);
    sfClock_restart(map->player->mov->clock);
    sfSprite_setPosition(map->player->sprite->temp->sprite, pos);
    move_clothes(map->player, pos);
    map->target_view = pos;
    sfRenderWindow_setView(game->window, map->view);
}

void compute_movement(ui_obj_t *obj, game_t *game)
{
    map_t *map = (map_t *)obj->ui_content;
    sfVector2f pos = sfSprite_getPosition(map->player->sprite->temp->sprite);
    sfVector2f ref = sfSprite_getPosition(map->player->sprite->temp->sprite);

    update_time(map->player->mov);
    pos = compute_pc_collision(map, move_diago(map,
        move_line(map, pos, game), game), pos);
    sfClock_restart(map->player->mov->clock);
    map->fight->dep_mouv.x -= get_distance(pos, ref);
    if (map->fight->dep_mouv.x < 0)
        map->fight->dep_mouv.x = 0;
    sfSprite_setPosition(map->player->sprite->temp->sprite, pos);
    move_clothes(map->player, pos);
    map->target_view = pos;
    if (pos.x != ref.x || pos.y != ref.y) {
        compute_mana_bar(map->fight);
        sfSprite_setPosition(map->fight->gui->mana_img->sprite, (sfVector2f)
            {sfView_getCenter(map->view).x - 960,
            sfView_getCenter(map->view).y - 540 + 30});
    }
}
