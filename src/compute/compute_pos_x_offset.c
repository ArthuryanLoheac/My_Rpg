/*
** EPITECH PROJECT, 2024
** compute_pos_x_offset
** File description:
** compute_pos_x_offset
*/
#include "my.h"
#include "gui_struct.h"

static void compute_pos_buttons(int off, int *i, page_shop_item_t *item)
{
    sfSprite_setPosition(item->buy->img->sprite,
        (sfVector2f){1290, 320 + off + *i * 100});
    sfSprite_setPosition(item->sell->img->sprite,
        (sfVector2f){1160, 320 + off + *i * 100});
    sfRectangleShape_setPosition(item->buy->rect,
        (sfVector2f){1290, 320 + off + *i * 100});
    sfRectangleShape_setPosition(item->sell->rect,
        (sfVector2f){1160, 320 + off + *i * 100});
    (*i)++;
}

void compute_pos_x_offset(linked_list_t *lst, int offset)
{
    page_shop_item_t *item;
    int off = offset * -100;
    int i = 0;

    while (lst) {
        item = ((page_shop_item_t *)(lst->data));
        sfSprite_setPosition(item->item->icon->sprite,
            (sfVector2f){660, 345 + off + i * 100});
        sfSprite_setPosition(item->item->background->sprite,
            (sfVector2f){613, 300 + off + i * 100});
        sfText_setPosition(item->name->txt, (sfVector2f)
            {730, 320 + off + i * 100});
        sfText_setPosition(item->nb_buy_txt->txt,
            (sfVector2f){1244, 340 + off + i * 100});
        sfText_setPosition(item->price_txt->txt,
            (sfVector2f){sfText_getPosition(item->price_txt->txt).x,
            360 + off + i * 100});
        compute_pos_buttons(off, &i, item);
        lst = lst->next;
    }
}
