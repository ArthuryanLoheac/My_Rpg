/*
** EPITECH PROJECT, 2024
** make_map
** File description:
** make_map
*/

#include "my.h"

static void go_to_menu(game_t *game)
{
    map_t *map = (map_t *)game->guis->map->ui_content;
    start_t *main_menu = ((start_t *)(game->guis->main_menu->ui_content));

    chapter_transition(game, "YOU DIED", "TRY AGAIN", sfRed);
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

void character_death(game_t *game)
{
    map_t *map = (map_t *)game->guis->map->ui_content;
    static int check = 0;

    if (check == 0) {
        map->player->movmult = 0;
        map->fade->is_active = true;
        check = 1;
        return;
    }
    if (map->fade->is_active == true)
        return;
    set_volume_for_musics(game->music, 0.);
    set_volume_for_sounds(game->sounds, 0.);
    go_to_menu(game);
    set_general_volume(game);
    check = 0;
}
