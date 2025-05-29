/*
** EPITECH PROJECT, 2024
** init shopp
** File description:
** shop
*/

#include "my.h"

entity_t *init_props(sfVector2f pos, assets_t **assets, bool poor_area)
{
    entity_t *data = malloc(sizeof(entity_t));
    char str[20];

    pos = (sfVector2f){pos.x - 24, pos.y - 24};
    if (!poor_area)
        sprintf(str, "Props_%d", (rand() % 9) + 1);
    else
        sprintf(str, "Props_%d", (rand() % 37) + 1);
    data->type = SCATTER;
    data->scatter = malloc(sizeof(scatter_t));
    data->scatter->scatter = init_image(
        get_asset(str, assets), pos, 1);
    data->scatter->map = my_strdup("Night_City/");
    data->scatter->init_new = NULL;
    data->scatter->interact = false;
    return data;
}

static sfVector2f get_pos_and_draw_rect_col(int random, map_panel_image_t *map,
    sfVector2f pos)
{
    if (random == 10 || random == 11 || random == 15)
        draw_rectangle_panel(map, pos, (sfVector2f){-4, 28}, (sfVector2f){-64,
            -32});
    else if (random == 3 || random == 4 || random == 12)
        draw_rectangle_panel(map, pos, (sfVector2f){-40, 40}, (sfVector2f){-32,
            24});
    else
        draw_rectangle_panel(map, pos, (sfVector2f){-16, 16}, (sfVector2f){-16,
            16});
    if (random == 3 || random == 4 || random == 12)
        return (sfVector2f){pos.x - 48, pos.y - 72};
    return (sfVector2f){pos.x - 24, pos.y - 72};
}

static sfVector2f get_pos_and_draw_rect(int random, map_t *map, sfVector2f pos)
{
    if (random == 10 || random == 11 || random == 15)
        draw_rectangle(map, pos, (sfVector2f){-4, 28}, (sfVector2f){-64, -32});
    else if (random == 3 || random == 4 || random == 12)
        draw_rectangle(map, pos, (sfVector2f){-40, 40}, (sfVector2f){-32, 24});
    else
        draw_rectangle(map, pos, (sfVector2f){-16, 16}, (sfVector2f){-16, 16});
    if (random == 3 || random == 4 || random == 12)
        return (sfVector2f){pos.x - 48, pos.y - 72};
    return (sfVector2f){pos.x - 24, pos.y - 72};
}

entity_t *init_toxic_props(sfVector2f pos, assets_t **assets, map_t *map)
{
    entity_t *data = malloc(sizeof(entity_t));
    char str[20];
    int random = (rand() % 15) + 1;

    sprintf(str, "Barrel_Props_%d", random);
    pos = get_pos_and_draw_rect(random, map, pos);
    data->type = SCATTER;
    data->scatter = malloc(sizeof(scatter_t));
    data->scatter->scatter = init_image(
        get_asset(str, assets), pos, 1);
    data->scatter->map = my_strdup("Night_City/");
    data->scatter->init_new = NULL;
    data->scatter->interact = false;
    return data;
}

entity_t *init_toxic_props_col(sfVector2f pos, assets_t **assets,
    map_panel_image_t *map)
{
    entity_t *data = malloc(sizeof(entity_t));
    char str[20];
    int random = (rand() % 15) + 1;

    sprintf(str, "Barrel_Props_%d", random);
    pos = get_pos_and_draw_rect_col(random, map, pos);
    data->type = SCATTER;
    data->scatter = malloc(sizeof(scatter_t));
    data->scatter->scatter = init_image(
        get_asset(str, assets), pos, 1);
    data->scatter->map = my_strdup("Night_City/");
    data->scatter->init_new = NULL;
    data->scatter->interact = false;
    return data;
}

entity_t *init_bins(sfVector2f pos, assets_t **assets)
{
    entity_t *data = malloc(sizeof(entity_t));
    char str[20];

    pos = (sfVector2f){pos.x - 24, pos.y - 72};
    sprintf(str, "Props_bin_%d", (rand() % 9) + 1);
    data->type = SCATTER;
    data->scatter = malloc(sizeof(scatter_t));
    data->scatter->scatter = init_image(
        get_asset(str, assets), pos, 1);
    data->scatter->map = my_strdup("Night_City/");
    data->scatter->init_new = NULL;
    data->scatter->interact = false;
    return data;
}

static sfVector2f set_pos_lamp(int dir, sfVector2f pos)
{
    if (dir == 0)
        return (sfVector2f){pos.x - 75, pos.y - 180};
    if (dir == 1)
        return (sfVector2f){pos.x - 25, pos.y - 180};
    return (sfVector2f){pos.x - 24, pos.y - 180};
}

entity_t *init_street_lamp(sfVector2f pos, assets_t **assets, int dir)
{
    entity_t *data = malloc(sizeof(entity_t));

    pos = set_pos_lamp(dir, pos);
    data->type = SCATTER;
    data->scatter = malloc(sizeof(scatter_t));
    if (dir < 2)
        data->scatter->scatter = init_image(
            get_asset("Street_Lamp", assets), pos, 1);
    else
        data->scatter->scatter = init_image(
            get_asset("Street_Lamp_simple", assets), pos, 1);
    init_animated_img(data->scatter->scatter, 190, 100, pos);
    if (dir == 0)
        data->scatter->scatter->animate->rect.top = 192;
    data->scatter->map = my_strdup("Night_City/");
    data->scatter->init_new = NULL;
    data->scatter->interact = false;
    return data;
}
