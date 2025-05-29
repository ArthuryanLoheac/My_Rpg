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
#include "my.h"
#include "rpg_struct.h"

typedef struct s_main {
    img_t *logo;
    img_t *background;
    img_t *building_one;
    img_t *building_two;
    img_t *hero;
    img_t *drone;
    img_t *clouds[12];
    gui_obj_t *play;
    gui_obj_t *settings;
    gui_obj_t *quit;
} main_t;

typedef struct s_start {
    img_t *logo;
    img_t *background;
    img_t *building_one;
    img_t *building_two;
    img_t *hero;
    img_t *drone;
    img_t *clouds[12];
    gui_obj_t *continues;
    gui_obj_t *nouveau;
    gui_obj_t *retour;
} start_t;

typedef struct s_role_select {
    img_t *background;
    gui_obj_t *solo;
    gui_obj_t *tech;
    gui_obj_t *medtech;
    label_t *choose_your_role;
    sfRectangleShape *sep1;
    sfRectangleShape *sep2;
} role_select_t;

typedef struct s_select {
    gui_obj_t *plus;
    gui_obj_t *minus;
    label_t *name;
    int value;
} select_t;


typedef struct s_stats_select {
    img_t *background;
    label_t *choose_your_stat;
    label_t *stat_desc;
    sfRectangleShape *sep;
    select_t *ref;
    select_t *dex;
    select_t *tech;
    select_t *will;
    select_t *luck;
    select_t *move;
    select_t *body;
    select_t *emp;
    gui_obj_t *validate;
    gui_obj_t *back;
} stats_select_t;

typedef struct s_gear_select {
    img_t *background;
    label_t *choose_your_gear;
    gui_tab_t *gear_shop;
    gui_obj_t *validate;
    gui_obj_t *back;
} gear_select_t;

typedef struct s_outfit_select {
    img_t *background;
    label_t *choose_your_outfit;
    gui_tab_t *outfit_shop;
    gui_obj_t *validate;
    gui_obj_t *back;
} outfit_select_t;

typedef struct s_validate_selection {
    img_t *background;
    label_t *choose_your_name;
    gui_obj_t *validate;
    gui_obj_t *back;
} validate_selection_t;

typedef struct s_summary {
    sfRectangleShape *sep;
    img_t *role_icon;
    label_t *role;
    label_t *ref;
    label_t *dex;
    label_t *tech;
    label_t *will;
    label_t *luck;
    label_t *move;
    label_t *body;
    label_t *emp;
    label_t *equipment;
    pc_sprite_t *sprite;
    label_t *name;
} summary_t;
