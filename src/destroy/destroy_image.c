/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** a function to destroy an image
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

static void destroy_animate(animated_img_t *animate)
{
    destroy_time(animate->clock_animation);
    destroy_time(animate->clock_intern);
    free(animate);
}

void destroy_image(img_t *img)
{
    if (img && img->texture)
        sfTexture_destroy(img->texture);
    if (img && img->sprite)
        sfSprite_destroy(img->sprite);
    if (img && img->animate != NULL)
        destroy_animate(img->animate);
    if (img)
        free(img);
}
