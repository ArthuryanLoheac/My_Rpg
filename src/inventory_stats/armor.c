/*
** EPITECH PROJECT, 2024
** ammor
** File description:
** ammor
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

void set_armor_stats(item_t *item, int current)
{
    if (item->type == ARMOR) {
        item->armor = malloc(sizeof(armor_t));
        item->armor = malloc(sizeof(armor_t));
        if (item->id % 100 == 1)
            item->armor->sp = (sfVector2i){4, 4};
        if (item->id % 100 == 2)
            item->armor->sp = (sfVector2i){7, 7};
        if (item->id % 100 == 3)
            item->armor->sp = (sfVector2i){11, 11};
        if (item->id % 100 == 4)
            item->armor->sp = (sfVector2i){12, 12};
        if (item->id % 100 == 5)
            item->armor->sp = (sfVector2i){13, 13};
        if (item->id % 100 == 6)
            item->armor->sp = (sfVector2i){15, 15};
        if (item->id % 100 == 7)
            item->armor->sp = (sfVector2i){current, 18};
        if (current == 99)
            item->armor->sp.x = item->armor->sp.y;
    }
}
