/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** a function to create a button
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

struct s_gui_drop_menu *add_option_drop_menu(struct s_gui_drop_menu *drop_menu,
    gui_obj_t *obj)
{
    struct s_gui_options *new = malloc(24);
    struct s_gui_options *list_ptr = (drop_menu->options);

    new->option = obj;
    new->next = NULL;
    if (drop_menu->options == NULL) {
        drop_menu->options = new;
        return drop_menu;
    }
    while (list_ptr->next != NULL)
        list_ptr = list_ptr->next;
    list_ptr->next = new;
    return drop_menu;
}
