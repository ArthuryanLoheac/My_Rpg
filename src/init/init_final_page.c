/*
** EPITECH PROJECT, 2024
** init_final_page
** File description:
** init_final_page
*/

#include "my.h"
#include "guis.h"
#include "gui_struct.h"

static void init_gender(assets_t **assets, page_final_t *page)
{
    sfVector2f size = {280, 80};
    sfVector2f pos_male = {660, 765};
    sfVector2f pos_female = {960, 765};

    page->gender = 0;
    page->female = init_button(pos_female, size, "GIRL", assets);
    page->male = init_button(pos_male, size, "BOY", assets);
}

static void init_name(assets_t **assets, page_final_t *page)
{
    page->name = malloc(sizeof(char) * 21);
    page->name[0] = '\0';
    page->title_name = init_label("--- Enter your name : ---",
        (sfVector2f){730, 630}, 20, get_asset("Font_pixel", assets));
    page->name_txt = init_label(page->name,
        (sfVector2f){810, 680}, 16, get_asset("Font_pixel", assets));
}

static void init_recap(page_final_t *page, assets_t **assets)
{
    page->recap = malloc(sizeof(recap_t));
    page->recap->Title = init_label("Summary", (sfVector2f){880, 220}, 25,
        get_asset("Font_pixel", assets));
    page->recap->line = init_label("---------------------"
    "--------------------",
        (sfVector2f){600, 270}, 15, get_asset("Font_pixel", assets));
    page->recap->Class = init_label("Class : No Class",
        (sfVector2f){630, 320}, 15, get_asset("Font_pixel", assets));
    page->recap->shop = init_label("-- Inventory --",
        (sfVector2f){1000, 320}, 15, get_asset("Font_pixel", assets));
    for (int i = 0; i < 10; i++) {
        page->recap->Inventory[i] = init_label("item",
            (sfVector2f){950, 350 + i * 25}, 10,
            get_asset("Font_pixel", assets));
        page->recap->Inventory[i + 10] = init_label("item",
            (sfVector2f){1150, 350 + i * 25}, 10,
            get_asset("Font_pixel", assets));
    }
}

page_final_t *init_final_page(assets_t **assets)
{
    page_final_t *page = malloc(sizeof(page_final_t));
    sfVector2f size = {280, 80};
    sfVector2f pos = {1060, 945};

    page->title = init_label("COMPLETE YOUR CHARACTER",
        (sfVector2f){580, 130}, 30, get_asset("Font_pixel", assets));
    sfText_setColor(page->title->txt, ORANGE);
    page->background = init_image(
        get_asset("Choose_BG", assets), vect0(), 1);
    page->valider = init_gui_obj(pos, size);
    page->valider->img = init_image(
        get_asset("Boutton_Valider", assets), pos, 1);
    init_animated_img(page->valider->img, size.y, size.x, pos);
    init_gender(assets, page);
    init_name(assets, page);
    init_recap(page, assets);
    return page;
}
