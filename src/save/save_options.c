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

void save_options(game_t *game)
{
    char str[100];

    if (game->saveoptions == -1) {
        return;
    }
    sprintf(str, "%d\n%d\n%d\n%d\n%d\n%d\n\n", (int)game->music->music_volume,
        (int)game->music->mute_volume, (int)game->video_mode.width,
        (int)game->video_mode.height, (int)game->video_mode.bitsPerPixel,
        (int)game->sounds->sound_volume);
    write(game->saveoptions, "\n###OPTIONS\n", 12);
    write(game->saveoptions, str, my_strlen(str));
}
