/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-matthieu.guillet-arnaud
** File description:
** compute_bullets
*/

#include "my.h"

fight_fx_t *init_explosion(game_t *game, sfVector2f pos)
{
    fight_fx_t *fx = malloc(sizeof(fight_fx_t));
    sfFloatRect rect;

    fx->hit_ppl = false;
    fx->img = init_image(get_asset("Explosion", game->assets), pos, 8);
    rect = sfSprite_getLocalBounds(fx->img->sprite);
    sfSprite_setOrigin(fx->img->sprite, (sfVector2f){22, 22});
    (void) rect;
    sfSprite_setTextureRect(fx->img->sprite, (sfIntRect){0, 0, 38, 38});
    fx->time = init_time();
    sfSound_play(game->sounds->explosion->sound);
    fx->explosion = true;
    return fx;
}

fight_fx_t *init_bullet(game_t *game, sfVector2f pos, bool hit, float angle)
{
    fight_fx_t *fx = malloc(sizeof(fight_fx_t));
    sfFloatRect rect;

    fx->hit_ppl = hit;
    fx->img = init_image(get_asset("Bullet_hit", game->assets), pos, 2);
    rect = sfSprite_getLocalBounds(fx->img->sprite);
    sfSprite_setOrigin(fx->img->sprite, (sfVector2f){19, 58});
    (void) rect;
    sfSprite_setTextureRect(fx->img->sprite, (sfIntRect){0, 0, 58, 50});
    sfSprite_setRotation(fx->img->sprite, angle + 180);
    if (hit == true) {
        sfSprite_setColor(fx->img->sprite, sfRed);
        sfSound_play(game->sounds->bullet_hit->sound);
    }
    fx->time = init_time();
    fx->explosion = false;
    return fx;
}

static void next_explosion_frame(sfIntRect rect, fight_fx_t *tmp)
{
    rect.left += 38;
    sfSprite_setTextureRect(tmp->img->sprite, rect);
    sfClock_restart(tmp->time->clock);
}

static void next_bullet_frame(sfIntRect rect, fight_fx_t *tmp)
{
    rect.left += 50;
    sfSprite_setTextureRect(tmp->img->sprite, rect);
    sfClock_restart(tmp->time->clock);
}

void compute_fight_fx(game_t *game, map_t *map)
{
    linked_list_t *element = map->fight_fx;
    sfIntRect rect;
    fight_fx_t *tmp;

    while (element) {
        tmp = element->data;
        update_time(tmp->time);
        rect = sfSprite_getTextureRect(tmp->img->sprite);
        if (rect.left >= 100)
            sfSprite_setColor(tmp->img->sprite, sfWhite);
        if (tmp->time->seconds > 0.06 && tmp->explosion == true)
            next_explosion_frame(rect, tmp);
        if (tmp->time->seconds > 0.18 && tmp->explosion == false)
            next_bullet_frame(rect, tmp);
        element = element->next;
    }
    (void) game;
}
