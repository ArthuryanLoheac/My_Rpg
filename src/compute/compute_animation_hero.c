/*
** EPITECH PROJECT, 2024
** compute_animation_hero
** File description:
** compute_animation_hero
*/
#include "my.h"

static sfVector2f *get_vector_move(game_t *game)
{
    sfVector2f *move = malloc(sizeof(sfVector2f));

    move->x = 0;
    move->y = 0;
    move->x -= sfKeyboard_isKeyPressed(game->keybinds->left);
    move->x += sfKeyboard_isKeyPressed(game->keybinds->right);
    move->y -= sfKeyboard_isKeyPressed(game->keybinds->up);
    move->y += sfKeyboard_isKeyPressed(game->keybinds->down);
    return move;
}

static void check_player_move(game_t *game)
{
    sfVector2f *move = get_vector_move(game);
    int direction = game->player->sprite->direction;

    if (move->x > 0)
        game->player->sprite->direction = 3;
    if (move->x < 0)
        game->player->sprite->direction = 2;
    if (move->y > 0)
        game->player->sprite->direction = 1;
    if (move->y < 0)
        game->player->sprite->direction = 4;
    if (move->x == 0 && move->y == 0) {
        if (direction == 0)
            game->player->sprite->direction = 5;
        if (direction <= 4 && direction >= 1)
            game->player->sprite->direction = direction + 4;
    }
    free(move);
}

static void check_cant_move(game_t *game)
{
    sfVector2f *move = get_vector_move(game);

    if (move->x > 0)
        game->player->sprite->direction = 7;
    if (move->x < 0)
        game->player->sprite->direction = 6;
    if (move->y > 0)
        game->player->sprite->direction = 5;
    if (move->y < 0)
        game->player->sprite->direction = 8;
    free(move);
}

static void update_image_clothes(pc_sprite_t *player)
{
    linked_list_t *lst = player->clothes;

    while (lst) {
        ((img_t *)(lst->data))->animate->rect = player->temp->animate->rect;
        lst = lst->next;
    }
}

void compute_animation_hero(pc_sprite_t *player, game_t *game)
{
    if (((map_t *)game->guis->map->ui_content)->fight->dep_mouv.x == 0) {
        check_cant_move(game);
    } else
        check_player_move(game);
    player->temp->animate->rect.top = player->temp->animate->rect.height *
        (player->direction - 1);
    compute_animation_img(player->temp->animate, false);
    update_image_clothes(player);
}
