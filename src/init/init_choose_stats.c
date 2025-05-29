/*
** EPITECH PROJECT, 2024
** init_options
** File description:
** init_options
*/

#include "my.h"
#include "guis.h"
#include "gui_struct.h"

static void init_dex(assets_t **assets, line_stats_t *line, char *str, int i)
{
    sfVector2f size = {56, 56};
    sfVector2f size_scaled = {54 * 1.5, 50 * 1.5};
    sfVector2f pos_moins = {1060, 280 + i * 80};
    sfVector2f pos_plus = {1260, 280 + i * 80};

    line->texte = malloc(sizeof(char) * 2);
    my_strcpy(line->texte, "4");
    line->value = init_label(line->texte,
        (sfVector2f){1190, 315 + i * 80}, 25, get_asset("Font_pixel", assets));
    line->Name = init_label(str, (sfVector2f){600, 315 + i * 80}, 25,
        get_asset("Font_pixel", assets));
    line->Moins = init_gui_obj(pos_moins, size_scaled);
    line->Moins->img = init_image(
        get_asset("Boutton_Moins", assets), pos_moins, 1.5);
    init_animated_img(line->Moins->img, size.y, size.x, pos_moins);
    line->Plus = init_gui_obj(pos_plus, size_scaled);
    line->Plus->img = init_image(
        get_asset("Boutton_Plus", assets), pos_moins, 1.5);
    init_animated_img(line->Plus->img, size.y, size.x, pos_plus);
}

static void all_init_lines(assets_t **assets, page_choose_stats_t *page)
{
    page->DEX = malloc(sizeof(line_stats_t));
    page->MOVE = malloc(sizeof(line_stats_t));
    page->TECH = malloc(sizeof(line_stats_t));
    page->BODY = malloc(sizeof(line_stats_t));
    page->WILL = malloc(sizeof(line_stats_t));
    page->REF = malloc(sizeof(line_stats_t));
    page->LUCK = malloc(sizeof(line_stats_t));
    page->EMP = malloc(sizeof(line_stats_t));
    init_dex(assets, page->DEX, "Dexterity", 0);
    init_dex(assets, page->MOVE, "Movement", 1);
    init_dex(assets, page->TECH, "Technique", 2);
    init_dex(assets, page->BODY, "Body", 3);
    init_dex(assets, page->WILL, "Will", 4);
    init_dex(assets, page->REF, "Reflexes", 5);
    init_dex(assets, page->LUCK, "Luck", 6);
    init_dex(assets, page->EMP, "Empathy", 7);
}

static void init_titles(page_choose_stats_t *page, assets_t **assets)
{
    page->Pts_restant = init_label("Remaining points : 10",
        (sfVector2f){950, 220}, 20, get_asset("Font_pixel", assets));
    page->line = init_label("---------------------"
    "--------------------",
        (sfVector2f){600, 265}, 15, get_asset("Font_pixel", assets));
    page->title = init_label("CHOOSE YOUR STATISTICS",
        (sfVector2f){600, 130}, 30, get_asset("Font_pixel", assets));
    sfText_setColor(page->title->txt, ORANGE);
    page->points_restant = 10;
}

static void init_recap(page_choose_stats_t *page, assets_t **assets)
{
    page->recap = malloc(sizeof(recap_t));
    page->recap->Title = init_label("Summary", (sfVector2f){1450, 150}, 25,
        get_asset("Font_pixel", assets));
    page->recap->Class = init_label("Class : No Class",
        (sfVector2f){1450, 220}, 15, get_asset("Font_pixel", assets));
}

page_choose_stats_t *init_choose_stats(assets_t **assets)
{
    page_choose_stats_t *page = malloc(sizeof(page_choose_stats_t));
    sfVector2f size = {280, 80};
    sfVector2f pos = {1060, 945};

    init_titles(page, assets);
    page->Valider = init_gui_obj(pos, size);
    page->Valider->img = init_image(
        get_asset("Boutton_Valider", assets), pos, 1);
    init_animated_img(page->Valider->img, size.y, size.x,
        pos);
    page->background = init_image(
        get_asset("Choose_BG", assets), vect0(), 1);
    all_init_lines(assets, page);
    init_recap(page, assets);
    return page;
}
