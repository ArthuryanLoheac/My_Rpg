/*
** EPITECH PROJECT, 2024
** init_view
** File description:
** init_view
*/

#include "my.h"

sfView *init_view(sfRenderWindow *window)
{
    sfView *view = sfView_create();

    sfView_setCenter(view, (sfVector2f){960, 540});
    sfView_setSize(view, (sfVector2f){1920, 1080});
    sfRenderWindow_setView(window, view);
    return view;
}

sfView *init_startview(sfRenderWindow *window)
{
    sfView *view = sfView_create();

    sfView_setCenter(view, (sfVector2f){17000, 10500});
    sfView_setSize(view, (sfVector2f){1920, 1080});
    sfRenderWindow_setView(window, view);
    return view;
}

sfView *init_continueview(sfRenderWindow *window, sfVector2f player_pos,
    game_t *game)
{
    sfView *view = sfView_create();

    (void) game;
    player_pos.x += 1000;
    player_pos.y += 1000;
    sfView_setCenter(view, player_pos);
    sfView_setSize(view, (sfVector2f){1920, 1080});
    sfRenderWindow_setView(window, view);
    return view;
}
