/*
** EPITECH PROJECT, 2024
** analyze_options
** File description:
** analyze_options
*/

#include "my.h"
#include "gui_struct.h"



static void update_state_button_valider(gui_obj_t *button,
    guis_t *gui, game_t *game, page_final_t *options)
{
    sfSprite_setColor(button->img->sprite, sfWhite);
    if (button->state == RELEASED) {
        gui->active = MAP;
        sfMusic_stop(game->music->menu_theme);
        sfMusic_play(game->music->main_theme);
        chapter_transition(game, "Chapter 1:", "Citizen Erazed", sfWhite);
        game->quests = init_quest("Citizen Erazed", 0);
        game->player->gender = options->gender;
        compute_add_hair_from_gender(game->player->gender, game, game->player);
        game->player->name = strdup(options->name);
        set_general_volume(game);
        save_data(game);
    }
    if (button->state == PRESSED)
        button->img->animate->rect.left = button->img->animate->rect.width;
    else if (button->state == HOVER)
        button->img->animate->rect.left = button->img->animate->rect.width * 2;
    else
        button->img->animate->rect.left = 0;
}

static void update_state_button_male(button_t *button,
    page_final_t *page)
{
    sfSprite_setColor(button->gui_obj->img->sprite, sfWhite);
    if (button->gui_obj->state == RELEASED) {
        page->gender = 1;
        button->gui_obj->state = NO_STATE;
    }
    compute_default_state_button(button);
}

static void update_state_button_female(button_t *button,
    page_final_t *page)
{
    sfSprite_setColor(button->gui_obj->img->sprite, sfWhite);
    if (button->gui_obj->state == RELEASED) {
        page->gender = 2;
        button->gui_obj->state = NO_STATE;
    }
    compute_default_state_button(button);
}

static void check_letter(page_final_t *page, game_t *game, int i, bool Maj)
{
    int len = 0;

    if (game->events->type == sfEvtKeyReleased && game->events->key.code ==
        i) {
        len = strlen(page->name);
        if (len >= 19)
            return;
        if (sfKeyboard_isKeyPressed(sfKeyLShift) && Maj == true)
            page->name[len] = i + 'A';
        else
            page->name[len] = i + 'a';
        page->name[len + 1] = '\0';
        sfText_setString(page->name_txt->txt, page->name);
        game->events->type = sfEvtCount;
    }
}

static void check_number(page_final_t *page, game_t *game, int i)
{
    int len = 0;

    if (game->events->type == sfEvtKeyReleased && game->events->key.code ==
        sfKeyNum0 + i) {
        len = strlen(page->name);
        if (len >= 19)
            return;
        page->name[len] = i + '0';
        page->name[len + 1] = '\0';
        sfText_setString(page->name_txt->txt, page->name);
        game->events->type = sfEvtCount;
    }
}

static void check_backspace(page_final_t *page, game_t *game)
{
    int len = 0;

    if (game->events->type == sfEvtKeyReleased && game->events->key.code ==
        sfKeyBackspace) {
        len = strlen(page->name);
        page->name[len - 1] = '\0';
        sfText_setString(page->name_txt->txt, page->name);
        game->events->type = sfEvtCount;
    }
}

static void check_space(page_final_t *page, game_t *game)
{
    int len = 0;

    if (game->events->type == sfEvtKeyReleased && game->events->key.code ==
        sfKeySpace) {
        len = strlen(page->name);
        if (len >= 19)
            return;
        page->name[len] = ' ';
        page->name[len + 1] = '\0';
        sfText_setString(page->name_txt->txt, page->name);
        game->events->type = sfEvtCount;
    }
}

static void write_name(page_final_t *page, game_t *game)
{
    for (int i = sfKeyA; i <= sfKeyZ; i++)
        check_letter(page, game, i, true);
    for (int i = 0; i <= 9; i++)
        check_number(page, game, i);
    check_backspace(page, game);
    check_space(page, game);
}

static void compute_recap(page_final_t *options, game_t *game)
{
    static bool i = false;

    if (options->gender != 0 && (int)strlen(options->name) > 0)
        update_state_button_valider(options->valider, game->guis, game,
            options);
    if (i == false) {
        compute_recap_shop(options->recap, game->player, game->player->stats);
        compute_recap_inventory(options->recap, game);
        i = true;
    }
}

void compute_final_page(ui_obj_t *obj, game_t *game)
{
    page_final_t *options = (page_final_t *)obj->ui_content;
    sfColor orange_trans = ORANGE;

    orange_trans.a = 128;
    write_name(options, game);
    sfSprite_setColor(options->valider->img->sprite, TRANSPARENT);
    if (options->gender == 0 || options->gender == 2)
        update_state_button_male(options->male, options);
    if (options->gender == 0 || options->gender == 1)
        update_state_button_female(options->female, options);
    if (options->gender == 1) {
        sfText_setColor(options->male->text->txt, orange_trans);
        sfSprite_setColor(options->male->gui_obj->img->sprite, TRANSPARENT);
    }
    if (options->gender == 2) {
        sfText_setColor(options->female->text->txt, orange_trans);
        sfSprite_setColor(options->female->gui_obj->img->sprite, TRANSPARENT);
    }
    compute_recap(options, game);
}
