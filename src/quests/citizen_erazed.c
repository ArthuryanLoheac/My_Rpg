/*
** EPITECH PROJECT, 2024
** quest
** File description:
** init_quest
*/

#include "my.h"

static void compute_citizen_erazed_5(quest_t *quest, map_t *map, game_t *game)
{
    if (!((quest->prog.x - 6) % 2 == 1))
        get_scatter(2, map->entity_all)->hidden = false;
    else
        get_scatter(2, map->entity_all)->hidden = true;
    if (!((quest->prog.x - 6) / 2 % 2 == 1))
        get_scatter(4, map->entity_all)->hidden = false;
    else
        get_scatter(4, map->entity_all)->hidden = true;
    if (!((quest->prog.x - 6) / 4 % 4 == 1))
        get_scatter(5, map->entity_all)->hidden = false;
    else
        get_scatter(5, map->entity_all)->hidden = true;
    (void) game;
}

static void compute_citizen_erazed_6_available_npc(quest_t *quest, map_t *map,
    game_t *game, int *dialogue)
{
    *dialogue = *dialogue + 1;
    get_npc("Dyn", map->entity_all)->talkable = YES_TL;
    get_npc("Dyn", map->entity_all)->map = my_strdup("QueenHouse/");
    get_npc("Cryspi", map->entity_all)->map = my_strdup("QueenHouse/");
    map->quest_ui->quest_pos = sfSprite_getPosition(get_npc("Dyn",
        map->entity_all)->npc->sprite);
    sfSprite_setPosition(get_npc("Dyn", map->entity_all)->npc->sprite,
        (sfVector2f){1116, 404});
    sfSprite_setPosition(get_npc("Cryspi", map->entity_all)->npc->sprite,
        (sfVector2f){1232, 420});
    (void) game;
    (void) quest;
}

static void animate_exit_house(map_t *map, int *dialogue)
{
        my_insert_back_list(&get_npc("Dyn", map->entity_all)->next_pos,
            vector(920, 530));
        my_insert_back_list(&get_npc("Cryspi", map->entity_all)->next_pos,
            vector(-1, 0.1));
        my_insert_back_list(&get_npc("Dyn", map->entity_all)->next_pos,
            vector(920, 600));
        my_insert_back_list(&get_npc("Cryspi", map->entity_all)->next_pos,
            vector(920, 480));
        my_insert_back_list(&get_npc("Cryspi", map->entity_all)->next_pos,
            vector(-1, 0.3));
        my_insert_back_list(&get_npc("Cryspi", map->entity_all)->next_pos,
            vector(920, 600));
        *dialogue = 3;
}

static void npc_get_out(map_t *map, int *dialogue, quest_t *quest)
{
    if (get_npc("Dyn", map->entity_all)->talkable == IS_TL) {
        map->dialogue = diag(quest->prefix, "dyn/queenhouse2");
        get_npc("Dyn", map->entity_all)->talkable = NO_TL;
        *dialogue = 2;
    }
    if (get_distance(sfSprite_getPosition(get_npc("Dyn",
            map->entity_all)->npc->sprite), (sfVector2f){920, 600}) < 5) {
        get_npc("Dyn", map->entity_all)->map = my_strdup("Night_City/");
        sfSprite_setPosition(get_npc("Dyn", map->entity_all)->npc->sprite,
            (sfVector2f){1520, 3730});
        *dialogue = 4;
    }
    if (get_distance(sfSprite_getPosition(get_npc("Cryspi",
            map->entity_all)->npc->sprite), (sfVector2f){920, 600}) < 5) {
        get_npc("Cryspi", map->entity_all)->map = my_strdup("Night_City/");
        sfSprite_setPosition(get_npc("Cryspi", map->entity_all)->npc->sprite,
            (sfVector2f){1687, 3750});
    }
}

static void compute_citizen_erazed_6(quest_t *quest, map_t *map, game_t *game)
{
    static int dialogue = 0;

    if (dialogue == 2 && empty_diag(map) && get_npc("Dyn", map->entity_all)
        ->talkable == NO_TL)
        animate_exit_house(map, &dialogue);
    if (my_strcmp(map->map->current_map, "QueenHouse/") == 0 && dialogue == 0)
        compute_citizen_erazed_6_available_npc(quest, map, game, &dialogue);
    npc_get_out(map, &dialogue, quest);
    if (my_strcmp(map->map->current_map, "Night_City/") == 0 &&
        dialogue == 4) {
        chapter_transition(game, "Chapter 2:", "Thought Contagion", sfWhite);
        sfView_setCenter(((map_t *)game->guis->map->ui_content)->view,
            (sfVector2f){1560, 3340});
        game->quests = init_thought_contagion(0);
        dialogue = 5;
    }
}

void compute_citizen_erazed(quest_t *quest, map_t *map, game_t *game)
{
    if (quest->objective)
        free(quest->objective);
    quest->objective = init_citizen_erazed_obj(quest->prog.x);
    if (quest->prog.x <= 2)
        return compute_citizen_erazed_1(quest, map, game);
    if (quest->prog.x <= 3)
        return compute_citizen_erazed_2(quest, map, game);
    if (quest->prog.x <= 4)
        return compute_citizen_erazed_3(quest, map, game);
    if (quest->prog.x <= 5)
        return compute_citizen_erazed_4(quest, map, game);
    if (quest->prog.x <= 12)
        return compute_citizen_erazed_5(quest, map, game);
    if (quest->prog.x <= 13)
        return compute_citizen_erazed_6(quest, map, game);
    return;
}

char *init_citizen_erazed_obj(int prog)
{
    if (prog >= 0 && prog <= 2)
        return my_strdup("Catch up with Dyn and Crys");
    if (prog == 3)
        return my_strdup("Do your speech");
    if (prog == 4)
        return my_strdup("Listen to the mission briefings");
    if (prog == 5)
        return my_strdup("Go to queen's home");
    if (prog >= 6 && prog <= 12)
        return my_strdup("Find any compromising clues");
    if (prog == 13)
        return my_strdup("Give the objects to Dyn");
    return NULL;
}

quest_t *init_citizen_erazed(int progression)
{
    quest_t *quest = malloc(sizeof(quest_t));

    quest->name = my_strdup("Citizen Erazed");
    quest->next_quest_name = my_strdup("Thought Contagion");
    quest->prefix = my_strdup("quests/citizen_erazed/");
    quest->prog = (sfVector2u){progression, 14};
    quest->objective = init_citizen_erazed_obj(progression);
    quest->compute = &compute_citizen_erazed;
    return quest;
}
