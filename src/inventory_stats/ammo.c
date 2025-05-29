/*
** EPITECH PROJECT, 2024
** ammo_stats
** File description:
** ammo
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

void set_ammo_stats(item_t *item, int nbr_bullets)
{
    if (item->type == AMMO) {
        item->ammo = malloc(sizeof(ammo_t));
        item->ammo->type = item->id % 100;
        if (item->id % 100 < 4)
            item->ammo->amount.y = 30;
        if (item->id % 100 == 4)
            item->ammo->amount.y = 3;
        if (item->id % 100 == 5)
            item->ammo->amount.y = 15;
        if (nbr_bullets == 99)
            item->ammo->amount.x = item->ammo->amount.y;
        else
            item->ammo->amount.x = nbr_bullets;
    }
}
