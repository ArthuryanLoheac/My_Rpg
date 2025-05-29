/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** a function to display a button
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

void analyze_gui_obj(sfRenderWindow *window, sfEvent *event,
    struct s_gui_object *obj)
{
    if (event->type == sfEvtMouseButtonPressed &&
        (&event->mouseButton)->button == sfMouseLeft && obj->is_clicked(obj,
        window)) {
        obj->state = PRESSED;
        return;
    }
    if (event->type == sfEvtMouseButtonReleased) {
        if (obj->is_clicked(obj, window))
            obj->state = RELEASED;
        else
            obj->state = NO_STATE;
        return;
    }
    if (event->type == sfEvtMouseMoved && obj->state != PRESSED) {
        if (obj->is_hover(obj, window))
            obj->state = HOVER;
        else
            obj->state = NO_STATE;
    }
}

void analyze_gui_slider(sfRenderWindow *window, sfEvent *event,
    struct s_gui_object *obj)
{
    if (event->type == sfEvtMouseButtonPressed) {
        if ((&event->mouseButton)->button == sfMouseLeft &&
            obj->is_clicked(obj, window))
            obj->state = PRESSED;
        else
            obj->state = NO_STATE;
    }
    if (event->type == sfEvtMouseButtonReleased &&
        (&event->mouseButton)->button == sfMouseLeft) {
        obj->state = RELEASED;
    }
    if (event->type == sfEvtMouseMoved &&
        obj->state != PRESSED && obj->state != RELEASED) {
        if (obj->is_hover(obj, window))
            obj->state = HOVER;
        else
            obj->state = NO_STATE;
    }
}

void analyze_gui_obj_drp(sfRenderWindow *window, sfEvent *event,
    struct s_gui_object *obj)
{
    if (event->type == sfEvtMouseButtonPressed &&
        (&event->mouseButton)->button == sfMouseLeft && obj->is_clicked(obj,
        window)) {
        obj->state = PRESSED;
        return;
    }
    if (event->type == sfEvtMouseButtonReleased) {
        if (obj->is_clicked(obj, window))
            obj->state = RELEASED;
        return;
    }
    if (event->type == sfEvtMouseMoved) {
        if (obj->is_hover(obj, window))
            obj->state = HOVER;
        else
            obj->state = NO_STATE;
    }
}
