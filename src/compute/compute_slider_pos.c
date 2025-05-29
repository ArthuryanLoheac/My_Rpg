/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** a function to analyze the color selection tool
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "../../include/my.h"
#include "../../include/lib.h"
#include <time.h>
#include <string.h>

void set_slider_pos_vertical(gui_slider_t *slider, int value)
{
    sfVector2f pos = sfRectangleShape_getPosition(slider->cursor->rect);
    sfVector2f min = sfRectangleShape_getPosition(slider->background);

    value = 255 - value;
    sfRectangleShape_setPosition(slider->cursor->rect, (sfVector2f){pos.x,
        min.y + (value / slider->value_per_pixel)});
}

void set_slider_pos(gui_slider_t *slider, int value)
{
    sfVector2f pos = sfRectangleShape_getPosition(slider->cursor->rect);
    sfVector2f min = sfRectangleShape_getPosition(slider->background);

    sfRectangleShape_setPosition(slider->cursor->rect, (sfVector2f){min.x +
    (value / slider->value_per_pixel), pos.y});
}

float get_slider_pos_vertical(gui_slider_t *slider)
{
    sfVector2f pos = sfRectangleShape_getPosition(slider->cursor->rect);
    sfVector2f min = sfRectangleShape_getPosition(slider->background);

    return (pos.y - min.y) * slider->value_per_pixel;
}

float get_slider_pos(gui_slider_t *slider)
{
    sfVector2f pos = sfRectangleShape_getPosition(slider->cursor->rect);
    sfVector2f min = sfRectangleShape_getPosition(slider->background);

    return pos.x - min.x;
}
