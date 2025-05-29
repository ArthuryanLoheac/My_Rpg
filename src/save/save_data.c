/*
** EPITECH PROJECT, 2024
** saving data
** File description:
** save_data
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "../include/my.h"
#include "../include/lib.h"
#include <time.h>
#include <string.h>

static void actualize_save_options(game_t *game)
{
    close(game->saveoptions);
    game->saveoptions = open("./save/Save_file_options.rtb", O_RDWR |
        O_CREAT | O_TRUNC, 0777);
    save_options(game);
}

void save_data(game_t *game)
{
    actualize_save_options(game);
    if (game->guis->map->ui_content && game->player
        && game->player->hp->x > 0) {
        close(game->savefile);
        game->savefilepath = next_filepath_choose();
        game->savefile = open(game->savefilepath, O_RDWR |
            O_CREAT | O_TRUNC, 0777);
        save_inventory(game->guis->map->ui_content, game);
        save_gender_and_name(game->guis->map->ui_content, game);
        save_stats(game->guis->map->ui_content, game);
        save_hp(game->guis->map->ui_content, game);
        save_class(game->guis->map->ui_content, game);
        save_quest(game);
        save_time(game, ((map_t *)(game->guis->map->ui_content)));
        save_map(game, ((map_t *)(game->guis->map->ui_content)));
        save_player(game);
        save_money(game);
        save_npc(((map_t *)(game->guis->map->ui_content))->entity_all, game);
    }
}
