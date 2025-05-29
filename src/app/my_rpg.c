/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** the main file
*/

#include "my.h"

int my_rpg(sfEvent *event)
{
    game_t *game = init_game(event);

    splash_screen(game);
    while (sfRenderWindow_isOpen(game->window)) {
        sfRenderWindow_clear(game->window, get_bg_color(game));
        while (sfRenderWindow_pollEvent(game->window, event)) {
            poll_event(game->window, event, game);
        }
        compute_game(game);
        make_game(game);
        sfRenderWindow_display(game->window);
    }
    save_data(game);
    destroy_game(game);
    return 0;
}
