/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-myrpg-matthieu.guillet-arnaud
** File description:
** get_nbr_slots_inv
*/

#include "my.h"

static int get_slots_empty(main_slots_t **slots,
    enum type_slots_e type)
{
    int nbr = 0;

    for (int i = 0; i < 20; i++)
        if (slots[i] && slots[i]->slot_type == type && slots[i]->items)
            nbr++;
    return nbr;
}

int nbr_max_slot(enum class_e class, main_slots_t **slots)
{
    int nbr_slots_nt_emp = get_slots_empty(slots, INVENTORY_SLOTS);

    if (class == SOLO || class == MED)
        return nbr_slots_nt_emp + 2;
    else
        return nbr_slots_nt_emp + 0;
}

int nbr_slot_wep(main_slots_t **slots)
{
    int nbr_slots_nt_emp = get_slots_empty(slots, WEAPON_SLOTS);

    return nbr_slots_nt_emp;
}

int nbr_slot_armor(main_slots_t **slots)
{
    int nbr_slots_nt_emp = get_slots_empty(slots, ARMOR_SLOTS);

    return nbr_slots_nt_emp;
}

int nbr_slot_cyber_inv(main_slots_t **slots)
{
    int nbr_slots_nt_emp = get_slots_empty(slots, CYBERWARE_SLOTS);

    return nbr_slots_nt_emp;
}
