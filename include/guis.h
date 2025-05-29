/*
** EPITECH PROJECT, 2023
** my
** File description:
** our own version of printf
*/

#pragma once
#include <stdarg.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include "struct.h"
#include "inventory.h"
#include "rpg_struct.h"
#include "my.h"

struct s_game;

enum e_active {
    NO_ACTIVE = 0,
    MAP,
    MAIN_MENU,
    START_MENU,
    OPTIONS,
    CHOOSE_CLASS,
    CHOOSE_STATS,
    PAGE_SHOP,
    PAGE_FINAL,
    PAUSE,
    SHOP_IN_GAME,
};

typedef struct s_ui_obj {
    void *ui_content;
    void (*make)(struct s_ui_obj *, struct s_game *);
    void (*analyze)(struct s_ui_obj *, struct s_game *);
    void (*compute)(struct s_ui_obj *, struct s_game *);
} ui_obj_t;

typedef struct s_guis {
    enum e_active active;
    time2_t *pause;
    ui_obj_t *map;
    ui_obj_t *main_menu;
    ui_obj_t *start_menu;
    ui_obj_t *options_page;
    ui_obj_t *choose_class;
    ui_obj_t *choose_stats;
    ui_obj_t *shop;
    ui_obj_t *shop_in_game;
    ui_obj_t *final;
} guis_t;
