/*
** EPITECH PROJECT, 2024
** set_animate_image
** File description:
** set_animate_image
*/

#include "my.h"

sfVector2f rotate_point(sfVector2f point_to_rotate,
    sfVector2f point_to_turn_around, float angle)
{
    float s = sin(angle);
    float c = cos(angle);
    float x_translated = point_to_rotate.x - point_to_turn_around.x;
    float y_translated = point_to_rotate.y - point_to_turn_around.y;

    return (sfVector2f){(x_translated * c - y_translated * s) +
        point_to_turn_around.x, (x_translated * s + y_translated * c) +
        point_to_turn_around.y};
}

sfVector2f add(sfVector2f pos, float x, float y)
{
    return ((sfVector2f){pos.x + x, pos.y + y});
}

float get_angle(sfVector2f pos1, sfVector2f pos2)
{
    return atan2(pos2.y - pos1.y, pos2.x - pos1.x);
}

double get_angle_degree(sfVector2f pos1, sfVector2f pos2)
{
    return atan2(pos1.y - pos2.y, pos1.x - pos2.x) * (180 / M_PI);
}

sfVector2f normalize(sfVector2f pos)
{
    float length = sqrt(pos.x * pos.x + pos.y * pos.y);

    if (length == 0)
        return pos;
    pos.x = pos.x / length;
    pos.y = pos.y / length;
    return pos;
}
