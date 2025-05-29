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

static void write_stats(int fd, main_slots_t **slots, int i)
{
    if (slots[i]->items->type == WEAPON)
        write_weapon(fd, slots[i]->items);
    if (slots[i]->items->type == AMMO)
        write_ammo(fd, slots[i]->items);
    if (slots[i]->items->type == ARMOR)
        write_armor(fd, slots[i]->items);
    if (slots[i]->items->type == DRUGS)
        write_drugs(fd, slots[i]->items);
    if (slots[i]->items->type == CYBERWARE)
        write_cyberware(fd, slots[i]->items);
}

static void add_inventory_in_file(int fd, main_slots_t **slots)
{
    char *nbr = NULL;

    write(fd, "###Inventory\n", 13);
    for (int i = 0; i < 20; i++) {
        nbr = int_to_str(i);
        write(fd, nbr, my_strlen(nbr));
        free(nbr);
        write(fd, " : ", 3);
        if (!slots[i] || slots[i]->items == NULL)
            write(fd, "null", 4);
        else {
            nbr = int_to_str(slots[i]->items->id);
            write(fd, nbr, my_strlen(nbr));
            free(nbr);
            write_stats(fd, slots, i);
        }
        write(fd, "\n", 1);
    }
}

void save_inventory(void *map, game_t *game)
{
    map_t *data = (map_t *)map;
    main_slots_t **slots = NULL;

    if (game->savefile == -1) {
        perror("open");
        return;
    }
    if (!(data->inventory && data->inventory->inventory &&
        data->inventory->inventory->main_slots))
        return;
    slots = data->inventory->inventory->main_slots;
    add_inventory_in_file(game->savefile, slots);
}
