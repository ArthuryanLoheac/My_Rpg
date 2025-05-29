/*
** EPITECH PROJECT, 2024
** My_Rpg
** File description:
** compute_buttons_escape
*/

#include "my.h"

static void update_pos_label(label_t *button, game_t *game, int x, int y)
{
    sfVector2f pos = sfView_getCenter(sfRenderWindow_getView(game->window));
    sfVector2f diff = {pos.x + 60, pos.y + 35};

    pos.x += x;
    pos.y += y;
    diff.x += x;
    diff.y += y;
    sfText_setPosition(button->txt, diff);
}

static void update_pos_gui(gui_obj_t *button, game_t *game, int x, int y)
{
    sfVector2f pos = sfView_getCenter(sfRenderWindow_getView(game->window));

    pos.x += x;
    pos.y += y;
    sfRectangleShape_setPosition(button->rect, pos);
    sfSprite_setPosition(button->img->sprite, pos);
}

static void compute_txt(map_t *map, game_t *game)
{
    stats_t *player = game->player->stats;
    level_up_menu_t *lev = map->level_menu;
    char str[200];

    sprintf(str, "+ 1 Move (actual : %d)", player->MOVE);
    sfText_setString(lev->Move_txt->txt, str);
    sprintf(str, "+ 1 Technology (actual : %d)", player->TECH);
    sfText_setString(lev->Tech_txt->txt, str);
    sprintf(str, "+ 1 Will (actual : %d)", player->WILL);
    sfText_setString(lev->Will_txt->txt, str);
    sprintf(str, "+ 1 Body (actual : %d)", player->BODY);
    sfText_setString(lev->Body_txt->txt, str);
    sprintf(str, "+ 1 Reflexes (actual : %d)", player->REF);
    sfText_setString(lev->REF_txt->txt, str);
    sprintf(str, "+ 1 Dexterity (actual : %d)", player->DEX);
    sfText_setString(lev->Dexterity_txt->txt, str);
    sprintf(str, "+ 1 Empathy (actual : %d)", player->EMP);
    sfText_setString(lev->EMP_txt->txt, str);
    sprintf(str, "+ 1 Luck (actual : %d)", player->LUCK);
    sfText_setString(lev->LUCK_txt->txt, str);
}

void compute_buttons_level(map_t *map, game_t *game)
{
    compute_button_state_level(map, game);
    compute_txt(map, game);
    update_pos_label(map->level_menu->title, game, -700, -(1080 / 2) + 50);
    update_pos_gui(map->level_menu->Move, game, -200, 100);
    update_pos_label(map->level_menu->Move_txt, game, -200, 90);
    update_pos_gui(map->level_menu->Tech, game, -200, 200);
    update_pos_label(map->level_menu->Tech_txt, game, -200, 190);
    update_pos_gui(map->level_menu->Will, game, -200, 300);
    update_pos_label(map->level_menu->Will_txt, game, -200, 290);
    update_pos_gui(map->level_menu->Body, game, -200, 400);
    update_pos_label(map->level_menu->Body_txt, game, -200, 390);
    update_pos_gui(map->level_menu->REF, game, -200, -300);
    update_pos_label(map->level_menu->REF_txt, game, -200, -310);
    update_pos_gui(map->level_menu->Dexterity, game, -200, -200);
    update_pos_label(map->level_menu->Dexterity_txt, game, -200, -210);
    update_pos_gui(map->level_menu->EMP, game, -200, -100);
    update_pos_label(map->level_menu->EMP_txt, game, -200, -110);
    update_pos_gui(map->level_menu->LUCK, game, -200, 0);
    update_pos_label(map->level_menu->LUCK_txt, game, -200, -10);
}
