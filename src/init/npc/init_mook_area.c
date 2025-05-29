/*
** EPITECH PROJECT, 2024
** init_mook_area.c
** File description:
** init_mook_area
*/

#include "my.h"

void init_entity_encounter1(linked_list_t ***ll, game_t *game)
{
    entity_t **entities = malloc(sizeof(entity_t *) * 8);

    for (int i = 0; i < 8; i++)
        entities[i] = init_mook(vect0(), game->assets,
        append_str2(my_strdup("#1Mook"), int_to_str(i)), 20 + rand() % 6);
    entities[0]->npc->ranged = init_item(306, game->assets);
    entities[1]->npc->melee = NULL;
    entities[2]->npc->ranged = init_item(305, game->assets);
    for (int i = 0; i < 8; i++)
        my_insert_back_list(*ll, entities[i]);
    free(entities);
}

void init_entity_red_area(linked_list_t ***ll, game_t *game)
{
    my_insert_back_list(*ll, init_mook((sfVector2f){12060, 4900},
        game->assets, "!1Mook1", 10));
    my_insert_back_list(*ll, init_mook((sfVector2f){11650, 5030},
        game->assets, "!1Mook2", 10));
    my_insert_back_list(*ll, init_mook((sfVector2f){11060, 5332},
        game->assets, "!1Mook3", 10));
    my_insert_back_list(*ll, init_mook((sfVector2f){11630, 5235},
        game->assets, "!1Mook4", 10));
    my_insert_back_list(*ll, init_mook((sfVector2f){11600, 4946},
        game->assets, "!1Mook5", 10));
    my_insert_back_list(*ll, init_mook((sfVector2f){12610, 5050},
        game->assets, "!1Mook6", 10));
}

static void init_area_second(linked_list_t ***ll, game_t *game)
{
    my_insert_back_list(*ll, init_mook((sfVector2f){7000, 1430},
        game->assets, "!2Mook1", 10));
    my_insert_back_list(*ll, init_mook((sfVector2f){7200, 1400},
        game->assets, "!2Mook2", 10));
    my_insert_back_list(*ll, init_mook((sfVector2f){7500, 1420},
        game->assets, "!2Mook3", 10));
}

static void init_area_four(linked_list_t ***ll, game_t *game)
{
    my_insert_back_list(*ll, init_mook((sfVector2f){2182, 7877},
        game->assets, "!4Mook1", 10));
    my_insert_back_list(*ll, init_mook((sfVector2f){2082, 7877},
        game->assets, "!4Mook2", 10));
    my_insert_back_list(*ll, init_mook((sfVector2f){2282, 7877},
        game->assets, "!4Mook3", 10));
    my_insert_back_list(*ll, init_mook((sfVector2f){2182, 7777},
        game->assets, "!4Mook3", 10));
}

static void init_area_five(linked_list_t ***ll, game_t *game)
{
    my_insert_back_list(*ll, init_mook((sfVector2f){4000, 10680},
        game->assets, "!5Mook1", 10));
    my_insert_back_list(*ll, init_mook((sfVector2f){4100, 10680},
        game->assets, "!5Mook2", 10));
    my_insert_back_list(*ll, init_mook((sfVector2f){4200, 10680},
        game->assets, "!5Mook3", 10));
    my_insert_back_list(*ll, init_mook((sfVector2f){4100, 10620},
        game->assets, "!5Mook3", 10));
}

static void init_area_six(linked_list_t ***ll, game_t *game)
{
    my_insert_back_list(*ll, init_mook((sfVector2f){15800, 7043},
        game->assets, "!6Mook1", 10));
    my_insert_back_list(*ll, init_mook((sfVector2f){15650, 7043},
        game->assets, "!6Mook2", 10));
    my_insert_back_list(*ll, init_mook((sfVector2f){15730, 6900},
        game->assets, "!6Mook3", 10));
}

static void init_area_seven(linked_list_t ***ll, game_t *game)
{
    my_insert_back_list(*ll, init_mook((sfVector2f){14297, 2635},
        game->assets, "!7Mook1", 10));
    my_insert_back_list(*ll, init_mook((sfVector2f){14494, 2711},
        game->assets, "!7Mook2", 10));
    my_insert_back_list(*ll, init_mook((sfVector2f){14430, 2983},
        game->assets, "!7Mook3", 10));
    my_insert_back_list(*ll, init_mook((sfVector2f){14204, 2914},
        game->assets, "!7Mook4", 10));
    my_insert_back_list(*ll, init_mook((sfVector2f){14368, 2822},
        game->assets, "!7Mook5", 10));
}

static void set_civ_npc_pos(entity_t **entities)
{
    sfSprite_setPosition(entities[0]->npc->npc->sprite,
        (sfVector2f){13570, 9100});
    sfSprite_setPosition(entities[1]->npc->npc->sprite,
        (sfVector2f){13570, 8960});
    sfSprite_setPosition(entities[2]->npc->npc->sprite,
        (sfVector2f){13530, 9020});
    sfSprite_setPosition(entities[3]->npc->npc->sprite,
        (sfVector2f){13558, 9080});
    sfSprite_setPosition(entities[4]->npc->npc->sprite,
        (sfVector2f){13335, 9000});
    sfSprite_setPosition(entities[5]->npc->npc->sprite,
        (sfVector2f){13342, 9120});
    sfSprite_setPosition(entities[6]->npc->npc->sprite,
        (sfVector2f){13372, 8960});
    sfSprite_setPosition(entities[7]->npc->npc->sprite,
        (sfVector2f){13351, 9080});
}

static void init_quest_mook(linked_list_t ***ll, game_t *game)
{
    entity_t **entities = malloc(sizeof(entity_t *) * 8);

    for (int i = 0; i < 8; i++) {
        entities[i] = init_mook(vect0(), game->assets,
            append_str2(my_strdup("Civ_npc"), int_to_str(i)), 20 + rand() % 6);
        entities[i]->npc->type = FRIENDLY;
    }
    set_civ_npc_pos(entities);
    for (int i = 0; i < 8; i++)
        my_insert_back_list(*ll, entities[i]);
    free(entities);
}

void init_entity_street(linked_list_t ***ll, game_t *game)
{
    init_quest_mook(ll, game);
    init_area_second(ll, game);
    my_insert_back_list(*ll, init_mook((sfVector2f){1703, 2590},
        game->assets, "!3Mook1", 10));
    my_insert_back_list(*ll, init_mook((sfVector2f){1603, 2590},
        game->assets, "!3Mook2", 10));
    my_insert_back_list(*ll, init_mook((sfVector2f){1653, 2490},
        game->assets, "!3Mook3", 10));
    init_area_four(ll, game);
    init_area_five(ll, game);
    init_area_six(ll, game);
    init_area_seven(ll, game);
    my_insert_back_list(*ll, init_mook((sfVector2f){12790, 8950},
        game->assets, "!8Mook1", 10));
    init_entity_encounter1(ll, game);
}
