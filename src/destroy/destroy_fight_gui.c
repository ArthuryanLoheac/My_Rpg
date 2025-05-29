/*
** EPITECH PROJECT, 2024
** init_fight_gui
** File description:
** init_fight_gui
*/

#include "my.h"
#include "guis.h"
#include "gui_struct.h"

void destroy_fight_gui(fight_gui_t *gui)
{
    destroy_image(gui->bg);
    destroy_gui_obj(gui->dodge);
    destroy_gui_obj(gui->done);
    destroy_gui_obj(gui->dash);
    destroy_gui_obj(gui->fire);
    destroy_gui_obj(gui->autofire);
    destroy_gui_obj(gui->shell);
    destroy_gui_obj(gui->expl);
    destroy_gui_obj(gui->melee);
    destroy_gui_obj(gui->unarmd);
    destroy_gui_obj(gui->bow);
    sfRectangleShape_destroy(gui->hp_bar);
    free(gui);
}
