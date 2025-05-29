/*
** EPITECH PROJECT, 2024
** compute_keybinds
** File description:
** compute_keybinds
*/

#include "my.h"
#include "gui_struct.h"

static void update_state_button_key(gui_obj_t *button, game_t *game,
    sfKeyCode *key, int hint)
{
    if (button->state == RELEASED || game->keybinds->wait_for_key == hint) {
        game->keybinds->wait_for_key = hint;
        button->state = PRESSED;
        if (game->events->key.code > 0 && game->events->key.code < 102
            && game->events->key.code != sfKeyEscape) {
            *key = game->events->key.code;
            game->keybinds->wait_for_key = sfFalse;
            button->state = NO_STATE;
        }
    }
    if (button->state == PRESSED)
        button->img->animate->rect.left = button->img->animate->rect.width;
    else if (button->state == HOVER)
        button->img->animate->rect.left = button->img->animate->rect.width * 2;
    else
        button->img->animate->rect.left = 0;
}

static int check_final_keybinds(game_t *game, page_options_t *options)
{
    if (game->keybinds->wait_for_key == 7 || !game->keybinds->wait_for_key) {
        update_state_button_key(options->keybinds_labels->progression
        ->change_bind, game, &game->keybinds->progression, 7);
        if (game->keybinds->wait_for_key != 0)
            return 1;
    }
    if (game->keybinds->wait_for_key == 8 || !game->keybinds->wait_for_key) {
        update_state_button_key(options->keybinds_labels->skip->change_bind,
            game, &game->keybinds->skip, 8);
        if (game->keybinds->wait_for_key != 0)
            return 1;
    }
    if (game->keybinds->wait_for_key == 9 || !game->keybinds->wait_for_key) {
        update_state_button_key(options->keybinds_labels->attack->change_bind,
            game, &game->keybinds->attack, 9);
        if (game->keybinds->wait_for_key != 0)
            return 1;
    }
    return 0;
}

static int check_other_keybinds(game_t *game, page_options_t *options)
{
    if (game->keybinds->wait_for_key == 4 || !game->keybinds->wait_for_key) {
        update_state_button_key(options->keybinds_labels->right->change_bind,
            game, &game->keybinds->right, 4);
        if (game->keybinds->wait_for_key != 0)
            return 1;
    }
    if (game->keybinds->wait_for_key == 5 || !game->keybinds->wait_for_key) {
        update_state_button_key(options->keybinds_labels->inventory->
            change_bind, game, &game->keybinds->inventory, 5);
        if (game->keybinds->wait_for_key != 0)
            return 1;
    }
    if (game->keybinds->wait_for_key == 6 || !game->keybinds->wait_for_key) {
        update_state_button_key(options->keybinds_labels->interact->
            change_bind, game, &game->keybinds->interact, 6);
        if (game->keybinds->wait_for_key != 0)
            return 1;
    }
    return (check_final_keybinds(game, options));
}

int check_keybinds_wait(game_t *game, page_options_t *options)
{
    if (game->keybinds->wait_for_key == 1 || !game->keybinds->wait_for_key) {
        update_state_button_key(options->keybinds_labels->up->change_bind,
            game, &game->keybinds->up, 1);
        if (game->keybinds->wait_for_key != 0)
            return 1;
    }
    if (game->keybinds->wait_for_key == 2 || !game->keybinds->wait_for_key) {
        update_state_button_key(options->keybinds_labels->down->change_bind,
            game, &game->keybinds->down, 2);
        if (game->keybinds->wait_for_key != 0)
            return 1;
    }
    if (game->keybinds->wait_for_key == 3 || !game->keybinds->wait_for_key) {
        update_state_button_key(options->keybinds_labels->left->change_bind,
            game, &game->keybinds->left, 3);
        if (game->keybinds->wait_for_key != 0)
            return 1;
    }
    return (check_other_keybinds(game, options));
}
