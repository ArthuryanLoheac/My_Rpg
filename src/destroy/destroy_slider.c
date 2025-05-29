/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** a function to destroy a slider
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

void destroy_slider(gui_slider_t *slider)
{
    sfRectangleShape_destroy(slider->background);
    destroy_gui_obj(slider->cursor);
    free(slider);
}
