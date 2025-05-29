/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** the main file
*/

#include "my.h"

static void display_splash_screen(game_t *game, sfSprite *sprite,
    sfSprite *sprite2, label_t *label)
{
    sfRenderWindow_clear(game->window, sfBlack);
    sfRenderWindow_drawSprite(game->window, sprite2, NULL);
    sfRenderWindow_drawSprite(game->window, sprite, NULL);
    sfRenderWindow_drawText(game->window, label->txt, NULL);
    sfRenderWindow_display(game->window);
}

static void destroy_and_clear(sfSprite *sprite,
    sfTexture *texture, game_t *game)
{
    sfRenderWindow_clear(game->window, sfColor_fromRGBA(121, 183, 193, 255));
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
}

static void init_two(splash_screen_t *splash_screen)
{
    sfSprite_setTexture(splash_screen->sprite2, splash_screen->texture2, 1);
    sfSprite_setTexture(splash_screen->sprite3, splash_screen->texture3, 1);
    sfSprite_scale(splash_screen->sprite3, (sfVector2f){1.6, 1.6});
    sfSprite_scale(splash_screen->sprite2, (sfVector2f){1.6, 1.6});
    sfSprite_setTexture(splash_screen->sprite, splash_screen->texture, 1);
    sfSprite_scale(splash_screen->sprite, (sfVector2f){2, 2});
    sfSprite_setPosition(splash_screen->sprite, splash_screen->pos);
    sfSprite_setPosition(splash_screen->sprite3, (sfVector2f){-20, 0});
}

static splash_screen_t *init_splash_screen(game_t *game)
{
    splash_screen_t *splash_screen = malloc(sizeof(splash_screen_t));

    splash_screen->sprite = sfSprite_create();
    splash_screen->sprite2 = sfSprite_create();
    splash_screen->sprite3 = sfSprite_create();
    splash_screen->clock = sfClock_create();
    splash_screen->pos = (sfVector2f){1920 / 2 - 150, 1080 / 2 - 250};
    splash_screen->label = init_label("Barely Ok Games .ltd", (sfVector2f)
        {10000, 10000}, 30, "./font/pixel.ttf");
    splash_screen->texture = sfTexture_createFromFile(get_asset("RDB_Logo2",
        game->assets), NULL);
    splash_screen->texture2 = sfTexture_createFromFile(get_asset(
        "SPLASH_SCREEN_BG", game->assets), NULL);
    splash_screen->texture3 = sfTexture_createFromFile(get_asset(
        "SPLASH_SCREEN", game->assets), NULL);
    splash_screen->background = splash_screen->sprite2;
    init_two(splash_screen);
    return splash_screen;
}

static void change_opacity_and_position(game_t *game, int *y, int *opacity)
{
    *opacity = ((sfTime_asSeconds(sfClock_getElapsedTime(game->splash_screen
        ->clock))) / 2500 * 255 * 1000);
    *y = ((sfTime_asSeconds(sfClock_getElapsedTime(game->splash_screen->
        clock))) / 2500 * 400 * 1000);
    if (*y > 400)
        *y = 400;
    if (*opacity > 255)
        *opacity = 255;
}

static void following(game_t *game, int *y, int *opacity)
{
    display_splash_screen(game, game->splash_screen->sprite,
        game->splash_screen->background, game->splash_screen->label);
    change_opacity_and_position(game, y, opacity);
    sfText_setPosition(game->splash_screen->label->txt, (sfVector2f)
        {720, 940 + 400 - *y});
    sfSprite_setColor(game->splash_screen->sprite,
        sfColor_fromRGBA(255, 255, 255, *opacity));
}

static void update_color_splash(game_t *game)
{
    sfUint8 alpha_color = 255 * fmax(0, sin(sfTime_asSeconds(
        sfClock_getElapsedTime(game->splash_screen->clock))));

    sfSprite_setColor(game->splash_screen->sprite3, (sfColor){255, 255,
        255, alpha_color});
    if (sfTime_asSeconds(sfClock_getElapsedTime(game->
        splash_screen->clock)) > 3.) {
        sfSprite_setColor(game->splash_screen->sprite2, (sfColor){255, 255,
            255, alpha_color});
        sfSprite_setColor(game->splash_screen->sprite, (sfColor){255, 255,
            255, alpha_color});
        sfText_setColor(game->splash_screen->label->txt, (sfColor){255, 255,
            255, alpha_color});
    }
}

void splash_screen(game_t *game)
{
    int opacity = 0;
    int y = 0;

    game->splash_screen = init_splash_screen(game);
    game->splash_screen->background = game->splash_screen->sprite2;
    sfClock_restart(game->splash_screen->clock);
    sfSprite_setColor(game->splash_screen->sprite, sfColor_fromRGBA
    (255, 255, 255, 0));
    while (sfTime_asMilliseconds(sfClock_getElapsedTime(game->splash_screen->
        clock)) < 4000) {
        update_color_splash(game);
        if ((int)(sfTime_asSeconds(sfClock_getElapsedTime(
            game->splash_screen->clock)) * 1000 / 400) % 2 == 0)
                game->splash_screen->background = game->splash_screen->sprite2;
        else
            game->splash_screen->background = game->splash_screen->sprite3;
        following(game, &y, &opacity);
    }
    destroy_and_clear(game->splash_screen->sprite, game->splash_screen->
        texture, game);
}
