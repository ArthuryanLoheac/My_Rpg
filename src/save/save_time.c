/*
** EPITECH PROJECT, 2024
** save_time
** File description:
** save_time
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "../include/my.h"
#include "../include/lib.h"
#include <time.h>
#include <string.h>

void save_time(game_t *game, map_t *map)
{
    if (game->savefile == -1) {
        perror("open");
        return;
    }
    dprintf(game->savefile, "\n###Time\n%d\n\n",
        (int)map->night->clock->seconds);
}
