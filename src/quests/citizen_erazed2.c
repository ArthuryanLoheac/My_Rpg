/*
** EPITECH PROJECT, 2024
** quest
** File description:
** init_quest
*/

#include "my.h"

static void prog_0(map_t *map, game_t *game)
{
    static bool tuto = false;

    map->quest_ui->quest_pos = sfSprite_getPosition(get_npc("Cryspi",
        map->entity_all)->npc->sprite);
    get_npc("Cryspi", map->entity_all)->talkable = YES_TL;
    if (tuto == false) {
        tuto = true;
        send_info(game, 5, "Move around with Z, Q, S and D\n"
            "Interact with F");
    }
}

static void prog_1(map_t *map, game_t *game)
{
    map->quest_ui->quest_pos = sfSprite_getPosition(get_npc("Dyn",
        map->entity_all)->npc->sprite);
    get_npc("Dyn", map->entity_all)->talkable = YES_TL;
    (void) game;
}

static void compute_citizen_erazed_1_2(quest_t *quest, map_t *map,
    game_t *game)
{
    if (quest->prog.x % 2 == 0)
        prog_0(map, game);
    if (quest->prog.x <= 1)
        prog_1(map, game);
    if (get_npc("Cryspi", map->entity_all)->talkable == NO_TL &&
        empty_diag(map))
        my_insert_back_list(&get_npc("Cryspi", map->entity_all)->next_pos,
            vector(13551, 9180));
    if (get_npc("Dyn", map->entity_all)->talkable == NO_TL && empty_diag(map))
        my_insert_back_list(&get_npc("Dyn", map->entity_all)->next_pos,
            vector(13451, 9175));
}

void compute_citizen_erazed_1(quest_t *quest, map_t *map, game_t *game)
{
    bool talked = false;
    bool talked2 = false;

    if (get_npc("Cryspi", map->entity_all)->talkable == IS_TL) {
        map->dialogue = diag(quest->prefix,
            "cryspi/meet_burial;cryspi/puddle");
        talked = true;
        quest->prog.x = quest->prog.x + 1;
    }
    if (get_npc("Dyn", map->entity_all)->talkable == IS_TL) {
        map->dialogue = diag(quest->prefix,
            "dyn/meet_burial;dyn/dyn;dyn/dyna");
        talked2 = true;
        quest->prog.x = quest->prog.x + 2;
    }
    compute_citizen_erazed_1_2(quest, map, game);
    if (talked2)
        get_npc("Dyn", map->entity_all)->talkable = NO_TL;
    if (talked)
        get_npc("Cryspi", map->entity_all)->talkable = NO_TL;
}

void compute_citizen_erazed_2(quest_t *quest, map_t *map, game_t *game)
{
    get_scatter(6, map->entity_all)->scatter->init_new = &coffin_action;
    map->quest_ui->quest_pos = sfSprite_getPosition(get_scatter(6,
        map->entity_all)->scatter->scatter->sprite);
    (void) game;
    (void) quest;
}

static void sit_down(map_t *map, game_t *game, int *interacted)
{
    sfFloatRect rect1 = sfSprite_getGlobalBounds(map->player->sprite->temp
        ->sprite);
    sfFloatRect rect2 = sfSprite_getGlobalBounds(get_scatter(8,
        map->entity_all)->scatter->scatter->sprite);

    if (my_strcmp(map->map->current_map, "Briefing/") == 0 &&
        *interacted == 0) {
        if (sfKeyboard_isKeyPressed(game->keybinds->interact) &&
            sfFloatRect_intersects(&rect1, &rect2, NULL))
            *interacted = 1;
    }
}

void compute_citizen_erazed_3(quest_t *quest, map_t *map, game_t *game)
{
    static int interacted = 0;

    if (empty_diag(map) && my_strcmp(map->map->current_map, "Briefing/") != 0)
        load_briefing(game, map);
    if (empty_diag(map) && interacted == 2) {
        map->fade->is_active = true;
        sfView_setRotation(map->view, 0);
        quest->prog.x = quest->prog.x + 1;
    }
    if (interacted == 1) {
        get_scatter(8, map->entity_all)->hidden = false;
        sfSprite_setColor(map->player->sprite->temp->sprite, sfTransparent);
        map->player->movmult = 0;
        map->dialogue = diag(quest->prefix, "memories/briefing");
        interacted = 2;
    } else if (interacted == 0)
        get_scatter(8, map->entity_all)->hidden = true;
    sit_down(map, game, &interacted);
}

static void in_queenhouse(map_t *map)
{
    if (my_strcmp(map->map->current_map, "QueenHouse/") == 0) {
        map->quest_ui->quest_pos = sfSprite_getPosition(get_npc("Dyn",
            map->entity_all)->npc->sprite);
        get_npc("Dyn", map->entity_all)->talkable = YES_TL;
        get_npc("Dyn", map->entity_all)->map = my_strdup("QueenHouse/");
        get_npc("Cryspi", map->entity_all)->map = my_strdup("QueenHouse/");
        sfSprite_setPosition(get_npc("Dyn", map->entity_all)->npc->sprite,
            (sfVector2f){1116, 404});
        sfSprite_setPosition(get_npc("Cryspi", map->entity_all)->npc->sprite,
            (sfVector2f){1232, 420});
    }
}

void compute_citizen_erazed_4(quest_t *quest, map_t *map, game_t *game)
{
    static bool loaded_nc = false;

    if (map->fade->is_active == false && !loaded_nc) {
        load_nc(game, map);
        map->quest_ui->quest_pos = (sfVector2f){1610, 3524};
        sfSprite_setPosition(map->player->sprite->temp->sprite,
            (sfVector2f){13400, 8800});
        sfSprite_setColor(map->player->sprite->temp->sprite, sfWhite);
        map->player->movmult = 1;
        sfView_setCenter(map->view, (sfVector2f){13400, 9000});
        loaded_nc = true;
    }
    if (get_npc("Dyn", map->entity_all)->talkable == IS_TL) {
        map->dialogue = diag(quest->prefix, "dyn/queenhouse");
        get_npc("Dyn", map->entity_all)->talkable = NO_TL;
        quest->prog.x = quest->prog.x + 1;
    }
    in_queenhouse(map);
}
