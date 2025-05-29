/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** a function to detect if an object is hovered
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "../include/my.h"
#include "../include/lib.h"
#include <time.h>
#include <string.h>

sfBool ishover(struct s_gui_object *btn, sfRenderWindow *window)
{
    sfVector2f offset = sfRectangleShape_getOrigin(btn->rect);
    sfVector2f pos = sfRectangleShape_getPosition(btn->rect);
    sfVector2f size = sfRectangleShape_getSize(btn->rect);
    sfVector2f pixcoord = sfRenderWindow_mapPixelToCoords(window,
        sfMouse_getPositionRenderWindow(window), sfRenderWindow_getView(window)
        );

    if (pixcoord.x > pos.x - offset.x && pixcoord.x < pos.x + size.x -
        offset.x && pixcoord.y > pos.y - offset.y && pixcoord.y < pos.y +
        size.y - offset.y + 1)
        return sfTrue;
    return sfFalse;
}
