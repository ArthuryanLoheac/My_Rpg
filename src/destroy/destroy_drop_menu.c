/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** a function to destroy a drop menu
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

void destroy_drop_menu(gui_drp_t *drop_menu)
{
    destroy_gui_obj(drop_menu->button);
    destroy_options(drop_menu->options);
    free(drop_menu);
}

void destroy_tab_menu(gui_tab_t *tab_menu)
{
    destroy_options(tab_menu->options);
    free(tab_menu);
}
