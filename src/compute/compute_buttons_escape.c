/*
** EPITECH PROJECT, 2024
** My_Rpg
** File description:
** compute_buttons_escape
*/

#include "my.h"

static void update_pos_button(button_t *button, game_t *game, int x, int y)
{
    sfVector2f pos = sfView_getCenter(sfRenderWindow_getView(game->window));
    sfVector2f diff = {pos.x + (110 - ((strlen(sfText_getString(
        button->text->txt)) - 4) * 15)), pos.y + 35};

    pos.x += x;
    pos.y += y;
    diff.x += x;
    diff.y += y;
    sfRectangleShape_setPosition(button->gui_obj->rect, pos);
    sfSprite_setPosition(button->gui_obj->img->sprite, pos);
    sfText_setPosition(button->text->txt, diff);
}

static void update_pos_gui(gui_obj_t *button, game_t *game, int x, int y)
{
    sfVector2f pos = sfView_getCenter(sfRenderWindow_getView(game->window));

    pos.x += x;
    pos.y += y;
    sfRectangleShape_setPosition(button->rect, pos);
    sfSprite_setPosition(button->img->sprite, pos);
}

void compute_buttons_escape(map_t *map, game_t *game)
{
    compute_button_state_escape(map, game);
    map = game->guis->map->ui_content;
    update_pos_button(map->escape_menu->save, game, -140, 0);
    update_pos_button(map->escape_menu->load, game, -140, -100);
    update_pos_button(map->escape_menu->main_menu, game, -140, 100);
    update_pos_gui(map->escape_menu->quit, game, -140, 200);
    update_pos_gui(map->escape_menu->options, game, -140, -200);
}
