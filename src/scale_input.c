/*
** EPITECH PROJECT, 2024
** scale_input
** File description:
** scale_input
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "my.h"
#include "lib.h"
#include <time.h>
#include <string.h>
#include <math.h>

sfVector2f scale_input(sfVector2f pixcoord, intern_var_t *intern_var)
{
    pixcoord.x = ((pixcoord.x - intern_var->img_pos->img_pos.x) /
        intern_var->zoom) + intern_var->img_pos->img_pos.x;
    pixcoord.y = ((pixcoord.y - intern_var->img_pos->img_pos.y) /
        intern_var->zoom) + intern_var->img_pos->img_pos.y;
    return pixcoord;
}
