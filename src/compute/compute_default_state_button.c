/*
** EPITECH PROJECT, 2024
** compute_default_state_button
** File description:
** compute_default_state_button
*/

#include "my.h"
#include "gui_struct.h"

void compute_default_state_button(button_t *button)
{
    if (button->gui_obj->state == PRESSED) {
        button->gui_obj->img->animate->rect.left =
            button->gui_obj->img->animate->rect.width;
        sfText_setColor(button->text->txt, sfWhite);
    } else if (button->gui_obj->state == HOVER) {
        button->gui_obj->img->animate->rect.left =
            button->gui_obj->img->animate->rect.width * 2;
        sfText_setColor(button->text->txt, sfWhite);
    } else {
        button->gui_obj->img->animate->rect.left = 0;
        sfText_setColor(button->text->txt, ORANGE);
    }
}
