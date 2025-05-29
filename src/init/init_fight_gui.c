/*
** EPITECH PROJECT, 2024
** init_fight_gui
** File description:
** init_fight_gui
*/

#include "my.h"
#include "guis.h"
#include "gui_struct.h"

static void init_fight_gui_array(fight_gui_t *gui)
{
    gui->arr = sfVertexArray_create();
    gui->points = malloc(sizeof(sfVertex) * 32);
    sfVertexArray_setPrimitiveType(gui->arr, sfQuads);
}

static void init_fight_gui_btn_format(fight_gui_t *gui)
{
    init_animated_img(gui->dodge->img, 126, 126, vect0());
    init_animated_img(gui->dash->img, 126, 126, vect0());
    init_animated_img(gui->fire->img, 126, 126, vect0());
    init_animated_img(gui->autofire->img, 126, 126, vect0());
    init_animated_img(gui->expl->img, 126, 126, vect0());
    init_animated_img(gui->unarmd->img, 126, 126, vect0());
    init_animated_img(gui->melee->img, 126, 126, vect0());
    init_animated_img(gui->shell->img, 126, 126, vect0());
    init_animated_img(gui->bow->img, 126, 126, vect0());
    init_animated_img(gui->done->img, 126, 126, vect0());
    format_gui_obj(gui->dodge, sfTrue, sfFalse);
    format_gui_obj(gui->dash, sfTrue, sfFalse);
    format_gui_obj(gui->fire, sfTrue, sfFalse);
    format_gui_obj(gui->done, sfTrue, sfFalse);
    format_gui_obj(gui->autofire, sfTrue, sfFalse);
    format_gui_obj(gui->expl, sfTrue, sfFalse);
    format_gui_obj(gui->shell, sfTrue, sfFalse);
    format_gui_obj(gui->unarmd, sfTrue, sfFalse);
    format_gui_obj(gui->melee, sfTrue, sfFalse);
    format_gui_obj(gui->bow, sfTrue, sfFalse);
}

static void init_fight_gui_btn2(assets_t **assets, fight_gui_t *gui,
    sfVector2f size, sfVector2f size2)
{
    gui->autofire = init_gui_obj((sfVector2f){1260, 1000}, size2);
    gui->autofire->img = init_image(get_asset("Fight_autofire", assets),
        vect0(), 0.25);
    gui->shell = init_gui_obj((sfVector2f){1260, 1000}, size);
    gui->shell->img = init_image(get_asset("Fight_shell", assets),
        vect0(), 1);
    gui->expl = init_gui_obj((sfVector2f){1260, 1000}, size);
    gui->expl->img = init_image(get_asset("Fight_expl", assets),
        vect0(), 1);
    gui->unarmd = init_gui_obj((sfVector2f){1260, 1000}, size);
    gui->unarmd->img = init_image(get_asset("Fight_unarmd", assets),
        vect0(), 1);
    gui->melee = init_gui_obj((sfVector2f){1260, 1000}, size);
    gui->melee->img = init_image(get_asset("Fight_melee", assets),
        vect0(), 1);
    gui->bow = init_gui_obj((sfVector2f){1260, 1000}, size);
    gui->bow->img = init_image(get_asset("Fight_bow", assets),
        vect0(), 1);
    init_fight_gui_btn_format(gui);
}

static void init_fight_gui_btn(assets_t **assets, fight_gui_t *gui)
{
    sfVector2f size = {120, 120};
    sfVector2f size2 = {50, 50};

    gui->bg = init_image(get_asset("Fight_BG", assets), vect0(),
        0.37);
    gui->dodge = init_gui_obj((sfVector2f){800, 1000}, size);
    gui->dodge->img = init_image(get_asset("Fight_dodge", assets),
        vect0(), 1);
    gui->fire = init_gui_obj((sfVector2f){920, 1000}, size);
    gui->fire->img = init_image(get_asset("Fight_fire", assets),
        vect0(), 1);
    gui->dash = init_gui_obj((sfVector2f){1140, 1000}, size);
    gui->dash->img = init_image(get_asset("Fight_dash", assets),
        vect0(), 1);
    gui->done = init_gui_obj((sfVector2f){1260, 1000}, size);
    gui->done->img = init_image(get_asset("Fight_done", assets),
        vect0(), 1);
    init_fight_gui_btn2(assets, gui, size, size2);
}

static img_t *init_mana_bar(assets_t **assets)
{
    img_t *img = NULL;

    img = init_image(get_asset("Fight_mov", assets),
        vect0(), 1);
    init_animated_img(img, 38, 300, (sfVector2f){210, 500});
    set_animate_image(img, 128, 128, 1);
    return img;
}

fight_gui_t *init_fight_gui(assets_t **assets)
{
    fight_gui_t *gui = malloc(sizeof(fight_gui_t));

    gui->mode = true;
    gui->mana_img = init_mana_bar(assets);
    sfSprite_setPosition(gui->mana_img->sprite, (sfVector2f){0, 30});
    init_fight_gui_array(gui);
    init_fight_gui_btn(assets, gui);
    gui->hp_bar = sfRectangleShape_create();
    gui->aoe_shotgun = sfRectangleShape_create();
    gui->aoe = sfCircleShape_create();
    sfRectangleShape_setFillColor(gui->aoe_shotgun, sfTransparent);
    sfRectangleShape_setOutlineColor(gui->aoe_shotgun, sfBlack);
    sfRectangleShape_setOutlineThickness(gui->aoe_shotgun, 5);
    sfRectangleShape_setSize(gui->aoe_shotgun, (sfVector2f){300, 300});
    sfCircleShape_setFillColor(gui->aoe, sfTransparent);
    sfCircleShape_setOutlineColor(gui->aoe, sfBlack);
    sfCircleShape_setOutlineThickness(gui->aoe, 5);
    sfCircleShape_setRadius(gui->aoe, 300);
    return gui;
}
