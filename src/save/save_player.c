/*
** EPITECH PROJECT, 2024
** save player
** File description:
** save_player
*/

#include "my.h"

void save_money(game_t *game)
{
    char *src = malloc(sizeof(char) * 1000);

    if (game->savefile == -1) {
        perror("open");
        return;
    }
    write(game->savefile, "###Money\n", 9);
    sprintf(src, "%d\n\n", game->player->euro_dollars);
    write(game->savefile, src, my_strlen(src));
    free(src);
}

void save_player(game_t *game)
{
    sfVector2f pos;
    xp_data_t *xp;
    char *src = malloc(sizeof(char) * 1000);

    if (game->savefile == -1) {
        perror("open");
        return;
    }
    write(game->savefile, "###PLAYER\n", 10);
    pos = sfSprite_getPosition(game->player->sprite->temp->sprite);
    xp = game->player->xp_data;
    sprintf(src, "%f,%f\n", pos.x, pos.y);
    write(game->savefile, src, my_strlen(src));
    free(src);
    src = malloc(sizeof(char) * 1000);
    sprintf(src, "%d,%d\n\n", xp->level, xp->xp_player.x);
    write(game->savefile, src, my_strlen(src));
    free(src);
}
