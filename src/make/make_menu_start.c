/*
** EPITECH PROJECT, 2024
** make_menu_start
** File description:
** make_menu_start
*/

#include "my.h"

void make_menu_main(ui_obj_t *obj, game_t *game)
{
    main_t *main_menu = (main_t *)obj->ui_content;

    make_img(main_menu->background, game->window);
    make_img(main_menu->drone, game->window);
    for (int i = 0; i < 12; i++)
        make_img(main_menu->clouds[i], game->window);
    make_img(main_menu->building_one, game->window);
    make_img(main_menu->hero, game->window);
    make_img(main_menu->building_two, game->window);
    make_img(main_menu->play->img, game->window);
    make_img(main_menu->settings->img, game->window);
    make_img(main_menu->quit->img, game->window);
    make_img(main_menu->logo, game->window);
}

static void define_transparence(game_t *game, gui_obj_t *continues)
{
    if (game->savefile == -1) {
        sfSprite_setColor(continues->img->sprite,
            sfColor_fromRGBA(255, 255, 255, 128));
    } else {
        sfSprite_setColor(continues->img->sprite, sfWhite);
    }
}

void make_button(button_t *button, game_t *game)
{
    make_img(button->gui_obj->img, game->window);
    sfRenderWindow_drawText(game->window, button->text->txt, NULL);
}

void make_menu_start(ui_obj_t *obj, game_t *game)
{
    start_t *main_menu = (start_t *)obj->ui_content;

    make_img(main_menu->background, game->window);
    make_img(main_menu->drone, game->window);
    for (int i = 0; i < 12; i++)
        make_img(main_menu->clouds[i], game->window);
    make_img(main_menu->building_one, game->window);
    make_img(main_menu->hero, game->window);
    make_img(main_menu->building_two, game->window);
    define_transparence(game, main_menu->continues);
    make_img(main_menu->continues->img, game->window);
    make_img(main_menu->nouveau->img, game->window);
    make_img(main_menu->retour->img, game->window);
    make_img(main_menu->logo, game->window);
}
