/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** a function to create a slider
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

gui_slider_t *init_slider(sfVector2f pos, sfVector2f size,
    float value_per_pixel, sfBool vertical)
{
    gui_slider_t *slider = malloc(sizeof(gui_slider_t));

    if (vertical == sfFalse)
        slider->cursor = init_gui_obj((sfVector2f){pos.x + (size.x / 2), pos.y
            + 3}, (sfVector2f){10, 14});
    else
        slider->cursor = init_gui_obj((sfVector2f){pos.x + (size.x / 2), pos.y
            }, (sfVector2f){10, 14});
    sfRectangleShape_setOrigin(slider->cursor->rect, (sfVector2f){5, 7});
    init_obj_outline(slider->cursor, SEPARATE_GREY);
    slider->value_per_pixel = value_per_pixel;
    slider->vertical = vertical;
    slider->background = sfRectangleShape_create();
    sfRectangleShape_setPosition(slider->background, pos);
    sfRectangleShape_setSize(slider->background, size);
    sfRectangleShape_setFillColor(slider->background, SEPARATE_GREY);
    return slider;
}
