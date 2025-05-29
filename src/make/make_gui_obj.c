/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** a function to display a button
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

void make_gui_obj(sfRenderWindow *window, struct s_gui_object *obj, sfColor
    color)
{
    sfRectangleShape_setFillColor(obj->rect, color);
    sfRectangleShape_setOutlineThickness(obj->rect, 0);
    if (obj->state == HOVER) {
        sfRectangleShape_setFillColor(obj->rect, sfTransparent);
        if (obj->outline == sfTrue)
            sfRectangleShape_setOutlineThickness(obj->rect, 2);
    }
    if (obj->state == PRESSED)
        sfRectangleShape_setFillColor(obj->rect, sfTransparent);
    sfRenderWindow_drawRectangleShape(window, obj->rect, sfFalse);
    if (obj->img != NULL)
        sfRenderWindow_drawSprite(window, obj->img->sprite, NULL);
    if (obj->label != NULL)
        sfRenderWindow_drawText(window, obj->label->txt, sfFalse);
}
