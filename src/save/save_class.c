/*
** EPITECH PROJECT, 2024
** save_class
** File description:
** save_class
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

static void add_stats_in_file(int fd, enum class_e class)
{
    char str[54];

    sprintf(str, "Class:%d\n", class);
    write(fd, "\n###Class\n", 10);
    write(fd, str, my_strlen(str));
}

void save_class(void *map, game_t *game)
{
    map_t *data = (map_t *) map;
    enum class_e class;

    if (game->savefile == -1) {
        perror("open");
        return;
    }
    if (data->player == NULL)
        return;
    class = data->player->class;
    add_stats_in_file(game->savefile, class);
}
