/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** a function to destroy all options in a drop menu
*/

#include "my.h"

void destroy_options(struct s_gui_options *opt)
{
    gui_opt_t *temp;

    while (opt->next != NULL) {
        destroy_gui_obj(opt->option);
        temp = opt->next;
        free(opt);
        opt = temp;
    }
}
