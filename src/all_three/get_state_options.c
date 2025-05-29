/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** a function to get weather or not a certain state appear in an option list
*/

#include "my.h"

int get_state_options(enum gui_state_e current_state,
    struct s_gui_options *list_ptr)
{
    while (list_ptr != NULL) {
        if (list_ptr->option->state == current_state)
            return 1;
        list_ptr = list_ptr->next;
    }
    return 0;
}
