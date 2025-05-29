/*
** EPITECH PROJECT, 2024
** create_weather
** File description:
** compute_weather
*/

#include "my.h"

static void move_rain_pixel(map_t *map, int x, int y)
{
    sfColor color = (sfColor){0, 0, 0, 255};

    color = sfImage_getPixel(map->weather->img, x, y);
    if (is_same_color(color, RAIN)) {
        sfImage_setPixel(map->weather->img, x, y, sfTransparent);
        if (y < 263)
            sfImage_setPixel(map->weather->img, x, y + 3, RAIN);
    }
}

static void move_rain_parse(map_t *map)
{
    for (int x = 0; x < 475; x++)
        for (int y = 269; y >= 0; y--)
            move_rain_pixel(map, x, y);
}

static void create_rain_pixel(map_t *map, int x)
{
    sfImage_setPixel(map->weather->img, x, 0, RAIN);
}

static void create_rain_parse(map_t *map)
{
    for (int x = 0; x < 480; x++)
        if ((rand() % 100) == 50)
            create_rain_pixel(map, x);
}

static void remove_usless_rain(map_t *map, int x, int y)
{
    sfColor color = (sfColor){0, 0, 0, 255};

    color = sfImage_getPixel(map->weather->img, x, y);
    if ((rand() % 100) == 50)
        if (is_same_color(color, RAIN))
            sfImage_setPixel(map->weather->img, x, y, sfTransparent);
}

static void remove_usless_rain_parse(map_t *map)
{
    for (int x = 0; x < 475; x++)
        for (int y = 269; y >= 0; y--)
            remove_usless_rain(map, x, y);
}

void compute_weather(map_t *map)
{
    static int time_rain_start = -1;
    static int rain_duration = 60;
    sfVector2f pos_screen = (sfVector2f){sfView_getCenter(map->view).x - 960,
        sfView_getCenter(map->view).y - 540};

    if (map->night->clock->seconds >= 3000) {
        map->night->clock->seconds = 0;
        time_rain_start = -1;
    }
    if (time_rain_start == -1)
        time_rain_start = rand() % 2940;
    if (map->night->clock->seconds >= time_rain_start &&
        map->night->clock->seconds < time_rain_start + rain_duration)
        create_rain_parse(map);
    move_rain_parse(map);
    remove_usless_rain_parse(map);
    sfTexture_updateFromImage(map->weather->texture, map->weather->img, 0, 0);
    sfSprite_setPosition(map->weather->sprite, pos_screen);
}
