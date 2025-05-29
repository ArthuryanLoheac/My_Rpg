/*
** EPITECH PROJECT, 2024
** compute_guis
** File description:
** compute_guis
*/

#include "my.h"

static char *get_music_cmb_rand(void)
{
    char *data1 = my_strdup("Fight_music_");
    char *result = malloc(sizeof(char) * (my_strlen(data1) + 2));
    int i = 0;

    result[my_strlen(data1) + 1] = '\0';
    for (; data1[i] != '\0'; i++)
        result[i] = data1[i];
    result[i] = int_to_str(rand() % 3 + 1)[0];
    free(data1);
    return result;
}

static void start_attack_music(game_t *game)
{
    sfMusic_pause(game->music->main_theme);
    game->music->combat_music = sfMusic_createFromFile(
        get_asset(get_music_cmb_rand(), game->assets));
    set_general_volume(game);
    sfMusic_setLoop(game->music->combat_music, sfTrue);
    sfMusic_play(game->music->combat_music);
}

void start_fight(game_t *game, map_t *map)
{
    linked_list_t *l = map->entity_all;

    start_attack_music(game);
    while (l != NULL) {
        if (((entity_t *)(l->data))->hidden == false && ((entity_t *)(l->data))
            ->type == NPC && ((entity_t *)(l->data))->npc->type == HOSTILE)
            my_insert_back_list(&(map->fight->turn_order),
                (entity_t *)(l->data));
        if (((entity_t *)(l->data))->type == PC)
            my_insert_back_list(&(map->fight->turn_order),
                (entity_t *)(l->data));
        l = l->next;
    }
    send_info(game, 5, "FIGHT !");
    map->fight->is_fight = true;
    map->fight->fighter = 0;
    map->fight->target = 0;
    map->player->movmult = 0.65;
    (void) game;
}

void start_fight_groups(game_t *game, map_t *map, char *grp)
{
    linked_list_t *l = map->entity_all;

    start_attack_music(game);
    while (l != NULL) {
        if (((entity_t *)(l->data))->hidden == false && ((entity_t *)(l->data))
            ->type == NPC && ((entity_t *)(l->data))->npc->type == HOSTILE &&
            my_strcmpstart(((entity_t *)(l->data))->npc->name, grp) == 0)
            my_insert_back_list(&(map->fight->turn_order),
                (entity_t *)(l->data));
        if (((entity_t *)(l->data))->type == PC)
            my_insert_back_list(&(map->fight->turn_order),
                (entity_t *)(l->data));
        l = l->next;
    }
    send_info(game, 5, "FIGHT !");
    map->fight->is_fight = true;
    map->fight->fighter = 0;
    map->fight->target = 0;
    map->player->movmult = 0.65;
    (void) game;
}
