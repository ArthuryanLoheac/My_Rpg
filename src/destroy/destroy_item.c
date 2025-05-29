/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** a function to create a button
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

void destroy_item(item_t *item)
{
    if (item->name)
        free(item->name);
    if (item->desc)
        free(item->desc);
    destroy_image(item->icon);
    if (item->background)
        destroy_image(item->background);
    if (item)
        free(item);
}
