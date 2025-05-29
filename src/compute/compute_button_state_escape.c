/*
** EPITECH PROJECT, 2024
** My_Rpg
** File description:
** compute_button_state_escape
*/


#include "my.h"

void go_to_menu2(game_t *game)
{
    map_t *map = (map_t *)game->guis->map->ui_content;
    start_t *main_menu = ((start_t *)(game->guis->main_menu->ui_content));

    main_menu->background = init_image(get_asset("Start_Menu_BG",
        game->assets), vect0(), 1);
    sfView_setCenter(map->view, vect0());
    init_animated_img(main_menu->background, 1080, 1920,
        vect0());
    set_animate_image(main_menu->background, 4, 1, 4);
    loading_screen(game, 0);
    update_menu_music(game);
    game->espace_active = false;
    game->level_up_active = false;
    game->guis->active = MAIN_MENU;
    map->player->movmult = 1;
}

static void update_state_button_save(button_t *button, game_t *game)
{
    if (((map_t *)(game->guis->map->ui_content))->fight->is_fight) {
        sfSprite_setColor(button->gui_obj->img->sprite, TRANSPARENT);
        sfText_setColor(button->text->txt, TRANSPARENT);
    } else {
        sfSprite_setColor(button->gui_obj->img->sprite, sfWhite);
        sfText_setColor(button->text->txt, sfWhite);
        if (button->gui_obj->state == RELEASED) {
            save_data(game);
            button->gui_obj->state = NO_STATE;
        }
        compute_default_state_button(button);
    }
}

static int update_state_button_load(button_t *button, game_t *game)
{
    if (button->gui_obj->state == RELEASED) {
        if (game->guis->map->ui_content)
            destroy_map(game->guis->map->ui_content);
        game->guis->map->ui_content = init_continue_game_map(game);
        game->espace_active = false;
        button->gui_obj->state = NO_STATE;
        return 1;
    }
    compute_default_state_button(button);
    return 0;
}

static void update_state_button_quitter(gui_obj_t *button, game_t *game)
{
    if (button->state == RELEASED) {
        close_window(game->window);
        button->state = NO_STATE;
    }
    if (button->state == PRESSED)
        button->img->animate->rect.left = button->img->animate->rect.width;
    else if (button->state == HOVER)
        button->img->animate->rect.left = button->img->animate->rect.width * 2;
    else
        button->img->animate->rect.left = 0;
}

static void update_state_button_options(gui_obj_t *button, game_t *game)
{
    if (button->state == RELEASED) {
        game->retour_options_in_game = sfTrue;
        game->guis->active = OPTIONS;
        button->state = NO_STATE;
    }
    if (button->state == PRESSED)
        button->img->animate->rect.left = button->img->animate->rect.width;
    else if (button->state == HOVER)
        button->img->animate->rect.left = button->img->animate->rect.width * 2;
    else
        button->img->animate->rect.left = 0;
}

void update_menu_music(game_t *game)
{
    if (game->music->main_theme != NULL)
        sfMusic_stop(game->music->main_theme);
    if (game->music->combat_music != NULL)
        sfMusic_stop(game->music->combat_music);
    sfMusic_play(game->music->menu_theme);
}

static void update_state_button_main_menu(button_t *button,
    game_t *game, map_t *map)
{
    start_t *main_menu = NULL;

    if (button->gui_obj->state == RELEASED) {
        main_menu = ((start_t *)(game->guis->main_menu->ui_content));
        main_menu->background = init_image(get_asset("Start_Menu_BG",
            game->assets), vect0(), 1);
        sfView_setCenter(map->view, vect0());
        init_animated_img(main_menu->background, 1080, 1920,
            vect0());
        set_animate_image(main_menu->background, 4, 1, 4);
        if (!((map_t *)(game->guis->map->ui_content))->fight->is_fight)
            save_data(game);
        loading_screen(game, 0);
        update_menu_music(game);
        game->espace_active = false;
        game->level_up_active = false;
        game->guis->active = MAIN_MENU;
        button->gui_obj->state = NO_STATE;
    }
    compute_default_state_button(button);
}

void compute_button_state_escape(map_t *map, game_t *game)
{
    update_state_button_quitter(map->escape_menu->quit, game);
    update_state_button_options(map->escape_menu->options, game);
    if (game->savefile == -1)
        sfSprite_setColor(map->escape_menu->load->gui_obj->img->sprite,
            sfColor_fromRGBA(255, 255, 255, 128));
    else {
        sfSprite_setColor(map->escape_menu->load->gui_obj->img->sprite,
            sfWhite);
        if (update_state_button_load(map->escape_menu->load, game))
            return;
    }
    update_state_button_save(map->escape_menu->save, game);
    update_state_button_main_menu(map->escape_menu->main_menu, game, map);
}
