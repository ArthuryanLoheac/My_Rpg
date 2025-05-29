/*
** EPITECH PROJECT, 2024
** init_map
** File description:
** init_map
*/

#include "my.h"

gui_obj_t *init_gui_obj_img(char *str, sfVector2f pos,
    sfVector2f size, game_t *game)
{
    gui_obj_t *gui = init_gui_obj(pos, size);

    gui->img = init_image(get_asset(str, game->assets), pos, 1);
    init_animated_img(gui->img, size.y, size.x, pos);
    return gui;
}
