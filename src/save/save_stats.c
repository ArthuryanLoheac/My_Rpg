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

static void add_stats_in_file(int fd, stats_t *stats)
{
    char str[100];

    sprintf(str, "MOVE:%d\nTECH:%d\nWILL:%d\n"
    "BODY:%d\nREF:%d\nDEX:%d\nEMP:%d\nLUCK:%d\nHUM:%d\n",
    stats->MOVE, stats->TECH, stats->WILL, stats->BODY,
    stats->REF, stats->DEX, stats->EMP, stats->LUCK, stats->HUM);
    write(fd, "\n###Stats\n", 10);
    write(fd, str, my_strlen(str));
}

static void remove_bonus(stats_t **stats, stats_t *bonus)
{
    if (!bonus)
        return;
    (*stats)->BODY -= bonus->BODY;
    (*stats)->DEX -= bonus->DEX;
    (*stats)->EMP -= bonus->EMP;
    (*stats)->HUM += bonus->HUM;
    (*stats)->LUCK -= bonus->LUCK;
    (*stats)->MOVE -= bonus->MOVE;
    (*stats)->REF -= bonus->REF;
    (*stats)->TECH -= bonus->TECH;
    (*stats)->WILL -= bonus->WILL;
}

void save_stats(void *map, game_t *game)
{
    map_t *data = (map_t *) map;
    stats_t *stats = NULL;

    if (game->savefile == -1) {
        perror("open");
        return;
    }
    if (!(data->player && data->player->stats))
        return;
    stats = data->player->stats;
    remove_bonus(&stats, data->player->bonus_stats);
    add_stats_in_file(game->savefile, stats);
}
