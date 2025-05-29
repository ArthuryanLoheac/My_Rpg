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
#include "../../include/my.h"
#include "../../include/lib.h"
#include <time.h>
#include <string.h>

label_t *init_label(char *default_text, sfVector2f pos, unsigned
    int size, char *font)
{
    label_t *label = malloc(sizeof(label_t));

    label->font = sfFont_createFromFile(font);
    label->txt = sfText_create();
    sfText_setString(label->txt, default_text);
    sfText_setFont(label->txt, label->font);
    sfText_setCharacterSize(label->txt, size);
    sfText_setPosition(label->txt, pos);
    sfText_setColor(label->txt, ICON_WHITE);
    return label;
}
