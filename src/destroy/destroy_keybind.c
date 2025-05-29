/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** a function to destroy the keybind struct
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

void destroy_keybind(struct s_keybind *keybind)
{
    free(keybind);
}
