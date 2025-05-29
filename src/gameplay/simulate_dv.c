/*
** EPITECH PROJECT, 2023
** simulate_dv.c
** File description:
** function that simulates fight between 2 entities
*/

#include "my.h"

static int seventh_weapon(int length)
{
    if (length < 6)
        return 17;
    if (length < 12)
        return 16;
    if (length < 20)
        return 15;
    if (length < 30)
        return 15;
    if (length < 42)
        return 20;
    if (length < 56)
        return 20;
    if (length < 72)
        return 25;
    if (length < 90)
        return 30;
    return 99;
}

static int sixth_weapon(int length)
{
    if (length < 6)
        return 16;
    if (length < 12)
        return 15;
    if (length < 20)
        return 15;
    if (length < 30)
        return 17;
    if (length < 42)
        return 20;
    if (length < 56)
        return 22;
    return 99;
}

static int fifth_weapon(int length)
{
    if (length < 6)
        return 15;
    if (length < 12)
        return 13;
    if (length < 20)
        return 15;
    if (length < 30)
        return 17;
    if (length < 42)
        return 20;
    if (length < 56)
        return 22;
    return 99;
}

static int fourth_weapon(int length)
{
    if (length < 6)
        return 30;
    if (length < 12)
        return 25;
    if (length < 20)
        return 20;
    if (length < 30)
        return 17;
    if (length < 42)
        return 14;
    if (length < 56)
        return 16;
    if (length < 72)
        return 17;
    if (length < 90)
        return 20;
    return 99;
}

static int third_weapon(int length)
{
    if (length < 6)
        return 17;
    if (length < 12)
        return 16;
    if (length < 20)
        return 15;
    if (length < 30)
        return 13;
    if (length < 42)
        return 15;
    if (length < 56)
        return 20;
    if (length < 72)
        return 25;
    if (length < 90)
        return 30;
    return 99;
}

static int second_weapon(int length)
{
    if (length < 6)
        return 15;
    if (length < 12)
        return 13;
    if (length < 20)
        return 15;
    if (length < 30)
        return 20;
    if (length < 42)
        return 25;
    if (length < 56)
        return 25;
    if (length < 72)
        return 30;
    return 99;
}

static int first_weapon(int length, int ammo)
{
    if (length < 6)
        return 13;
    if (length < 12)
        return 15;
    if (length < 20)
        return 20;
    if (length < 30)
        return 25;
    if (length < 42)
        return 30;
    if (length < 200 && (ammo == PISTOL || ammo == HPISTOL))
        return 30;
    if (length < 200 && ammo == SHOTGUN)
        return 35;
    return 99;
}

unsigned int simulate_dv(weapon_t *weapon, unsigned int length)
{
    if (weapon->type == PISTOL || weapon->type == SHOTGUN
        || weapon->type == HPISTOL)
        return (first_weapon(length, weapon->type)) - 6;
    if (weapon->type == SMG)
        return second_weapon(length) - 6;
    if (weapon->type == RIFLE)
        return third_weapon(length) - 6;
    if (weapon->type == SNIPER)
        return fourth_weapon(length) - 6;
    if (weapon->type == BOW)
        return fifth_weapon(length) - 6;
    if (weapon->type == NADL)
        return sixth_weapon(length) - 6;
    if (weapon->type == ROCKET_L)
        return seventh_weapon(length) - 6;
    return 0;
}
