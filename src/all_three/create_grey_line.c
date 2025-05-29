/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** a function to initialize the grey line separating each selection category
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

sfRectangleShape *create_grey_line(int x, int y)
{
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setPosition(rect, (sfVector2f){x, y});
    sfRectangleShape_setSize(rect, (sfVector2f){6, 100});
    sfRectangleShape_setFillColor(rect, SEPARATE_GREY);
    return rect;
}
