/*
** EPITECH PROJECT, 2024
** My_Rpg
** File description:
** init_houses_entity
*/

#include "my.h"

static void analyze_pixel_image(params_t params,
    game_t *game, linked_list_t **ll, map_t *map)
{
    if (!check_all_houses(params, game, ll, map)) {
        check_pos_scatters(params, game->assets, ll, map);
    }
}

static void analyze_one_image(map_t *map, sfVector2i lc,
    game_t *game, linked_list_t **ll)
{
    params_t params;

    for (int y = 0; y < 270; y++) {
        for (int x = 0; x < 480; x++) {
            params.color = sfImage_getPixel(
                map->map->map[lc.x][lc.y]->col, x, y);
            params.pos.y = lc.x * 270 + y;
            params.pos.x = lc.y * 480 + x;
            analyze_pixel_image(params, game, ll, map);
        }
    }
}

static void update_txt_loading(game_t *game, int i)
{
    char *str = my_strdup("Loading");
    label_t *lab = NULL;

    if (i % 24 >= 18)
        str = append_str(str, ".");
    if (i % 24 >= 12)
        str = append_str(str, ".");
    if (i % 24 >= 6)
        str = append_str(str, ".");
    lab = init_label(str, (sfVector2f){(1920 / 2) - 3.5, 1080 / 2 - 1.5}, 80,
        get_asset("Font_pixel", game->assets));
    sfText_setScale(lab->txt, (sfVector2f){0.0125, 0.0125});
    sfRenderWindow_drawText(game->window, lab->txt, NULL);
    destroy_label(lab);
    free(str);
}

static void charging_bar(game_t *game, int i)
{
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRenderWindow_clear(game->window, sfBlack);
    update_txt_loading(game, i);
    sfRectangleShape_setPosition(rect, (sfVector2f){(1920 / 2) - 6, 1080 / 2});
    sfRectangleShape_setScale(rect, (sfVector2f){0.05, 0.05});
    sfRectangleShape_setSize(rect, (sfVector2f){99 * 2.5, 10});
    sfRectangleShape_setFillColor(rect, sfWhite);
    sfRenderWindow_drawRectangleShape(game->window, rect, NULL);
    sfRectangleShape_setSize(rect, (sfVector2f){(i + 1) * 2.5, 10});
    sfRectangleShape_setFillColor(rect, sfColor_fromRGBA(121, 68, 245, 255));
    sfRenderWindow_drawRectangleShape(game->window, rect, NULL);
    sfRenderWindow_display(game->window);
    sfRectangleShape_destroy(rect);
}

static void init_multiple_civils(game_t *game, linked_list_t **ll, int *i)
{
    sfVector2f pos = {0, 0};
    sfEvent temp;

    for (int j = 0; j < 10; j++) {
        pos = (sfVector2f){
            ((i[1] * 1920) + 960) + (rand() % 1920 - 960),
            ((i[0] * 1080) + 540) + (rand() % 1080 - 540)};
        my_insert_front_list(ll, init_civilian(game, pos));
    }
    charging_bar(game, i[2]);
    while (sfRenderWindow_pollEvent(game->window, &temp));
}

void init_houses_entity(linked_list_t **ll, map_t *map, game_t *game)
{
    int i[3] = {0, 0, 0};

    srand(42);
    for (int l = 0; l < 11; l++) {
        for (int c = 0; c < 9; c++) {
            i[0] = l;
            i[1] = c;
            analyze_one_image(map, (sfVector2i){l, c}, game, ll);
            init_multiple_civils(game, ll, i);
            i[2] += 1;
        }
    }
    srand(time(NULL));
}
