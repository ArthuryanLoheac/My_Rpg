/*
** EPITECH PROJECT, 2023
** test.c
** File description:
** the function to interact with the window
*/

#include "my.h"

void poll_event(sfRenderWindow *window, sfEvent *event, game_t *game)
{
    if (game->keybinds->wait_for_key != sfFalse) {
        if (event->type == sfEvtClosed)
            close_window(window);
        analyze_guis(game->guis, game);
        return;
    }
    analyze_game(game);
    if (event->type == sfEvtClosed)
        close_window(window);
}
