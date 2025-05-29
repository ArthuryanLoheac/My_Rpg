/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** a function to display a drop_menu
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

void make_drop_menu(sfRenderWindow *window, struct s_gui_drop_menu *drop_menu)
{
    struct s_gui_options *list_ptr = (drop_menu->options);

    make_gui_obj(window, drop_menu->button, GREY_BAR);
    if (drop_menu->button->state == HOVER || get_state_options(HOVER,
        list_ptr)) {
        while (list_ptr != NULL) {
            make_gui_obj(window, list_ptr->option, GREY_BAR);
            list_ptr = list_ptr->next;
        }
    }
}

void make_tab_menu(sfRenderWindow *window, struct s_gui_tab_menu *tab_menu)
{
    struct s_gui_options *list_ptr = (tab_menu->options);
    int index = 0;

    while (list_ptr != NULL) {
        if (index == tab_menu->active && tab_menu->content_bg != NULL)
            sfRenderWindow_drawSprite(window, tab_menu->content_bg->sprite,
                NULL);
        make_gui_obj(window, list_ptr->option, GREY_BAR);
        list_ptr = list_ptr->next;
        index++;
    }
}
