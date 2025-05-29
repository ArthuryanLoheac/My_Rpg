/*
** EPITECH PROJECT, 2024
** My_Rpg
** File description:
** init_level_menu
*/
#include "my.h"

static void init_part_one(level_up_menu_t *menu, game_t *game)
{
    menu->Body_txt = init_label("Body", vect0(),
        20, get_asset("Font_pixel", game->assets));
    menu->Body = init_gui_obj_img("Boutton_Plus", vect0(),
        (sfVector2f){56, 56}, game);
    menu->Will_txt = init_label("Will", vect0(),
        20, get_asset("Font_pixel", game->assets));
    menu->Will = init_gui_obj_img("Boutton_Plus", vect0(),
        (sfVector2f){56, 56}, game);
    menu->Move_txt = init_label("Move", vect0(),
        20, get_asset("Font_pixel", game->assets));
    menu->Move = init_gui_obj_img("Boutton_Plus", vect0(),
        (sfVector2f){56, 56}, game);
    menu->Tech_txt = init_label("Technology", vect0(),
        20, get_asset("Font_pixel", game->assets));
    menu->Tech = init_gui_obj_img("Boutton_Plus", vect0(),
        (sfVector2f){56, 56}, game);
    menu->REF_txt = init_label("Reflexes", vect0(),
        20, get_asset("Font_pixel", game->assets));
    menu->REF = init_gui_obj_img("Boutton_Plus", vect0(),
        (sfVector2f){56, 56}, game);
}

static void init_bg(game_t *game, level_up_menu_t *menu)
{
    menu->bg = init_image(get_asset("Inventory_BG", game->assets),
        vect0(), 1);
    sfSprite_setScale(menu->bg->sprite, (sfVector2f){1, 1.19});
}

level_up_menu_t *init_level_menu(game_t *game)
{
    level_up_menu_t *menu = malloc(sizeof(level_up_menu_t));

    init_part_one(menu, game);
    menu->title = init_label("Level up: improve a statistic by 1 point",
        vect0(), 40, get_asset("Font_pixel", game->assets));
    menu->Dexterity_txt = init_label("Dexterity", vect0(),
        20, get_asset("Font_pixel", game->assets));
    menu->Dexterity = init_gui_obj_img("Boutton_Plus", vect0(),
        (sfVector2f){56, 56}, game);
    menu->EMP_txt = init_label("Empathy", vect0(),
        20, get_asset("Font_pixel", game->assets));
    menu->EMP = init_gui_obj_img("Boutton_Plus", vect0(),
        (sfVector2f){56, 56}, game);
    menu->LUCK_txt = init_label("Luck", vect0(),
        20, get_asset("Font_pixel", game->assets));
    menu->LUCK = init_gui_obj_img("Boutton_Plus", vect0(),
        (sfVector2f){56, 56}, game);
    init_bg(game, menu);
    return menu;
}
