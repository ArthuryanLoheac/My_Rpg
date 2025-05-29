/*
** EPITECH PROJECT, 2023
** test.c
** File description:
** Bootstrap initiation graphical prog in c
** gcc test.c -lcsfml-graphics
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "../include/my.h"

static void init_context(sfContextSettings *setting)
{
    setting->depthBits = 0;
    setting->stencilBits = 0;
    setting->antialiasingLevel = 0;
    setting->majorVersion = 1;
    setting->minorVersion = 1;
    setting->attributeFlags = 0;
    setting->sRgbCapable = sfFalse;
}

sfRenderWindow *create_window(unsigned int x, unsigned int y,
    assets_t **assets)
{
    sfRenderWindow *window;
    sfVideoMode video_mode;
    sfImage *icon = sfImage_createFromFile(get_asset("RDB_Icon", assets));
    char title[] = "Rust, dust and bust";
    sfContextSettings *setting = malloc(sizeof(sfContextSettings));

    init_context(setting);
    video_mode.bitsPerPixel = 32;
    video_mode.height = y;
    video_mode.width = x;
    window = sfRenderWindow_create(video_mode, title, sfDefaultStyle, setting);
    sfRenderWindow_setFramerateLimit(window, 60);
    sfRenderWindow_setMouseCursorVisible(window, sfTrue);
    sfRenderWindow_setIcon(window, 80, 80, sfImage_getPixelsPtr(icon));
    return window;
}
