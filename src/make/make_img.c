/*
** EPITECH PROJECT, 2024
** make_img
** File description:
** make_img
*/

#include "my.h"

void make_img(img_t *image, sfRenderWindow *window)
{
    if (image->animate != NULL)
        sfSprite_setTextureRect(image->sprite, image->animate->rect);
    sfRenderWindow_drawSprite(window, image->sprite, NULL);
}
