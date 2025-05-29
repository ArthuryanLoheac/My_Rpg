/*
** EPITECH PROJECT, 2024
** destroy_time
** File description:
** destroy_time
*/

#include "my.h"

void destroy_time(time2_t *time)
{
    sfClock_destroy(time->clock);
    free(time);
}
