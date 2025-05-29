/*
** EPITECH PROJECT, 2024
** init_entity
** File description:
** init_entity
*/

#include "my.h"

static void npc_err_exit(char *name)
{
    if (name)
        fprintf(stderr, "Error reading save file's npc in %s\n", name);
    else
        fprintf(stderr, "Error reading save file's npc\n");
    exit(84);
}

static entity_t *init_pc_entity(player_character_t *player, game_t *game)
{
    entity_t *pc = malloc(sizeof(entity_t));

    pc->hidden = false;
    pc->type = PC;
    pc->pc = player;
    pc->position = (sfVector2f){300, 300};
    pc->map = (int)pc->position.x / 1920 +
        (int)pc->position.y / 1080 * 9;
    pc->move = true;
    (void) game;
    return pc;
}

static void init_scatter_sec_part(game_t *game, linked_list_t **ll, map_t *map)
{
    my_insert_back_list(ll, init_shop_scatter((sfVector2f){13400, 9200},
        game->assets, map));
    my_insert_back_list(ll, init_shop_scatter((sfVector2f){13400, 9200},
        game->assets, map));
    my_insert_back_list(ll, init_chair_scatter((sfVector2f){11727, 10756},
        game->assets));
}

static void init_scatter_entity(game_t *game, linked_list_t **ll, map_t *map)
{
    my_insert_back_list(ll, init_door((sfVector2f){1500, 3500},
        game->assets));
    my_insert_back_list(ll, init_door2((sfVector2f){900, 640},
        game->assets));
    my_insert_back_list(ll, init_glock((sfVector2f){450, 90},
        game->assets));
    my_insert_back_list(ll, init_photo((sfVector2f){180, 140},
        game->assets));
    my_insert_back_list(ll, init_candy((sfVector2f){150, 320},
        game->assets));
    my_insert_back_list(ll, init_coffin((sfVector2f){13400, 9000},
        game->assets, map));
    my_insert_back_list(ll, init_sat_down((sfVector2f){380, 440},
        game->assets, map->player->gender));
    my_insert_back_list(ll, init_shop_scatter((sfVector2f){13400, 9200},
        game->assets, map));
    init_scatter_sec_part(game, ll, map);
}

static void init_new_entity_npc_pc(player_character_t *player, game_t *game,
    linked_list_t **ll)
{
    init_entity_red_area(&ll, game);
    init_entity_street(&ll, game);
    my_insert_back_list(ll, init_cryspi((sfVector2f){13800, 9300},
        game->assets));
    my_insert_front_list(ll, init_dyn((sfVector2f){13800, 9600},
        game->assets));
    my_insert_front_list(ll, init_pc_entity(player, game));
}

sfVector2f str_to_sfvector2f(char *str, int offset)
{
    sfVector2f vector = {0, 0};
    char *parsed_input;
    char *endpoint;
    int count = 0;

    parsed_input = strtok(strdup(&str[offset]), ",");
    while (parsed_input != NULL && count < 2) {
        if (count == 0)
            vector.x += strtof(parsed_input, &endpoint);
        if (count == 1)
            vector.y += strtof(parsed_input, &endpoint);
        if (endpoint == parsed_input || *endpoint != '\0')
            npc_err_exit(NULL);
        parsed_input = strtok(NULL, " ");
        count++;
    }
    free(parsed_input);
    return vector;
}

sfVector2i str_to_sfvector2i(char *str, int offset)
{
    sfVector2i vector = {0, 0};
    char *parsed_input;
    char *endpoint;
    int count = 0;

    parsed_input = strtok(strdup(&str[offset]), ",");
    while (parsed_input != NULL && count < 2) {
        if (count == 0)
            vector.x += strtol(parsed_input, &endpoint, 10);
        if (count == 1)
            vector.y += strtol(parsed_input, &endpoint, 10);
        if (endpoint == parsed_input || *endpoint != '\0')
            npc_err_exit(NULL);
        parsed_input = strtok(NULL, " ");
        count++;
    }
    free(parsed_input);
    return vector;
}

static void load_1_npc(linked_list_t *ll, char **npcs, game_t *game)
{
    entity_t *e = get_index_npc2(ll, &npcs[0][2]);

    if (my_pointlen(npcs) < 19 || !e)
        npc_err_exit(&npcs[0][2]);
    sfSprite_setPosition(e->npc->npc->sprite, str_to_sfvector2f(npcs[1], 6));
    e->hidden = my_getnbr(&npcs[2][9]);
    e->npc->hp = str_to_sfvector2i(npcs[3], 5);
    e->npc->map = my_strdup(npcs[4]);
    if (e->npc->hp.x <= 0) {
        sfTexture_destroy(e->npc->npc->texture);
        e->npc->npc->texture = sfTexture_createFromFile(get_asset("Hero_Ded",
        game->assets), NULL);
        sfSprite_setTexture(e->npc->npc->sprite,
            e->npc->npc->texture, sfFalse);
    }
}

static void import_entity_npc_pc(game_t *game,
    linked_list_t *ll)
{
    char **npcs = my_str_to_word_array(import_from_save("NPC",
        game->savefilepath), "\n", 0);

    for (int i = 0; i < my_pointlen(npcs); i++) {
        if (my_strcmpstart(npcs[i], "##") == 0) {
            load_1_npc(ll, &npcs[i], game);
        }
    }
}

linked_list_t *init_main_entity(player_character_t *player, game_t *game,
    bool new_game, map_t *map)
{
    linked_list_t *ll = NULL;

    init_scatter_entity(game, &ll, map);
    init_new_entity_npc_pc(player, game, &ll);
    init_houses_entity(&ll, map, game);
    if (!new_game)
        import_entity_npc_pc(game, ll);
    return ll;
}
