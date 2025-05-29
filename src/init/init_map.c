/*
** EPITECH PROJECT, 2024
** init_map
** File description:
** init_map
*/

#include "my.h"

//val should be between 0 and 1, 1 being the end
void loading_screen(game_t *game, float val)
{
    val = 1 - val;
    sfView_setSize(game->view, (sfVector2f){val * 1920, val * 1080});
    sfRenderWindow_setView(game->window, game->view);
    val *= 255;
    sfSprite_setColor(((main_t *)(game->guis->main_menu->ui_content))
        ->background->sprite, (sfColor){val, val, val, 255});
    sfRenderWindow_drawSprite(game->window, ((main_t *)
        (game->guis->main_menu->ui_content))->background->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, ((main_t *)
        (game->guis->main_menu->ui_content))->hero->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, ((main_t *)
        (game->guis->main_menu->ui_content))->building_one->sprite, NULL);
    sfRenderWindow_display(game->window);
    sfSprite_setColor(((main_t *)(game->guis->main_menu->ui_content))
        ->background->sprite, sfWhite);
}

static void set_map_null(map_t *map)
{
    map->fight_tools = NULL;
    map->fight_fx = NULL;
    map->dice = NULL;
    map->entity_area = NULL;
}

static void init_common_map(game_t *game, map_t *map, bool new_game)
{
    map->player = init_player(game, new_game);
    map->entity_all = init_main_entity(map->player, game, new_game, map);
    map->escape_menu = init_escape_menu(game);
    map->level_menu = init_level_menu(game);
    map->view_clock = init_time();
    map->view_speed = PLAYER_SPEED;
    map->dialogue = NULL;
    game->player = map->player;
    map->fight = init_new_game_fight(game);
    map->inventory->player = map->player;
    map->inventory->stats_area = init_stats_area(map->player->stats,
        game->assets, map->player->class);
    map->player->inventory = map->inventory->inventory;
    set_map_null(map);
    map->night = init_night(game, new_game);
    map->fade = init_fade(game);
    map->quest_ui = init_quest_ui(game);
    map->weather = init_weather();
}

map_t *init_new_game_map(game_t *game)
{
    map_t *map = malloc(sizeof(map_t));

    map->player = init_player(game, true);
    map->inventory = init_inventory(true, NULL, game->assets);
    map->dialogue_pipeline = init_diag_pipe(game->assets);
    map->portrait = init_portrait(game->assets);
    map->map_nc = load_map(game, "Night_City/", (sfVector2u){11, 9}, true);
    map->map = map->map_nc;
    init_common_map(game, map, true);
    map->view = init_view(game->window);
    map->target_view = sfView_getCenter(map->view);
    sfRenderWindow_setView(game->window, map->view);
    return map;
}

map_t *init_continue_game_map(game_t *game)
{
    map_t *map = malloc(sizeof(map_t));

    map->player = init_player(game, false);
    map->inventory = init_inventory(false, game, game->assets);
    map->dialogue_pipeline = init_diag_pipe(game->assets);
    map->portrait = init_portrait(game->assets);
    map->map_nc = load_map(game, "Night_City/", (sfVector2u){11, 9}, true);
    map->map = map->map_nc;
    init_common_map(game, map, false);
    map->map = init_game_map(game, false, map);
    map->view = init_continueview(game->window,
        sfSprite_getPosition(game->player->sprite->temp->sprite), game);
    map->target_view = sfView_getCenter(map->view);
    sfRenderWindow_setView(game->window, map->view);
    map->fade->overlay = sfBlack;
    map->fade->is_active = true;
    return map;
}
