/*
** EPITECH PROJECT, 2024
** save_stats
** File description:
** save_stats
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

static void add_stats_in_file(int fd, sfVector2i *stats)
{
    char str[54];

    sprintf(str, "%d:%d\n",
    stats->x, stats->y);
    write(fd, "\n###HP\n", 7);
    write(fd, str, my_strlen(str));
}

void save_hp(void *map, game_t *game)
{
    map_t *data = (map_t *) map;
    sfVector2i *stats = NULL;

    if (game->savefile == -1) {
        perror("open");
        return;
    }
    if (!(data->player && data->player->hp))
        return;
    stats = data->player->hp;
    add_stats_in_file(game->savefile, stats);
}
