/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-matthieu.guillet-arnaud
** File description:
** compute_dice
*/

#include "my.h"

dice_fx_t *init_dice(game_t *game, sfVector2f pos, int res)
{
    dice_fx_t *fx = malloc(sizeof(dice_fx_t));

    fx->img = init_image(get_asset("Dice", game->assets),
        add(pos, 0, - 128), 1);
    sfSprite_setOrigin(fx->img->sprite, (sfVector2f){48, 48});
    sfSprite_setTextureRect(fx->img->sprite, (sfIntRect){0, 0, 96, 96});
    fx->time = init_time();
    fx->result = res;
    fx->sec_todo = 1;
    return fx;
}

static void next_frame(sfIntRect rect, dice_fx_t *tmp)
{
    if (tmp->sec_todo < 0)
        rect.left = (tmp->result - 1) * 96;
    else
        rect.left = rand() % 10 * 96;
    sfSprite_setTextureRect(tmp->img->sprite, rect);
    tmp->sec_todo -= tmp->time->seconds;
    sfClock_restart(tmp->time->clock);
}

static int do_delete_node_dice(linked_list_t **element, dice_fx_t **data_dice)
{
    linked_list_t *next;

    if (!(element && *element && (*element)->prev))
        return 1;
    next = (*element)->next;
    (*element)->prev->next = next;
    if (next)
        next->prev = (*element)->prev;
    destroy_image((*data_dice)->img);
    destroy_time((*data_dice)->time);
    free((*data_dice));
    free((*element));
    *element = next;
    return 0;
}

static int delete_node_dice(map_t *map, linked_list_t **element,
    dice_fx_t **data_dice)
{
    linked_list_t *next = (*element)->next;

    if (map->dice == (*element)) {
        map->dice = next;
        if (map->dice)
            map->dice->prev = NULL;
        destroy_image((*data_dice)->img);
        destroy_time((*data_dice)->time);
        free((*data_dice));
        free((*element));
        (*element) = map->dice;
        return 0;
    } else
        return do_delete_node_dice(element, data_dice);
}

void compute_dice_fx(game_t *game, map_t *map)
{
    linked_list_t **element = &map->dice;
    sfIntRect rect;
    dice_fx_t *tmp;

    while (*element) {
        tmp = (*element)->data;
        update_time(tmp->time);
        rect = sfSprite_getTextureRect(tmp->img->sprite);
        if (tmp->time->seconds > 0.1)
            next_frame(rect, tmp);
        if (tmp->sec_todo < -1 && delete_node_dice(map, element, &tmp))
            return;
        if (!(tmp->sec_todo < -1))
            (*element) = (*element)->next;
    }
    (void) game;
}
