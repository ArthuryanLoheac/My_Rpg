/*
** EPITECH PROJECT, 2024
** compute_animation_img
** File description:
** compute_animation_img
*/

#include "my.h"

void move_rect(animated_img_t *image, bool restart_top)
{
    image->rect.left += image->rect.width;
    image->status_image += 1;
    if (image->rect.left >= (image->rect.width) * image->nb_images_width) {
        image->rect.left = 0;
        if (restart_top == true)
            image->rect.top += image->rect.height;
    }
    if (image->status_image >= image->nb_images && restart_top == true) {
        image->rect.left = 0;
        image->rect.top = 0;
        image->status_image = 0;
    } else if (image->status_image >= image->nb_images &&
        restart_top == false) {
        image->rect.left = 0;
        image->status_image = 0;
    }
}

void compute_animation_img(animated_img_t *image, bool restart_top)
{
    update_time(image->clock_animation);
    if (image->clock_animation->seconds > image->animation_time) {
        move_rect(image, restart_top);
        sfClock_restart(image->clock_animation->clock);
        image->clock_animation->seconds = 0;
    }
}
