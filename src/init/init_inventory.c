/*
** EPITECH PROJECT, 2024
** inventory
** File description:
** init_inventory
*/

#include "my.h"

static player_stats_t *init_status_player(assets_t **assets)
{
    player_stats_t *stats = malloc(sizeof(player_stats_t));

    stats->player_img = init_image(get_asset("Inventory_hero", assets),
        (sfVector2f){195, 155}, 1);
    stats->health_bar = init_image(get_asset("Inventory_health", assets),
        (sfVector2f){210, 500}, 1);
    init_animated_img(stats->health_bar, 38, 300, (sfVector2f){210, 500});
    set_animate_image(stats->health_bar, 128, 128, 1);
    return stats;
}

static void compute_pos(sfVector2f *pos, int i)
{
    pos->x += 155;
    if ((i) % 4 == 0) {
        pos->x = 600;
        pos->y += 145;
    }
}

static inventory_slots_t *init_inventory_slots(assets_t **assets)
{
    inventory_slots_t *slots = malloc(sizeof(inventory_slots_t));
    sfVector2f pos = {600, 25};

    slots->main_slots = malloc(sizeof(item_t *) * (21));
    slots->main_slots[20] = NULL;
    for (int i = 0; i < 20; i++) {
        compute_pos(&pos, i);
        slots->main_slots[i] = malloc(sizeof(main_slots_t));
        slots->main_slots[i]->items = NULL;
        slots->main_slots[i]->position_icon.x = pos.x + 63;
        slots->main_slots[i]->position_icon.y = pos.y + 63;
        set_image_slots(slots->main_slots[i], i, pos, assets);
    }
    return slots;
}

quest_area_t *init_quest_area(assets_t **assets)
{
    quest_area_t *quest = malloc(sizeof(quest_area_t));

    quest->area = init_image(get_asset("Inventory_objectifs", assets),
        (sfVector2f){1240, 170}, 1);
    quest->text = sfText_create();
    quest->font = sfFont_createFromFile(get_asset("Font_pixel", assets));
    sfText_setScale(quest->text, (sfVector2f){0.5, 0.5});
    sfText_setFont(quest->text, quest->font);
    sfText_setColor(quest->text, sfWhite);
    sfText_setPosition(quest->text, (sfVector2f){1300, 300});
    sfText_setString(quest->text, "No quest");
    return quest;
}

static logo_t *init_logo(assets_t **assets)
{
    logo_t *logo = malloc(sizeof(logo_t));

    logo->logo_img = init_image(get_asset("Inventory_description", assets),
        (sfVector2f){1240, 585}, 1);
    logo->txt = init_label("Click on a object to see it",
        (sfVector2f){1240, 585}, 20, get_asset("Font_pixel", assets));
    return logo;
}

stats_area_t *init_stats_area(stats_t *stats,
    assets_t **assets, enum class_e class)
{
    stats_area_t *quest = malloc(sizeof(stats_area_t));

    quest->text = sfText_create();
    quest->font = sfFont_createFromFile(get_asset("Font_pixel", assets));
    sfText_setScale(quest->text, (sfVector2f){0.5, 0.5});
    sfText_setFont(quest->text, quest->font);
    sfText_setColor(quest->text, sfColor_fromRGB(223, 227, 244));
    sfText_setPosition(quest->text, (sfVector2f){225, 590});
    init_txt_stats(quest->text, stats, class);
    return quest;
}

gui_inventory_t *init_inventory(bool new_game, void *game,
    struct s_assets **assets)
{
    gui_inventory_t *data = malloc(sizeof(gui_inventory_t));

    data->background = init_image(get_asset("Inventory_BG", assets),
        (sfVector2f){160, 120}, 1);
    data->logo = init_logo(assets);
    data->quest = init_quest_area(assets);
    data->stats = init_status_player(assets);
    data->inventory = init_inventory_slots(assets);
    if (!new_game)
        import_inventory_slots(game, data->inventory->main_slots);
    data->is_display = false;
    data->item_info = init_label("", vect0(), 12, get_asset(
        "Font_pixel", assets));
    data->items_slots_picked = -1;
    data->durability = sfRectangleShape_create();
    data->is_picked = false;
    return data;
}
