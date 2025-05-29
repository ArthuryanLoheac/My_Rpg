/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** compute_usual_state
*/

#include "my.h"

void compute_usual_state(gui_obj_t *button)
{
    if (button->state == PRESSED)
        button->img->animate->rect.left = button->img->animate->rect.width * 2;
    else if (button->state == HOVER)
        button->img->animate->rect.left = button->img->animate->rect.width;
    else
        button->img->animate->rect.left = 0;
}
