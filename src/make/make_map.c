/*
** EPITECH PROJECT, 2024
** make_map
** File description:
** make_map
*/

#include "my.h"

static void make_map_image(map_t *map, sfRenderWindow *window)
{
    for (int r = 0; map->map->map[r]; r++) {
        for (int c = 0; map->map->map[r][c]; c++) {
            make_img(map->map->map[r][c]->map, window);
        }
    }
}

static void make_bullets(map_t *map, sfRenderWindow *window)
{
    linked_list_t *element = map->fight_tools;

    while (element) {
        sfRenderWindow_drawSprite(window,
            ((bullet_fight_t *)(element->data))->bullet->sprite, NULL);
        if (((bullet_fight_t *)(element->data))->weapon)
            sfRenderWindow_drawSprite(window,
                ((bullet_fight_t *)(element->data))->weapon->sprite, NULL);
        element = element->next;
    }
}

static void make_fight_fx(map_t *map, sfRenderWindow *window)
{
    linked_list_t *element = map->fight_fx;

    while (element) {
        sfRenderWindow_drawSprite(window,
            ((fight_fx_t *)(element->data))->img->sprite, NULL);
        element = element->next;
    }
}

static void make_dice_fx(map_t *map, sfRenderWindow *window)
{
    linked_list_t *element = map->dice;

    while (element) {
        if (((dice_fx_t *)(element->data)) && ((dice_fx_t *)(element->data))
            ->img && ((dice_fx_t *)(element->data))->img->sprite)
        sfRenderWindow_drawSprite(window,
            ((dice_fx_t *)(element->data))->img->sprite, NULL);
        element = element->next;
    }
}

static void make_escape(escape_menu_t *map, game_t *game)
{
    make_button(map->main_menu, game);
    make_button(map->save, game);
    make_button(map->load, game);
    make_img(map->options->img, game->window);
    make_img(map->quit->img, game->window);
}

static void make_level_up(level_up_menu_t *menu, game_t *game)
{
    sfSprite_setPosition(menu->bg->sprite, add(sfView_getCenter(
        sfRenderWindow_getView(game->window)), - 825, - 490));
    make_img(menu->bg, game->window);
    make_label(menu->title, game->window);
    make_img(menu->Body->img, game->window);
    make_label(menu->Body_txt, game->window);
    make_img(menu->Will->img, game->window);
    make_label(menu->Will_txt, game->window);
    make_img(menu->Move->img, game->window);
    make_label(menu->Move_txt, game->window);
    make_img(menu->EMP->img, game->window);
    make_label(menu->EMP_txt, game->window);
    make_img(menu->Dexterity->img, game->window);
    make_label(menu->Dexterity_txt, game->window);
    make_img(menu->LUCK->img, game->window);
    make_label(menu->LUCK_txt, game->window);
    make_img(menu->Tech->img, game->window);
    make_label(menu->Tech_txt, game->window);
    make_img(menu->REF->img, game->window);
    make_label(menu->REF_txt, game->window);
}

static void make_night(night_t *night, game_t *game)
{
    int val;

    update_time(night->clock);
    night->clock->seconds = (int)(night->clock->seconds * night->time_mult) %
        1200;
    val = (int)night->clock->seconds;
    if (val > 700) {
        sfSprite_setColor(night->overlay->sprite, (sfColor){255, 255, 255, 160
            * ((val - 700) / 500.0)});
    } else if (val < 500) {
        sfSprite_setColor(night->overlay->sprite, (sfColor){255, 255, 255, 160
            * ((500 - val) / 500.0)});
    } else
        sfSprite_setColor(night->overlay->sprite, (sfColor){255, 255, 255,
            0.0});
    if (night->clock->seconds > 1200.0)
        sfClock_restart(night->clock->clock);
    if (night->clock->offset > 1200)
        night->clock->offset -= 1200;
    make_img(night->overlay, game->window);
}

static void make_ui(game_t *game, map_t *map)
{
    make_diag_pipe(game->window, map->dialogue_pipeline);
    make_inventory(game->window, map->inventory);
    make_img(map->inventory->stats->health_bar, game->window);
    if (map->fight->is_fight == true && map->inventory->is_display == false)
        make_fight_gui(game->window, game, map->fight->gui);
    else
        sfRenderWindow_drawSprite(game->window, map->quest_ui->quest_arrow
            ->sprite, NULL);
    if (game->espace_active)
        make_escape(map->escape_menu, game);
    if (game->level_up_active)
        make_level_up(map->level_menu, game);
    make_img(map->fade->img, game->window);
}

static void make_map_entity_bullets_fxs(game_t *game, ui_obj_t *obj)
{
    map_t *map = (map_t *)obj->ui_content;

    make_map_image(map, game->window);
    make_entity(game->window, &(map->entity_area), map);
    make_bullets(map, game->window);
    make_fight_fx(map, game->window);
    make_dice_fx(map, game->window);
}

void make_map(ui_obj_t *obj, game_t *game)
{
    map_t *map = (map_t *)obj->ui_content;

    make_map_entity_bullets_fxs(game, obj);
    if (map->weather->sprite &&
        my_strcmp("Night_City/", map->map->current_map) == 0)
        sfRenderWindow_drawSprite(game->window, map->weather->sprite, NULL);
    make_night(map->night, game);
    make_ui(game, map);
    if (game->player->hp->x <= 0)
        character_death(game);
    if (game->player->hp->y <= 0)
        go_to_menu2(game);
    sfRenderWindow_drawRectangleShape(game->window,
        map->player->range_trigger, NULL);
}
