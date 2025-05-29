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
#include "guis.h"

#define PLAYER_SPEED 5.0

struct s_map;

enum mode_e {
    NO_MODE,
    MAIN,
    GAME,
    COMBAT,
    CUTSCENE,
    INVENTORY,
    SETTINGS
};

enum class_e {
    NO_CLASS,
    SOLO,
    TECH,
    MED
};

enum npc_type_e {
    NO_NPC,
    HOSTILE,
    EDGE,
    FRIENDLY,
};

enum entity_type_e {
    NO_ENTITY,
    NPC,
    PC,
    SCATTER,
    CIVILIAN,
    ITEM
};

enum talkable_e {
    NO_TL,
    YES_TL,
    IS_TL,
};

enum action_e {
    NO_ACTION,
    DODGE,
    DASH,
    SHOOT,
    OTHER,
};

typedef struct s_stats {
    unsigned int MOVE;
    unsigned int TECH;
    unsigned int WILL;
    unsigned int BODY;
    unsigned int REF;
    unsigned int DEX;
    unsigned int EMP;
    unsigned int LUCK;
    unsigned int HUM;
} stats_t;

typedef struct s_diag_queue {
    char *text;
    img_t *portrait;
    int *answer_loc;
    char *name;
} diag_queue_t;

typedef struct s_portrait {
    img_t *protagonist;
    img_t *alter;
    img_t *queen;
    img_t *dyn;
    img_t *cryspi;
    img_t *puddle;
    img_t *man;
} portrait_t;

typedef struct s_diag_pipe {
    time2_t *clock;
    sfBool close;
    label_t *label;
    label_t *label_n;
    img_t *background;
    char *text;
    char *name;
    img_t *portrait;
    linked_list_t *ll;
    char **answer;
    int *answer_loc;
    gui_obj_t **answer_btn;
    img_t *answer_bg;
} diag_pipe_t;

typedef struct s_pc_sprite {
    img_t *temp;
    int direction;
    linked_list_t *clothes;
} pc_sprite_t;

typedef struct s_info {
    time2_t *clock;
    float target;
    label_t *label;
    label_t *label_end;
    img_t *background;
    char *text;
} info_t;

typedef struct s_keybind {
    sfKeyCode up;
    sfKeyCode down;
    sfKeyCode left;
    sfKeyCode right;
    sfKeyCode interact;
    sfKeyCode attack;
    sfKeyCode inventory;
    sfKeyCode progression;
    sfKeyCode skip;
    int wait_for_key;
} keybind_t;

typedef struct xp_data {
    int level;
    sfVector2i xp_player;
    sfRectangleShape *background;
    sfRectangleShape *xp_bg;
    sfText *niv_label;
}xp_data_t;

typedef struct s_player_character {
    pc_sprite_t *sprite;
    sfVector2i *hp;
    time2_t *own_clock;
    time2_t *mov;
    stats_t *stats;
    stats_t *bonus_stats;
    sfBool invincible;
    float movmult;
    enum class_e class;
    int euro_dollars;
    int gender;
    char *name;
    xp_data_t *xp_data;
    inventory_slots_t *inventory;
    sfRectangleShape *range_trigger;
    int id_active_armor;
} player_character_t;

typedef struct s_quest {
    char *name;
    char *prefix;
    char *next_quest_name;
    sfVector2u prog;
    char *objective;
    void (*compute)(struct s_quest *, struct s_map *, struct s_game *);
} quest_t;

typedef struct s_assets {
    char *name;
    char *path;
}assets_t;

typedef struct s_params {
    sfVector2f pos;
    sfColor color;
} params_t;

typedef struct music_s {
    sfMusic *menu_theme;
    sfMusic *combat_music;
    sfMusic *main_theme;
    bool mute_volume;
    float music_volume;
}music_t;

typedef struct under_sound_s {
    sfSound *sound;
    sfSoundBuffer *buffer;
}under_sound_t;

typedef struct sounds_s {
    under_sound_t *pistolet;
    under_sound_t *shotgun;
    under_sound_t *assault_rifle;
    under_sound_t *smg;
    under_sound_t *assault_rifle_rafale;
    under_sound_t *smg_rafale;
    under_sound_t *sniper;
    under_sound_t *nadl;
    under_sound_t *explosion;
    under_sound_t *bullet_hit;
    under_sound_t *rocket_l;
    under_sound_t *melee;
    float sound_volume;
}sounds_t;

typedef struct splash_screen_s {
    sfSprite *sprite;
    sfSprite *sprite2;
    sfSprite *sprite3;
    sfTexture *texture;
    sfTexture *texture2;
    sfTexture *texture3;
    img_t *logo;
    img_t *bg;
    sfClock *clock;
    sfVector2f pos;
    label_t *label;
    sfSprite *background;
} splash_screen_t;

typedef struct s_game {
    // bool is_dead;
    splash_screen_t *splash_screen;
    bool retour_options_in_game;
    sfEvent *events;
    sfRenderWindow *window;
    sfView *view;
    keybind_t *keybinds;
    guis_t *guis;
    info_t *info;
    music_t *music;
    sounds_t *sounds;
    char *savefilepath;
    int savefile;
    char *saveoptionsfilepath;
    int saveoptions;
    quest_t *quests;
    assets_t **assets;
    int window_state;
    player_character_t *player;
    bool espace_active;
    bool level_up_active;
    sfVideoMode video_mode;
} game_t;

typedef struct s_civ {
    img_t *civ;
    sfBool in_combat;
    time2_t *own_clock;
    sfVector2f vector;
    float time_move_dir;
    linked_list_t *clothes;
} civ_t;

typedef struct s_dialogue {
    int id;
    char **options;
    char **answer;
    struct s_dialogue *next;
} dialogue_t;

typedef struct s_npc {
    char *name;
    char *prefix;
    char *map;
    enum talkable_e talkable;
    img_t *npc;
    linked_list_t *clothes;
    sfBool in_combat;
    sfVector2i hp;
    time2_t *own_clock;
    linked_list_t *next_pos;
    float fade_death_counter;
    enum npc_type_e type;
    item_t *ranged;
    item_t *melee;
    item_t *armor;
    item_t *loot_1;
    item_t *loot_2;
    stats_t *stats;
} npc_t;

typedef struct img_map {
    bool is_load;
    img_t *map;
    sfImage *col;
} img_map_t;

typedef struct bullet_fight_s {
    img_t *bullet;
    img_t *weapon;
    time2_t *time;
    sfVector2f vector;
    float lifetime;
    bool hit;
    bool explosion;
} bullet_fight_t;

typedef struct fight_fx_s {
    img_t *img;
    time2_t *time;
    bool hit_ppl;
    bool explosion;
} fight_fx_t;

typedef struct dice_fx_s {
    img_t *img;
    time2_t *time;
    int result;
    float sec_todo;
} dice_fx_t;

typedef struct map_panel_image {
    int nbr_row;
    int nbr_col;
    int current_row;
    int current_col;
    char *current_map;
    img_map_t ***map;
} map_panel_image_t;

typedef struct s_fight_gui {
    img_t *bg;
    bool mode;
    gui_obj_t *autofire;
    gui_obj_t *fire;
    gui_obj_t *expl;
    gui_obj_t *shell;
    gui_obj_t *unarmd;
    gui_obj_t *melee;
    gui_obj_t *bow;
    gui_obj_t *swap;
    gui_obj_t *dash;
    gui_obj_t *dodge;
    gui_obj_t *done;
    img_t *mana_img;
    sfVertexArray *arr;
    sfVertex *points;
    sfRectangleShape *hp_bar;
    sfRectangleShape *aoe_shotgun;
    sfCircleShape *aoe;
} fight_gui_t;

typedef struct s_fight {
    linked_list_t *turn_order;
    bool is_fight;
    bool fired;
    enum action_e action;
    int fighter;
    int target;
    sfVector2f dep_mouv;
    fight_gui_t *gui;
    bool action_taken;
} fight_t;

typedef struct s_escape_menu {
    button_t *save;
    button_t *load;
    gui_obj_t *options;
    gui_obj_t *quit;
    button_t *main_menu;
} escape_menu_t;

typedef struct level_up_menu {
    label_t *title;
    label_t *Move_txt;
    gui_obj_t *Move;
    label_t *Tech_txt;
    gui_obj_t *Tech;
    label_t *Body_txt;
    gui_obj_t *Body;
    label_t *Will_txt;
    gui_obj_t *Will;
    label_t *REF_txt;
    gui_obj_t *REF;
    label_t *Dexterity_txt;
    gui_obj_t *Dexterity;
    label_t *LUCK_txt;
    gui_obj_t *LUCK;
    label_t *EMP_txt;
    gui_obj_t *EMP;
    img_t *bg;
} level_up_menu_t;

typedef struct s_night {
    time2_t *clock;
    img_t *overlay;
    float time_mult;
    sfFloatRect *sleep_zone;
} night_t;

typedef struct s_fade {
    sfColor overlay;
    time2_t *clock;
    bool is_active;
    img_t *img;
} fade_t;


typedef struct s_quest_ui {
    sfVector2f quest_pos;
    img_t *quest_arrow;
} quest_ui_t;


typedef struct weather_s {
    sfTexture *texture;
    sfImage *img;
    sfSprite *sprite;
} weather_t;

typedef struct s_map {
    gui_inventory_t *inventory;
    linked_list_t *entity_area;
    linked_list_t *entity_all;
    linked_list_t *fight_tools;
    linked_list_t *fight_fx;
    linked_list_t *dice;
    map_panel_image_t *map;
    map_panel_image_t *map_nc;
    diag_pipe_t *dialogue_pipeline;
    char **dialogue;
    portrait_t *portrait;
    player_character_t *player;
    sfView *view;
    sfVector2f target_view;
    time2_t *view_clock;
    float view_speed;
    fight_t *fight;
    int id_dropped;
    escape_menu_t *escape_menu;
    level_up_menu_t *level_menu;
    night_t *night;
    fade_t *fade;
    quest_ui_t *quest_ui;
    weather_t *weather;
} map_t;

typedef struct s_scatter {
    int id;
    img_t *scatter;
    void (*init_new)(game_t *, map_t *);
    bool interact;
    char *map;
} scatter_t;

typedef struct s_entity {
    enum entity_type_e type;
    sfVector2f position;
    int map;
    bool move;
    int id_item;
    bool hidden;
    union {
        npc_t *npc;
        player_character_t *pc;
        civ_t *civ;
        item_t *item;
        scatter_t *scatter;
    };
} entity_t;
