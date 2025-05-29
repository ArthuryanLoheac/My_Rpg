/*
** EPITECH PROJECT, 2024
** gear
** File description:
** gear
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
#include <fcntl.h>
#include <sys/stat.h>

void set_gear_stats(item_t *item)
{
    if (item->type == GEAR) {
        item->gear = malloc(sizeof(gear_t));
        item->gear->effect = item->id % 100;
    }
}
