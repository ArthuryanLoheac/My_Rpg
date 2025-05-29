/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** a function to display a slider
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

void make_slider(sfRenderWindow *window, gui_slider_t *slider, sfColor color)
{
    sfRenderWindow_drawRectangleShape(window, slider->background, sfFalse);
    make_gui_obj(window, slider->cursor, color);
}
