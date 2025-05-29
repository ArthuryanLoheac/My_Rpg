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
#include "pregame_gui_struct.h"
#include "rpg_struct.h"
#include "rpg_struct.h"
#include "lib.h"
#include "gui_struct.h"

float randf(float min, float max);

bool is_same_color(sfColor a, sfColor b);
struct s_gui_drop_menu *add_option_drop_menu(struct s_gui_drop_menu *drop_menu,
    gui_obj_t *obj);
char *get_asset(char *name, assets_t **assets);
linked_list_t *get_actual_list_shop(page_shop_t *options);

//INIT
void check_pos_scatters(params_t params,
    assets_t **assets, linked_list_t **ll, map_t *map);
entity_t *init_toxic_props_col(sfVector2f pos, assets_t **assets,
    map_panel_image_t *map);
int check_all_houses(params_t params, game_t *game,
    linked_list_t **ll, map_t *map);
level_up_menu_t *init_level_menu(game_t *game);
void draw_collision(sfVector2f pos, map_t *map);
void draw_rectangle(map_t *map, sfVector2f pos,
    sfVector2f x_values, sfVector2f y_values);
void draw_rectangle_panel(map_panel_image_t *map, sfVector2f pos,
    sfVector2f x_values, sfVector2f y_values);
entity_t *init_building_name(sfVector2f pos, assets_t **assets, char *str);
entity_t *init_building_shop(sfVector2f pos, assets_t **assets, char *str);
void init_houses_entity(linked_list_t **ll, map_t *map, game_t *game);
entity_t *init_toxic_props_col(sfVector2f pos, assets_t **assets,
    map_panel_image_t *map);

void loading_screen(game_t *game, float val);
page_final_t *init_final_page(assets_t **assets);
button_t *init_button(sfVector2f position, sfVector2f size,
    char *txt, assets_t **assets);
void define_button_image(button_t *my_button, char *path,
    sfVector2f position, sfVector2f size);
page_shop_item_t *init_item_shop(assets_t **assets, int id, int pos);
page_shop_t *init_shop(assets_t **assets, enum class_e class);
sfVector2i *init_hp(game_t *game);
enum class_e init_class(game_t *game);
sfRenderWindow *create_window(unsigned int x, unsigned int y,
    assets_t **assets);
void init_txt_stats(sfText *txt, stats_t *stats, enum class_e class);
player_character_t *init_player(game_t *game, bool new_game);
stats_t *init_stats(game_t *game, bool new_game);
stats_t *init_stats2(int *data);
page_choose_class_t *init_choose_class(assets_t **assets);
page_choose_stats_t *init_choose_stats(assets_t **assets);
item_t *init_item(int id, assets_t **assets);
map_t *init_new_game_map(game_t *game);
map_t *init_continue_game_map(game_t *game);
guis_t *init_guis(assets_t **assets);
void update_pos_sprites_options(game_t *game, page_options_t *options);
void compute_state_buttons(main_t *menu, game_t *game);
void compute_state_buttons_two(start_t *menu, game_t *game);
void move_rect(animated_img_t *image, bool restart_top);
main_t *init_main_menu(assets_t **assets);
start_t *init_start_menu(assets_t **assets);
keybind_t *init_keybind(void);
game_t *init_game(sfEvent *event);
void load_game(game_t *game);
keybind_t *init_keybind(void);
gui_obj_t *init_gui_obj(sfVector2f position, sfVector2f size);
gui_drp_t *init_drop_menu(sfVector2f *pos_size,
    int option_number, char **labels, assets_t **assets);
sfText *init_text(char *default_text, char *font, sfVector2f pos, float size);
label_t *init_label(char *default_text, sfVector2f pos, unsigned int size,
    char *font);
void init_animated_img(img_t *img, int height, int width, sfVector2f position);
img_t *init_image(char *filename, sfVector2f position,
    float scale);
gui_slider_t *init_slider(sfVector2f pos, sfVector2f size,
    float value_per_pixel, sfBool vertical);
void init_obj_outline(struct s_gui_object *obj, sfColor color);
time2_t *init_time(void);
entity_t *init_civilian(game_t *game, sfVector2f position);
void init_dialogue(diag_queue_t *diag_q, diag_pipe_t *dialogue_pipeline,
    char *pc_name, int gender);
fight_fx_t *init_explosion(game_t *game, sfVector2f pos);
fight_fx_t *init_bullet(game_t *game, sfVector2f pos, bool hit, float angle);
diag_queue_t *init_queue_diag(char *txt, img_t *portrait, int *answer_loc,
    char *name);
portrait_t *init_portrait(assets_t **assets);
quest_t *init_quest(char *name, int progression);
quest_t *continue_quest(game_t *game);
assets_t **init_assets(void);
pc_sprite_t *init_player_sprite(assets_t **assets, sfVector2f start_pos);
sfView *init_view(sfRenderWindow *window);
sfView *init_startview(sfRenderWindow *window);
sfView *init_continueview(sfRenderWindow *window,
    sfVector2f player_pos, game_t *game);
gui_inventory_t *init_inventory(bool new_game, void *game,
    struct s_assets **assets);
stats_area_t *init_stats_area(stats_t *stats,
    assets_t **assets, enum class_e class);
fight_t *init_new_game_fight(game_t *game);
fight_gui_t *init_fight_gui(assets_t **assets);
page_options_t *init_options(assets_t **assets);
void character_death(game_t *game);
void init_entity_red_area(linked_list_t ***ll, game_t *game);
void init_entity_street(linked_list_t ***ll, game_t *game);

map_panel_image_t *load_map(game_t *game, char *asset_map_name,
    sfVector2u size, bool force);
map_panel_image_t *load_game_map(game_t *game, char *asset_map_name,
    sfVector2u size);
void drop_item(linked_list_t **pos, game_t **game,
    sfVector2f position, int id);
void drop_item_with_item(linked_list_t **pos, map_t **map,
    sfVector2f position, item_t *item);
sfSprite *get_sprite(entity_t *entity);
linked_list_t *check_is_view(bool *is_player, linked_list_t *element,
    const int *data_node, sfView *view);
bool display_shoot(game_t *game, sfFloatRect tas, int type, bool f_hit);
void animation_shoot(game_t *game, sfVector2i hits,
    sfFloatRect target_and_shooter, int wpn_type);
void add_node_bullet(linked_list_t **pos,
    bullet_fight_t *data_added, int i);
bullet_fight_t *init_fight_shotgun_bullets(assets_t **assets,
    sfVector2f pos, float angle, int type);
bullet_fight_t *init_fight_ranged_bullets(game_t *game,
    sfVector2f pos, float angle, int type);
bullet_fight_t *init_fight_rocket_bullets(game_t *game,
    sfVector2f pos, float angle, int type);
void check_use_items(map_t *map, game_t *game, bool *is_picked);
map_panel_image_t *init_game_map(game_t *game, bool is_new, map_t *map);
fight_fx_t *init_explosion(game_t *game, sfVector2f pos);
entity_t *init_shop_scatter(sfVector2f pos, assets_t **assets, map_t *map);
entity_t *init_chair_scatter(sfVector2f pos, assets_t **assets);
// INIT SCATTERS
entity_t *init_street_lamp(sfVector2f pos, assets_t **assets, int dir);
entity_t *init_trash(sfVector2f pos, assets_t **assets);
entity_t *init_props(sfVector2f pos, assets_t **assets, bool poor_area);
entity_t *init_props_str(sfVector2f pos, assets_t **assets,
    char *str_f, int nb);
entity_t *init_toxic_props(sfVector2f pos, assets_t **assets, map_t *map);
entity_t *init_bins(sfVector2f pos, assets_t **assets);
weather_t *init_weather(void);
night_t *init_night(game_t *game, bool is_new);
diag_pipe_t *init_diag_pipe(assets_t **assets);
escape_menu_t *init_escape_menu(game_t *game);
quest_ui_t *init_quest_ui(game_t *game);
fade_t *init_fade(game_t *game);
gui_obj_t *init_gui_obj_img(char *str, sfVector2f pos,
    sfVector2f size, game_t *game);
float compute_no_hit2(void);
float compute_no_hit(void);
void import_inventory_slots(game_t *game,
    main_slots_t **inv);
sfVector2f bullet_pos(sfFloatRect tas);

void update_menu_start(ui_obj_t *obj, game_t *game);
void compute_guis(guis_t *guis, game_t *game);
void compute_game(game_t *game);

//COMPUTE
void check_generate_one_civil(linked_list_t **ll,
    linked_list_t **ll2, game_t *game);
void compute_add_hair_from_gender(int gender,
    game_t *game, player_character_t *player);
void compute_quest_ui(map_t *map, game_t *game);
void compute_fade(map_t *map);
void compute_weather(map_t *map);
void compute_button_state_level(map_t *map, game_t *game);
void compute_buttons_level(map_t *map, game_t *game);
void update_position_entity(linked_list_t **entity);
void add_clothe(assets_t **assets, linked_list_t **lst,
    char *str, sfVector2f pos);
void add_clothe_npc(assets_t **assets, linked_list_t **lst,
    char *str, npc_t *npc);
void set_volume_for_musics(music_t *music, float volume);
void compute_button_state_escape(map_t *map, game_t *game);
void compute_buttons_escape(map_t *map, game_t *game);
void compute_echap(game_t *game);
void compute_final_page(ui_obj_t *obj, game_t *game);
void compute_default_state_button(button_t *button);
void compute_recap_shop(recap_t *recap, player_character_t *player,
    stats_t *stats);
void compute_recap_inventory(recap_t *recap, game_t *game);
void compute_transfer_every_item_buyed(page_shop_t *options, game_t *game);
void compute_pos_x_offset(linked_list_t *lst, int offset);
void compute_everyone_transparent(page_shop_t *options);
void compute_buy_sell(page_shop_t *options, game_t *game);
void compute_item(linked_list_t *lst, player_character_t *player,
    nb_item_buyed_t *nb_item, enum type_shop_e state);
void compute_animation_hero(pc_sprite_t *player, game_t *game);
void compute_choose_class(ui_obj_t *obj, game_t *game);
void compute_choose_stats(ui_obj_t *obj, game_t *game);
int compute_civilian(entity_t *civil, map_t *map);
void compute_all_civilians(game_t *game, linked_list_t **entity_all);
void update_menu_start(ui_obj_t *obj, game_t *game);
void update_menu_main(ui_obj_t *obj, game_t *game);
void update_state_buttons(main_t *menu, game_t *game);
void update_state_buttons_two(start_t *menu, game_t *game);

void compute_shop(ui_obj_t *obj, game_t *game);
void compute_menu_start(ui_obj_t *obj, game_t *game);
void compute_menu_main(ui_obj_t *obj, game_t *game);
void compute_animation_img(animated_img_t *image, bool restart_top);
void compute_guis(guis_t *guis, game_t *game);
void compute_game(game_t *game);
void compute_info(sfRenderWindow *window, info_t *info, assets_t **assets);
void send_info(game_t *game, float time, char *str);
void compute_options(ui_obj_t *obj, game_t *game);

void update_menu_music(game_t *game);
void compute_diag_pipe(sfRenderWindow *window, diag_pipe_t *diag_pipe,
    assets_t **assets, player_character_t *player);
void compute_answer(diag_pipe_t *diag_pipe);
void compute_map(ui_obj_t *obj, game_t *game);
void compute_pause(guis_t *guis);
void compute_quest(quest_t *quest, game_t *game);
bool no_collision(map_t *map, sfVector2f pos);
bool no_collision_civils(map_t *map, sfVector2f pos,
    entity_t *civil);
bool no_collision_entity(map_t *map, sfVector2f pos);
bool sight_collision(map_t *map, sfVector2f pos1, sfVector2f pos2);
void compute_health_bar(gui_inventory_t *inventory, sfView *view);
sfVector2f compute_pc_collision(map_t *map, sfVector2f pos, sfVector2f old);
void compute_talk(game_t *game, npc_t *npc);
void compute_npc(game_t *game, entity_t *entity);
void compute_scatter(game_t *game, entity_t *entity);
void compute_entity(game_t *game, linked_list_t **ll);
void compute_1_entity(game_t *game, entity_t *entity);
void compute_dialogue(map_t *map);
void compute_movement(ui_obj_t *obj, game_t *game);
void compute_movement_free(ui_obj_t *obj, game_t *game);
void move_inventory_assets(map_t *map);
void compute_fight(ui_obj_t *obj, game_t *game);
void compute_player_turn(game_t *game, ui_obj_t *obj, map_t *map);
void npc_death(game_t *game, map_t *map);
void compute_fight_gui_pos(sfRenderWindow *window, fight_gui_t *gui);
void compute_shoot_line_pos(fight_gui_t *gui, sfVector2f pos1,
    sfVector2f pos2);
void compute_shoot_line_color(map_t *map, sfVector2f pos1,
    sfVector2f pos2, weapon_t *weapon);
void compute_shoot_line(map_t *map, sfVector2f pos1,
    sfVector2f pos2);
bool player_second_action(game_t *game);
void compute_player_fight(ui_obj_t *obj, game_t *game);
void compute_player_actions_done(ui_obj_t *obj, game_t *game);
void compute_player_actions_dash(ui_obj_t *obj, game_t *game);
void compute_player_actions_dodge(ui_obj_t *obj, game_t *game);
void compute_usual_state(gui_obj_t *button);
void compute_view_pos(game_t *game, map_t *map);
void compute_inventory(map_t *map, game_t *game);
sfVector2i empty_weapon(int hits, game_t *game);
sfVector2i compute_player_atk_npc(map_t *map, npc_t *npc, fight_t *fight,
    game_t *game);
int d10(sfSprite *sprite, game_t *game, int i);
int difs(weapon_t *wpn, sfSprite *sprite1, sfSprite *sprite2);
int difv(weapon_t *wpn, sfVector2f p1, sfVector2f p2);
void compute_ranged_hit_pc(stats_t *stat, player_character_t *pc,
    weapon_t *weapon);
void compute_ranged_hit_npc(stats_t *stat, npc_t *npc,
    weapon_t *weapon);
void compute_ranged_autofire_hit_npc(stats_t *stat, npc_t *npc,
    weapon_t *weapon, int diff);
void compute_melee_hit_pc(stats_t *stat, player_character_t *pc,
    weapon_t *weapon);
void compute_melee_hit_npc(stats_t *stats, npc_t *npc,
    weapon_t *weapon);
void compute_unarmd_hit_pc(stats_t *stats, player_character_t *pc);
void compute_unarmd_hit_npc(stats_t *stats, npc_t *npc);
sfVector2i compute_ranged_npc_atks(map_t *map, npc_t *npc, npc_t *target);
void compute_melee_npc_atk(map_t *map, npc_t *npc, npc_t *target);
void compute_unarmd_npc_atk(map_t *map, npc_t *npc, npc_t *target);
int compute_npc_fight(map_t *map, game_t *game, npc_t *npc,
    bool is_new);
sfVector2i compute_shell(game_t *game, weapon_t *weapon,
    sfRectangleShape *target, sfVector2f shooter_pos);
sfVector2i compute_expl(game_t *game, weapon_t *weapon, sfCircleShape *target,
    sfVector2f shooter_pos);
int find_target_ai(map_t *map, npc_t *npc);
sfVector2f find_pos_ai(map_t *map, sfVector2f target_pos,
    sfVector2f my_pos);
sfVector2f find_ideal_pos_ai(map_t *map, sfVector2f target_pos,
    npc_t *npc);
void compute_aoe_atk_npc(stats_t *stat, weapon_t *weapon,
    npc_t *target, sfVector2f shooter_pos);
void compute_aoe_atk_pc(stats_t *stat, weapon_t *weapon,
    player_character_t *target, sfVector2f shooter_pos);
void compute_aoe_target(stats_t *stat, weapon_t *weapon,
    entity_t *entity, sfVector2f shooter_pos);
void compute_items_on_ground(game_t *game);
void compute_bullets(bool has_del, map_t *map, game_t *game);
void compute_fight_fx(game_t *game, map_t *map);
void compute_dice_fx(game_t *game, map_t *map);
dice_fx_t *init_dice(game_t *game, sfVector2f pos, int res);
void compute_pc(map_t *map, game_t *game);
void compute_exp_player(map_t *map, game_t *game);
void compute_mana_bar(fight_t *fight);
void compute_shop_in_game(ui_obj_t *obj,
    game_t *game);
void compute_cyberware(map_t *map);
linked_list_t *check_swapping_node(sfFloatRect data_sprite[2],
    linked_list_t **a, linked_list_t **b);

// ACTIONS
void done(map_t *map);
void dash(ui_obj_t *obj, game_t *game);
void fire(ui_obj_t *obj, game_t *game);
void dodge(ui_obj_t *obj, game_t *game);

// MAKE
void make_label(label_t *label, sfRenderWindow *window);
void make_final_page(ui_obj_t *obj, game_t *game);
void make_shop(ui_obj_t *obj, game_t *game);
void make_img(img_t *image, sfRenderWindow *window);
void make_choose_class(ui_obj_t *obj, game_t *game);
void make_choose_stats(ui_obj_t *obj, game_t *game);
void make_options(ui_obj_t *obj, game_t *game);
void make_map(ui_obj_t *obj, game_t *game);
void make_guis(guis_t *guis, game_t *game);
void make_button(button_t *button, game_t *game);
void make_game(game_t *game);
void make_menu_start(ui_obj_t *obj, game_t *game);
void make_menu_main(ui_obj_t *obj, game_t *game);
void make_drop_menu(sfRenderWindow *window,
    struct s_gui_drop_menu *drop_menu);
void make_gui_obj(sfRenderWindow *window, struct s_gui_object *obj,
    sfColor color);
void make_slider(sfRenderWindow *window, gui_slider_t *slider, sfColor color);
void make_layers(sfRenderWindow *window, linked_list_t *layer_ll);
void make_diag_pipe(sfRenderWindow *window, diag_pipe_t *diag_pipe);
void make_npc(sfRenderWindow *window, npc_t *npc);
void make_player(sfRenderWindow *window, player_character_t *player);
void make_entity(sfRenderWindow *window, linked_list_t **ll, map_t *map);
void make_inventory(sfRenderWindow *window, gui_inventory_t *inventory);
void make_fight_gui(sfRenderWindow *window, game_t *game,
    fight_gui_t *fight_gui);
void make_dropped_items(sfRenderWindow *window, linked_list_t *dropped_items);
void make_shop_in_game(ui_obj_t *obj, game_t *game);

// ANALYSE
void analyze_shop(ui_obj_t *obj, game_t *game);
void analyze_shop_in_game(ui_obj_t *obj, game_t *game);
void analyze_final_page(ui_obj_t *obj, game_t *game);
void analyze_choose_class(ui_obj_t *obj, game_t *game);
void analyze_choose_stats(ui_obj_t *obj, game_t *game);
void analyze_options(ui_obj_t *obj, game_t *game);
void analyze_menu_start(ui_obj_t *obj, game_t *game);
void analyze_menu_main(ui_obj_t *obj, game_t *game);
void analyze_guis(guis_t *guis, game_t *game);
void analyze_game(game_t *game);
void analyze_map(ui_obj_t *obj, game_t *game);
void analyze_slider(sfRenderWindow *window, sfEvent event,
    gui_slider_t *slider);
void analyze_drop_menu(sfRenderWindow *window, sfEvent event,
    struct s_gui_drop_menu *drop_menu);
void analyze_gui_obj(sfRenderWindow *window, sfEvent *event,
    struct s_gui_object *obj);
void analyze_gui_obj_drp(sfRenderWindow *window, sfEvent *event,
    struct s_gui_object *obj);
void analyze_gui_slider(sfRenderWindow *window, sfEvent *event,
    struct s_gui_object *obj);
void analyze_diag_pipe(game_t *game, diag_pipe_t *diag_pipe);
void analyze_inventory(ui_obj_t *obj, game_t *game);
void analyze_reload_weapon(main_slots_t *k, main_slots_t *i,
    bool *is_reload, bool is_weapon_dep);
void analyze_use_gears(main_slots_t *k, main_slots_t *i,
    bool *is_reload, bool is_weapon_dep);
void analyze_fight(ui_obj_t *obj, game_t *game);
void analyze_fight_gui(sfRenderWindow *window, fight_gui_t *gui, game_t *game);
void do_swap_item(map_t *map, int k, int i);

// DESTROY
void destroy_time(time2_t *time);
void destroy_keybind(struct s_keybind *keybind);
void destroy_game(struct s_game *game);
void destroy_guis(struct s_guis *guis);
void destroy_main_menu(main_t *menu);
void destroy_drop_menu(gui_drp_t *drop_menu);
void destroy_options(struct s_gui_options *opt);
void destroy_gui_obj(struct s_gui_object *btn);
void destroy_image(img_t *img);
void destroy_label(label_t *label);
void destroy_slider(gui_slider_t *slider);
void destroy_layers(linked_list_t *ll);
void destroy_item(item_t *item);
void destroy_current_queued(diag_pipe_t *diag_pipe);
void destroy_map(map_t *map);
void destroy_start_menu(start_t *menu);
void destroy_choose_class_menu(page_choose_class_t *menu);
void destroy_options_menu(page_options_t *menu);
void destroy_player(player_character_t *player);
void destroy_stats(stats_t *stats);
void destroy_entity(linked_list_t *ll);
void destroy_1_entity(entity_t *entity);
void destroy_civilian(civ_t *civ);
void destroy_npc(npc_t *npc);
void destroy_fight_gui(fight_gui_t *gui);
void destroy_new_game_fight(fight_t *fight);
void destroy_button(button_t *button);
void destroy_game_map(map_panel_image_t *map);
