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

keybind_t *init_keybind(void)
{
    keybind_t *keybind = malloc(sizeof(keybind_t));

    keybind->attack = (sfKeyCode)sfMouseRight;
    keybind->up = (sfKeyCode)sfKeyZ;
    keybind->down = (sfKeyCode)sfKeyS;
    keybind->left = (sfKeyCode)sfKeyQ;
    keybind->right = (sfKeyCode)sfKeyD;
    keybind->interact = (sfKeyCode)sfKeyF;
    keybind->inventory = (sfKeyCode)sfKeyTab;
    keybind->progression = (sfKeyCode)sfKeyB;
    keybind->skip = (sfKeyCode)sfKeySpace;
    return keybind;
}
