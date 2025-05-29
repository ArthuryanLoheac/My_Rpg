/*
** EPITECH PROJECT, 2024
** save
** File description:
** save_inventory
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

static void add_gender_in_file(int fd, player_character_t *player)
{
    char str[4];

    write(fd, "\n###Gender\n", 11);
    sprintf(str, "%d\n", player->gender);
    write(fd, str, strlen(str));
}

static void save_gender(void *map, game_t *game)
{
    map_t *data = (map_t *)map;
    player_character_t *player = NULL;

    if (game->savefile == -1) {
        perror("open");
        return;
    }
    if (!(data->player))
        return;
    player = data->player;
    add_gender_in_file(game->savefile, player);
}

static void add_name_in_file(int fd, player_character_t *player)
{
    char str[21];

    write(fd, "\n###Name\n", 9);
    sprintf(str, "%s\n", player->name);
    write(fd, str, strlen(str));
}

static void save_name(void *map, game_t *game)
{
    map_t *data = (map_t *)map;
    player_character_t *player = NULL;

    if (game->savefile == -1) {
        perror("open");
        return;
    }
    if (!(data->player && data->player->name))
        return;
    player = data->player;
    add_name_in_file(game->savefile, player);
}

void save_gender_and_name(void *map, game_t *game)
{
    save_gender(map, game);
    save_name(map, game);
}
