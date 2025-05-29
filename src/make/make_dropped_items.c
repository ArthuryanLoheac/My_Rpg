/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-matthieu.guillet-arnaud
** File description:
** TODO: add description
*/

#include "my.h"

void make_dropped_items(sfRenderWindow *window, linked_list_t *dropped_items)
{
    linked_list_t *elements = dropped_items;
    item_t *items_find = NULL;

    while (elements) {
        items_find = ((entity_t *)(elements->data))->item;
        if (items_find->id / 100 == 3)
            sfSprite_setScale(items_find->icon->sprite, (sfVector2f){
                0.50, 0.50});
        else
            sfSprite_setScale(items_find->icon->sprite, (sfVector2f){
                0.10, 0.10});
        make_img(items_find->icon, window);
        elements = elements->next;
    }
}
