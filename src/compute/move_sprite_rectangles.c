/*
** EPITECH PROJECT, 2024
** compute_keybinds
** File description:
** compute_keybinds
*/

#include "my.h"
#include "gui_struct.h"

void change_txt_volume(page_options_t *options, game_t *game)
{
    char *src = strdup("Music volume        ");
    char *str = malloc(sizeof(char) * 4);
    char *result;

    if (game->music->music_volume < 100 && game->music->music_volume >= 1) {
        free(src);
        src = strdup("Music volume         ");
    } else if (game->music->music_volume == 0) {
        free(src);
        src = strdup("Music volume          ");
    }
    sprintf(str, "%.0f", game->music->music_volume);
    result = malloc(sizeof(char) * (strlen(src) + strlen(str) + 2));
    strcpy(result, src);
    strcat(result, str);
    sfText_setString(options->music_str->txt, result);
    free(result);
    free(str);
}

static void move_txt(sfText *txt, sfVector2f vector, game_t *game)
{
    sfVector2f pos = sfView_getCenter(sfRenderWindow_getView(game->window));

    pos = add(pos, -960, -540);
    pos = add(pos, vector.x, vector.y);
    sfText_setPosition(txt, pos);
}

static void move_image(sfSprite *sprite,
    sfVector2f vector, game_t *game)
{
    sfVector2f pos = sfView_getCenter(sfRenderWindow_getView(game->window));

    pos = add(pos, -960, -540);
    pos = add(pos, vector.x, vector.y);
    sfSprite_setPosition(sprite, pos);
}

static void move_sprite(gui_obj_t *sprite, sfVector2f vector,
    game_t *game)
{
    sfVector2f pos = sfView_getCenter(sfRenderWindow_getView(game->window));

    pos = add(pos, -960, -540);
    pos = add(pos, vector.x, vector.y);
    sfSprite_setPosition(sprite->img->sprite, pos);
    sfRectangleShape_setPosition(sprite->rect, pos);
}

void move_button(button_t *button, sfVector2f vector,
    game_t *game, sfVector2f vector_txt)
{
    sfVector2f pos = sfView_getCenter(sfRenderWindow_getView(game->window));

    pos = add(pos, -960, -540);
    pos = add(pos, vector.x, vector.y);
    move_txt(button->text->txt, vector_txt, game);
    move_sprite(button->gui_obj, vector, game);
}

static void update_pos_txt_keybinds(game_t *game, page_options_t *options)
{
    int i = 83;

    move_txt(options->keybinds_labels->up->label->txt,
        (sfVector2f){100, 190 + i * 0}, game);
    move_txt(options->keybinds_labels->down->label->txt,
        (sfVector2f){100, 190 + i * 1}, game);
    move_txt(options->keybinds_labels->left->label->txt,
        (sfVector2f){100, 190 + i * 2}, game);
    move_txt(options->keybinds_labels->right->label->txt,
        (sfVector2f){100, 190 + i * 3}, game);
    move_txt(options->keybinds_labels->keybinds_str->txt,
        (sfVector2f){100, 90}, game);
    move_txt(options->keybinds_labels->attack->label->txt,
        (sfVector2f){100, 190 + i * 4}, game);
    move_txt(options->keybinds_labels->inventory->label->txt,
        (sfVector2f){100, 190 + i * 5}, game);
    move_txt(options->keybinds_labels->progression->label->txt,
        (sfVector2f){100, 190 + i * 6}, game);
}

static void update_pos_sprites_keybinds(game_t *game, page_options_t *options)
{
    int i = 83;

    move_sprite(options->keybinds_labels->up->change_bind,
        (sfVector2f){400, 170 + i * 0}, game);
    move_sprite(options->keybinds_labels->down->change_bind,
        (sfVector2f){400, 170 + i * 1}, game);
    move_sprite(options->keybinds_labels->left->change_bind,
        (sfVector2f){400, 170 + i * 2}, game);
    move_sprite(options->keybinds_labels->right->change_bind,
        (sfVector2f){400, 170 + i * 3}, game);
    move_sprite(options->keybinds_labels->attack->change_bind,
        (sfVector2f){400, 170 + i * 4}, game);
    move_sprite(options->keybinds_labels->inventory->change_bind,
        (sfVector2f){400, 170 + i * 5}, game);
    move_sprite(options->keybinds_labels->progression->change_bind,
        (sfVector2f){400, 170 + i * 6}, game);
    move_sprite(options->keybinds_labels->skip->change_bind,
        (sfVector2f){400, 170 + i * 7}, game);
    move_sprite(options->keybinds_labels->interact->change_bind,
        (sfVector2f){400, 170 + i * 8}, game);
}

static void update_pos_sprites_buttons_f(game_t *game, page_options_t *options)
{
    move_sprite(options->retour, (sfVector2f){45, 955}, game);
    move_sprite(options->lower_volume, (sfVector2f){990, 445}, game);
    move_sprite(options->greater_volume,
        (sfVector2f){1180, 445}, game);
    move_sprite(options->greater_volume_sound,
        (sfVector2f){1180, 538}, game);
    move_sprite(options->lower_volume_sound,
        (sfVector2f){990, 538}, game);
}

static void update_pos_sprites_buttons(game_t *game, page_options_t *options)
{
    move_image(options->background->sprite, vect0(), game);
    move_button(options->fullscreen, (sfVector2f){800, 145}, game,
        (sfVector2f){800 + 110 - (strlen("Fullscreen") - 4) * 15, 145 + 35});
    move_txt(options->music_str->txt, (sfVector2f){680, 468}, game);
    move_txt(options->sound_str->txt, (sfVector2f){680, 560}, game);
    move_button(options->mute_volume, (sfVector2f){800, 745}, game,
        (sfVector2f){800 + 110 - (strlen("Mute") - 2) * 15, 745 + 35});
    move_button(options->unmute_volume, (sfVector2f){800, 745}, game,
        (sfVector2f){800 + 110 - (strlen("Unmute") - 4) * 15, 745 + 35});
    move_button(options->save, (sfVector2f){1515, 955}, game,
        (sfVector2f){1515 + 110 - (strlen("Save") - 4) * 15, 955 + 35});
    move_button(options->min_resolution, (sfVector2f){1500, 245}, game,
        (sfVector2f){1500 + 135 - (strlen("1280 x 720") - 2) * 15, 245 + 35});
    move_button(options->mid_resolution, (sfVector2f){1500, 445}, game,
        (sfVector2f){1500 + 138 - (strlen("1366 x 768") - 2) * 15, 445 + 35});
    move_button(options->max_resolution, (sfVector2f){1500, 645}, game,
        (sfVector2f){1500 + 135 - (strlen("1920 x 1080") - 2) * 15, 645 + 35});
    update_pos_sprites_buttons_f(game, options);
}

void update_pos_sprites_options(game_t *game, page_options_t *options)
{
    int i = 83;

    update_pos_sprites_buttons(game, options);
    update_pos_sprites_keybinds(game, options);
    update_pos_txt_keybinds(game, options);
    move_txt(options->keybinds_labels->skip->label->txt,
        (sfVector2f){100, 190 + i * 7}, game);
    move_txt(options->keybinds_labels->interact->label->txt,
        (sfVector2f){100, 190 + i * 8}, game);
}
