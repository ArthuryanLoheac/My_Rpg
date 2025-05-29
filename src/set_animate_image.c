/*
** EPITECH PROJECT, 2024
** set_animate_image
** File description:
** set_animate_image
*/

#include "my.h"

void set_animate_image(img_t *image,
    int nb_image, int height, int width)
{
    image->animate->nb_images = nb_image;
    image->animate->nb_images_height = height;
    image->animate->nb_images_width = width;
    image->animate->animation_time = 0.12f;
}
