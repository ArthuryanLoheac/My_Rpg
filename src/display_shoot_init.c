/*
** EPITECH PROJECT, 2024
** display shoot
** File description:
** display_shoot
*/

#include "my.h"

static sfVector2f get_vector(float angle_degrees)
{
    float angle_radians = angle_degrees * (M_PI / 180.0f);
    float cos_val = cos(angle_radians);
    float sin_val = sin(angle_radians);

    return (sfVector2f){cos_val, sin_val};
}

static void bullet_alloc(bullet_fight_t *data, float angle)
{
    data->time = malloc(sizeof(time2_t));
    data->time->clock = sfClock_create();
    data->vector = get_vector(angle);
}

bullet_fight_t *init_fight_shotgun_bullets(assets_t **assets,
    sfVector2f pos, float angle, int type)
{
    bullet_fight_t *data = malloc(sizeof(bullet_fight_t));
    sfFloatRect sp_weapon;

    data->bullet = init_image(get_asset("SHOTGUN_BULLET", assets), pos, 1);
    sfSprite_setRotation(data->bullet->sprite, angle);
    if (type == -1)
        data->weapon = NULL;
    else {
        data->weapon = init_image(get_asset("SHOTGUN", assets), pos, 1);
        sfSprite_setRotation(data->weapon->sprite, angle - 90);
        sp_weapon = sfSprite_getGlobalBounds(data->weapon->sprite);
        sfSprite_setOrigin(data->weapon->sprite, (sfVector2f){sp_weapon.width
            / 2, sp_weapon.height / 2});
    }
    bullet_alloc(data, angle - 90);
    return data;
}

static void init_fight_ranged_bullets_hit(game_t *game,
    sfVector2f pos, int type, bullet_fight_t *data)
{
    if (type == PISTOL || type == HPISTOL) {
        data->weapon = init_image(get_asset("PISTOLET", game->assets), pos, 1);
        sfSound_play(game->sounds->pistolet->sound);
    }
    if (type == SNIPER) {
        data->weapon = init_image(get_asset("SNIPER", game->assets), pos, 1);
        sfSound_play(game->sounds->sniper->sound);
    }
    if (type == RIFLE) {
        data->weapon = init_image(get_asset("ASSAULT_RIFFLE", game->assets),
            pos, 1);
        sfSound_play(game->sounds->assault_rifle->sound);
    }
    if (type == SMG) {
        data->weapon = init_image(get_asset("SMG", game->assets), pos, 1);
        sfSound_play(game->sounds->smg->sound);
    }
}

bullet_fight_t *init_fight_ranged_bullets(game_t *game,
    sfVector2f pos, float angle, int type)
{
    bullet_fight_t *data = malloc(sizeof(bullet_fight_t));
    sfFloatRect sp_weapon;

    data->bullet = init_image(get_asset("BULLET", game->assets), pos, 1);
    sfSprite_setRotation(data->bullet->sprite, angle + 90);
    if (type == -1)
        data->weapon = NULL;
    else {
        init_fight_ranged_bullets_hit(game, pos, type, data);
        sfSprite_setRotation(data->weapon->sprite, angle);
        if (angle > 90 || angle < -90)
            sfSprite_setScale(data->weapon->sprite, (sfVector2f){1, -1});
        sp_weapon = sfSprite_getGlobalBounds(data->weapon->sprite);
        sfSprite_setOrigin(data->weapon->sprite, (sfVector2f){sp_weapon.width
            / 2, sp_weapon.height / 2});
    }
    bullet_alloc(data, angle);
    return data;
}

static void check_rocket_weapons_hit(game_t *game, int type,
    sfVector2f pos, bullet_fight_t *data)
{
    if (type == NADL) {
        data->weapon = init_image(get_asset("NADL", game->assets), pos, 1);
        sfSound_play(game->sounds->nadl->sound);
    }
    if (type == ROCKET_L) {
        data->weapon = init_image(get_asset("ROCKET_L",
            game->assets), pos, 1);
        sfSound_play(game->sounds->rocket_l->sound);
    }
}

bullet_fight_t *init_fight_rocket_bullets(game_t *game,
    sfVector2f pos, float angle, int type)
{
    bullet_fight_t *data = malloc(sizeof(bullet_fight_t));
    sfFloatRect sp_weapon;

    data->bullet = init_image(get_asset("ROCKET", game->assets), pos, 1);
    sfSprite_setRotation(data->bullet->sprite, angle);
    if (type == -1)
        data->weapon = NULL;
    else {
        check_rocket_weapons_hit(game, type, pos, data);
        sfSprite_setRotation(data->weapon->sprite, angle - 90);
        sp_weapon = sfSprite_getGlobalBounds(data->weapon->sprite);
        sfSprite_setOrigin(data->weapon->sprite, (sfVector2f){sp_weapon.width
            / 2, sp_weapon.height / 2});
    }
    bullet_alloc(data, angle);
    return data;
}
