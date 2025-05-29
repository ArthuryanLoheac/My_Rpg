/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** a function to set an outline to a gui object
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

void init_obj_outline(struct s_gui_object *obj, sfColor color)
{
    sfRectangleShape_setOutlineColor(obj->rect, color);
    sfRectangleShape_setOutlineThickness(obj->rect, 0);
    obj->outline = sfTrue;
}
