/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** miscellaneous function for computing button and keyboard keys
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "../../include/my.h"
#include "../../include/lib.h"
#include <time.h>
#include <string.h>

sfBool btn_is_pressed(enum gui_state_e state, enum gui_state_e prev)
{
    if (state == RELEASED && prev == PRESSED)
        return sfTrue;
    return sfFalse;
}

sfBool btn_is_pressed_drp(enum gui_state_e state, enum gui_state_e prev)
{
    if (state == PRESSED && prev == HOVER)
        return sfTrue;
    return sfFalse;
}

sfBool key_is_pressed_ctrl(sfKeyCode key, sfBool pressed)
{
    if (pressed == sfFalse && sfKeyboard_isKeyPressed(key) == sfTrue &&
        (sfKeyboard_isKeyPressed(sfKeyLControl) == sfTrue ||
        sfKeyboard_isKeyPressed(sfKeyRControl) == sfTrue))
        return sfTrue;
    return sfFalse;
}

sfBool key_is_pressed(sfKeyCode key, sfBool pressed)
{
    if (pressed == sfFalse && sfKeyboard_isKeyPressed(key) == sfTrue)
        return sfTrue;
    return sfFalse;
}

sfBool mouse_is_pressed(sfMouseButton mouse, sfBool pressed)
{
    if (pressed == sfFalse && sfMouse_isButtonPressed(mouse) == sfTrue)
        return sfTrue;
    return sfFalse;
}
