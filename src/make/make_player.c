/*
** EPITECH PROJECT, 2024
** make_player
** File description:
** make_player, own function because it will probably be extened with weapon
** and armor displaying
*/

#include "my.h"

static int check_make_armor(img_t *img, player_character_t *player,
    sfRenderWindow *window, int id)
{
    if (player->id_active_armor == id)
        make_img(img, window);
    return 1;
}

static bool is_armor(img_t *img, player_character_t *player,
    sfRenderWindow *window)
{
    if (!my_strcmp("Leather_Armor", img->name))
        return check_make_armor(img, player, window, 1);
    if (!my_strcmp("Kevlar_Armor", img->name))
        return check_make_armor(img, player, window, 2);
    if (!my_strcmp("Light_Armorjack", img->name))
        return check_make_armor(img, player, window, 3);
    if (!my_strcmp("Medium_Armorjack", img->name))
        return check_make_armor(img, player, window, 4);
    if (!my_strcmp("Heavy_Armorjack", img->name))
        return check_make_armor(img, player, window, 5);
    if (!my_strcmp("Flak_Armor", img->name))
        return check_make_armor(img, player, window, 6);
    if (!my_strcmp("Metalgear_Armor", img->name))
        return check_make_armor(img, player, window, 7);
    return 0;
}

static void check_print_if_no_armor(linked_list_t *lst,
    player_character_t *player, sfRenderWindow *window)
{
    if (!is_armor(lst->data, player, window))
        make_img(lst->data, window);
}

void make_player(sfRenderWindow *window, player_character_t *player)
{
    linked_list_t *element = *(&(player->sprite->clothes));

    make_img(player->sprite->temp, window);
    if (sfSprite_getColor(player->sprite->temp->sprite).a > 1) {
        while (element) {
            check_print_if_no_armor(element, player, window);
            element = element->next;
        }
    }
}
