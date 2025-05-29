/*
** EPITECH PROJECT, 2023
** my
** File description:
** our own version of printf
*/

#pragma once
#include <math.h>
#include <stdarg.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include "struct.h"
#include "struct_prototype.h"
#include "lib.h"
#include "inventory.h"
#include "stats.h"
#include "pregame_gui_struct.h"
#include "color.h"
#include "rpg_struct.h"
#include "quest.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))
#define NOT_NULL(X, Y) (((void *)(X) == NULL) ? (Y) : (X))
#define M_PI 3.14159265358979323846
#define SCALE_HOUSE 2.5


sfVideoMode init_video_mode(game_t *game);
int other_last_check(game_t *game);
int check_here(char *file, game_t *game);
void splash_screen(game_t *game);
info_t *init_info(assets_t **assets);
int init_money(game_t *game, bool new_game);
void set_volume_for_sounds(sounds_t *sounds, float volume);
void set_general_volume(game_t *game);
void compute_sound(game_t *game, ui_obj_t *obj);
void make_sound(game_t *game, page_options_t *options);
void change_txt_sound(page_options_t *options, game_t *game);
void analyze_escape_key(game_t *game, sfEvent *event);
void change_txt_volume(page_options_t *options, game_t *game);
int check_keybinds_wait(game_t *game, page_options_t *options);
void loading_screen(game_t *game, float val);
void reset_postion_items(map_t *map);
unsigned int roll_dice_10(int n);
unsigned int roll_dice_6(int n);
sfVector2f vect0(void);
sfVector2f vectcenter(void);
void set_clothes_dyn(assets_t **assets, npc_t *npc, int armor);
void set_clothes_cryspi(assets_t **assets, npc_t *npc, int armor);
void simul_fight(weapon_t *attacker, unsigned int reflex,
    int length, player_character_t *defender);
unsigned int simulate_dv(weapon_t *weapon, unsigned int length);
void make_info(sfRenderWindow *window, info_t *info);
void poll_event(sfRenderWindow *window, sfEvent *event, game_t *gamey);
char *get_input_old(char *prompt);
char *get_input(char *prompt);
sfBool isclicked(struct s_gui_object *btn, sfRenderWindow *window);
sfBool ishover(struct s_gui_object *btn, sfRenderWindow *window);
int get_state_options(enum gui_state_e current_state,
    struct s_gui_options *list_ptr);
sfRectangleShape *create_grey_line(int x, int y);
float get_slider_pos_vertical(gui_slider_t *slider);
float get_slider_pos(gui_slider_t *slider);
void set_slider_pos(gui_slider_t *slider, int value);
void set_slider_pos_vertical(gui_slider_t *slider, int value);
int about(char *login);
sfVector2f get_mouse_pos(sfRenderWindow *window);
void backup_layers(linked_list_t **ll);
linked_list_t *dup_layers(linked_list_t *ll);
img_t *dup_image(img_t *img);
sfBool key_is_pressed_ctrl(sfKeyCode key, sfBool pressed);
sfBool key_is_pressed(sfKeyCode key, sfBool pressed);
sfBool btn_is_pressed_drp(enum gui_state_e state, enum gui_state_e prev);
sfBool btn_is_pressed(enum gui_state_e state, enum gui_state_e prev);
sfBool mouse_is_pressed(sfMouseButton mouse, sfBool pressed);
void update_time(time2_t *times);
void update_time2(time2_t *times);
void update_time_add(time2_t *times);
int my_rpg(sfEvent *event);
sfColor get_bg_color(game_t *game);
void format_gui_obj(struct s_gui_object *obj, sfBool fitimg, sfBool fittxt);
void send_script(char *path, portrait_t *portraits, diag_pipe_t *diag_pipe,
    int *answer_loc);
char **remove_inhibitor(char **dest);
char *remove_inhibitor_line(char *str);
int do_dialogue(char *id, map_t *map);
char *getmap(char const *filepath);
char *getmap2(char const *filepath);
char *import_from_save(char *part, char *savefile);
void set_clothes_color(linked_list_t *lst, sfColor col);
char *next_filepath_choose(void);
char *last_filepath_choose(void);
void wrong_savefile(char *file, char *place);
void set_animate_image(img_t *image,
    int nb_image, int height, int width);
void chapter_transition(game_t *game, char *title, char *text, sfColor color);
void go_to_menu2(game_t *game);
//GET entity
img_t *get_img(char *name, linked_list_t *img);
npc_t *get_npc(char *name, linked_list_t *entity);
entity_t *get_npc2(char *name, linked_list_t *entity);
int get_npc_index(char *name, linked_list_t *entity);
npc_t *get_index_npc(linked_list_t *entity, int i);
entity_t *get_index_npc2(linked_list_t *entity, char *name);
int get_pc_index(linked_list_t *entity);
entity_t *get_scatter(int id, linked_list_t *entity);

//Entity operation
void set_scatter_shown(int id, linked_list_t *entity);
void set_npc_item_hidden(linked_list_t *ll);
void set_npc_shown(linked_list_t *ll, char *name, bool val);
void set_npc_pos(linked_list_t *ll, char *name, sfVector2f pos);


//Vector Operation
float get_distance(sfVector2f pos1, sfVector2f pos2);
float get_len(sfVector2f pos);
float get_angle(sfVector2f pos1, sfVector2f pos2);
double get_angle_degree(sfVector2f pos1, sfVector2f pos2);
sfVector2f rotate_point(sfVector2f point_to_rotate,
    sfVector2f point_to_turn_around, float angle);
sfVector2f normalize(sfVector2f pos);
sfVector2f add(sfVector2f pos, float x, float y);
sfVector2f sub2(sfVector2f pos, sfVector2f pos2);
sfVector2f add2(sfVector2f pos, sfVector2f pos2);
sfVector2f add3(sfVector2f pos, float val);
sfVector2f mult2(sfVector2f pos, sfVector2f pos2);
sfVector2f mult3(sfVector2f pos, float val);
sfVector2f div3(sfVector2f pos, float val);
sfVector2f set_image_slots(main_slots_t *data, int i, sfVector2f pos,
    assets_t **assets);
bool point_in_rectangle(sfRectangleShape *rect, sfVector2f point);
void swap_items(item_t **items1, item_t **items2);
void change_window(game_t *game, bool change);

//Saving
void save_money(game_t *game);
void save_options(game_t *game);
void save_data(game_t *game);
void save_inventory(void *map, game_t *game);
void save_gender_and_name(void *map, game_t *game);
void save_hp(void *map, game_t *game);
void save_stats(void *map, game_t *game);
void save_quest(game_t *game);
void save_time(game_t *game, map_t *map);
void save_npc(linked_list_t *ll, game_t *game);
void save_class(void *map, game_t *game);
void save_player(game_t *game);
void save_map(game_t *game, map_t *map);

//NPC
void set_clothes_npc(assets_t **assets, npc_t *npc, int armor);
npc_t *init_npc(char *name, sfVector2i hp, img_t *img, enum npc_type_e type);
npc_t *init_cryspi_npc(sfVector2f pos, assets_t **assets);
entity_t *init_cryspi(sfVector2f pos, assets_t **assets);
npc_t *init_dyn_npc(sfVector2f pos, assets_t **assets);
entity_t *init_dyn(sfVector2f pos, assets_t **assets);
entity_t *init_mook(sfVector2f pos, assets_t **assets, char *name, int hp);
npc_t *init_mook_npc(sfVector2f pos, assets_t **assets, char *name, int hp);
linked_list_t *init_main_entity(player_character_t *player, game_t *game,
    bool new_game, map_t *map);

//SCATTER
entity_t *init_door(sfVector2f pos, assets_t **assets);
scatter_t *init_door_scatter(sfVector2f pos, assets_t **assets);
entity_t *init_door2(sfVector2f pos, assets_t **assets);
scatter_t *init_door_scatter2(sfVector2f pos, assets_t **assets);
entity_t *init_glock(sfVector2f pos, assets_t **assets);
scatter_t *init_glock_scatter(sfVector2f pos, assets_t **assets);
entity_t *init_coffin(sfVector2f pos, assets_t **assets, map_t *map);
scatter_t *init_coffin_scatter(sfVector2f pos, assets_t **assets);
void coffin_action(game_t *game, map_t *map);
entity_t *init_candy(sfVector2f pos, assets_t **assets);
scatter_t *init_candy_scatter(sfVector2f pos, assets_t **assets);
entity_t *init_photo(sfVector2f pos, assets_t **assets);
scatter_t *init_photo_scatter(sfVector2f pos, assets_t **assets);
entity_t *init_sat_down(sfVector2f pos, assets_t **assets, int gender);
scatter_t *init_sat_down_scatter(sfVector2f pos, assets_t **assets,
    int gender);
void check_assets(game_t *game);

//LOAD
void load_house1(game_t *game, map_t *map);
void load_nc(game_t *game, map_t *map);
void load_briefing(game_t *game, map_t *map);
//FIGHT
int count_hostile(linked_list_t *ll);
void start_fight(game_t *game, map_t *map);
void start_fight_groups(game_t *game, map_t *map, char *grp);
void end_fight(game_t *game, map_t *map);


//Drag and drop

void research_items_selected(map_t *map, game_t *game, bool *is_picked);
void research_slots_inventory(map_t *map, game_t *game, int k);
void check_void_slots(map_t *map, int i, int k,
    bool *is_good_slots);
void check_void_slots_wep(map_t *map, int i, int k,
    bool *is_good_slots);
void check_void_slots_armor(map_t *map, int i, int k,
    bool *is_good_slots);

void sort_entity_list(linked_list_t **entity, sfView *view);
void swap_node(linked_list_t *first,
    linked_list_t *second, linked_list_t **entity);
int nbr_max_slot(enum class_e class, main_slots_t **slots);
int nbr_slot_wep(main_slots_t **slots);
int nbr_slot_armor(main_slots_t **slots);
int nbr_slot_cyber_inv(main_slots_t **slots);
void check_change_dir(entity_t *civil, sfVector2f curent_pos);
