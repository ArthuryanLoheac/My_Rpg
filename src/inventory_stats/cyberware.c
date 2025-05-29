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

void set_cyberware_stats(item_t *item, int value)
{
    if (item->type == CYBERWARE) {
        item->cyberware = malloc(sizeof(cyberware_t));
        item->cyberware->effect = item->id % 100;
        item->cyberware->value = value;
    }
}
