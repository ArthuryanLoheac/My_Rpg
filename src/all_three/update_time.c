/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** a function to analyze the size selection tool
*/

#include "my.h"

void update_time(time2_t *times)
{
    times->time = sfClock_getElapsedTime(times->clock);
    times->seconds = times->offset + (times->time.microseconds / 1000000.0);
}

void update_time2(time2_t *times)
{
    times->time = sfClock_getElapsedTime(times->clock);
    times->seconds = (times->time.microseconds / 1000000.0);
}
