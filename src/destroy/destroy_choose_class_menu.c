/*
** EPITECH PROJECT, 2024
** destroy_main_menu
** File description:
** destroy_main_menu
*/

#include "my.h"

void destroy_choose_class_menu(page_choose_class_t *menu)
{
    destroy_gui_obj(menu->Class_one->Valider);
    destroy_gui_obj(menu->Class_three->Valider);
    destroy_gui_obj(menu->Class_two->Valider);
    free(menu);
}
