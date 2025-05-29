/*
** EPITECH PROJECT, 2024
** compute_guis
** File description:
** compute_guis
*/

#include "my.h"

void set_clothes_color(linked_list_t *lst, sfColor col)
{
    while (lst) {
        sfSprite_setColor(((img_t *)(lst->data))->sprite, col);
        lst = lst->next;
    }
}

void compute_talk(game_t *game, npc_t *npc)
{
    if (((map_t *)(game->guis->map->ui_content))->fight->is_fight == false &&
        npc->talkable == YES_TL && get_distance(sfSprite_getPosition(
        game->player->sprite->temp->sprite), sfSprite_getPosition(npc
        ->npc->sprite)) < 100) {
        if (sfKeyboard_isKeyPressed(game->keybinds->interact) == sfTrue)
            npc->talkable = IS_TL;
        sfSprite_setColor(npc->npc->sprite, sfColor_fromRGB(255, 255, 200));
        set_clothes_color(npc->clothes, sfColor_fromRGB(255, 255, 20));
    } else {
        if (sfSprite_getColor(npc->npc->sprite).b == 200) {
            sfSprite_setColor(npc->npc->sprite, sfWhite);
            set_clothes_color(npc->clothes, sfWhite);
        }
    }
}
