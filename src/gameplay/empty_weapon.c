/*
** EPITECH PROJECT, 2024
** update_menu_start
** File description:
** update_menu_start
*/

#include "my.h"

sfVector2i empty_weapon(int hits, game_t *game)
{
    send_info(game, 2, "Should've checked that magazine !\n");
    return (sfVector2i){hits, hits};
}
