/*
** EPITECH PROJECT, 2024
** compute_state_buttons
** File description:
** compute_state_buttons
*/

#include "my.h"

static void compute_state_button_play(gui_obj_t *button, guis_t *guis)
{
    if (button->state == RELEASED) {
        guis->active = START_MENU;
        button->state = NO_STATE;
    }
    if (button->state == PRESSED)
        button->img->animate->rect.left = button->img->animate->rect.width;
    else if (button->state == HOVER)
        button->img->animate->rect.left = button->img->animate->rect.width * 2;
    else
        button->img->animate->rect.left = 0;
}

static void compute_state_button_settings(gui_obj_t *button, guis_t *guis)
{
    if (button->state == RELEASED) {
        guis->active = OPTIONS;
        button->state = NO_STATE;
    }
    if (button->state == PRESSED)
        button->img->animate->rect.left = button->img->animate->rect.width;
    else if (button->state == HOVER)
        button->img->animate->rect.left = button->img->animate->rect.width * 2;
    else
        button->img->animate->rect.left = 0;
}

static void compute_state_button_continuer(gui_obj_t *button, guis_t *guis,
    game_t *game)
{
    sfSprite_setColor(button->img->sprite, sfWhite);
    if (button->state == RELEASED) {
        guis->active = MAP;
        button->state = NO_STATE;
        game->quests = continue_quest(game);
        if (guis->map->ui_content)
            destroy_map(guis->map->ui_content);
        guis->map->ui_content = init_continue_game_map(game);
        guis->shop_in_game->ui_content = init_shop(game->assets,
            ((map_t *)(guis->map->ui_content))->player->class);
        sfMusic_stop(game->music->menu_theme);
        sfMusic_play(game->music->main_theme);
        set_general_volume(game);
    }
    if (button->state == PRESSED)
        button->img->animate->rect.left = button->img->animate->rect.width;
    else if (button->state == HOVER)
        button->img->animate->rect.left = button->img->animate->rect.width * 2;
    else
        button->img->animate->rect.left = 0;
}

static void compute_state_button_nouveau(gui_obj_t *button, guis_t *guis,
    game_t *game)
{
    if (button->state == RELEASED) {
        close(game->savefile);
        game->savefilepath = NULL;
        game->savefile = open(game->savefilepath,
            O_CREAT | O_RDWR | O_TRUNC, 0777);
        if (guis->map->ui_content)
            destroy_map(guis->map->ui_content);
        guis->map->ui_content = init_new_game_map(game);
        guis->active = CHOOSE_CLASS;
        button->state = NO_STATE;
    }
    if (button->state == PRESSED)
        button->img->animate->rect.left = button->img->animate->rect.width;
    else if (button->state == HOVER)
        button->img->animate->rect.left = button->img->animate->rect.width * 2;
    else
        button->img->animate->rect.left = 0;
}

static void compute_state_button_retour(gui_obj_t *button, guis_t *guis)
{
    if (button->state == RELEASED) {
        guis->active = MAIN_MENU;
        button->state = NO_STATE;
    }
    if (button->state == PRESSED)
        button->img->animate->rect.left = button->img->animate->rect.width;
    else if (button->state == HOVER)
        button->img->animate->rect.left = button->img->animate->rect.width * 2;
    else
        button->img->animate->rect.left = 0;
}

static void compute_state_button_quitter(gui_obj_t *button,
    sfRenderWindow *window)
{
    if (button->state == RELEASED)
        close_window(window);
    if (button->state == PRESSED)
        button->img->animate->rect.left = button->img->animate->rect.width;
    else if (button->state == HOVER)
        button->img->animate->rect.left = button->img->animate->rect.width * 2;
    else
        button->img->animate->rect.left = 0;
}

void compute_state_buttons(main_t *menu, game_t *game)
{
    compute_state_button_play(menu->play, game->guis);
    compute_state_button_settings(menu->settings, game->guis);
    compute_state_button_quitter(menu->quit, game->window);
}

char **get_res(char *file)
{
    if (file)
        return my_str_to_word_array(file, "\n", 0);
    return NULL;
}

void compute_state_buttons_two(start_t *menu, game_t *game)
{
    static char *file = NULL;
    static char **res = NULL;
    static int count = 0;

    sfSprite_setColor(menu->continues->img->sprite, TRANSPARENT);
    if (game->savefile != -1 && strlen(game->savefilepath) > 3) {
        if (count <= 0) {
            file = import_from_save("Quest",
                game->savefilepath);
            res = get_res(file);
            count = 120;
        }
        if (!(!res || my_pointlen(res) != 2 || (my_getnbr(res[1]) == 0
            && res[1][0] != '0')))
            compute_state_button_continuer(menu->continues, game->guis, game);
    }
    compute_state_button_nouveau(menu->nouveau, game->guis, game);
    compute_state_button_retour(menu->retour, game->guis);
    count--;
}
