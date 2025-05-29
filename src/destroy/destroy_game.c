/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** a function to destroy the game struct
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "../../include/my.h"
#include "../../include/lib.h"
#include <time.h>
#include <string.h>

static void destroy_info(info_t *info)
{
    destroy_image(info->background);
    if (info->clock != NULL)
        destroy_time(info->clock);
    if (info->text != NULL)
        free(info->text);
    free(info);
}

void destroy_game(struct s_game *game)
{
    close(game->savefile);
    close(game->saveoptions);
    sfRenderWindow_destroy(game->window);
    destroy_keybind(game->keybinds);
    destroy_guis(game->guis);
    destroy_info(game->info);
    free(game);
}
