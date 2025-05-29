/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** a function to display a message
*/

#include "my.h"

static void draw_autofire(sfRenderWindow *window, fight_gui_t *fight_gui,
    enum weapon_type_e type)
{
    if (type == SMG || type == RIFLE) {
        make_img(fight_gui->fire->img, window);
        make_img(fight_gui->autofire->img, window);
    } else {
        make_img(fight_gui->fire->img, window);
    }
}

static void draw_weapon_type(sfRenderWindow *window, game_t *game,
    fight_gui_t *fight_gui)
{
    enum weapon_type_e type;

    if (((map_t *)(game->guis->map->ui_content))->inventory->inventory
        ->main_slots[12]->items == NULL) {
        make_img(fight_gui->unarmd->img, window);
        return;
    }
    type = ((map_t *)(game->guis->map->ui_content))->inventory
        ->inventory->main_slots[12]->items->weapon->type;
    if (type < 7)
        draw_autofire(window, fight_gui, type);
    if (type == NADL || type == ROCKET_L)
        make_img(fight_gui->expl->img, window);
    if (type == BOW)
        make_img(fight_gui->bow->img, window);
    if (type == SHOTGUN)
        make_img(fight_gui->shell->img, window);
    if (type >= 10 && type <= 13)
        make_img(fight_gui->melee->img, window);
}

static void make_1_hp_bar(sfRenderWindow *window, game_t *game,
    fight_gui_t *gui, int i)
{
    npc_t *npc = get_index_npc(((map_t *)(game->guis->map->ui_content))
        ->fight->turn_order, i);

    sfRectangleShape_setPosition(gui->hp_bar, add(sfSprite_getPosition(
        npc->npc->sprite), -32, -64));
    sfRectangleShape_setSize(gui->hp_bar, (sfVector2f){64, 10});
    sfRectangleShape_setFillColor(gui->hp_bar, sfRed);
    sfRenderWindow_drawRectangleShape(window, gui->hp_bar, NULL);
    sfRectangleShape_setPosition(gui->hp_bar, add(sfSprite_getPosition(
        npc->npc->sprite), -32, -64));
    sfRectangleShape_setSize(gui->hp_bar, (sfVector2f){64 * ((float)
        npc->hp.x / npc->hp.y), 10});
    if (npc->type == FRIENDLY)
        sfRectangleShape_setFillColor(gui->hp_bar, sfBlue);
    else
        sfRectangleShape_setFillColor(gui->hp_bar, sfGreen);
    sfRenderWindow_drawRectangleShape(window, gui->hp_bar, NULL);
}

static void make_hp_bar(sfRenderWindow *window, game_t *game,
    fight_gui_t *gui)
{
    map_t *map = ((map_t *)(game->guis->map->ui_content));

    for (int i = 0; i < my_list_size(map->fight->turn_order); i++) {
        if (get_index_npc(map->fight->turn_order, i)) {
            make_1_hp_bar(window, game, gui, i);
        }
    }
}

static void make_shell_rect(sfRenderWindow *window, game_t *game,
    fight_gui_t *gui)
{
    map_t *map = ((map_t *)(game->guis->map->ui_content));
    item_t *itm = map->inventory->inventory->main_slots[12]->items;

    if (!itm || (itm->weapon->type != SHOTGUN))
        return;
    sfRenderWindow_drawRectangleShape(window, gui->aoe_shotgun, NULL);
}

static void make_explosion_rect(sfRenderWindow *window, game_t *game,
    fight_gui_t *gui)
{
    map_t *map = ((map_t *)(game->guis->map->ui_content));
    item_t *itm = map->inventory->inventory->main_slots[12]->items;

    if (!itm || (itm->weapon->type != NADL && itm->weapon->type != ROCKET_L))
        return;
    sfRenderWindow_drawCircleShape(window, gui->aoe, NULL);
}

void make_fight_gui(sfRenderWindow *window, game_t *game,
    fight_gui_t *gui)
{
    map_t *map = ((map_t *)(game->guis->map->ui_content));

    if (get_pc_index(map->fight->turn_order) == map->fight->fighter) {
        if (map->fight->action == SHOOT && map->fight->fired == false) {
            make_shell_rect(window, game, gui);
            make_explosion_rect(window, game, gui);
            sfRenderWindow_drawVertexArray(window, gui->arr, NULL);
        }
        sfRenderWindow_drawSprite(window, gui->bg->sprite, NULL);
        make_img(gui->dash->img, window);
        draw_weapon_type(window, game, gui);
        make_img(gui->dodge->img, window);
        make_img(gui->done->img, window);
        make_img(gui->mana_img, window);
    }
    make_hp_bar(window, game, gui);
}
