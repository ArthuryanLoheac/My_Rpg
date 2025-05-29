/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** the function to get the input from the terminal
*/

#include "my.h"

img_t *dup_image(img_t *img)
{
    img_t *new = malloc(sizeof(img_t));

    new->sprite = sfSprite_copy(img->sprite);
    new->texture = sfTexture_copy(img->texture);
    new->animate = NULL;
    return new;
}
