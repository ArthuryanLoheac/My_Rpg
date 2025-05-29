/*
** EPITECH PROJECT, 2024
** make_options
** File description:
** make_options
*/

#include "my.h"
#include "gui_struct.h"

static void make_class(class_choose_t *class, game_t *game)
{
    make_img(class->Valider->img, game->window);
    make_img(class->logo, game->window);
    sfRenderWindow_drawText(game->window, class->Title->txt, NULL);
    sfRenderWindow_drawText(game->window, class->Description->txt,
        NULL);
}

void make_choose_class(ui_obj_t *obj, game_t *game)
{
    page_choose_class_t *options = (page_choose_class_t *)obj->ui_content;

    make_img(options->background, game->window);
    make_class(options->Class_one, game);
    make_class(options->Class_two, game);
    make_class(options->Class_three, game);
    sfRenderWindow_drawText(game->window, options->title->txt, NULL);
}
