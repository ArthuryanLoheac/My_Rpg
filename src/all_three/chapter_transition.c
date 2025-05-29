/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** the function to get the input from the terminal
*/

#include "my.h"

static void destroy_chapter_transition(time2_t *clock, label_t *txt,
    label_t *txt2)
{
    destroy_time(clock);
    destroy_label(txt);
    destroy_label(txt2);
}

static void transition_loop(game_t *game, time2_t *clock, label_t *txt,
    label_t *txt2)
{
    sfEvent temp;

    sfRenderWindow_clear(game->window, sfBlack);
    if (clock->seconds > 1.5)
        sfRenderWindow_drawText(game->window, txt->txt, NULL);
    if (clock->seconds > 3)
        sfRenderWindow_drawText(game->window, txt2->txt, NULL);
    sfRenderWindow_display(game->window);
    update_time(clock);
    while (sfRenderWindow_pollEvent(game->window, &temp));
}

static void init_chapter_transition_pos(game_t *game, label_t *txt,
    sfFloatRect rect)
{
    sfView_setCenter(((map_t *)game->guis->map->ui_content)->view,
        (sfVector2f){960, 540});
    sfRenderWindow_setView(game->window,
        ((map_t *)game->guis->map->ui_content)->view);
    sfText_setOrigin(txt->txt, (sfVector2f){rect.width / 2, rect.height / 2});
}

void chapter_transition(game_t *game, char *title, char *text, sfColor color)
{
    time2_t *clock = init_time();
    label_t *txt = init_label(title, (sfVector2f){960, 480}, 90, get_asset(
        "Font_pixel", game->assets));
    label_t *txt2 = init_label(text, (sfVector2f){960, 640}, 90, get_asset(
        "Font_pixel", game->assets));
    sfFloatRect rect = sfText_getGlobalBounds(txt->txt);
    sfFloatRect rect2 = sfText_getGlobalBounds(txt2->txt);

    init_chapter_transition_pos(game, txt, rect);
    sfText_setColor(txt->txt, color);
    sfText_setColor(txt2->txt, color);
    init_chapter_transition_pos(game, txt, rect);
    sfText_setOrigin(txt2->txt, (sfVector2f)
        {rect2.width / 2, rect2.height / 2});
    while (clock->seconds < 5)
        transition_loop(game, clock, txt, txt2);
    destroy_chapter_transition(clock, txt, txt2);
    ((map_t *)(game->guis->map->ui_content))->view =
        init_startview(game->window);
    ((map_t *)(game->guis->map->ui_content))->fade->is_active = true;
}
