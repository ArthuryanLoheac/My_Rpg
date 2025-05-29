/*
** EPITECH PROJECT, 2024
** init_options
** File description:
** init_options
*/

#include "my.h"
#include "guis.h"
#include "gui_struct.h"

sfText *init_text(char *default_text, char *font, sfVector2f pos, float size)
{
    sfText *txt = sfText_create();
    sfFont *Font = sfFont_createFromFile(font);

    sfText_setFont(txt, Font);
    sfText_setColor(txt, sfWhite);
    sfText_setPosition(txt, pos);
    sfText_setScale(txt, (sfVector2f){size, size});
    sfText_setString(txt, default_text);
    return txt;
}

static class_choose_t *init_solo(assets_t **assets)
{
    sfVector2f size = {280, 80};
    sfVector2f pos = {180, 925};
    class_choose_t *class = malloc(sizeof(class_choose_t));

    class->Title = init_label("-- SOLO --",
        (sfVector2f){170, 600}, 32, get_asset("Font_pixel", assets));
    class->Description = init_label("Solos are assassins.\n\n"
    "His ability allows the Solo to call\nupon his training to attack a second"
    " \ntime, at the cost of all movement.",
        (sfVector2f){60, 750}, 16, get_asset("Font_pixel", assets));
    class->logo = init_image(get_asset("Icon_Solo", assets),
        (sfVector2f){170, 300}, 1);
    class->Valider = init_gui_obj(pos, size);
    class->Valider->img = init_image(
        get_asset("Boutton_Valider", assets), pos, 1);
    init_animated_img(class->Valider->img, size.y, size.x,
        pos);
    return class;
}

static class_choose_t *init_tech(assets_t **assets)
{
    sfVector2f size = {280, 80};
    sfVector2f pos = {820, 925};
    class_choose_t *class = malloc(sizeof(class_choose_t));

    class->Title = init_label("-- TECH --",
        (sfVector2f){810, 600}, 32, get_asset("Font_pixel", assets));
    class->Description = init_label("Techs are technicians.\n\n"
        "Their skills enable you to pack\nmore equipment and cybernetics.",
        (sfVector2f){700, 750}, 16, get_asset("Font_pixel", assets));
    class->logo = init_image(get_asset("Icon_Tech", assets),
        (sfVector2f){810, 300}, 1);
    class->Valider = init_gui_obj(pos, size);
    class->Valider->img = init_image(
        get_asset("Boutton_Valider", assets), pos, 1);
    init_animated_img(class->Valider->img, size.y, size.x,
        pos);
    return class;
}

static class_choose_t *init_med(assets_t **assets)
{
    sfVector2f size = {280, 80};
    sfVector2f pos = {1460, 925};
    class_choose_t *class = malloc(sizeof(class_choose_t));

    class->Title = init_label("-- MED --",
        (sfVector2f){1450, 600}, 32, get_asset("Font_pixel", assets));
    class->Description = init_label("Medtechs are doctors.\n\n"
    "They have access to stimulant,\nmedicine and such, to heal\nthemselves"
    " in combat",
        (sfVector2f){1340, 750}, 16, get_asset("Font_pixel", assets));
    class->logo = init_image(get_asset("Icon_Med", assets),
        (sfVector2f){1450, 300}, 1);
    class->Valider = init_gui_obj(pos, size);
    class->Valider->img = init_image(
        get_asset("Boutton_Valider", assets), pos, 1);
    init_animated_img(class->Valider->img, size.y, size.x,
        pos);
    return class;
}

page_choose_class_t *init_choose_class(assets_t **assets)
{
    page_choose_class_t *page = malloc(sizeof(page_choose_class_t));

    page->title = init_label("CHOOSE YOUR CLASS",
        (sfVector2f){470, 100}, 50, get_asset("Font_pixel", assets));
    sfText_setColor(page->title->txt, ORANGE);
    page->Class_one = init_solo(assets);
    page->Class_two = init_tech(assets);
    page->Class_three = init_med(assets);
    page->background = init_image(get_asset("Class_BG", assets),
        vect0(), 1);
    return page;
}
