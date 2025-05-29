/*
** EPITECH PROJECT, 2024
** make_options
** File description:
** make_options
*/

#include "my.h"
#include "gui_struct.h"

void make_label(label_t *label, sfRenderWindow *window)
{
    sfRenderWindow_drawText(window, label->txt, NULL);
}

void make_final_page(ui_obj_t *obj, game_t *game)
{
    page_final_t *options = (page_final_t *)obj->ui_content;

    make_img(options->background, game->window);
    make_img(options->valider->img, game->window);
    make_button(options->female, game);
    make_button(options->male, game);
    make_label(options->title, game->window);
    make_label(options->name_txt, game->window);
    make_label(options->title_name, game->window);
    sfRenderWindow_drawText(game->window, options->recap->Class->txt, NULL);
    sfRenderWindow_drawText(game->window, options->recap->Title->txt, NULL);
    sfRenderWindow_drawText(game->window, options->recap->line->txt, NULL);
    sfRenderWindow_drawText(game->window, options->recap->shop->txt, NULL);
    for (int i = 0; i < 20; i++)
        sfRenderWindow_drawText(game->window,
            options->recap->Inventory[i]->txt, NULL);
}
