/*
** EPITECH PROJECT, 2024
** compute_recap_shop
** File description:
** compute_recap_shop
*/

#include "my.h"
#include "gui_struct.h"

void compute_recap_inventory(recap_t *recap, game_t *game)
{
    main_slots_t **slots = ((map_t *)(game->guis->map->ui_content))
        ->inventory->inventory->main_slots;
    int j = 0;

    for (int i = 0; i < 20; i++) {
        if (slots[i] && slots[i]->items != NULL) {
            sfText_setString(recap->Inventory[j]->txt, slots[i]->items->name);
            j++;
        }
    }
    for (int x = j; x < 20; x++)
        sfText_setString(recap->Inventory[x]->txt, " ");
}
