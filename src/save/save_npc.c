/*
** EPITECH PROJECT, 2024
** save
** File description:
** save_inventory
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "../include/my.h"
#include "../include/lib.h"
#include <time.h>
#include <string.h>

static void write_weapon(int fd, item_t *item)
{
    char *nbr = NULL;

    write(fd, ",", 1);
    nbr = int_to_str(item->weapon->magazine.x);
    write(fd, nbr, my_strlen(nbr));
    free(nbr);
    write(fd, ",", 1);
    nbr = int_to_str(item->weapon->durability.x);
    write(fd, nbr, my_strlen(nbr));
    free(nbr);
    write(fd, ",", 1);
    nbr = int_to_str(item->weapon->bonus_tohit);
    write(fd, nbr, my_strlen(nbr));
    free(nbr);
    write(fd, ",", 1);
    nbr = int_to_str(item->weapon->bonus_damage);
    write(fd, nbr, my_strlen(nbr));
    free(nbr);
}

static void write_cyberware(int fd, item_t *item)
{
    char *nbr = NULL;

    write(fd, ",", 1);
    nbr = int_to_str(item->cyberware->value);
    write(fd, nbr, my_strlen(nbr));
    free(nbr);
}

static void write_ammo(int fd, item_t *item)
{
    char *nbr = NULL;

    write(fd, ",", 1);
    nbr = int_to_str(item->ammo->amount.x);
    write(fd, nbr, my_strlen(nbr));
    free(nbr);
}

static void write_armor(int fd, item_t *item)
{
    char *nbr = NULL;

    write(fd, ",", 1);
    nbr = int_to_str(item->armor->sp.x);
    write(fd, nbr, my_strlen(nbr));
    free(nbr);
}

static void write_drugs(int fd, item_t *item)
{
    char *nbr = NULL;

    write(fd, ",", 1);
    nbr = int_to_str(item->drug->uses.x);
    write(fd, nbr, my_strlen(nbr));
    free(nbr);
}

static void write_item(int fd, item_t *items, char *prefix)
{
    write(fd, prefix, my_strlen(prefix));
    write(fd, " : ", 3);
    if (items == NULL)
        write(fd, "null\n", 5);
    else {
        write(fd, int_to_str(items->id), my_strlen(int_to_str(items->id)));
        if (items->type == WEAPON)
            write_weapon(fd, items);
        if (items->type == AMMO)
            write_ammo(fd, items);
        if (items->type == ARMOR)
            write_armor(fd, items);
        if (items->type == DRUGS)
            write_drugs(fd, items);
        if (items->type == CYBERWARE)
            write_cyberware(fd, items);
        write(fd, "\n", 1);
    }
}

static void add_npc_in_file(int fd, entity_t *e)
{
    write(fd, "##", 2);
    write(fd, e->npc->name, my_strlen(e->npc->name));
    write(fd, "\n", 1);
    dprintf(fd, "Pos : %f,%f\nHidden : %d\nHp : %d,%d\n%s\n#Stats\nMOVE:%d\n"
        "TECH:%d\nWILL:%d\nBODY:%d\nREF:%d\nDEX:%d\nEMP:%d\nLUCK:%d\nHUM:%d\n",
        e->position.x, e->position.y, (int)e->hidden, e->npc->hp.x, e->npc
        ->hp.y, e->npc->map, e->npc->stats->MOVE, e->npc->stats->TECH, e->npc
        ->stats->WILL, e->npc->stats->BODY, e->npc->stats->REF, e->npc->stats
        ->DEX, e->npc->stats->EMP, e->npc->stats->LUCK, e->npc->stats->HUM);
    write_item(fd, e->npc->ranged, "ranged");
    write_item(fd, e->npc->melee, "melee");
    write_item(fd, e->npc->loot_1, "loot1");
    write_item(fd, e->npc->loot_2, "loot2");
    write(fd, "\n", 1);
}

void save_npc(linked_list_t *ll, game_t *game)
{
    if (game->savefile == -1) {
        perror("open");
        return;
    }
    write(game->savefile, "###NPC\n", 7);
    while (ll != NULL) {
        if (((entity_t *)(ll->data))->type == NPC)
            add_npc_in_file(game->savefile, ((entity_t *)(ll->data)));
        ll = ll->next;
    }
}
