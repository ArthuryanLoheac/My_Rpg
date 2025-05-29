/*
** EPITECH PROJECT, 2024
** init_map
** File description:
** init_map
*/

#include "my.h"

static img_map_t *init_any_img_map(int r, int c, char *prefix)
{
    img_map_t *map;

    map = malloc(sizeof(img_map_t));
    map->is_load = false;
    map->map = init_image(append_str(append_str(
        append_str(append_str("./assets/map/", prefix), int_to_str(r + 1)),
            append_str("-", int_to_str(c + 1))), ".png"), (sfVector2f){1920 *
            (c), 1080 * (r)}, 4);
    map->col = sfImage_createFromFile(append_str(append_str(
        append_str(append_str("./assets/col/", prefix), int_to_str(r + 1)),
            append_str("-", int_to_str(c + 1))), ".png"));
    if (map->col == NULL) {
        fprintf(stderr, "Missing file in /assets/col/\n");
        exit(84);
    }
    return map;
}

static map_panel_image_t *ret_map_free_map(game_t *game,
    map_panel_image_t *map)
{
    free(map);
    return ((map_t *)(game->guis->map->ui_content))->map;
}

static void load_game_screen(game_t *game, map_panel_image_t *map,
    sfVector2u size, char *asset_map_name)
{
    sfEvent temp;

    for (int r = 0; r < (int)size.x; r++) {
        map->map[r] = malloc(sizeof(img_map_t *) * ((int)size.y + 1));
        map->map[r][(int)size.y] = NULL;
        for (int c = 0; c < (int)size.y; c++) {
            map->map[r][c] = init_any_img_map(r, c, asset_map_name);
            loading_screen(game,
            ((float)(r * (int)size.y + c)) / ((int)size.x * (int)size.y));
        }
        while (sfRenderWindow_pollEvent(game->window, &temp));
    }
}

map_panel_image_t *load_map(game_t *game, char *asset_map_name,
    sfVector2u size, bool force)
{
    map_panel_image_t *map = malloc(sizeof(map_panel_image_t));

    if (!force && ((map_t *)game->guis->map->ui_content)->fight->is_fight)
        return ret_map_free_map(game, map);
    sfRenderWindow_setFramerateLimit(game->window, 100);
    map->current_map = my_strdup(asset_map_name);
    map->map = malloc(sizeof(img_map_t **) * ((int)size.x + 1));
    map->map[(int)size.x] = NULL;
    load_game_screen(game, map, size, asset_map_name);
    sfRenderWindow_setFramerateLimit(game->window, 60);
    return map;
}

map_panel_image_t *load_game_map(game_t *game, char *asset_map_name,
    sfVector2u size)
{
    if (((map_t *)(game->guis->map->ui_content))->fight->is_fight)
        return ((map_t *)(game->guis->map->ui_content))->map;
    if (my_strcmp("Night_City/", asset_map_name) == 0)
        return ((map_t *)(game->guis->map->ui_content))->map_nc;
    else
        return load_map(game, asset_map_name, size, false);
}

void load_house1(game_t *game, map_t *map)
{
    sfSprite_setPosition(map->player->sprite->temp->sprite, (sfVector2f){920,
        550});
    sfView_setCenter(map->view, (sfVector2f){920, 550});
    if (my_strcmp("Night_City/", map->map->current_map) != 0)
        destroy_game_map(map->map);
    map->map = load_game_map(game, "QueenHouse/", (sfVector2u){1, 1});
    set_npc_item_hidden(map->entity_all);
    get_scatter(3, map->entity_all)->hidden = false;
}

void load_briefing(game_t *game, map_t *map)
{
    sfSprite_setPosition(map->player->sprite->temp->sprite, (sfVector2f){128,
        380});
    sfView_setCenter(map->view, (sfVector2f){128, 380});
    if (my_strcmp("Night_City/", map->map->current_map) != 0)
        destroy_game_map(map->map);
    map->map = load_game_map(game, "Briefing/", (sfVector2u){1, 1});
    set_npc_item_hidden(map->entity_all);
}

void load_nc(game_t *game, map_t *map)
{
    sfSprite_setPosition(map->player->sprite->temp->sprite, (sfVector2f){13300,
        9100});
    if (my_strcmp("Night_City/", map->map->current_map) != 0)
        destroy_game_map(map->map);
    map->map = load_game_map(game, "Night_City/", (sfVector2u){11, 9});
    set_npc_item_hidden(map->entity_all);
    set_npc_shown(map->entity_all, "Mook1", false);
    set_npc_shown(map->entity_all, "Mook2", false);
    get_scatter(1, map->entity_all)->hidden = false;
    get_scatter(3, map->entity_all)->hidden = false;
    set_scatter_shown(9, map->entity_all);
}
