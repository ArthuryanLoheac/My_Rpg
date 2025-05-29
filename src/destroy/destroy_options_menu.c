/*
** EPITECH PROJECT, 2024
** destroy_main_menu
** File description:
** destroy_main_menu
*/

#include "my.h"

static void free_set_keybinds(label_button_t *to_free)
{
    destroy_label(to_free->label);
    destroy_gui_obj(to_free->change_bind);
    free(to_free);
}

static void destroy_keybinds(page_options_t *menu)
{
    free_set_keybinds(menu->keybinds_labels->up);
    free_set_keybinds(menu->keybinds_labels->down);
    free_set_keybinds(menu->keybinds_labels->left);
    free_set_keybinds(menu->keybinds_labels->right);
    free_set_keybinds(menu->keybinds_labels->attack);
    free_set_keybinds(menu->keybinds_labels->inventory);
    free_set_keybinds(menu->keybinds_labels->interact);
    free_set_keybinds(menu->keybinds_labels->skip);
    free_set_keybinds(menu->keybinds_labels->progression);
    destroy_label(menu->keybinds_labels->keybinds_str);
    free(menu->keybinds_labels);
}

void destroy_options_menu(page_options_t *menu)
{
    destroy_gui_obj(menu->retour);
    destroy_button(menu->fullscreen);
    destroy_gui_obj(menu->greater_volume);
    destroy_gui_obj(menu->lower_volume);
    destroy_button(menu->mute_volume);
    destroy_button(menu->unmute_volume);
    destroy_image(menu->background);
    destroy_label(menu->music_str);
    destroy_button(menu->save);
    destroy_keybinds(menu);
    destroy_button(menu->min_resolution);
    destroy_button(menu->mid_resolution);
    destroy_button(menu->max_resolution);
    free(menu);
}
