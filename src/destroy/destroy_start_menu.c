/*
** EPITECH PROJECT, 2024
** destroy_main_menu
** File description:
** destroy_main_menu
*/

#include "my.h"

void destroy_button(button_t *button)
{
    destroy_gui_obj(button->gui_obj);
    destroy_label(button->text);
}

void destroy_start_menu(start_t *menu)
{
    destroy_image(menu->background);
    destroy_image(menu->building_one);
    destroy_image(menu->building_two);
    destroy_image(menu->drone);
    for (int i = 0; i < 12; i++)
        destroy_image(menu->clouds[i]);
    destroy_image(menu->hero);
    destroy_gui_obj(menu->nouveau);
    destroy_gui_obj(menu->retour);
    destroy_gui_obj(menu->continues);
    free(menu);
}
