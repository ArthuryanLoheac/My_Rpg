/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** a function to analyze a slider
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

sfVector2f get_mouse_pos(sfRenderWindow *window)
{
    return sfRenderWindow_mapPixelToCoords(window,
        sfMouse_getPositionRenderWindow(window),
        sfRenderWindow_getView(window));
}

void analyze_slider(sfRenderWindow *window, sfEvent event,
    gui_slider_t *slider)
{
    analyze_gui_slider(window, &event, slider->cursor);
    slider->mouse_pos = get_mouse_pos(window);
    if (slider->vertical == sfFalse) {
        slider->mouse_pos.y =
            (sfRectangleShape_getPosition(slider->cursor->rect)).y;
    } else {
        slider->mouse_pos.x =
            (sfRectangleShape_getPosition(slider->cursor->rect)).x;
    }
}
