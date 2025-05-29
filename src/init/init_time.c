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

time2_t *init_time(void)
{
    time2_t *times = malloc(sizeof(time2_t));

    times->clock = sfClock_create();
    times->time = sfClock_getElapsedTime(times->clock);
    times->seconds = times->time.microseconds / 1000000.0;
    times->offset = 0;
    return times;
}
