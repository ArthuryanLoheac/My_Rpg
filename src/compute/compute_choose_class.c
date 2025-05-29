/*
** EPITECH PROJECT, 2024
** analyze_options
** File description:
** analyze_options
*/

#include "my.h"
#include "gui_struct.h"

static void update_state_button_solo(gui_obj_t *button, guis_t *guis,
    player_character_t *player)
{
    if (button->state == RELEASED) {
        player->class = SOLO;
        guis->active = CHOOSE_STATS;
        button->state = NO_STATE;
    }
    if (button->state == PRESSED)
        button->img->animate->rect.left = button->img->animate->rect.width;
    else if (button->state == HOVER)
        button->img->animate->rect.left = button->img->animate->rect.width * 2;
    else
        button->img->animate->rect.left = 0;
}

static void update_state_button_tech(gui_obj_t *button, guis_t *guis,
    player_character_t *player)
{
    if (button->state == RELEASED) {
        player->class = TECH;
        guis->active = CHOOSE_STATS;
        button->state = NO_STATE;
    }
    if (button->state == PRESSED)
        button->img->animate->rect.left = button->img->animate->rect.width;
    else if (button->state == HOVER)
        button->img->animate->rect.left = button->img->animate->rect.width * 2;
    else
        button->img->animate->rect.left = 0;
}

static void update_state_button_med(gui_obj_t *button, guis_t *guis,
    player_character_t *player)
{
    if (button->state == RELEASED) {
        player->class = MED;
        guis->active = CHOOSE_STATS;
        button->state = NO_STATE;
    }
    if (button->state == PRESSED)
        button->img->animate->rect.left = button->img->animate->rect.width;
    else if (button->state == HOVER)
        button->img->animate->rect.left = button->img->animate->rect.width * 2;
    else
        button->img->animate->rect.left = 0;
}

void compute_choose_class(ui_obj_t *obj, game_t *game)
{
    page_choose_class_t *options = (page_choose_class_t *)obj->ui_content;

    update_state_button_solo(options->Class_one->Valider,
        game->guis, game->player);
    update_state_button_tech(options->Class_two->Valider,
        game->guis, game->player);
    update_state_button_med(options->Class_three->Valider,
        game->guis, game->player);
}
