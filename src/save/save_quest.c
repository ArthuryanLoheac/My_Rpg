/*
** EPITECH PROJECT, 2024
** save_quest
** File description:
** save_quest
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

void save_quest(game_t *game)
{
    if (game->savefile == -1) {
        perror("open");
        return;
    }
    if (game->quests == NULL)
        return;
    dprintf(game->savefile, "\n###Quest\n%s\n%d\n\n", game->quests->name,
        game->quests->prog.x);
}
