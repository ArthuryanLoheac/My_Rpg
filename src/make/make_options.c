/*
** EPITECH PROJECT, 2024
** make_options
** File description:
** make_options
*/

#include "my.h"
#include "gui_struct.h"

static void make_keybind(label_button_t *to_make, game_t *game)
{
    sfRenderWindow_drawText(game->window, to_make->label->txt, NULL);
    make_img(to_make->change_bind->img, game->window);
}

static void make_keybinds(ui_obj_t *obj, game_t *game)
{
    page_options_t *options = (page_options_t *)obj->ui_content;

    make_keybind(options->keybinds_labels->up, game);
    make_keybind(options->keybinds_labels->down, game);
    make_keybind(options->keybinds_labels->left, game);
    make_keybind(options->keybinds_labels->right, game);
    make_keybind(options->keybinds_labels->interact, game);
    make_keybind(options->keybinds_labels->inventory, game);
    make_keybind(options->keybinds_labels->attack, game);
    make_keybind(options->keybinds_labels->skip, game);
    make_keybind(options->keybinds_labels->progression, game);
}

void make_options(ui_obj_t *obj, game_t *game)
{
    page_options_t *options = (page_options_t *)obj->ui_content;

    make_img(options->background, game->window);
    make_img(options->retour->img, game->window);
    make_button(options->fullscreen, game);
    make_button(options->save, game);
    if (game->music->mute_volume == sfTrue)
        make_button(options->mute_volume, game);
    else
        make_button(options->unmute_volume, game);
    make_button(options->min_resolution, game);
    make_button(options->mid_resolution, game);
    make_button(options->max_resolution, game);
    sfRenderWindow_drawText(game->window, options->music_str->txt, NULL);
    sfRenderWindow_drawText(game->window, options->keybinds_labels->
        keybinds_str->txt, NULL);
    make_img(options->lower_volume->img, game->window);
    make_img(options->greater_volume->img, game->window);
    make_sound(game, options);
    make_keybinds(obj, game);
}
