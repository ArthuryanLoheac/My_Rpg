/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** a function to display a message
*/

#include "my.h"

void make_info(sfRenderWindow *window, info_t *info)
{
    if (info->clock != NULL) {
            make_img(info->background, window);
            if (info->label && info->label->txt)
                sfRenderWindow_drawText(window, info->label->txt, NULL);
    }
}
