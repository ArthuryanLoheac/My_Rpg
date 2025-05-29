/*
** EPITECH PROJECT, 2024
** My_Rpg
** File description:
** compute_button_state_escape
*/


#include "my.h"

static void update_state_button_body(gui_obj_t *button,
    game_t *game, unsigned int *i)
{
    int save_hp = game->player->hp->y;
    int moyenne = 0;

    if (button->state == RELEASED) {
        *i += 1;
        game->player->stats->HUM = game->player->stats->EMP * 10;
        moyenne = (int)floor((game->player->stats->WILL
            + game->player->stats->BODY) / 2.0);
        game->player->hp->y = 10 + (5 * moyenne);
        if (save_hp != game->player->hp->y)
            game->player->hp->x += (game->player->hp->y - save_hp);
        game->level_up_active = false;
        button->state = NO_STATE;
    }
    if (button->state == PRESSED)
        button->img->animate->rect.left = button->img->animate->rect.width;
    else if (button->state == HOVER)
        button->img->animate->rect.left = button->img->animate->rect.width * 2;
    else
        button->img->animate->rect.left = 0;
}

void compute_button_state_level(map_t *map, game_t *game)
{
    update_state_button_body(map->level_menu->Move,
        game, &game->player->stats->MOVE);
    update_state_button_body(map->level_menu->Tech,
        game, &game->player->stats->TECH);
    update_state_button_body(map->level_menu->Will,
        game, &game->player->stats->WILL);
    update_state_button_body(map->level_menu->REF,
        game, &game->player->stats->REF);
    update_state_button_body(map->level_menu->Dexterity,
        game, &game->player->stats->DEX);
    update_state_button_body(map->level_menu->EMP,
        game, &game->player->stats->EMP);
    update_state_button_body(map->level_menu->LUCK,
        game, &game->player->stats->LUCK);
    update_state_button_body(map->level_menu->Body,
        game, &game->player->stats->BODY);
}
