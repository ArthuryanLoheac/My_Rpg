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
#include "struct_prototype.h"
#include "rpg_struct.h"
#include "rpg_struct.h"

typedef enum item_type_e {
    NO_ITEM,
    ARMOR,
    AMMO,
    WEAPON,
    DRUGS,
    GEAR,
    CYBERWARE,
    QUEST
} item_type_t;

enum ammo_type_e {
    NO_AMMO,
    HANDGUN,
    SHOULDER_ARM,
    SLUGS,
    HEAVY,
    ARCHERY,
    MELEE
};

enum weapon_type_e {
    NO_WEAPON,
    PISTOL,
    HPISTOL,
    SMG,
    SHOTGUN,
    RIFLE,
    SNIPER,
    ROCKET_L,
    NADL,
    BOW,
    KNIFE,
    TOMAHAWK,
    KATANA,
    HELICO_BLADES,
    NADE
};

enum drug_effect_e {
    NO_DRUG,
    BODY_WILL_HEAL,
    NO_POISON,
};

enum gear_effect_e {
    NO_GEAR,
    REPAIR_ARMOR,
    REPAIR_WEAPON,
    DAMAGINCREASE,
    TOHIT_INCREASE,
    ROF_INCREASE,
    HANDLING_INCREASE,
    BARREL_INCREASE,
    FIRMOD,
    ELEC_MOD,
    POISON_MOD,
    BLEED_MOD,
    USED
};

enum cyberwareffect_e {
    UNDEFINED = 0,
    BODY_INCREASE,
    MOVINCREASE,
    REF_INCREASE,
    DEX_INCREASE,
    ELEC_REGEN,
    TOXIN_FILER,
    MONOFILAMENT,
    TECH_SCAN,
    SUBDERMAL,
    KERENZIKOV,
    MICRO_ROTOR,
    POPUP_SMG,
    POPUP_PISTOL,
    PAIN_EDITOR,
    LL_I_UV,
    MACROPTIC,
    MOUNT,
    POCKET,
    MEDSCANNER
};

enum spec_fx_e {
    NONE = 0,
    ELEC,
    FIRE,
    POISON,
    BLEED
};
typedef struct s_armor {
    sfVector2i sp;
} armor_t;

typedef struct s_ammo {
    enum ammo_type_e type;
    sfVector2u amount;
} ammo_t;

typedef struct s_ques_obj {
    sfVector2u amount;
} quest_obj_t;

typedef struct s_drug {
    sfVector2u uses;
    enum drug_effect_e effect;
} drug_t;

typedef struct s_gear {
    enum gear_effect_e effect;
} gear_t;

typedef struct s_cyberware {
    enum cyberwareffect_e effect;
    int value;
    unsigned int hum_cost;
} cyberware_t;

typedef struct s_weapon {
    enum weapon_type_e type;
    enum ammo_type_e ammo_type_e;
    sfVector2i durability;
    sfVector2i mods;
    sfVector2i magazine;
    int critical;
    int rof;
    int damagd6;
    int bonus_damage;
    int bonus_tohit;
    enum spec_fx_e effect;
    int opt_distance;
} weapon_t;

typedef struct s_item {
    int id;
    char *name;
    img_t *icon;
    char *desc;
    img_t *background;
    sfRectangleShape *border;
    enum item_type_e type;
    sfVector2f position;
    int price_item;
    union {
        armor_t *armor;
        weapon_t *weapon;
        ammo_t *ammo;
        quest_obj_t *quest;
        drug_t *drug;
        gear_t *gear;
        cyberware_t *cyberware;
    };
} item_t;

typedef struct player_stats_s {
    img_t *player_img;
    img_t *health_bar;
}player_stats_t;

typedef enum type_slots_e {
    NONE_SLOTS = 0,
    CYBERWARE_SLOTS,
    ARMOR_SLOTS,
    WEAPON_SLOTS,
    INVENTORY_SLOTS,
}type_slots_t;

typedef struct main_slots {
    item_t *items;
    img_t *background;
    sfVector2f position;
    sfVector2f position_icon;
    type_slots_t slot_type;
}main_slots_t;

typedef struct inventory_slots_s {
    main_slots_t **main_slots;
}inventory_slots_t;

typedef struct quest_area_s {
    img_t *area;
    sfFont *font;
    sfText *text;
}quest_area_t;

typedef struct stats_area_s {
    sfFont *font;
    sfText *text;
} stats_area_t;

typedef struct logo_game {
    img_t *logo_img;
    label_t *txt;
} logo_t;

typedef struct gui_inventory_s {
    player_stats_t *stats;
    img_t *background;
    inventory_slots_t *inventory;
    label_t *item_info;
    sfRectangleShape *durability;
    quest_area_t *quest;
    logo_t *logo;
    stats_area_t *stats_area;
    bool is_display;
    struct s_player_character *player;
    int items_slots_picked;
    bool is_picked;
} gui_inventory_t;
