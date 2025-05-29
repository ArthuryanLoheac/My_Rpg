/*
** EPITECH PROJECT, 2024
** point_in_rectangle
** File description:
** function that simulates fight between 2 entities
*/

#include "my.h"

bool point_in_rectangle(sfRectangleShape *rect, sfVector2f point)
{
    float angle = sfRectangleShape_getRotation(rect);
    sfFloatRect global_b;

    point = rotate_point(point, sfRectangleShape_getPosition(rect), -angle *
        (M_PI / 180.0));
    sfRectangleShape_setRotation(rect, 0);
    global_b = sfRectangleShape_getGlobalBounds(rect);
    if (sfFloatRect_contains(&global_b, point.x, point.y) == sfTrue) {
        sfRectangleShape_setRotation(rect, angle);
        return true;
    }
    sfRectangleShape_setRotation(rect, angle);
    return false;
}
