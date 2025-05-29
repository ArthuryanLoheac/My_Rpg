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

enum tab_type_e {
    NO_TAB_TYPE = 0,
    SHOP,
    SKILL,
};

typedef struct s_game_menu {
    img_t *background;
    gui_tab_t *game_menu;
} game_menu_t;

typedef struct label_button_s {
    label_t *label;
    gui_obj_t *change_bind;
} label_button_t;

typedef struct set_keybinds_s {
    label_button_t *up;
    label_button_t *down;
    label_button_t *left;
    label_button_t *right;
    label_button_t *interact;
    label_button_t *attack;
    label_button_t *inventory;
    label_button_t *progression;
    label_button_t *skip;
    label_t *keybinds_str;
} set_keybinds_t;

typedef struct s_page_options {
    label_t *music_str;
    label_t *sound_str;
    set_keybinds_t *keybinds_labels;
    img_t *background;
    button_t *fullscreen;
    gui_obj_t *retour;
    gui_obj_t *lower_volume;
    gui_obj_t *greater_volume;
    gui_obj_t *lower_volume_sound;
    gui_obj_t *greater_volume_sound;
    button_t *mute_volume;
    button_t *unmute_volume;
    button_t *min_resolution;
    button_t *mid_resolution;
    button_t *max_resolution;
    button_t *save;
} page_options_t;

typedef struct s_class_choose {
    img_t *logo;
    label_t *Title;
    label_t *Description;
    gui_obj_t *Valider;
} class_choose_t;

typedef struct s_page_choose_class {
    img_t *background;
    class_choose_t *Class_one;
    class_choose_t *Class_two;
    class_choose_t *Class_three;
    label_t *title;
} page_choose_class_t;

typedef struct s_line_stats {
    label_t *Name;
    label_t *value;
    char *texte;
    gui_obj_t *Plus;
    gui_obj_t *Moins;
} line_stats_t;

typedef struct recap_s {
    label_t *Title;
    label_t *Class;
    label_t *line;
    label_t *shop;
    label_t *Inventory[20];
} recap_t;

typedef struct s_page_choose_stats {
    img_t *background;
    label_t *Pts_restant;
    label_t *line;
    int points_restant;
    label_t *title;
    line_stats_t *MOVE;
    line_stats_t *TECH;
    line_stats_t *BODY;
    line_stats_t *WILL;
    line_stats_t *REF;
    line_stats_t *DEX;
    line_stats_t *LUCK;
    line_stats_t *EMP;
    gui_obj_t *Valider;
    recap_t *recap;
} page_choose_stats_t;

enum type_shop_e {
    MELEE_WEAPON_SHOP,
    RANGED_WEAPON_SHOP,
    ARMOR_SHOP,
    ITEMS_SHOP,
    CYBERWARE_SHOP
};

typedef struct s_page_shop_item {
    item_t *item;
    gui_obj_t *buy;
    gui_obj_t *sell;
    label_t *name;
    label_t *price_txt;
    int nb_buy;
    label_t *nb_buy_txt;
    int price;
} page_shop_item_t;

typedef struct s_nb_item_buyed {
    int cyberware;
    int armor;
    int weapon;
    int other;
} nb_item_buyed_t;

typedef struct s_page_shop {
    img_t *background;
    label_t *title;
    label_t *euro_dollar;
    label_t *shop_state_txt;
    label_t *line;
    gui_obj_t *Valider;
    enum type_shop_e state;
    button_t *Melee;
    button_t *Ranged;
    button_t *Armor;
    button_t *Items;
    button_t *Cyberware;
    linked_list_t *items_melee;
    linked_list_t *items_ranged;
    linked_list_t *items_armor;
    linked_list_t *items_other;
    linked_list_t *items_cyberware;
    nb_item_buyed_t *nb_items;
    int offset;
    gui_obj_t *inc_offset;
    gui_obj_t *dec_offset;
    recap_t *recap;
} page_shop_t;


typedef struct s_page_final {
    img_t *background;
    gui_obj_t *valider;
    label_t *title;
    recap_t *recap;
    button_t *male;
    button_t *female;
    int gender;
    label_t *title_name;
    label_t *name_txt;
    char *name;
} page_final_t;
