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

void destroy_label(label_t *label)
{
    sfText_destroy(label->txt);
    label->txt = NULL;
    sfFont_destroy(label->font);
    label->font = NULL;
    free(label);
    label = NULL;
}
