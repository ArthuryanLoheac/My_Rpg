/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** a function to analyze a drop_menu
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

void analyze_drop_menu(sfRenderWindow *window, sfEvent event, struct
    s_gui_drop_menu *drop_menu)
{
    struct s_gui_options *list_ptr = (drop_menu->options);

    if (drop_menu->button->state == HOVER || get_state_options(HOVER,
        list_ptr)) {
        while (list_ptr != NULL) {
            analyze_gui_obj_drp(window, &event, list_ptr->option);
            list_ptr = list_ptr->next;
        }
    }
    analyze_gui_obj(window, &event, drop_menu->button);
}

void analyze_tab_menu(sfRenderWindow *window, sfEvent event, struct
    s_gui_tab_menu *tab_menu)
{
    struct s_gui_options *list_ptr = (tab_menu->options);

    while (list_ptr != NULL) {
        analyze_gui_obj(window, &event, list_ptr->option);
        list_ptr = list_ptr->next;
    }
}
