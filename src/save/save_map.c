/*
** EPITECH PROJECT, 2024
** save_map
** File description:
** save_map
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

void save_map(game_t *game, map_t *map)
{
    if (game->savefile == -1) {
        perror("open");
        return;
    }
    dprintf(game->savefile, "\n###Map\n%s\n\n", map->map->current_map);
}
