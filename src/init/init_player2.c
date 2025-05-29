/*
** EPITECH PROJECT, 2024
** init_player
** File description:
** init_player
*/

#include "my.h"

pc_sprite_t *init_player_sprite(assets_t **assets, sfVector2f start_pos)
{
    pc_sprite_t *sprite = malloc(sizeof(pc_sprite_t));
    sfFloatRect rect;

    sprite->direction = 8;
    sprite->temp = init_image(get_asset("Hero_Blue", assets),
        (sfVector2f)start_pos, 1);
    init_animated_img(sprite->temp, 96, 96, (sfVector2f)start_pos);
    set_animate_image(sprite->temp, 4, 1, 4);
    sprite->temp->animate->animation_time = 0.2;
    sprite->direction = 8;
    rect = sfSprite_getGlobalBounds(sprite->temp->sprite);
    sfSprite_setOrigin(sprite->temp->sprite,
        (sfVector2f){rect.width / 2, rect.height / 2});
    sprite->temp->animate->rect.top = sprite->temp->animate->rect.height * 4;
    return sprite;
}
