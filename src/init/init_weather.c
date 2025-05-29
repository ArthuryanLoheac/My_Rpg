/*
** EPITECH PROJECT, 2024
** init_weather
** File description:
** init_weather
*/

#include "my.h"

weather_t *init_weather(void)
{
    weather_t *data = malloc(sizeof(weather_t));
    sfUint8 *pixels = malloc(480 * 270 * 4 * sizeof(sfUint8));

    if (!pixels)
        exit(84);
    for (int i = 0; i < 480 * 270 * 4; i += 4) {
        pixels[i] = sfTransparent.r;
        pixels[i + 1] = sfTransparent.g;
        pixels[i + 2] = sfTransparent.b;
        pixels[i + 3] = sfTransparent.a;
    }
    data->img = sfImage_createFromPixels(480, 270, pixels);
    free(pixels);
    data->texture = sfTexture_createFromImage(data->img, NULL);
    data->sprite = sfSprite_create();
    sfSprite_setTexture(data->sprite, data->texture, sfTrue);
    sfSprite_setScale(data->sprite, (sfVector2f){4, 4});
    return data;
}
