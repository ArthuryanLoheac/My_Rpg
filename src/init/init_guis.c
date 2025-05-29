/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** a function to create a button
*/

#include "my.h"

static ui_obj_t *init_main_menu_ui(assets_t **assets)
{
    ui_obj_t *main_menu_ui = malloc(sizeof(ui_obj_t));

    main_menu_ui->ui_content = init_main_menu(assets);
    main_menu_ui->analyze = &analyze_menu_main;
    main_menu_ui->compute = &compute_menu_main;
    main_menu_ui->make = &make_menu_main;
    return main_menu_ui;
}

static ui_obj_t *init_start_menu_ui(assets_t **assets)
{
    ui_obj_t *start_menu_ui = malloc(sizeof(ui_obj_t));

    start_menu_ui->ui_content = init_start_menu(assets);
    start_menu_ui->analyze = &analyze_menu_start;
    start_menu_ui->compute = &compute_menu_start;
    start_menu_ui->make = &make_menu_start;
    return start_menu_ui;
}

static ui_obj_t *init_map_ui(void)
{
    ui_obj_t *map_ui = malloc(sizeof(ui_obj_t));

    map_ui->ui_content = NULL;
    map_ui->analyze = &analyze_map;
    map_ui->compute = &compute_map;
    map_ui->make = &make_map;
    return map_ui;
}

static ui_obj_t *init_options_ui(assets_t **assets)
{
    ui_obj_t *options = malloc(sizeof(ui_obj_t));

    options->ui_content = init_options(assets);
    options->analyze = &analyze_options;
    options->compute = &compute_options;
    options->make = &make_options;
    return options;
}

static ui_obj_t *init_choose_class_ui(assets_t **assets)
{
    ui_obj_t *options = malloc(sizeof(ui_obj_t));

    options->ui_content = init_choose_class(assets);
    options->analyze = &analyze_choose_class;
    options->compute = &compute_choose_class;
    options->make = &make_choose_class;
    return options;
}

static ui_obj_t *init_choose_stats_ui(assets_t **assets)
{
    ui_obj_t *stats = malloc(sizeof(ui_obj_t));

    stats->ui_content = init_choose_stats(assets);
    stats->analyze = &analyze_choose_stats;
    stats->compute = &compute_choose_stats;
    stats->make = &make_choose_stats;
    return stats;
}

static ui_obj_t *init_final_page_ui(assets_t **assets)
{
    ui_obj_t *final = malloc(sizeof(ui_obj_t));

    final->ui_content = init_final_page(assets);
    final->analyze = &analyze_final_page;
    final->compute = &compute_final_page;
    final->make = &make_final_page;
    return final;
}

static ui_obj_t *init_shop_in_game_ui(void)
{
    ui_obj_t *stats = malloc(sizeof(ui_obj_t));

    stats->ui_content = NULL;
    stats->analyze = &analyze_shop;
    stats->compute = &compute_shop_in_game;
    stats->make = &make_shop_in_game;
    return stats;
}

static ui_obj_t *init_shop_ui(void)
{
    ui_obj_t *stats = malloc(sizeof(ui_obj_t));

    stats->ui_content = NULL;
    stats->analyze = &analyze_shop;
    stats->compute = &compute_shop;
    stats->make = &make_shop;
    return stats;
}

guis_t *init_guis(assets_t **assets)
{
    guis_t *guis = malloc(sizeof(guis_t));

    guis->active = MAIN_MENU;
    guis->main_menu = init_main_menu_ui(assets);
    guis->map = init_map_ui();
    guis->start_menu = init_start_menu_ui(assets);
    guis->options_page = init_options_ui(assets);
    guis->choose_class = init_choose_class_ui(assets);
    guis->pause = init_time();
    guis->choose_stats = init_choose_stats_ui(assets);
    guis->shop = init_shop_ui();
    guis->shop_in_game = init_shop_in_game_ui();
    guis->final = init_final_page_ui(assets);
    return guis;
}
