/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** a function to create a drop menu
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "../../include/my.h"
#include "../../include/lib.h"
#include <time.h>
#include <string.h>

static void fill_drop_menu(gui_opt_t *option_ptr,
    sfVector2f *pos_size, char **labels, assets_t **assets)
{
    unsigned int index = 1;
    sfVector2f pos = pos_size[0];
    sfVector2f size = pos_size[1];

    while (option_ptr != NULL) {
        pos.y += size.y;
        option_ptr->option->label = init_label(labels[index], (sfVector2f){
            pos.x + 14 - my_strlen(labels[index]), pos.y + 7}, 10,
                get_asset("Font_pixel", assets));
        index++;
        option_ptr = option_ptr->next;
    }
}

gui_drp_t *init_drop_menu(sfVector2f *pos_size,
    int option_number, char **labels, assets_t **assets)
{
    gui_drp_t *menu = malloc(sizeof(gui_drp_t));
    sfVector2f pos = pos_size[0];
    sfVector2f size = pos_size[1];

    menu->button = init_gui_obj(pos, size);
    menu->button->label = init_label(labels[0], (sfVector2f){pos.x + 14, pos.y
        + 5}, 16, get_asset("Font_pixel", assets));
    menu->options = NULL;
    for (int i = 0; i != option_number; i++) {
        pos.y += size.y * (i + 1);
        add_option_drop_menu(menu, init_gui_obj(pos, size));
        pos.y -= size.y * (i + 1);
    }
    fill_drop_menu(menu->options, pos_size, labels, assets);
    return menu;
}
