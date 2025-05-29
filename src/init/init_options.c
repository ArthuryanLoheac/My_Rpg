/*
** EPITECH PROJECT, 2024
** init_options
** File description:
** init_options
*/

#include "my.h"
#include "guis.h"
#include "gui_struct.h"

static label_button_t *init_label_button(assets_t **assets, char *text,
    sfVector2f vector_txt, sfVector2f vector_button)
{
    sfVector2f size = {56, 80};
    label_button_t *button = malloc(sizeof(label_button_t));

    button->label = init_label(text, vector_txt,
        25, get_asset("Font_pixel", assets));
    button->change_bind = init_gui_obj(vector_button, size);
    button->change_bind->img = init_image(
        get_asset("Boutton_Plus", assets), vector_button, 1);
    init_animated_img(button->change_bind->img, size.y, size.x, vector_button);
    return button;
}

static void init_movement_keybinds_label(assets_t **assets,
    page_options_t **option)
{
    page_options_t *options = *option;
    int i = 83;

    options->keybinds_labels->up = init_label_button(assets, "Up",
        (sfVector2f) {100, 190}, (sfVector2f) {400, 170 + i * 0});
    options->keybinds_labels->down = init_label_button(assets, "Down",
        (sfVector2f) {100, 190 + i * 1}, (sfVector2f) {400, 170 + i * 1});
    options->keybinds_labels->left = init_label_button(assets, "Left",
        (sfVector2f) {100, 190 + i * 2}, (sfVector2f) {400, 170 + i * 2});
    options->keybinds_labels->right = init_label_button(assets, "Right",
        (sfVector2f) {100, 190 + i * 3}, (sfVector2f) {400, 170 + i * 3});
}

static void init_keybinds_label(assets_t **assets, page_options_t **option)
{
    page_options_t *options = *option;
    int i = 83;

    options->keybinds_labels = malloc(sizeof(set_keybinds_t));
    init_movement_keybinds_label(assets, option);
    options->keybinds_labels->keybinds_str = init_label("Keybinds",
        (sfVector2f) {100, 90}, 40, get_asset("Font_pixel", assets));
    sfText_setColor(options->keybinds_labels->keybinds_str->txt, ORANGE);
    options->keybinds_labels->attack = init_label_button(assets, "Attack",
        (sfVector2f) {100, 190 + i * 4}, (sfVector2f) {400, 170 + i * 4});
    options->keybinds_labels->inventory = init_label_button(assets,
        "Inventory",
        (sfVector2f) {100, 190 + i * 5}, (sfVector2f) {400, 170 + i * 5});
    options->keybinds_labels->progression = init_label_button(assets,
        "Progression",
        (sfVector2f) {100, 190 + i * 6}, (sfVector2f) {400, 170 + i * 6});
    options->keybinds_labels->skip = init_label_button(assets, "Skip",
        (sfVector2f) {100, 190 + i * 7}, (sfVector2f) {400, 170 + i * 7});
    options->keybinds_labels->interact = init_label_button(assets, "Interact",
        (sfVector2f) {100, 190 + i * 8}, (sfVector2f) {400, 170 + i * 8});
}

static void init_animation(page_options_t **options)
{
    sfVector2f size = {280, 80};
    sfVector2f size_vol = {56, 80};

    init_animated_img((*options)->retour->img, size.y, size.x,
        (sfVector2f){45, 955});
    init_animated_img((*options)->lower_volume->img, size_vol.y, size_vol.x,
        (sfVector2f){990, 445});
    init_animated_img((*options)->greater_volume->img, size_vol.y, size_vol.x,
        (sfVector2f){1180, 445});
    init_animated_img((*options)->lower_volume_sound->img, size_vol.y,
        size_vol.x, (sfVector2f){990, 538});
    init_animated_img((*options)->greater_volume_sound->img, size_vol.y,
        size_vol.x, (sfVector2f){1180, 538});
}

static void init_images(assets_t **assets, page_options_t **options)
{
    sfVector2f size = {280, 80};

    (*options)->background = init_image(get_asset("Choose_BG", assets),
        vect0(), 1);
    (*options)->retour->img = init_image(get_asset("Boutton_Retour", assets),
        (sfVector2f){45, 955}, 1);
    (*options)->lower_volume->img = init_image(get_asset("Boutton_Moins",
        assets), (sfVector2f){990, 445}, 1);
    (*options)->greater_volume->img = init_image(get_asset("Boutton_Plus",
        assets), (sfVector2f){1180, 445}, 1);
    (*options)->lower_volume_sound->img = init_image(get_asset("Boutton_Moins",
        assets), (sfVector2f){990, 538}, 1);
    (*options)->greater_volume_sound->img = init_image(get_asset("Boutton_Plus"
        , assets), (sfVector2f){1180, 538}, 1);
    (*options)->save = init_button((sfVector2f){1515, 955},
        size, "Save", assets);
}

static void init_buttons(assets_t **assets, page_options_t **options)
{
    sfVector2f size = {280, 80};

    (*options)->fullscreen = init_button((sfVector2f){800, 145},
        size, "Fullscreen", assets);
    (*options)->mute_volume = init_button((sfVector2f){800, 745},
        size, "Unmute", assets);
    (*options)->unmute_volume = init_button((sfVector2f){800, 745},
        size, "Mute", assets);
    (*options)->min_resolution = init_button((sfVector2f){1500, 245},
        size, "1280 x 720", assets);
    (*options)->mid_resolution = init_button((sfVector2f){1500, 445},
        size, "1366 x 768", assets);
    (*options)->max_resolution = init_button((sfVector2f){1500, 645},
        size, "1920 x 1080", assets);
}

page_options_t *init_options(assets_t **assets)
{
    sfVector2f size = {280, 80};
    sfVector2f size_vol = {56, 80};
    page_options_t *options = malloc(sizeof(page_options_t));

    options->music_str = init_label("Music volume        100",
        (sfVector2f){680, 468}, 25, get_asset("Font_pixel", assets));
    options->retour = init_gui_obj((sfVector2f){45, 955}, size);
    options->lower_volume = init_gui_obj((sfVector2f){990, 445}, size_vol);
    options->greater_volume = init_gui_obj((sfVector2f){1180, 445}, size_vol);
    options->sound_str = init_label("Sound volume        100",
        (sfVector2f){680, 560}, 25, get_asset("Font_pixel", assets));
    options->greater_volume_sound = init_gui_obj((sfVector2f)
        {1180, 538}, size_vol);
    options->lower_volume_sound = init_gui_obj((sfVector2f)
        {990, 538}, size_vol);
    init_buttons(assets, &options);
    init_images(assets, &options);
    init_animation(&options);
    init_keybinds_label(assets, &options);
    return options;
}
