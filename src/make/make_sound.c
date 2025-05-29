/*
** EPITECH PROJECT, 2024
** make_options
** File description:
** make_options
*/

#include "my.h"
#include "gui_struct.h"

void change_txt_sound(page_options_t *options, game_t *game)
{
    char *src = strdup("Sound volume        ");
    char *str = malloc(sizeof(char) * 4);
    char *result;

    if (game->sounds->sound_volume < 100 && game->sounds->sound_volume >= 1) {
        free(src);
        src = strdup("Sound volume         ");
    } else if (game->sounds->sound_volume == 0) {
        free(src);
        src = strdup("Sound volume          ");
    }
    sprintf(str, "%.0f", game->sounds->sound_volume);
    result = malloc(sizeof(char) * (strlen(src) + strlen(str) + 2));
    strcpy(result, src);
    strcat(result, str);
    sfText_setString(options->sound_str->txt, result);
    free(result);
    free(str);
}

void update_state_button_lower_sound(gui_obj_t *button,
    game_t *game, page_options_t *options)
{
    if (button->state == RELEASED) {
        if (game->sounds->sound_volume > 5)
            game->sounds->sound_volume -= 5.;
        else
            game->sounds->sound_volume = 0.;
        button->state = NO_STATE;
        change_txt_sound(options, game);
        set_general_volume(game);
    }
    if (button->state == PRESSED)
        button->img->animate->rect.left = button->img->animate->rect.width;
    else if (button->state == HOVER)
        button->img->animate->rect.left = button->img->animate->rect.width * 2;
    else
        button->img->animate->rect.left = 0;
}

void update_state_button_greater_sound(gui_obj_t *button, game_t *game,
    page_options_t *options)
{
    if (button->state == RELEASED) {
        if (game->sounds->sound_volume < 95)
            game->sounds->sound_volume += 5.;
        else
            game->sounds->sound_volume = 100;
        button->state = NO_STATE;
        change_txt_sound(options, game);
        set_general_volume(game);
    }
    if (button->state == PRESSED)
        button->img->animate->rect.left = button->img->animate->rect.width;
    else if (button->state == HOVER)
        button->img->animate->rect.left = button->img->animate->rect.width * 2;
    else
        button->img->animate->rect.left = 0;
}

void compute_sound(game_t *game, ui_obj_t *obj)
{
    page_options_t *options = (page_options_t *)obj->ui_content;

    set_general_volume(game);
    update_state_button_lower_sound(options->lower_volume_sound,
        game, options);
    update_state_button_greater_sound(options->greater_volume_sound,
        game, options);
}

void make_sound(game_t *game, page_options_t *options)
{
    sfRenderWindow_drawText(game->window, options->sound_str->txt, NULL);
    make_img(options->lower_volume_sound->img, game->window);
    make_img(options->greater_volume_sound->img, game->window);
}
