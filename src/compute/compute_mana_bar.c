/*
** EPITECH PROJECT, 2024
** mana bar
** File description:
** compute_mana_bar
*/

/*
** EPITECH PROJECT, 2024
** compute_health_bar
** File description:
** compute_health_bar
*/

#include "my.h"

void compute_mana_bar(fight_t *fight)
{
    float frame = 0.0;
    float x = (float)fight->dep_mouv.x;
    float y = (float)fight->dep_mouv.y;

    if (x < 0)
        x = 0;
    if (y < 0)
        y = 0;
    if (x > y) {
        x -= y;
        sfSprite_setColor(fight->gui->mana_img->sprite, sfRed);
    } else
        sfSprite_setColor(fight->gui->mana_img->sprite, sfWhite);
    frame = round((x / y) *
        (float)fight->gui->mana_img->animate->nb_images);
    if (frame > (float)fight->gui->mana_img->animate->nb_images)
        frame = (float)fight->gui->mana_img->animate->nb_images;
    fight->gui->mana_img->animate->rect.top = frame *
        fight->gui->mana_img->animate->rect.height;
}
