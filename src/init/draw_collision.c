/*
** EPITECH PROJECT, 2024
** My_Rpg
** File description:
** draw_collision
*/

#include "my.h"

void draw_collision(sfVector2f pos, map_t *map)
{
    int col = (int)(pos.x / 1920);
    int line = (int)(pos.y / 1080);
    int x = ((int)(pos.x) % 1920 / 4);
    int y = ((int)(pos.y) % 1080 / 4);

    if (pos.x >= (1920 * 9) || pos.x < 0 ||
        pos.y >= (1080 * 11) || pos.y < 0)
        return;
    sfImage_setPixel(map->map->map[line][col]->col,
        x, y, sfBlack);
}

void draw_collision_panel(sfVector2f pos, map_panel_image_t *map)
{
    int col = (int)(pos.x / 1920);
    int line = (int)(pos.y / 1080);
    int x = ((int)(pos.x) % 1920 / 4);
    int y = ((int)(pos.y) % 1080 / 4);

    if (pos.x >= (1920 * 9) || pos.x < 0 ||
        pos.y >= (1080 * 11) || pos.y < 0)
        return;
    sfImage_setPixel(map->map[line][col]->col,
        x, y, sfBlack);
}

void draw_rectangle(map_t *map, sfVector2f pos,
    sfVector2f x_values, sfVector2f y_values)
{
    for (int i = x_values.x; i < x_values.y; i++) {
        for (int j = y_values.x; j < y_values.y; j++) {
            draw_collision((sfVector2f){pos.x + i, pos.y + j}, map);
        }
    }
}

void draw_rectangle_panel(map_panel_image_t *map, sfVector2f pos,
    sfVector2f x_values, sfVector2f y_values)
{
    for (int i = x_values.x; i < x_values.y; i++) {
        for (int j = y_values.x; j < y_values.y; j++) {
            draw_collision_panel((sfVector2f){pos.x + i, pos.y + j}, map);
        }
    }
}
