/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** a function to set an image
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

static sfIntRect set_rect(int top, int left, int width, int height)
{
    sfIntRect rect;

    rect.top = top;
    rect.left = left;
    rect.width = width;
    rect.height = height;
    return rect;
}

void init_animated_img(img_t *img, int height, int width, sfVector2f position)
{
    img->animate = malloc(sizeof(animated_img_t));
    img->animate->clock_animation = init_time();
    img->animate->clock_intern = init_time();
    img->animate->rect = set_rect(0, 0, width, height);
    img->animate->animation_time = 0.1f;
    img->animate->nb_images = 1;
    img->animate->nb_images_height = 1;
    img->animate->nb_images_width = 1;
    img->animate->status_image = 1;
    sfSprite_setTextureRect(img->sprite, img->animate->rect);
    sfSprite_setPosition(img->sprite, position);
}

img_t *init_image(char *filename, sfVector2f position,
    float scale)
{
    img_t *img = malloc(sizeof(img_t));

    img->sprite = sfSprite_create();
    img->texture = sfTexture_createFromFile(filename, NULL);
    img->animate = NULL;
    img->name = NULL;
    if (img->texture == NULL) {
        fprintf(stderr, "Error finding the asset : %s\n", filename);
        exit(84);
    }
    sfSprite_setPosition(img->sprite, position);
    sfSprite_setTexture(img->sprite, img->texture, sfFalse);
    sfSprite_setScale(img->sprite, (sfVector2f){scale, scale});
    return img;
}
