/*
** EPITECH PROJECT, 2024
** update_menu_start
** File description:
** update_menu_start
*/

#include "my.h"

static void compute_vertex_array(map_t *map)
{
    item_t *itm = map->inventory->inventory->main_slots[12]->items;

    sfVertexArray_clear(map->fight->gui->arr);
    if (itm == NULL || (itm->weapon->type >= 10 && itm->weapon->type <= 13)) {
        for (int i = 0; i < 4; ++i)
            sfVertexArray_append(map->fight->gui->arr,
                map->fight->gui->points[i]);
    } else {
        for (int i = 0; i < 32; ++i)
            sfVertexArray_append(map->fight->gui->arr,
                map->fight->gui->points[i]);
    }
}

static void compute_shell_rect(map_t *map, game_t *game)
{
    sfRectangleShape *shape = map->fight->gui->aoe_shotgun;
    item_t *itm = map->inventory->inventory->main_slots[12]->items;
    sfVector2f pos = get_mouse_pos(game->window);
    sfFloatRect rect;

    if (!itm || itm->weapon->type != SHOTGUN)
        return;
    rect = sfRectangleShape_getLocalBounds(shape);
    sfRectangleShape_setOrigin(shape, (sfVector2f){rect.width / 2, 0});
    sfRectangleShape_setRotation(shape, 90 + (get_angle(pos,
        sfSprite_getPosition(map->player->sprite->temp->sprite)) *
        (180.0 / M_PI)));
    sfRectangleShape_setPosition(shape, sfSprite_getPosition(map->player
        ->sprite->temp->sprite));
}

static void compute_explosion_rect(map_t *map, game_t *game)
{
    sfCircleShape *shape = map->fight->gui->aoe;
    item_t *itm = map->inventory->inventory->main_slots[12]->items;
    sfVector2f pos = get_mouse_pos(game->window);
    sfFloatRect rect;

    if (!itm || (itm->weapon->type != NADL && itm->weapon->type != ROCKET_L))
        return;
    rect = sfCircleShape_getLocalBounds(shape);
    sfCircleShape_setOrigin(shape,
        (sfVector2f){rect.width / 2, rect.height / 2});
    sfCircleShape_setRotation(shape, get_angle(pos, sfSprite_getPosition(
        map->player->sprite->temp->sprite)) * (180.0 / M_PI));
    sfCircleShape_setPosition(shape, pos);
}

static void get_shoot_line(map_t *map, game_t *game)
{
    item_t *itm = map->inventory->inventory->main_slots[12]->items;

    if (!itm || (itm->weapon->type != NADL && itm->weapon->type != ROCKET_L
        && itm->weapon->type != SHOTGUN)) {
        compute_shoot_line(map, sfSprite_getPosition(map->player->sprite->temp
            ->sprite), sfSprite_getPosition(get_index_npc(map->fight
            ->turn_order, map->fight->target)->npc->sprite));
        return;
    }
    compute_shoot_line(map, sfSprite_getPosition(map->player->sprite->temp
        ->sprite), get_mouse_pos(game->window));
}

static void find_target(map_t *map, game_t *game)
{
    if (linked_list_len(&(map->fight->turn_order)) == 1)
        return;
    while (get_index_npc(map->fight->turn_order, map->fight->target) == NULL) {
        map->fight->target++;
        if (map->fight->target >= my_list_size(map->fight->turn_order))
        map->fight->target = 0;
    }
    get_shoot_line(map, game);
    if (sfMouse_isButtonPressed(sfMouseMiddle) == sfFalse && map->fight->fired
        == false && map->inventory->is_display == false)
        map->target_view = sfSprite_getPosition(get_index_npc(
        map->fight->turn_order, map->fight->target)->npc->sprite);
    compute_vertex_array(map);
    compute_explosion_rect(map, game);
    compute_shell_rect(map, game);
}

static void cycle_target(map_t *map)
{
    map->fight->target++;
    if (map->fight->target >= my_list_size(map->fight->turn_order))
        map->fight->target = 0;
    if (get_index_npc(map->fight->turn_order, map->fight->target) != NULL &&
        get_index_npc(map->fight->turn_order, map->fight->target)->type
        == FRIENDLY)
        map->fight->target++;
    if (map->fight->target >= my_list_size(map->fight->turn_order))
        map->fight->target = 0;
}

static sfFloatRect get_target_shooter_rect(map_t *map)
{
    sfVector2f player_pos = sfSprite_getPosition(map->player->sprite
        ->temp->sprite);
    sfVector2f target_pos = sfSprite_getPosition(get_index_npc(map->fight
        ->turn_order, map->fight->target)->npc->sprite);

    return (sfFloatRect){player_pos.x, player_pos.y,
        target_pos.x, target_pos.y};
}

static void do_compute_shoot(game_t *game, map_t *map)
{
    sfVector2i hits = compute_player_atk_npc(map, get_index_npc(map->fight
        ->turn_order, map->fight->target), map->fight, game);

    if (map->inventory->inventory->main_slots[12]->items) {
        animation_shoot(game, hits, get_target_shooter_rect(map), map->
        inventory->inventory->main_slots[12]->items->weapon->type);
    }
    map->fight->fired = true;
}

static void compute_shoot(game_t *game, map_t *map)
{
    static sfBool pressed = sfFalse;

    find_target(map, game);
    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue && map->fight->fired ==
        false) {
        map->fight->action = NO_ACTION;
        map->fight->action_taken = false;
    }
    if (sfMouse_isButtonPressed(sfMouseRight) == sfTrue
        && map->fight->fired == false)
            do_compute_shoot(game, map);
    if (key_is_pressed(game->keybinds->skip, pressed) == sfTrue)
        cycle_target(map);
    pressed = sfKeyboard_isKeyPressed(game->keybinds->skip);
    sfRenderWindow_setView(game->window, map->view);
}

void compute_player_turn(game_t *game, ui_obj_t *obj, map_t *map)
{
    if (map->fight->action_taken == false) {
        map->fight->action = NO_ACTION;
        map->fight->fired = false;
    }
    compute_player_fight(obj, game);
    if (map->fight->action == SHOOT)
        compute_shoot(game, map);
}
