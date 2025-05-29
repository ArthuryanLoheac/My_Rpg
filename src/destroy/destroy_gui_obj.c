/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** a function to destroy a button
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

void destroy_gui_obj(struct s_gui_object *btn)
{
    sfRectangleShape_destroy(btn->rect);
    if (btn->label != NULL)
        destroy_label(btn->label);
    if (btn->img != NULL)
        destroy_image(btn->img);
    free(btn);
}
