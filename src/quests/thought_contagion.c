/*
** EPITECH PROJECT, 2024
** quest
** File description:
** init_quest
*/

#include "my.h"

static void encounter_allies(map_t *map)
{
    sfSprite_setPosition(get_npc("Cryspi", map->entity_all)->npc->sprite,
        (sfVector2f){1687, 3750});
    sfSprite_setPosition(get_npc("Dyn", map->entity_all)->npc->sprite,
        (sfVector2f){1520, 3730});
    my_insert_back_list(&(map->fight->turn_order), get_npc2("Cryspi",
        map->entity_all));
    my_insert_back_list(&(map->fight->turn_order), get_npc2("Dyn",
        map->entity_all));
}

static void start_encounter_1(map_t *map)
{
    sfSprite_setPosition(get_npc("#1Mook0", map->entity_all)->npc->sprite,
        (sfVector2f){1780, 3978});
    sfSprite_setPosition(get_npc("#1Mook1", map->entity_all)->npc->sprite,
        (sfVector2f){1687, 4000});
    sfSprite_setPosition(get_npc("#1Mook2", map->entity_all)->npc->sprite,
        (sfVector2f){1500, 3900});
    sfSprite_setPosition(get_npc("#1Mook3", map->entity_all)->npc->sprite,
        (sfVector2f){1370, 3750});
    sfSprite_setPosition(get_npc("#1Mook4", map->entity_all)->npc->sprite,
        (sfVector2f){1980, 3950});
    sfSprite_setPosition(get_npc("#1Mook5", map->entity_all)->npc->sprite,
        (sfVector2f){1587, 3934});
    sfSprite_setPosition(get_npc("#1Mook6", map->entity_all)->npc->sprite,
        (sfVector2f){1250, 4967});
    sfSprite_setPosition(get_npc("#1Mook7", map->entity_all)->npc->sprite,
        (sfVector2f){1970, 4350});
    encounter_allies(map);
}

static void compute_thought_contagion_1(quest_t *quest, map_t *map,
    game_t *game)
{
    static bool started = false;

    if (!map->fight->is_fight && started)
        quest->prog.x++;
    if (!map->fight->is_fight && !started) {
        start_fight_groups(game, map, "#1");
        if (is_in_fight("#1", map->entity_all) == false) {
            start_encounter_1(map);
        }
        started = true;
    }
    (void) quest;
}

static void compute_thought_contagion_2(quest_t *quest, map_t *map,
    game_t *game)
{
    if (get_npc("Dyn", map->entity_all)->talkable == IS_TL) {
        map->dialogue = diag(quest->prefix, "dyn/after_fight");
        get_npc("Dyn", map->entity_all)->talkable = NO_TL;
        quest->prog.x = quest->prog.x + 1;
    }
    get_npc("Dyn", map->entity_all)->talkable = YES_TL;
    map->quest_ui->quest_pos = sfSprite_getPosition(get_npc("Dyn",
        map->entity_all)->npc->sprite);
    (void) quest;
    (void) game;
}

static void compute_thought_contagion_3(quest_t *quest, map_t *map,
    game_t *game)
{
    static bool fade = false;

    if (!empty_diag(map))
        return;
    if (fade == false) {
        map->fade->is_active = true;
        fade = true;
    }
    if (map->fade->is_active == false) {
        chapter_transition(game, "Thanks for playing",
            "To be continued...", sfWhite);
        map->player->hp->y = -1;
    }
    (void) quest;
    (void) game;
}

void compute_thought_contagion(quest_t *quest, map_t *map, game_t *game)
{
    if (quest->objective)
        free(quest->objective);
    quest->objective = init_thought_contagion_obj(quest->prog.x);
    if (quest->prog.x == 0)
        return compute_thought_contagion_1(quest, map, game);
    if (quest->prog.x == 1)
        return compute_thought_contagion_2(quest, map, game);
    if (quest->prog.x == 2)
        return compute_thought_contagion_3(quest, map, game);
    (void) map;
    (void) game;
}

char *init_thought_contagion_obj(int prog)
{
    if (prog == 0)
        return my_strdup("Defeat the thug");
    if (prog >= 1)
        return my_strdup("Talk With your friend about what happened");
    return NULL;
}

quest_t *init_thought_contagion(int progression)
{
    quest_t *quest = malloc(sizeof(quest_t));

    quest->name = my_strdup("Thought Contagion");
    quest->next_quest_name = my_strdup("Soldier's Poem");
    quest->prefix = my_strdup("quests/thought_contagion/");
    quest->prog = (sfVector2u){progression, 14};
    quest->objective = init_thought_contagion_obj(progression);
    quest->compute = &compute_thought_contagion;
    return quest;
}
