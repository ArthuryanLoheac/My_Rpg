/*
** EPITECH PROJECT, 2024
** make make_inventory
** File description:
** make_inventory
*/

#include "my.h"

void make_durability_bar(sfRenderWindow *window, gui_inventory_t *inventory,
    item_t *item)
{
    sfRectangleShape_setPosition(inventory->durability, add(
        sfSprite_getPosition(item->icon->sprite), -40, -58));
    sfRectangleShape_setSize(inventory->durability, (sfVector2f){80, 6});
    sfRectangleShape_setFillColor(inventory->durability, sfRed);
    sfRenderWindow_drawRectangleShape(window, inventory->durability, NULL);
    sfRectangleShape_setPosition(inventory->durability, add(
        sfSprite_getPosition(item->icon->sprite), -40, -58));
    sfRectangleShape_setSize(inventory->durability, (sfVector2f){80 * ((float)
        item->weapon->durability.x / item->weapon->durability.y), 6});
    sfRectangleShape_setFillColor(inventory->durability, sfGreen);
    sfRenderWindow_drawRectangleShape(window, inventory->durability, NULL);
}

static void draw_item_ui(sfRenderWindow *window, gui_inventory_t *inventory,
    item_t *item)
{
    char *tmp = malloc(sizeof(char) * 12);

    tmp[0] = 0;
    if (item->type == WEAPON && item->id < 310) {
        sprintf(tmp, "%d/%d\n", item->weapon->magazine.x,
            item->weapon->magazine.y);
        make_durability_bar(window, inventory, item);
    }
    if (item->type == ARMOR)
        sprintf(tmp, "%d/%d\n", item->armor->sp.x, item->armor->sp.y);
    if (item->type == AMMO)
        sprintf(tmp, "%d/%d\n", item->ammo->amount.x, item->ammo->amount.y);
    if (item->type == DRUGS)
        sprintf(tmp, "%u/%u\n", item->drug->uses.x, item->drug->uses.y);
    sfText_setPosition(inventory->item_info->txt,
        add(sfSprite_getPosition(item->icon->sprite), -50, 40));
    sfText_setString(inventory->item_info->txt, tmp);
    sfRenderWindow_drawText(window, inventory->item_info->txt, NULL);
    free(tmp);
}

static void display_items(sfRenderWindow *window,
    gui_inventory_t *inventory)
{
    item_t *item;

    for (int i = 0; i < 20; i++) {
        if (!inventory->inventory->main_slots[i])
            continue;
        item = inventory->inventory->main_slots[i]->items;
        if (item && item->icon) {
            make_img(item->icon, window);
            draw_item_ui(window, inventory, item);
        }
    }
}

static void make_inventory_slots(sfRenderWindow *window,
    gui_inventory_t *inventory)
{
    item_t *item;

    for (int i = 0; i < 20; i++) {
        if (!inventory->inventory->main_slots[i])
            continue;
        make_img(inventory->inventory->main_slots[i]->background, window);
    }
    display_items(window, inventory);
    if (inventory->items_slots_picked != -1) {
        item = inventory->inventory->main_slots[inventory->items_slots_picked]
            ->items;
        if (item && item->icon) {
            make_img(item->icon, window);
            draw_item_ui(window, inventory, item);
        }
    }
}

void make_inventory(sfRenderWindow *window, gui_inventory_t *inventory)
{
    if (inventory->is_display == true) {
        make_img(inventory->background, window);
        make_img(inventory->stats->player_img, window);
        make_img(inventory->stats->health_bar, window);
        make_img(inventory->quest->area, window);
        sfRenderWindow_drawText(window, inventory->quest->text, NULL);
        sfRenderWindow_drawText(window, inventory->stats_area->text, NULL);
        make_img(inventory->logo->logo_img, window);
        sfRenderWindow_drawText(window, inventory->logo->txt->txt, NULL);
        make_inventory_slots(window, inventory);
        sfRenderWindow_drawRectangleShape(window, inventory->player->xp_data->
            background, NULL);
        sfRenderWindow_drawRectangleShape(window, inventory->player->xp_data->
            xp_bg, NULL);
        sfRenderWindow_drawText(window, inventory->player->xp_data->niv_label,
            NULL);
    }
}
