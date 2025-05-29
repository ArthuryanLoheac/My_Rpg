/*
** EPITECH PROJECT, 2024
** drug
** File description:
** drug
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

void set_drugs_stats(item_t *item, int nbr_bullets)
{
    if (item->type == DRUGS) {
        item->drug = malloc(sizeof(drug_t));
        item->drug->effect = item->id % 100;
        if (item->id % 100 == 1)
            item->drug->uses.y = 1;
        if (item->id % 100 == 2)
            item->drug->uses.y = 3;
        if (nbr_bullets == 99)
            item->drug->uses.x = item->drug->uses.y;
        else
            item->drug->uses.x += nbr_bullets;
    }
}
