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
#include "my.h"
#include <time.h>
#include <string.h>

struct s_gui_object *init_gui_obj(sfVector2f position, sfVector2f size)
{
    gui_obj_t *my_btn = malloc(sizeof(gui_obj_t));

    my_btn->rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(my_btn->rect, position);
    sfRectangleShape_setSize(my_btn->rect, size);
    sfRectangleShape_setFillColor(my_btn->rect, sfTransparent);
    my_btn->is_clicked = isclicked;
    my_btn->is_hover = ishover;
    my_btn->img = NULL;
    my_btn->label = NULL;
    my_btn->outline = sfFalse;
    my_btn->state = NO_STATE;
    return my_btn;
}

button_t *init_button(sfVector2f position, sfVector2f size,
    char *txt, assets_t **assets)
{
    button_t *my_button = malloc(sizeof(button_t));
    sfVector2f pos_txt = {position.x +
        (110 - ((strlen(txt) - 4) * 15)), position.y + 35};

    my_button->gui_obj = init_gui_obj(position, size);
    my_button->gui_obj->img = init_image(get_asset("Boutton_Void",
        assets), position, 1);
    init_animated_img(my_button->gui_obj->img, size.y, size.x, position);
    my_button->text = init_label(txt, pos_txt, 25,
        get_asset("Font_pixel", assets));
    return my_button;
}
