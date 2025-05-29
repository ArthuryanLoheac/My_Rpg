/*
** EPITECH PROJECT, 2024
** change window
** File description:
** change window
*/

#include "my.h"

static sfUint32 window_conditions(game_t *game, bool change)
{
    bool is_changed = false;
    sfUint32 style;

    if (game->window_state == sfFullscreen && change == true) {
        style = sfDefaultStyle | sfResize | sfClose;
        game->window_state = sfDefaultStyle;
        is_changed = true;
    }
    if (!is_changed && game->window_state == sfDefaultStyle
        && change == true) {
        style = sfFullscreen | sfResize | sfClose;
        game->window_state = sfFullscreen;
    }
    if (change == false && game->window_state == sfFullscreen) {
        style = sfFullscreen | sfResize | sfClose;
    } else if (change == false && game->window_state == sfDefaultStyle)
        style = sfDefaultStyle | sfResize | sfClose;
    return style;
}

void change_window(game_t *game, bool change)
{
    char title[] = "Rust, dust and bust";
    sfUint32 style;
    sfImage *icon = sfImage_createFromFile(get_asset("RDB_Icon",
        game->assets));

    sfRenderWindow_close(game->window);
    sfRenderWindow_destroy(game->window);
    style = window_conditions(game, change);
    game->window = sfRenderWindow_create(game->video_mode, title, style, NULL);
    sfRenderWindow_setFramerateLimit(game->window, 60);
    sfRenderWindow_setMouseCursorVisible(game->window, sfTrue);
    sfRenderWindow_setView(game->window, game->view);
    sfRenderWindow_setIcon(game->window, 80, 80, sfImage_getPixelsPtr(icon));
}
