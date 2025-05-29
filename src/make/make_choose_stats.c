/*
** EPITECH PROJECT, 2024
** make_options
** File description:
** make_options
*/

#include "my.h"
#include "gui_struct.h"

static void make_line(line_stats_t *line, game_t *game)
{
    make_img(line->Moins->img, game->window);
    make_img(line->Plus->img, game->window);
    sfRenderWindow_drawText(game->window, line->Name->txt, NULL);
    sfRenderWindow_drawText(game->window, line->value->txt, NULL);
}

static void make_recap(recap_t *recap, game_t *game)
{
    sfRenderWindow_drawText(game->window, recap->Title->txt, NULL);
    sfRenderWindow_drawText(game->window, recap->Class->txt, NULL);
}

void make_choose_stats(ui_obj_t *obj, game_t *game)
{
    page_choose_stats_t *options = (page_choose_stats_t *)obj->ui_content;

    make_img(options->background, game->window);
    sfRenderWindow_drawText(game->window, options->title->txt, NULL);
    sfRenderWindow_drawText(game->window, options->Pts_restant->txt, NULL);
    sfRenderWindow_drawText(game->window, options->line->txt, NULL);
    make_img(options->Valider->img, game->window);
    make_line(options->DEX, game);
    make_line(options->MOVE, game);
    make_line(options->TECH, game);
    make_line(options->BODY, game);
    make_line(options->WILL, game);
    make_line(options->REF, game);
    make_line(options->LUCK, game);
    make_line(options->EMP, game);
    make_recap(options->recap, game);
}
