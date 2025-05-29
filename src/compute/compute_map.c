/*
** EPITECH PROJECT, 2024
** update_menu_start
** File description:
** update_menu_start
*/

#include "my.h"

static void compute_quest_area(map_t *map, game_t *game)
{
    sfText_setString(map->inventory->quest->text, game->quests->objective);
}

static void compute_pos(sfVector2f *pos, int i, sfVector2f pos_view)
{
    pos->x += 155;
    if ((i) % 4 == 0) {
        pos->x = pos_view.x - 960 + 600;
        pos->y += 145;
    }
}

static void move_slots(sfVector2f pos_view, inventory_slots_t *slots)
{
    sfVector2f pos = {pos_view.x - 960 + 600, pos_view.y - 540 + 25};

    for (int i = 0; i < 20; i++) {
        compute_pos(&pos, i, pos_view);
        if (!slots->main_slots[i])
            continue;
        slots->main_slots[i]->position_icon.x = pos.x + 63;
        slots->main_slots[i]->position_icon.y = pos.y + 63;
        if (slots->main_slots[i]->items) {
            sfSprite_setPosition(slots->main_slots[i]->items->icon->sprite,
                slots->main_slots[i]->position_icon);
        }
        sfSprite_setPosition(slots->main_slots[i]->background->sprite, pos);
    }
}

void move_inventory_assets(map_t *map)
{
    sfVector2f pos_view = sfView_getCenter(map->view);

    sfSprite_setPosition(map->inventory->background->sprite,
        (sfVector2f){pos_view.x - 960 + 160, pos_view.y - 540 + 120});
    sfSprite_setPosition(map->inventory->logo->logo_img->sprite, (sfVector2f)
        {pos_view.x - 960 + 1240, pos_view.y - 540 + 585});
    sfText_setPosition(map->inventory->logo->txt->txt, (sfVector2f)
        {pos_view.x - 960 + 1260, pos_view.y - 540 + 685});
    sfSprite_setPosition(map->inventory->quest->area->sprite, (sfVector2f)
        {pos_view.x - 960 + 1240, pos_view.y - 540 + 170});
    if (map->inventory->is_display == true)
        sfSprite_setPosition(map->inventory->stats->health_bar->sprite,
            (sfVector2f){pos_view.x - 960 + 210, pos_view.y - 540 + 500});
    sfSprite_setPosition(map->inventory->stats->player_img->sprite,
        (sfVector2f){pos_view.x - 960 + 195, pos_view.y - 540 + 155});
    sfText_setPosition(map->inventory->quest->text, (sfVector2f)
        {pos_view.x - 960 + 1300, pos_view.y - 540 + 300});
    sfText_setPosition(map->inventory->stats_area->text, (sfVector2f)
        {pos_view.x - 960 + 225, pos_view.y - 540 + 590});
    move_slots(pos_view, map->inventory->inventory);
}

static void compute_sound_music(game_t *game)
{
    set_general_volume(game);
}

static void compute_fight_queue(map_t *map, game_t *game)
{
    compute_bullets(false, map, game);
    compute_fight_fx(game, map);
    compute_dice_fx(game, map);
}

static void compute_overlay(map_t *map, game_t *game)
{
    compute_view_pos(game, map);
    compute_fade(map);
}

void compute_map_not_pause(ui_obj_t *obj, map_t *map, game_t *game)
{
    compute_items_on_ground(game);
    sort_entity_list(&(map->entity_area), game->view);
    compute_all_civilians(game, &(map->entity_all));
    if (map->fight->is_fight == true)
        compute_fight(obj, game);
    else {
        compute_dialogue(map);
        compute_diag_pipe(game->window, map->dialogue_pipeline, game->assets,
            game->player);
        compute_quest_area(map, game);
        compute_quest(game->quests, game);
        compute_movement_free(obj, game);
        compute_quest_ui(map, game);
    }
    compute_entity(game, &(map->entity_area));
    move_inventory_assets(map);
    compute_sound_music(game);
    compute_pc(map, game);
    compute_fight_queue(map, game);
    compute_overlay(map, game);
}

static void compute_equiped_armor(map_t *map, player_character_t *player)
{
    main_slots_t **main_slots_v = map->inventory->inventory->main_slots;

    if (main_slots_v[8]->items == NULL) {
        player->id_active_armor = 0;
        return;
    }
    if (main_slots_v[8]->items->id >= 101 &&
        main_slots_v[8]->items->id <= 107)
        player->id_active_armor = main_slots_v[8]->items->id - 100;
}

void compute_map(ui_obj_t *obj, game_t *game)
{
    map_t *map = (map_t *)obj->ui_content;

    compute_echap(game);
    compute_equiped_armor(map, game->player);
    if (game->espace_active)
        compute_buttons_escape(map, game);
    else if (game->level_up_active)
        compute_buttons_level(map, game);
    else
        compute_map_not_pause(obj, map, game);
}
