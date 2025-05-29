/*
** EPITECH PROJECT, 2024
** init_main_menu
** File description:
** init_main_menu
*/

#include "my.h"

static void init_background(main_t *main_menu, assets_t **assets)
{
    sfVector2f pos = {0, 0};

    main_menu->background = init_image(get_asset("Start_Menu_BG", assets)
        , pos, 1);
    init_animated_img(main_menu->background, 1080, 1920, pos);
    set_animate_image(main_menu->background, 4, 1, 4);
    main_menu->building_one = init_image(
        get_asset("Start_Menu_Building1", assets), pos, 1);
    main_menu->building_two = init_image(
        get_asset("Start_Menu_Building2", assets), pos, 1);
}

static void init_clouds(main_t *main_menu, assets_t **assets)
{
    char str[] = "Start_Menu_cloud1";
    sfVector2f position;

    for (int i = 0; i < 6; i++) {
        str[16] = (i + 1) + '0';
        position.y = 600 + rand() % 100;
        position.x = rand() % 1920;
        main_menu->clouds[i] = init_image(get_asset(str, assets)
            , position, 1);
        init_animated_img(main_menu->clouds[i], 1000, 1000, position);
        set_animate_image(main_menu->clouds[i], 1, 1, 1);
        position.x = rand() % 1920 - 1500;
        main_menu->clouds[i + 6] = init_image(get_asset(str, assets)
            , position, 1);
        init_animated_img(main_menu->clouds[i + 6], 1000, 1000, position);
        set_animate_image(main_menu->clouds[i + 6], 1, 1, 1);
    }
}

static void init_buttons(main_t *main_menu, assets_t **assets)
{
    sfVector2f size = {280, 80};

    main_menu->play = init_gui_obj((sfVector2f){45, 375}, size);
    main_menu->play->img = init_image(get_asset("Boutton_Jouer", assets)
        , (sfVector2f){45, 375}, 1);
    init_animated_img(main_menu->play->img, size.y, size.x,
        (sfVector2f){45, 375});
    main_menu->settings = init_gui_obj((sfVector2f){45, 475}, size);
    main_menu->settings->img = init_image(get_asset("Boutton_Options", assets)
        , (sfVector2f){45, 475}, 1);
    init_animated_img(main_menu->settings->img, size.y, size.x,
        (sfVector2f){45, 475});
    main_menu->quit = init_gui_obj((sfVector2f){45, 575}, size);
    main_menu->quit->img = init_image(get_asset("Boutton_Quitter", assets)
        , (sfVector2f){45, 575}, 1);
    init_animated_img(main_menu->quit->img, size.y, size.x,
        (sfVector2f){45, 575});
}

main_t *init_main_menu(assets_t **assets)
{
    main_t *main_menu = malloc(sizeof(main_t));

    init_background(main_menu, assets);
    main_menu->logo = init_image(get_asset("RDB_Logo", assets)
        , (sfVector2f){90, 45}, 1.3);
    main_menu->hero = init_image(get_asset("Start_Menu_BG_Hero", assets)
        , (sfVector2f){840, 527}, 1);
    init_animated_img(main_menu->hero, 156, 100, (sfVector2f){840, 527});
    set_animate_image(main_menu->hero, 15, 1, 15);
    main_menu->drone = init_image(get_asset("Start_Menu_Drone", assets)
        , (sfVector2f){-1000, 100}, 1);
    init_animated_img(main_menu->drone, 80, 80, (sfVector2f){-1000, 100});
    set_animate_image(main_menu->drone, 2, 1, 2);
    init_clouds(main_menu, assets);
    init_buttons(main_menu, assets);
    return main_menu;
}
